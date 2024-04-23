project(DataBase VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Sql REQUIRED)

add_library(databaseLibrary STATIC
    dataprovider.h dataprovider.cpp)

target_link_libraries(databaseLibrary PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(databaseLibrary PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

