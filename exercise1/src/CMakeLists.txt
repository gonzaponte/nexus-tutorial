## -----------------------------------------------------------------------------
##  Exercise1 | src/CMakeLists.txt
##
##
## -----------------------------------------------------------------------------

file(GLOB SRCS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(Exercise1_SRC OBJECT ${SRCS})
