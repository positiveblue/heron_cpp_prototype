cmake_minimum_required (VERSION 2.8.2)
project (HERON_CPP_PROTOTYPE)

# include_directories (  )
# add_definitions( )

ADD_DEFINITIONS(
    -std=c++11
)

include_directories ( "include/" )
add_executable(test test.cpp)
