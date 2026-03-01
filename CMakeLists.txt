cmake_minimum_required(VERSION 3.21.2)

project(RaphEngine2_example_proj VERSION 1.0.0 LANGUAGES CXX)

file(GLOB RaphEngine2_example_SRC
     "src/*.cpp"
)

add_executable(RaphEngine2_example ${RaphEngine2_example_SRC})

find_package(RaphEngine2 REQUIRED)

target_link_libraries(RaphEngine2_example
    PRIVATE
        RaphEngine2::RaphEngine2
)

target_compile_features(RaphEngine2_example PRIVATE cxx_std_20)

target_compile_options(RaphEngine2_example
    PRIVATE
        -Wall
        -Wextra
        -pedantic
)

target_include_directories(RaphEngine2_example
    PUBLIC
        include/
)
