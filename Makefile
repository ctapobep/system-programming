TARGET_DIR=./target
SRC_DIR=./src/main/c
CC=gcc -I $(SRC_DIR)

all: main.o readfile.o
	$(TARGET_DIR)/readfile
main.o: prepare
	$(CC) main.c -o $(TARGET_DIR)/main
readfile.o: $(SRC_DIR)/csapp.h rio.o
	$(CC) -o $(TARGET_DIR)/readfile readfile.c $(TARGET_DIR)/rio.o
rio.o: prepare $(SRC_DIR)/csapp.h
	$(CC) -c $(SRC_DIR)/rio.c -o $(TARGET_DIR)/rio.o

prepare:
	-mkdir $(TARGET_DIR)
clean:
	-rm -r $(TARGET_DIR)