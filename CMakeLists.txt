cmake_minimum_required(VERSION 3.16)
project(mic-renamer-hub LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)
find_package(OpenGL REQUIRED)

qt_standard_project_setup()

# QML sources
set(QML_SOURCES
    qml/Main.qml
    qml/RenamerPage.qml
)

qt_add_qml_module(mic-renamer-hub
    URI Hub
    VERSION 1.0
    QML_FILES ${QML_SOURCES}
)

# C++ sources
set(PROJECT_SOURCES
    src/main.cpp
    src/IModule.h
    src/modules/RenamerModule.cpp
    src/modules/RenamerModule.h
)

# Executable
qt_add_executable(mic-renamer-hub-app
    ${PROJECT_SOURCES}
)

target_include_directories(mic-renamer-hub-app PRIVATE src)

# Link libraries
target_link_libraries(mic-renamer-hub-app PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    mic-renamer-hub
    "-framework CoreFoundation"
    "-framework CoreServices"
    "-framework OpenGL"
)
