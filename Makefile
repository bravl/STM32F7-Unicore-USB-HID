# Makefile for STM32F779 - Test PROJECT
# https://github.com/ulfen/stm32f7-discovery-blinky
# Used as template

PROJECT = STM_Eval

################
# Sources

#SOURCES_S = Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/gcc/startup_stm32f779xx.s

# Uncomment when not using semihosting
SOURCES_C = $(shell find src/ -name "*.c")
#FREERTOS_C = $(shell find FreeRTOS/Source/ -name "*.c" -not -path "*/portable/*" -not -path "*/CMSIS_RTOS/*")
#$(info $(FREERTOS_C))
#FREERTOS_C += FreeRTOS/Source/portable/MemMang/heap_3.c
#FREERTOS_C += FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/port.c
#FREERTOS_C += FreeRTOS/Source/portable/Common/mpu_wrappers.c
#SOURCES_C += sys/stubs.c sys/_sbrk.c sys/_io.c
#SOURCES_C += Drivers/CMSIS/Device/ST/STM32F7xx/Source/Templates/system_stm32f7xx.c
#SOURCES_C += Drivers/BSP/STM32F769I_EVAL/stm32f769i_eval.c
#SOURCES_C += Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_gpio.c
#SOURCES_C += Drivers/STM32F7xx_HAL_Driver/Src/stm32f7xx_hal_adc.c

SOURCES = $(SOURCES_S) $(SOURCES_C) $(FREERTOS_C)
OBJS = $(SOURCES_S:.s=.o) $(SOURCES_C:.c=.o) $(FREERTOS_C:.c=.o)
OBJS += unicore-mx/lib/libucmx_stm32f7.a

################
# Includes and Defines

INCLUDES += -I src
INCLUDES += -I unicore-mx/include/
INCLUDES += -I unicore-mx/lib/
#INCLUDES += -I FreeRTOS/Source/include/
#INCLUDES += -I FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1/

DEFINES = -DSTM32 -DSTM32F7 -DSTM32F779xx

################
# Compiler/Assembler/Linker/etc

CC_PATH = /usr/bin/
PREFIX = $(CC_PATH)/arm-none-eabi

CC = $(PREFIX)-gcc
AS = $(PREFIX)-as
AR = $(PREFIX)-ar
LD = $(PREFIX)-gcc
NM = $(PREFIX)-nm
OBJCOPY = $(PREFIX)-objcopy
OBJDUMP = $(PREFIX)-objdump
READELF = $(PREFIX)-readelf
SIZE = $(PREFIX)-size
GDB = $(PREFIX)-gdb
RM = rm -f

################
# Compiler options

MCUFLAGS = -mcpu=cortex-m7 -mlittle-endian
MCUFLAGS += -mfloat-abi=hard -mfpu=fpv5-sp-d16
MCUFLAGS += -mthumb

DEBUGFLAGS = -Og -g -gdwarf-2
#DEBUGFLAGS = -O2

CFLAGS = -std=c11
#CFLAGS += -Wall -Wextra --pedantic

CFLAGS_EXTRA = -nostartfiles -fdata-sections -ffunction-sections
CFLAGS_EXTRA += -Wl,--gc-sections -Wl,-Map=$(PROJECT).map

CFLAGS += $(DEFINES) $(MCUFLAGS) $(DEBUG_FLAGS) $(CFLAGS_EXTRA) $(INCLUDES)

LDFLAGS = -static $(MCUFLAGS)
LDFLAGS += -Wl,--start-group -lgcc -lm -lc -lg -Wl,--end-group

# Enable Semihosting
LDFLAGS += --specs=rdimon.specs -lrdimon

LDFLAGS += -Wl,--gc-sections
LDFLAGS += -T STM32F7x9.ld -L. -Lldscripts
LDFLAGS += -Xlinker -Map -Xlinker $(PROJECT).map

################
# Build rules

all: unicore $(PROJECT).hex

unicore:
	make -C unicore-mx/

$(PROJECT).hex: $(PROJECT).elf
	$(OBJCOPY) -O ihex $(PROJECT).elf $(PROJECT).hex

$(PROJECT).elf: $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(PROJECT).elf
	$(SIZE) -A $(PROJECT).elf

clean:
	$(RM) $(OBJS) $(PROJECT).elf $(PROJECT).hex $(PROJECT).map
