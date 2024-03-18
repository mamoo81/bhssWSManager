cmake_minimum_required(VERSION 3.16)

project(bhssWSManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Core Quick Network)

qt_standard_project_setup()

qt_add_executable(appbhssWSManager
    main.cpp
)

qt_add_qml_module(appbhssWSManager
    URI bhssWSManager
    VERSION 1.0
    QML_FILES
        Main.qml
        StokKarti.qml
        Categories.qml
        SubCategories.qml
    RESOURCES
        "ui-icons/menu.svg"
        "ui-icons/back.svg"
        "ui-icons/settings.svg"
        "ui-icons/backspace.svg"
        "ui-icons/product.svg"
        "ui-icons/new.svg"
        "ui-icons/edit.svg"
        "ui-icons/save.svg"
        "ui-icons/cancel.svg"
        "android/AndroidManifest.xml"
        SOURCES restapihelper.h restapihelper.cpp
                product.h product.cpp
                SOURCES subcategory.h subcategory.cpp
                SOURCES category.h category.cpp
                SOURCES unit.h unit.cpp
                SOURCES producer.h producer.cpp
)

qt_add_resources(appbhssWSManager "assets"
    PREFIX "/ui-icons/"
)

qt_add_resources(appbhssWSManager "assets"
    PREFIX "/android/"
)

include(/home/mamoo/Android/Sdk/android_openssl/android_openssl.cmake)

if (ANDROID)
    add_android_openssl_libraries(appbhssWSManager)
endif()

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appbhssWSManager PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appbhssWSManager
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appbhssWSManager
    PRIVATE Qt6::Quick Qt6::Core Qt6::Network
)

include(GNUInstallDirs)
install(TARGETS appbhssWSManager
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
