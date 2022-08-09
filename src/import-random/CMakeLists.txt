add_executable(import-random
    main.cpp
    SpinnerWindow.cpp
)

target_link_libraries(import-random PRIVATE
    Qt6::Widgets
    SpinningWheel
)

set_target_properties(import-random PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)
