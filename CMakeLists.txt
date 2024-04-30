# CMakeLists.txt of PsychicHttp component

# Src files
file(GLOB_RECURSE PsychicHttp_SRCS
    src/*.c
    src/*.cpp
)
# Include
set(PsychicHttp_INCS
    src/
)

# Public component requirement
set(PsychicHttp_REQUIRES
    esp_http_server
    esp_https_server
    arduino-esp32
    ArduinoJson
)

# Private component requirement
set(PsychicHttp_PRIV_REQUIRES
)

# Register component
idf_component_register(
    SRCS ${PsychicHttp_SRCS}
    INCLUDE_DIRS ${PsychicHttp_INCS}
    REQUIRES ${PsychicHttp_REQUIRES}
    PRIV_REQUIRES ${PsychicHttp_PRIV_REQUIRES}
)
