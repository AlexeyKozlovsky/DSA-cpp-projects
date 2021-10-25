set(BINARY ${PROJECT_NAME})
file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.hpp *.cpp)
file(GLOB HEADERS "../include/*.hpp")

set(SOURCES ${SOURCES})
add_executable(${BINARY}_run ${SOURCES} ${HEADERS})

add_library(${BINARY}_lib STATIC ${SOURCES})
