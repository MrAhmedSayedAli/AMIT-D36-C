add_subdirectory(mcal)
add_subdirectory(lib)
add_subdirectory(hal)
#add_subdirectory(RTOS)
add_subdirectory(FREERTOS)

set(APP_SOURCES
        ${APP_SOURCES}
        src/main.c

        PARENT_SCOPE
        )