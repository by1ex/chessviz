# Переменная CC указывает компилятор, используемый для сборки
CC = gcc
# Переменная CFLAGS содержит флаги, которые передаются компилятору
CFLAGS = -std=gnu11 -Wall -Werror

# Объявление фиктивных целей 'clean' 'start' 'all'
.PHONY: clean start all

# Создание зависимостей:
all: bin/main

test: bin/test

-include build/src/*.d

#Список всех зависимостей обрабатываемого правила
bin/main: build/src/main.o build/src/board_print_html.o build/src/board_read.o build/src/board_print_plain.o build/src/check.o
	$(CC) $(CFLAGS) -o $@ $^ 

build/src/main.o: src/main.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/src/board_print_html.o: src/board_print_html.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/src/board_read.o: src/board_read.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/src/board_print_plain.o: src/board_print_plain.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/src/check.o: src/check.c
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

-include build/test/*.d

bin/test: build/test/main.o build/test/check.o build/test/tests.o
	$(CC) $(CFLAGS) -o $@ $^

build/test/main.o: test/main.c
	$(CC) -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/tests.o: test/tests.c
	$(CC) -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

build/test/check.o: src/check.c
	$(CC) -I thirdparty -I src $(CFLAGS) -MMD -c -o $@ $<

start: bin/main
	bin/main

clean:
	rm -rf build/src/*.o build/src/*.d build/test/*.o build/test/*.d 