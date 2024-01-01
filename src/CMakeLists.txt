SET(INCLUDE_PATHS "./")
SET(LIBRARY_SOURCES
    "queue.cpp"
    "location.cpp"
    "graph.cpp"
    "algorithm.cpp")
SET(HEADER_SOURCES 
    "queue.h"
    "location.h"
    "node.h"
    "graph.h"
    "algorithm.h")
add_library(${SOURCE} STATIC ${LIBRARY_SOURCES} ${HEADER_SOURCES})
target_include_directories(${SOURCE} PUBLIC ${INCLUDE_PATHS})