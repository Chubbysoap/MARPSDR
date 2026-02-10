CC = gcc
CFLAGS = -Wall
TARGET = marp
SRC = ./src/marp.c
dependFiles = ./src/mouse.c ./src/button.c ./src/screen.c
dependOFiles = ./src/mouse.o ./src/button.o ./src/screen.o

build: $(dependOFiles)
	$(CC) $(CFLAGS) $(SRC) -lSDL2 -lSDL2_image $(dependOFiles) -o $(TARGET)

depend:
	$(CC) $(CFLAGS) -c $(dependFiles)

clean:
	rm -f $(TARGET) $(dependOFiles)