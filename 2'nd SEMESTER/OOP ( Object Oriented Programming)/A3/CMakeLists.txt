cmake_minimum_required(VERSION 3.21)
project(a5-6-holmogigi)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.2.4/mingw_64/lib/cmake")
find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(a5-6-holmogigi
        CSVRepository.cpp
        CSVRepository.h
        domain.cpp
        domain.h
        HTMLRepository.cpp
        HTMLRepository.h
        main.cpp
        repository.cpp
        repository.h
        service.cpp
        service.h
        ui.cpp
        ui.h
        userRepo.cpp
        userRepo.h
        userService.cpp
        userService.h
        validators.cpp
        validators.h
         GUI.cpp
        GUI.h)

target_link_libraries(a5-6-holmogigi
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
    set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif ()
endif ()
if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
endif ()
foreach (QT_LIB Core Gui Widgets)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy
            "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
endforeach (QT_LIB)