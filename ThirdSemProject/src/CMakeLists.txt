file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.cpp *.h)
file(GLOB HEADERS "../include/*.h")

set(SOURCES ${SOURCES})
add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES} ${HEADERS})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES} ${HEADERS})