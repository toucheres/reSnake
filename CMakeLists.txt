cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(reSnake LANGUAGES CXX)
elseif(UNIX)
    project(reSnake)
endif()

#set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)

#======================= INCLUSION OF Qt =======================#
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Multimedia REQUIRED)

#=================== INCLUSION OF Project Files ====================#
set(FORMS_DIR "${CMAKE_SOURCE_DIR}/forms")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")

include_directories(${FORMS_DIR})
include_directories(${INCLUDE_DIR})
include_directories(${SOURCE_DIR})

file(GLOB_RECURSE SOURCES
    "${FORMS_DIR}/*.ui"
    "${FORMS_DIR}/*.qrc"
    "${INCLUDE_DIR}/*.h"
    "${SOURCE_DIR}/*.cpp"
)

#=================== SETUP EXECTUABLE ====================#
# Enable debug logging on RELWITHDEBINFO configuration
set_property(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS
    $<$<CONFIG:RELWITHDEBINFO>:QT_MESSAGELOGCONTEXT>
)

#${CMAKE_AUTOUIC_SEARCH_PATHS}可能默认为cmakelists同级目录
message("--------------------------")
message(STATUS ${CMAKE_AUTOUIC_SEARCH_PATHS})
message("--------------------------")

#!!!必须将包含.ui .qrc的目录写入
# Add the forms directory to the AUTOUIC search paths
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_AUTOUIC_SEARCH_PATHS} ${FORMS_DIR})

message("--------------------------")
message(STATUS ${CMAKE_AUTOUIC_SEARCH_PATHS})
message("--------------------------")

# Add the executable
if (WIN32) 
    add_executable(reSnake WIN32 ${SOURCES})
elseif(UNIX)
    add_executable(reSnake ${SOURCES})
endif()

# Add the target includes for MY_PROJECT 
target_include_directories(reSnake PRIVATE ${FORMS_DIR})
target_include_directories(reSnake PRIVATE ${INCLUDE_DIR})
target_include_directories(reSnake PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(reSnake Qt6::Widgets Qt6::Multimedia)
