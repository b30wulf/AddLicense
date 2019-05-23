cmake_minimum_required (VERSION 3.8)

add_executable (AddLicense "AddLicense.cpp" "AddLicense.h")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "license")
