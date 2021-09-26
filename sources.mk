#******************************************************************************
# Author: MH_TEALEB.
# Date: 4 June 2021. 
#
#*****************************************************************************


# Add your Source files to this variable.
SOURCES = ./src/main.c \
          ./src/course1.c \
	  ./src/data.c \
	  ./src/stats.c \
	  ./src/memory.c \
          ./src/system_msp432p401r.c \
	  ./src/startup_msp432p401r_gcc.c \
	  ./src/interrupts_msp432p401r_gcc.c

 # Add your Include paths to this variable.
INCLUDES = -I./include/common \
	   -I./include/msp432 \
           -I./include/CMSIS 
