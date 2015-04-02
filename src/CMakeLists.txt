

rock_library(rest_api_cppclient
    SOURCES Http.cpp Commands.cpp
    HEADERS Http.hpp Commands.hpp
    LIBS curl)

rock_executable(rest_api_cppclient_bin Main.cpp
    DEPS rest_api_cppclient
    )