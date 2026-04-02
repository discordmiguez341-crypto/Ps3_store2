TARGET = PS3-MiniStore

OFILES = source/main.o

CFLAGS = -I$(PS3DEV)/ppu/include -std=gnu99

LDFLAGS = -lrsx -lgcm_sys -lsysutil -lrt -llv2

BUILDDIR = build

TITLE = Mini Loja PS3
APPID = MINISTORE

include $(PSL1GHT)/ppu_rules

pkg: $(TARGET).pkg

run:
	@ps3load $(TARGET).self

clean:
	rm -rf $(TARGET)*.pkg $(TARGET)*.self $(BUILDDIR) source/*.o
