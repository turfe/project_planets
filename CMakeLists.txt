cmake_minimum_required(VERSION 3.14)
project(graphic)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

set(SFML_ROOT_DIR "C:/sfml")
set(SFML_DIR "${SFML_ROOT_DIR}/lib/cmake/SFML")

find_package(SFML REQUIRED system window graphics network audio)
#find_package(SFML 2.5 REQUIRED COMPONENTS system window graphics network audio)

set(SFML_LIBRARIES sfml-graphics sfml-window sfml-system)

message(STATUS "SFML libraries: ${SFML_LIBRARIES}")

add_executable(${PROJECT_NAME} main.cpp vector.h vectorS.cpp)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
