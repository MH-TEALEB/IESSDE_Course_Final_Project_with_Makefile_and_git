#******************************************************************************
# Author: MH_TEALEB.
# Date: 4 June 2021. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# makefile for the HOST-Environment & MSP432-Embedded Target build systems.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# TARGET:
#	<FILE>.i    - Builds <FILE>.i preprocessor file.
#       <FILE>.asm  - Builds <FILE>.asm assembly file.
#	<FILE>.o    - Builds <FILE>.o object file.
#	Compile-all - Compile all object files, but DO NOT link.
#       build       - Builds and links all source files(It will out this files".o & .out & .map"and size. Maybe add other files if needed).
#       all         - Same as build.
#       build-all   - Builds and links all source files(It will out this files".i & .asm & .o & .out & .map", size and any other files needed).
#	all-all     - Same as build-all.
#       clean       - removes all generated files.
#
# PLATFORM-OVERRIDES:
#	For Host Environment:
#       	PLATFORM=HOST
#
#	For Target Embedded System(msp432):
#		PLATFORM=MSP432 
#		CPU - ARM Cortex Architecture (cortex-m4).
#       	ARCH - ARM Architecture for msp432 CPU (arm, thumb).
#       	SPECS - Specs file to give the linker (nosys.specs, nano.specs)
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST

# Variables and Flags For Host Environment:
ifeq ($(PLATFORM),HOST)
	SOURCES =./src/main.c \
		 ./src/course1.c \
		 ./src/data.c \
		 ./src/stats.c \
	         ./src/memory.c
	INCLUDES = -I./include/common
	CC = gcc
        LD = ld
	sz = size
	OBJDUMP = objdump
	CPPFLAGS = -E
	ASMFLAGS = -S
	CFLAGS = -DHOST -DCOURSE1 -DVERBOSE -std=c99 -Wall -Werror -g -O0
	LDFLAGS = -Wl,-Map=$(TARGET).map
	DEPFLAGS = -M
	TARGET = course1

endif

# Variables and Flags For Target Embedded System(msp432)
ifeq ($(PLATFORM),MSP432)
	SOURCES = ./src/main.c \
                  ./src/course1.c \
	 	  ./src/data.c \
	  	  ./src/stats.c \
	          ./src/memory.c \
		  ./src/system_msp432p401r.c \
		  ./src/startup_msp432p401r_gcc.c \
		  ./src/interrupts_msp432p401r_gcc.c
	INCLUDES = -I./include/common \
	           -I./include/msp432 \
                   -I./include/CMSIS 
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	sz = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	CPPFLAGS = -E
	ASMFLAGS = -S
	CFLAGS = -DMSP432 -mcpu=$(CPU) -m$(ARCH) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=$(SPECS) \
                 -DCOURSE1 -DVERBOSE -std=c99 -Wall -Werror -g -O0
	LDFLAGS = -Wl,-Map=$(TARGET).map -T./$(LINKER_FILE)
	DEPFLAGS = -M
	TARGET = course1

endif


# Builds Dependency Files from Source Files.
DEPENDENCIES = $(SOURCES:.c=.dep)

%.dep : %.c
	$(CC) $(INCLUDES) $(CFLAGS) $(DEPFLAGS) -o $@ $<
##############################################


# Builds Preprocessor Files From Source Files.
CPPS = $(SOURCES:.c=.i)

%.i : %.c
	$(CC) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -o $@ $<
##############################################


# Builds Assembly Files From Source Files.
ASMS = $(SOURCES:.c=.asm)

%.asm : %.c
	$(CC) $(INCLUDES) $(ASMFLAGS) $(CFLAGS) -o $@ $<
##############################################


# Builds Assembly Target Files(project.asm) For the Target Output File(project.out)
$(TARGET).asm : $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out >> $@
###########################################


# Builds Object Files from Source Files.
OBJECTS = $(SOURCES:.c=.o)

%.o : %.c
	$(CC) -c $(INCLUDES) $(CFLAGS) -o $@ $<
##############################################


# Builds Target File from Object Files and get the size of it.

$(TARGET).out: $(OBJECTS) 
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(sz) $@	
###############################################################


.PHONY: preprocessor-all
preprocessor-all: $(CPPS)

.PHONY: assembly-all
assembly-all: $(ASMS)

.PHONY: object-all
object-all: compile-all

.PHONY: compile-all
compile-all: $(OBJECTS)

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: build-all
build-all: all-all

.PHONY: all-all
all-all: $(CPPS) $(ASMS) $(DEPENDENCIES) $(TARGET).out 

.PHONY: clean
clean:
	rm -f $(CPPS) $(ASMS) $(OBJECTS) $(DEPENDENCIES) $(TARGET).out $(TARGET).map $(TARGET).asm
