file (GLOB libfit_src
        "ui/*.cpp"
        "core/*.cpp"
)

file (GLOB libfit_header
        "ui/*.hpp"
        "core/*.hpp"
)

add_library (libfit SHARED ${libfit_src} ${libfit_header})

set_target_properties (libfit
                       PROPERTIES
                       VERSION ${libfit_version}
)

INSTALL (TARGETS libfit
         DESTINATION lib
         PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

INSTALL (DIRECTORY core ui
         DESTINATION include/libfit
         FILES_MATCHING PATTERN "*.hpp"
         PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
)

INSTALL(FILES UI Core All
        DESTINATION include/libfit
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ)
