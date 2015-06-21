TARGET = template
OBJS = main.o graphics.o framebuffer.o

INCDIR = 
CFLAGS = -O2 -G0 -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBS=-lpspgu -lpng -lz -lm
LIBDIR =
LDFLAGS = 

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = Skate or Dice
PSP_EBOOT_ICON = ICON0.PNG 
PSP_EBOOT_PIC1 = PIC1.PNG 

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
