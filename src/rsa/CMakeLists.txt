project(rsa)

set(HEADER_FILES rsa.h)

set(SOURCE_FILES rsa.cpp)

add_library(rsa STATIC ${SOURCE_FILES} ${HEADER_FILES})
