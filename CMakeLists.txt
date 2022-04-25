cmake_minimum_required (VERSION 3.7 FATAL_ERROR)
project(SimpleCalculator)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Concurrent Network WebSockets)

add_library(RemoteObjectsLib SHARED
            Integer.cpp
            Integer.h
            Calculator.cpp
            Calculator.h)
            
target_include_directories(RemoteObjectsLib PRIVATE ${CUTE_SERVER_SDK_DIR}/include)
target_compile_definitions(RemoteObjectsLib PUBLIC SERVER_SIDE)
            
target_link_libraries(RemoteObjectsLib
                      ${CUTE_SERVER_SDK_DIR}/lib/libCuteServerSdk.so
                      Qt${QT_VERSION_MAJOR}::Core
                      Qt${QT_VERSION_MAJOR}::Concurrent
                      Qt${QT_VERSION_MAJOR}::Network
                      Qt${QT_VERSION_MAJOR}::WebSockets)
                          
add_executable(CalculatorClientApp
               CalculatorApp.cpp
               CalculatorClient.h
               Integer.cpp
               Integer.h)
               
target_include_directories(CalculatorClientApp PRIVATE ${CUTE_CLIENT_SDK_DIR}/include)
target_compile_definitions(CalculatorClientApp PUBLIC CLIENT_SIDE)
            
target_link_libraries(CalculatorClientApp
                      ${CUTE_CLIENT_SDK_DIR}/lib/libCuteClientSdk.so
                      Qt${QT_VERSION_MAJOR}::Core
                      Qt${QT_VERSION_MAJOR}::Concurrent
                      Qt${QT_VERSION_MAJOR}::Network
                      Qt${QT_VERSION_MAJOR}::WebSockets)
