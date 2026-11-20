# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.cmf"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.hex"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.hxl"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.mum"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.o"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.sdb"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V05.X\\out\\tundar_RX_CRC8_V05\\default.sym"
  )
endif()
