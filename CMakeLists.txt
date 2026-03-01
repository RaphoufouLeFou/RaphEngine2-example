cmake_minimum_required(VERSION 3.21.2)

project(RaphEngine2_example LANGUAGES CXX)

include(FetchContent)

add_executable(RaphEngine2_example
    src/main.cpp
)

target_compile_features(RaphEngine2_example PRIVATE cxx_std_20)

# Link the engine librairy
find_package(RaphEngine2 REQUIRED)
target_link_libraries(RaphEngine2_example
    PRIVATE
        RaphEngine2::RaphEngine2
)

# Copies the DLL into the same folder as the executable for win builds
if(WIN32)
    add_custom_command(TARGET RaphEngine2_example POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:RaphEngine2::RaphEngine2>
            $<TARGET_FILE_DIR:RaphEngine2_example>
    )
endif()

# =========================
# dependencies (glm is mandatory)
# =========================

find_package(glm QUIET)

if(NOT glm_FOUND)
    FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 0af55ccecd98d4e5a8d1fad7de25ba429d60e863
    )
    FetchContent_MakeAvailable(glm)
endif()

target_link_libraries(RaphEngine2_example PRIVATE glm::glm)
