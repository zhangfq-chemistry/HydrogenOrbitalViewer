# Install script for directory: /home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so.2.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/libQtColorWidgets-Qt52.so.2.0.0"
    "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/libQtColorWidgets-Qt52.so.2"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so.2.0.0"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so.2"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/libQtColorWidgets-Qt52.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libQtColorWidgets-Qt52.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/include/" FILES_MATCHING REGEX "^.*.h$|^.*.hpp$|^.*$" REGEX "CMakeLists.txt" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtColorWidgets" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/QtColorWidgets_version.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/QtColorWidgets" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/include/QtColorWidgets/colorwidgets_global.hpp")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52.cmake"
         "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/CMakeFiles/Export/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/CMakeFiles/Export/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/CMakeFiles/Export/lib/cmake/QtColorWidgets-Qt52/QtColorWidgets-Qt52-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets.cmake"
         "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/CMakeFiles/Export/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/CMakeFiles/Export/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^()$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/CMakeFiles/Export/lib/cmake/QtColorWidgets-Qt52/qtcolorwidgets-qt52-targets-noconfig.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/QtColorWidgets-Qt52" TYPE FILE FILES
    "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/QtColorWidgets/qtcolorwidgets-qt52-config.cmake"
    "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/QtColorWidgets/qtcolorwidgets-qt52-config-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/QtColorWidgets-Qt52.pc")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/include/QtColorWidgets/cmake_install.cmake")
  include("/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/resources/QtColorWidgets/cmake_install.cmake")
  include("/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/src/QtColorWidgets/cmake_install.cmake")
  include("/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/gallery/cmake_install.cmake")
  include("/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/color_widgets_designer_plugin/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/zhangfq/Method-II/HydrogenOrbitalViewer/colorPicker/Qt-Color-Widgets/color_widgets_designer_plugin/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
