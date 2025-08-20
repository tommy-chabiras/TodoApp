cmake_minimum_required(VERSION 3.16)

project(TodoApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS Core Quick Sql QuickControls2)


file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "src/*.hpp")


qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)


qt_add_resources(RESOURCES
    resources/qml.qrc
)

qt_add_executable(TodoApp
	${SOURCES}
	${HEADERS}
	${RESOURCES}
)


qt_add_qml_module(TodoApp
    URI TodoApp
    VERSION 1.0
    QML_FILES
        resources/qml/main.qml
)

target_include_directories(TodoApp PRIVATE
    src
)

target_link_libraries(TodoApp PRIVATE
    Qt6::Core
    Qt6::Quick
    Qt6::Sql
	Qt6::QuickControls2
)


set_target_properties(TodoApp PROPERTIES
    WIN32_EXECUTABLE FALSE
)

include(GNUInstallDirs)
install(TARGETS TodoApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
