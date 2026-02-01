CC = gcc
CFLAGS = -Wall
TARGET = marp
SRC = marp.c
dependFiles = mouse.c button.c
dependOFiles = mouse.o button.o

build: $(dependOFiles)
	$(CC) $(CFLAGS) $(SRC) -lSDL2 -lSDL2_image $(dependOFiles) -o $(TARGET)

depend:
	$(CC) $(CFLAGS) -c $(dependFiles)

clean:
	rm -f $(TARGET) $(dependFiles)