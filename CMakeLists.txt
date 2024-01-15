cmake_minimum_required(VERSION 3.2)
project(dsv)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(dsv src/main.cpp src/application.cpp)

target_link_libraries(dsv PRIVATE sfml-graphics)
target_compile_features(dsv PRIVATE cxx_std_20)
