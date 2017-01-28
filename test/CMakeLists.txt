add_executable (tree tree.cpp)
target_link_libraries (tree libfit)

add_executable (demo_ui demo_ui.cpp)
target_link_libraries (demo_ui libfit)

add_executable (log log.cpp)
target_link_libraries (log libfit)

add_executable (matrix matrix.cpp)
target_link_libraries (matrix libfit)

add_executable (stringlist stringlist.cpp)
target_link_libraries (stringlist libfit)

add_executable (input input.cpp)
target_link_libraries (input libfit)
