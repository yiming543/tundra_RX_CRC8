# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.cmf"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.hex"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.hxl"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.mum"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.o"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.sdb"
  "D:\\yiming\\00work\\tundar_RX_CRC8_V04.X\\out\\tundar_RX_CRC8_V04\\default.sym"
  )
endif()
