cmake_minimum_required(VERSION 3.20)

add_executable(PacManClone 
main.cpp
Engine.cpp
Entity.cpp
Game.cpp
PacManGame.cpp
ResourceManager.cpp
PacMan.cpp
Level.cpp
Coin.cpp
Ghost.cpp
ScoreText.cpp
Text.cpp
PowerUp.cpp
Animation.cpp
Menu.cpp
Utilities.cpp
)

target_link_libraries(PacManClone
    PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)

target_include_directories(PacManClone PRIVATE include)



