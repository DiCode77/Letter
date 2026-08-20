cmake_minimum_required(VERSION 3.25)
project(Letter LANGUAGES CXX OBJCXX)

set(SRC      "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(EXAMPLES "${CMAKE_CURRENT_SOURCE_DIR}/examples")

set(SRC_APPL   "${SRC}/app")
set(SRC_CORE   "${SRC}/core")
set(SRC_VIEW   "${SRC}/view")
set(SRC_TOOLS  "${SRC}/tools")
set(SRC_WINDOW "${SRC}/window")

set(LIB_NAME "${PROJECT_NAME}")

# // Framework

file(GLOB_RECURSE SRC_APPL_FILES    "${SRC_APPL}/*.hpp" "${SRC_APPL}/*.h" "${SRC_APPL}/*.mm")
file(GLOB_RECURSE SRC_CORE_FILES    "${SRC_CORE}/*.hpp" "${SRC_CORE}/*.h")
file(GLOB_RECURSE SRC_VIEW_FILES    "${SRC_VIEW}/*.hpp" "${SRC_VIEW}/*.h" "${SRC_VIEW}/*.cpp" "${SRC_VIEW}/*.mm")
file(GLOB_RECURSE SRC_TOOLS_FILES   "${SRC_TOOLS}/*.hpp" "${SRC_TOOLS}/*.cpp" "${SRC_TOOLS}/*.inl")
file(GLOB_RECURSE SRC_WINDOW_FILES  "${SRC_WINDOW}/*.hpp" "${SRC_WINDOW}/*.h" "${SRC_WINDOW}/*.cpp" "${SRC_WINDOW}/*.mm")

find_library(APPKIT_FRAMEWORK AppKit REQUIRED)
find_library(MAPKIT_FRAMEWORK MapKit REQUIRED)
find_library(CORE_LOCATION_FRAMEWORK CoreLocation REQUIRED)
find_library(FOUNDATION_FRAMEWORK Foundation REQUIRED)

add_library(${LIB_NAME} SHARED ${SRC_APPL_FILES} ${SRC_CORE_FILES} ${SRC_VIEW_FILES} ${SRC_TOOLS_FILES} ${SRC_WINDOW_FILES})

target_include_directories(${LIB_NAME} PUBLIC ${SRC_APPL} ${SRC_CORE} ${SRC_VIEW} ${SRC_TOOLS} ${SRC_WINDOW})

target_link_libraries(${LIB_NAME} PUBLIC
                                        ${APPKIT_FRAMEWORK} 
                                        ${MAPKIT_FRAMEWORK} 
                                        ${CORE_LOCATION_FRAMEWORK} 
                                        ${FOUNDATION_FRAMEWORK})

set_target_properties(${LIB_NAME} PROPERTIES 
                                            CXX_STANDARD 23 
                                            CXX_STANDARD_REQUIRED ON 
                                           
                                            FRAMEWORK TRUE 
                                            FRAMEWORK_VERSION A 
                                            UBLIC_HEADER "${PUBLIC_HEADERS}")  


source_group("src\\app"    FILES ${SRC_APPL_FILES})
source_group("src\\core"   FILES ${SRC_CORE_FILES})
source_group("src\\view"   FILES ${SRC_VIEW_FILES})
source_group("src\\tools"  FILES ${SRC_TOOLS_FILES})
source_group("src\\window" FILES ${SRC_WINDOW_FILES})

# // Executable

set(APP_NAME "${PROJECT_NAME}App")

add_executable(${APP_NAME} ${EXAMPLES}/window/main.cpp)

target_link_libraries(${APP_NAME} PRIVATE ${LIB_NAME})

set_target_properties(${APP_NAME} PROPERTIES 
                                            CXX_STANDARD 23 
                                            CXX_STANDARD_REQUIRED ON )  

target_include_directories(${APP_NAME} PRIVATE ${SRC_APPL} ${SRC_CORE} ${SRC_VIEW} ${SRC_TOOLS} ${SRC_WINDOW})

source_group("examples\\window" FILES ${EXAMPLES}/window/main.cpp)

# // macOS App Bundle

set_target_properties(${APP_NAME} PROPERTIES 
                                            MACOSX_BUNDLE TRUE
                                            MACOSX_BUNDLE_GUI_IDENTIFIER "com.letter.dicode77.app"
                                            MACOSX_BUNDLE_BUNDLE_NAME "${APP_NAME}"
                                            MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
                                            MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
                                        