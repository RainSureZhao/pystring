set(TARGET pystring)

add_library(${TARGET} STATIC ${SOURCES})

target_include_directories(${TARGET} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)