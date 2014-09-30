rock_library(webapp
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(webapp_bin Main.cpp
    DEPS webapp)

