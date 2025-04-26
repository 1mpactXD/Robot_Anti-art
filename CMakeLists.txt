cmake_minimum_required(VERSION 3.10)
project(RobotProject)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(MOSQUITTO REQUIRED libmosquitto)

include_directories(${MOSQUITTO_INCLUDE_DIRS})

add_executable(RobotProject 
    main.cpp 
    Robot_controller.cpp 
    Server.cpp 
    Robot_server_interaction.cpp
)

target_link_libraries(RobotProject ${MOSQUITTO_LIBRARIES})
