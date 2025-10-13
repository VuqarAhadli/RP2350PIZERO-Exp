# Replace TMDS with 10 bit UART (same baud rate):
# add_definitions(-DDVI_SERIAL_DEBUG=1)
# add_definitions(-DRUN_FROM_CRYSTAL)

add_executable(${NAME}
	main.c
)

target_compile_options(${NAME} PRIVATE -Wall)

set(DVI_DEFAULT_SERIAL_CONFIG "pico_sock_cfg" CACHE STRING
	"Select a default pin configuration from common_dvi_pin_configs.h")


target_compile_definitions(${NAME} PRIVATE
	DVI_DEFAULT_SERIAL_CONFIG=${DVI_DEFAULT_SERIAL_CONFIG}
	DVI_VERTICAL_REPEAT=1
	DVI_N_TMDS_BUFFERS=3
	PICO_PIO_USE_GPIO_BASE=1
)


pico_enable_stdio_uart(${NAME} 0)
pico_enable_stdio_usb(${NAME}  1)

target_link_libraries(${NAME}
	pico_stdlib
	pico_multicore
	libdvi
	libgui
)

# create map/bin/hex file etc.
pico_add_extra_outputs(${NAME})
