cmake_minimum_required(VERSION 3.19)
project(blueprint-auto-layout-zadanie2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(blueprint-auto-layout-zadanie2
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    graphlayout.h
    graphlayout.cpp
)

target_link_libraries(blueprint-auto-layout-zadanie2
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS blueprint-auto-layout-zadanie2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET blueprint-auto-layout-zadanie2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
