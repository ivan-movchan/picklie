# Makefile: the GNU make build file for Picklie.
# See LICENSE for copyright and licensing details.

SOURCE = picklie.c
TARGET = picklie.exe

RES_SOURCE = picklie.rc
RES_TARGET = picklie.res

CC = gcc
CCFLAGS = -O2 -Wl,-s
LDFLAGS = -lgdi32 -static
WINDRES = windres

VERSION = \""0.1\""

all: picklie-res picklie

picklie-res:
	$(WINDRES) -O coff -o $(RES_TARGET) $(RES_SOURCE)

picklie:
	$(CC) $(CCFLAGS) -DVERSION=$(VERSION) -o $(TARGET) $(SOURCE) $(RES_TARGET) $(LDFLAGS)