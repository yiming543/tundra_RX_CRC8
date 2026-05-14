/*
 * File:   Receiver_PWM.c
 * Author: T00904
 *
 * Created on May 13, 2026, 5:30 PM
 */

#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/eccp3.h"
#define _XTAL_FREQ 32000000
#define UART_LEVEL (21)

uint8_t rx_buf = 0;
bool byte_ready = 0;

void ECCP3_CallBack(uint16_t capturedValue)
{
    uint16_t pluse_width_LO = 0;
    static uint8_t state = 0;
    static uint8_t bit_index = 0;
    bool data_bit = 0;

    static bool fEdge_falling_get = 0; // 1: falling edge get
    uint16_t width = 0;
    uint16_t now = 0;
    static uint16_t last_capture = 0;

    now = capturedValue;
    if (fEdge_falling_get == 0)
    {
        last_capture = now;
        CCP3CON = 0x05; // 改成上升沿捕捉
        fEdge_falling_get = 1;
    }
    else
    {
        // 上升沿 → 計算低電平寬度 (含溢位補償)
        if (now >= last_capture)
        {
            width = now - last_capture;
        }
        else
        {
            width = (~last_capture) + 1 + now; // 溢位補償
        }

        pluse_width_LO = width >> 3; // Timer1 tick=0.125µs to 1us
        CCP3CON = 0x04; // 改成下降沿捕捉
        fEdge_falling_get = 0;

        // PWM 變成 UART 19200 baud
        if (pluse_width_LO < UART_LEVEL)
        {
            UART_TX_LAT = 1;
            data_bit = 1;
        }
        else
        {
            UART_TX_LAT = 0;
            data_bit = 0;
        }

        if (state == 0)
        {
            // 等待 Start bit (必須是長低電平)
            if (data_bit == 0)
            {
                state = 1;
                bit_index = 0;
                rx_buf = 0;
            }
        }
        else if (state == 1)
        {
            // data
            if (data_bit == 0)
            {
                // bit=0
                // rx_buf &= ~(1 << bit_index);
            }
            else
            {
                // bit=1
                rx_buf |= (1 << bit_index);
            }

            bit_index++;
            if (bit_index > 7)
            {
                state = 2;
            }
        }
        else if (state == 2)
        {
            // 等待 Stop bit (必須是短低電平)
            if (data_bit == 1)
            {
                byte_ready = 1; // 收到完整 byte
            }
            state = 0; // 回到等待 Start bit
        }
    }
}

