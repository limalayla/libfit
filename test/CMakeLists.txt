add_executable (tree tree.cpp)
target_link_libraries (tree fit)

add_executable (demo_ui demo_ui.cpp)
target_link_libraries (demo_ui fit)

add_executable (log log.cpp)
target_link_libraries (log fit)

add_executable (matrix matrix.cpp)
target_link_libraries (matrix fit)

add_executable (stringlist stringlist.cpp)
target_link_libraries (stringlist fit)
