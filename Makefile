# Переменная CC указывает компилятор, используемый для сборки
CC = g++
# Переменная CFLAGS содержит флаги, которые передаются компилятору
CFLAGS = -std=c++11 -Wall -Werror

# Объявление фиктивных целей 'clean' 'start' 'all'
.PHONY: clean start all

# Создание зависимостей:
all:bin/main

-include build/*.d

#Список всех зависимостей обрабатываемого правила
bin/main: build/main.o build/board_print_html.o build/board_read.o build/board_print_plain.o
	$(CC) $(CFLAGS) -o $@ $^ 

build/main.o: src/main.cpp
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/board_print_html.o: src/board_print_html.cpp
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/board_read.o: src/board_read.cpp
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

build/board_print_plain.o: src/board_print_plain.cpp
	$(CC) $(CFLAGS) -MMD -c -o $@ $<

start: bin/main
	bin/main

clean:
	rm -rf build/*