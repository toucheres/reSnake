cmake_minimum_required(VERSION 3.14)

if (WIN32)
    project(reSnake LANGUAGES CXX)
elseif(UNIX)
    project(reSnake LANGUAGES CXX)  # 确保也设置了语言
endif()

# 设置环境变量以便在运行时找到合适的平台插件
set(ENV{QT_QPA_PLATFORM} "xcb")

# 设置 Qt 安装路径
set(CMAKE_PREFIX_PATH "/usr/local/Qt-6.7.2")
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 查找所需的 Qt 包
find_package(Qt6Core REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Multimedia REQUIRED)
find_package(Qt6MultimediaWidgets REQUIRED)  # 添加这一行

# 如果您需要 Wayland 支持
# find_package(Qt6WaylandClient)
# if (NOT Qt6WaylandClient_FOUND)
#     message(WARNING "Qt6 Wayland Client not found. Wayland support will not be available.")
# endif()

# 检查 GStreamer (多媒体后端的常用依赖)
find_package(PkgConfig QUIET)
if(PKG_CONFIG_FOUND)
    pkg_check_modules(GSTREAMER gstreamer-1.0)
    if(NOT GSTREAMER_FOUND)
        message(WARNING "GStreamer not found. Qt multimedia backend may not work properly.")
    endif()
endif()

# 其余部分保持不变
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
# 建议使用set_target_properties来代替全局set
set_target_properties(reSnake PROPERTIES
    AUTOMOC ON    # 处理Q_OBJECT宏
    AUTOUIC ON    # 处理.ui文件
    AUTORCC ON    # 处理.qrc文件
)
# Add the target includes for MY_PROJECT 
target_include_directories(reSnake PRIVATE ${FORMS_DIR})
target_include_directories(reSnake PRIVATE ${INCLUDE_DIR})
target_include_directories(reSnake PRIVATE ${SOURCE_DIR})

#===================== LINKING LIBRARIES =======================#
target_link_libraries(reSnake Qt6::Widgets Qt6::Multimedia Qt6::MultimediaWidgets)
