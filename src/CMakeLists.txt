

rock_library(webapp
    SOURCES Http.cpp Commands.cpp
    HEADERS Http.hpp Commands.hpp
    LIBS curl)

rock_executable(webapp_bin Main.cpp
    DEPS webapp
    )