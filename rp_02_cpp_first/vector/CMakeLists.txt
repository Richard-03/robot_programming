add_library(veclib vecF.cpp)
add_executable(main main.cpp)
target_link_libraries(main veclib)
