CC = gcc
CFLAGS = -Wall
TARGET = marp
SRC = ./src/marp.c
dependFiles = ./src/mouse.c ./src/button.c ./src/screen.c ./src/textbox.c
dependOFiles = ./src/mouse.o ./src/button.o ./src/screen.o ./src/textbox.o
linkLibraries = -lSDL2 -lSDL2_image -lSDL2_ttf

build: $(dependOFiles)
	$(CC) $(CFLAGS) $(SRC) $(dependOFiles) -o $(TARGET) $(linkLibraries)

depend:
	$(CC) $(CFLAGS) -c $(dependFiles)

clean:
	rm -f $(TARGET) $(dependOFiles)