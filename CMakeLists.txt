cmake_minimum_required(VERSION 3.17)
project(Klausur)

find_package(Qt5Widgets REQUIRED)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
add_executable(Klausur
        main.cpp
        game/Game.cpp
        game/Board.cpp
        game/Object.cpp
        game/Position.cpp
        objects/Actor.cpp
        objects/Wall.cpp
        objects/PacDot.cpp
        objects/Player.cpp
        objects/Ghost.cpp
        game/Collision.cpp
        PacmanWidget.cpp objects/SmartGhost.cpp objects/SmartGhost.h objects/PacPill.cpp objects/PacPill.h rendering/ImageLoader.cpp rendering/ImageLoader.h rendering/MenuRenderer.cpp rendering/MenuRenderer.h rendering/GameRenderer.cpp rendering/GameRenderer.h rendering/EndgameRenderer.cpp rendering/EndgameRenderer.h)
target_link_libraries (Klausur
        Qt5::Widgets
        Threads::Threads)

FILE(COPY copyme/ DESTINATION "${CMAKE_BINARY_DIR}")

include(CPack)