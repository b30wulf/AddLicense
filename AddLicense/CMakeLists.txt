cmake_minimum_required (VERSION 3.5)

add_executable (AddLicense "AddLicense.cpp" "AddLicense.h" "LicenseList.h")
set_target_properties (${PROJECT_NAME} PROPERTIES OUTPUT_NAME "addlic")
