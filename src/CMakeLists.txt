file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

set(SOURCES ${SOURCES})

add_executable(solution ${SOURCES})

add_library(solution_lib STATIC ${SOURCES})