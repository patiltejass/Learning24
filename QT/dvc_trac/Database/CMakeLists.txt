
project(Service VERSION 0.1 LANGUAGES CXX)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Gui Widgets Sql REQUIRED)

set(QT_PLUGIN_PATH "C:/Qt/6.4.2/msvc2019_64/plugins")
add_library(
	Database SHARED
	database.h
	database.cpp
)
 qt_import_plugins(service PLUGINS SQLiteDriverPlugin)

# target_link_libraries(service PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(Database PRIVATE  Qt${QT_VERSION_MAJOR}::Sql)

