cmake_minimum_required(VERSION 3.16)

project(TodoApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Sql)


file(GLOB WIDGET_SOURCES "src/widgets/*.cpp")
file(GLOB SOURCES "src/*.cpp")

set(PROJECT_SOURCES
	${SOURCES}
	${WIDGET_SOURCES}
)

qt_add_executable(TodoApp
	${PROJECT_SOURCES}
)
target_include_directories(TodoApp PRIVATE
    src
    src/widgets
)

target_link_libraries(TodoApp PRIVATE Qt6::Widgets Qt6::Sql)


set_target_properties(TodoApp PROPERTIES
    WIN32_EXECUTABLE FALSE
)

include(GNUInstallDirs)
install(TARGETS TodoApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
