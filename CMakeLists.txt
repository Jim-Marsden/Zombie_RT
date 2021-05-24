cmake_minimum_required(VERSION 3.19)
project(Zombie_RT)

set(CMAKE_CXX_STANDARD 17)

Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)

FetchContent_MakeAvailable(Catch2)
set(Zombie_RT_Source zombie_statements.hpp dynamic_type.cpp dynamic_type.h task.cpp task.h main.cpp)

set(Zombie_Test_Source zombie_statements.hpp dynamic_type.cpp dynamic_type.h task.cpp task.h test_dynamic_type.cpp test_main.cpp)

add_executable(Zombie_RT ${Zombie_RT_Source})
target_link_libraries(Zombie_RT Catch2::Catch2)

add_executable(Zombie_Test ${Zombie_Test_Source})
target_link_libraries(Zombie_Test Catch2::Catch2)



list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)
include(CTest)
include(Catch)
catch_discover_tests(Zombie_Test)