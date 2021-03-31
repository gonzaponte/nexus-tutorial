## -----------------------------------------------------------------------------
##  Exercise2 | src/CMakeLists.txt
##
##
## -----------------------------------------------------------------------------

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(Exercise2_SRC OBJECT ${SRCS})
