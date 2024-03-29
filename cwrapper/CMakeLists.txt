if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "Prevented in-tree built. Please create a build directory outside of the source code and call cmake from there")
endif()

project(GoAtlasEngineLib)
cmake_minimum_required(VERSION 3.6)

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
	message(FATAL_ERROR "32 bit isn't supported")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
if (MINGW)
set(CMKAE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

set(OpenGL_GL_PREFERENCE GLVND)

add_subdirectory(engine)

# Setting linker flags and library stuff for the different platforms
if (MINGW)
	set(GO_ATLAS_LIB_LIBS mingw32)
endif()

if(APPLE)
    INCLUDE_DIRECTORIES(/System/Library/Frameworks)
    FIND_LIBRARY(COCOA_LIBRARY Cocoa)
    FIND_LIBRARY(OpenGL_LIBRARY OpenGL)
    FIND_LIBRARY(IOKit_LIBRARY IOKit)
    FIND_LIBRARY(CoreVideo_LIBRARY CoreVideo)
    MARK_AS_ADVANCED(COCOA_LIBRARY OpenGL_LIBRARY)
    SET(APPLE_LIBS ${COCOA_LIBRARY} ${IOKit_LIBRARY} ${OpenGL_LIBRARY} ${CoreVideo_LIBRARY})
    set(GO_ATLAS_LIB_LIBS ${GO_ATLAS_LIB_LIBS} ${APPLE_LIBS})
endif()

if(UNIX AND NOT APPLE)
    # for Linux, BSD, Solaris, Minix
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
    find_package(OpenGL REQUIRED)
    add_definitions(${OPENGL_DEFINITIONS})
    find_package(X11 REQUIRED)
    # note that the order is important for setting the libs
    # use pkg-config --libs $(pkg-config --print-requires --print-requires-private glfw3) in a terminal to confirm
    set(GO_ATLAS_LIB_LIBS ${GO_ATLAS_LIB_LIBS} X11 Xxf86vm GL dl pthread)
    set (CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

        # rpath settings
    SET(CMAKE_SKIP_BUILD_RPATH FALSE)
    SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    SET(CMAKE_INSTALL_RPATH "./")
    SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
endif()

# include directories

include_directories(engine/src)

file(GLOB_RECURSE GO_ATLAS_LIB_SOURCE_FILES
        "src/*.cpp"
        "src/*.c"
		"src/*.h"
		"src/*.hpp"
        )

foreach(SOURCE_FILE IN ITEMS ${GO_ATLAS_LIB_SOURCE_FILES})
    if (IS_ABSOLUTE "${SOURCE_FILE}")
        file(RELATIVE_PATH SOURCE_FILE_REL "${CMAKE_CURRENT_SOURCE_DIR}" "${SOURCE_FILE}")
    else()
        set(SOURCE_FILE_REL "${SOURCE_FILE}")
    endif()
    get_filename_component(SOURCE_PATH "${SOURCE_FILE_REL}" PATH)
    string(REPLACE "/" "\\" SOURCE_PATH_CONVERTED "${SOURCE_PATH}")
    source_group("${SOURCE_PATH_CONVERTED}" FILES "${SOURCE_FILE}")
endforeach()  

# We need to make it available in the upper CMakeLists
set(ATLAS_ENGINE_MAIN_FILE ${ATLAS_ENGINE_MAIN_FILE} PARENT_SCOPE)

add_library(${PROJECT_NAME} SHARED ${GO_ATLAS_LIB_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${GO_ATLAS_LIB_LIBS} AtlasEngine)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND python ${CMAKE_SOURCE_DIR}/postbuild.py
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Executing post-build script"
)