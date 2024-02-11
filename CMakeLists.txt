cmake_minimum_required(VERSION 3.2)
project(dsv)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x
        GIT_SHALLOW true
)
FetchContent_MakeAvailable(SFML)

set(BOOST_INCLUDE_LIBRARIES signals2)
set(BOOST_ENABLE_CMAKE ON)
FetchContent_Declare(
        Boost
        URL https://github.com/boostorg/boost/releases/download/boost-1.84.0/boost-1.84.0.tar.xz
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
FetchContent_MakeAvailable(Boost)

add_executable(dsv
        src/controller/controller.cpp
        src/model/model.cpp
        src/ui/ui.cpp
        src/view/view.cpp
        src/application.cpp
        src/main.cpp
)

include_directories(src)

target_link_libraries(dsv PRIVATE sfml-graphics Boost::signals2)
target_compile_features(dsv PRIVATE cxx_std_20)

