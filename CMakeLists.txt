cmake_minimum_required(VERSION 4.2)
project(particleLife)

set(CMAKE_POLICY_VERSION_MINIMUM 4.2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
        GIT_PROGRESS TRUE
)
FETCHCONTENT_MAKEAVAILABLE(raylib)

add_executable(particleLife main.cpp
        particles/Particle.cpp
        particles/Particle.h
        particles/ParticleTypes.h
        particles/GlobalTypes.h
        utils/Vector.h
        utils/Point.h
        utils/Point.cpp
        utils/Vector.cpp
        GUI/Window.h
        GUI/Window.cpp
        simulation/Simulation.cpp
        simulation/Simulation.h
        particles/Interaction.h
)

target_link_libraries(particleLife PRIVATE raylib)
