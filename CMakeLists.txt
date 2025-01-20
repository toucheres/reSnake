cmake_minimum_required(VERSION 3.5.0)
project(cmakeqt VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt6 6.7.2 EXACT REQUIRED COMPONENTS Widgets Multimedia)

add_executable(cmakeqt foodClass.cpp SmallWidget.cpp game.cpp main.cpp mypushbutton.cpp reSnake.cpp select.cpp snakeClass.cpp snakemapClass.cpp snakeNodeClass.cpp reSnake.qrc)
target_link_libraries(cmakeqt PRIVATE Qt6::Widgets Qt6::Multimedia)