# Makefile: the GNU make build file for Picklie.
# See LICENSE for copyright and licensing details.

SOURCE = picklie.c
TARGET = picklie.exe

CC = gcc
CCFLAGS = -O2 -Wl,-s -static

VERSION = \""0.1\""

all: picklie

picklie:
	$(CC) $(CCFLAGS) -DVERSION=$(VERSION) -o $(TARGET) $(SOURCE)