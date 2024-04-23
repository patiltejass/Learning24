project(database VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets Sql REQUIRED)

add_library(SeriviceLibrary STATIC
    serviceprovider.h serviceprovider.cpp)

target_link_libraries(SeriviceLibrary PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(SeriviceLibrary PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_include_directories(SeriviceLibrary PUBLIC DataBase)
target_link_libraries(SeriviceLibrary PRIVATE databaseLibrary)

