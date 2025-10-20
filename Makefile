CC = gcc
CFLAGS = -Wall -Iinclude -Iraylib/include
LDFLAGS = -Lraylib/lib -lraylib -lopengl32 -lgdi32 -lwinmm
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = build/main.exe

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

clean:
	del /Q build\*.exe

run:
	.\build\main.exe
