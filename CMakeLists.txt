cmake_minimum_required(VERSION 3.21.2)

project(RaphEngine2_example LANGUAGES CXX)

include(FetchContent)

add_executable(RaphEngine2_example
    src/main.cpp
)

target_compile_features(RaphEngine2_example PRIVATE cxx_std_20)

if(NOT WIN32)
    target_compile_options(RaphEngine2_example PRIVATE -fsanitize=address -fno-omit-frame-pointer -g)
    target_link_options(RaphEngine2_example PRIVATE -fsanitize=address)
endif()

# Link the engine librairy
find_package(RaphEngine2 REQUIRED)
target_link_libraries(RaphEngine2_example
    PRIVATE
        RaphEngine2::RaphEngine2
)

target_include_directories(RaphEngine2_example PUBLIC
    $<BUILD_INTERFACE:${RaphEngine2_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${RaphEngine2_SOURCE_DIR}/include/RaphEngine2>

)

# Copies the DLL into the same folder as the executable for win builds
if(WIN32)
    add_custom_command(TARGET RaphEngine2_example POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:RaphEngine2::RaphEngine2>
            $<TARGET_FILE_DIR:RaphEngine2_example>
    )
endif()

# ============
# dependencies 
# ============

find_package(glm QUIET)

if(NOT glm_FOUND)
    FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863
    )
    FetchContent_MakeAvailable(glm)
endif()

find_package(nlohmann_json QUIET)

if(nlohmann_json_FOUND)
    target_link_libraries(RaphEngine2_example PUBLIC nlohmann_json::nlohmann_json)
else()
    FetchContent_Declare(
        nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.12.0
    )
    FetchContent_MakeAvailable(nlohmann_json)

    target_link_libraries(RaphEngine2_example PRIVATE nlohmann_json::nlohmann_json)

    target_include_directories(RaphEngine2_example PUBLIC
        $<BUILD_INTERFACE:${nlohmann_json_SOURCE_DIR}/include>
    )
endif()

target_link_libraries(RaphEngine2_example PRIVATE glm::glm)
