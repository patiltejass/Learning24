cmake_minimum_required(VERSION 3.10)

project(dvc_trac VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt6 COMPONENTS Core GUI Sql Widgets PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_subdirectory(Service)
add_subdirectory(Database)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(dvc_trac
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

		generatepdf.h generatepdf.cpp generatepdf.ui
		updatedetails.h updatedetails.cpp updatedetails.ui
		Service/service.h Service/service.cpp
		Database/database.h Database/database.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET dvc_trac APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(dvc_trac SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(dvc_trac
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_directories(dvc_trac PUBLIC Service)
target_link_libraries(dvc_trac PRIVATE service)
target_link_libraries(dvc_trac PRIVATE Qt::Core Qt::Gui Qt::Widgets Qt::PrintSupport)

target_link_directories(dvc_trac PUBLIC Database)
target_link_libraries(dvc_trac PRIVATE Database)

target_link_libraries(dvc_trac PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(dvc_trac PRIVATE Qt${QT_VERSION_MAJOR}::Sql)



# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.dvc_trac)
endif()
set_target_properties(dvc_trac PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS dvc_trac
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(dvc_trac)
endif()
