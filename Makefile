# Makefile: the GNU make build file for Picklie.
# See LICENSE for copyright and licensing details.

SOURCE = src/picklie.c
TARGET = picklie.exe

RES_SOURCE = src/picklie.rc
RES_TARGET = picklie.res

CC = gcc
WINDRES = windres

CCFLAGS = -O2 -Wl,-s
LDFLAGS = -lgdi32 -static

VERSION = \""1.0\""

all: picklie-res picklie

picklie-res:
	@echo Building Picklie resource file...
	@$(WINDRES) -O coff -o $(RES_TARGET) $(RES_SOURCE)

picklie:
	@echo Building Picklie application...
	@$(CC) $(CCFLAGS) -DVERSION=$(VERSION) -o $(TARGET) $(SOURCE) $(RES_TARGET) $(LDFLAGS)