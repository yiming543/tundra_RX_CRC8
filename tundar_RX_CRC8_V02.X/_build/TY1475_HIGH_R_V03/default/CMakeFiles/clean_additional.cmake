# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.cmf"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.hex"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.hxl"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.mum"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.o"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.sdb"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V01.X\\out\\TY1475_HIGH_R_V03\\default.sym"
  )
endif()
