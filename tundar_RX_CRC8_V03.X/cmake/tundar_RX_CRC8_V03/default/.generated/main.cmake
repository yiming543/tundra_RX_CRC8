include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(tundar_RX_CRC8_V03_default_library_list )

set(OUTPUT_SUFFIX elf)
# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_assemble)
add_library(tundar_RX_CRC8_V03_default_default_XC8_assemble OBJECT ${tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_assemble})
    tundar_RX_CRC8_V03_default_default_XC8_assemble_rule(tundar_RX_CRC8_V03_default_default_XC8_assemble)
    list(APPEND tundar_RX_CRC8_V03_default_library_list "$<TARGET_OBJECTS:tundar_RX_CRC8_V03_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(tundar_RX_CRC8_V03_default_default_XC8_assemblePreprocess OBJECT ${tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_assemblePreprocess})
    tundar_RX_CRC8_V03_default_default_XC8_assemblePreprocess_rule(tundar_RX_CRC8_V03_default_default_XC8_assemblePreprocess)
    list(APPEND tundar_RX_CRC8_V03_default_library_list "$<TARGET_OBJECTS:tundar_RX_CRC8_V03_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_compile)
add_library(tundar_RX_CRC8_V03_default_default_XC8_compile OBJECT ${tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_compile})
    tundar_RX_CRC8_V03_default_default_XC8_compile_rule(tundar_RX_CRC8_V03_default_default_XC8_compile)
    list(APPEND tundar_RX_CRC8_V03_default_library_list "$<TARGET_OBJECTS:tundar_RX_CRC8_V03_default_default_XC8_compile>")

endif()


# Main target for this project
add_executable(tundar_RX_CRC8_V03_default_image_fMDJEE5_ ${tundar_RX_CRC8_V03_default_library_list})

set_target_properties(tundar_RX_CRC8_V03_default_image_fMDJEE5_ PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${tundar_RX_CRC8_V03_default_output_dir}")
target_link_libraries(tundar_RX_CRC8_V03_default_image_fMDJEE5_ PRIVATE ${tundar_RX_CRC8_V03_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
tundar_RX_CRC8_V03_default_link_rule( tundar_RX_CRC8_V03_default_image_fMDJEE5_)



