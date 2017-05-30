CC=gcc
TARGET_DIR=./target

all: readfile.o
	$(TARGET_DIR)/readfile
main.o: prepare
	$(CC) main.c -o $(TARGET_DIR)/main
readfile.o: prepare
	$(CC) readfile.c -o $(TARGET_DIR)/readfile
prepare:
	-mkdir $(TARGET_DIR)
clean:
	-rm -r $(TARGET_DIR)
run:
	$(TARGET_DIR)/readfile