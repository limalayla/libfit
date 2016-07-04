add_executable (tree tree.cpp)
target_link_libraries (tree libfit)

add_executable (demo_ui demo_ui.cpp)
target_link_libraries (demo_ui libfit)
