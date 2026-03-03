CC = gcc
CFLAGS = -m32 -fno-stack-protector -g -Wall -ansi -pedantic

string_operations.o: ../source/string_operations.c ../include/string_operations.h
	$(CC) $(CFLAGS) -c ../source/string_operations.c -o string_operations.o
number_convert.o: ../source/number_convert.c ../include/number_convert.h
	$(CC) $(CFLAGS) -c ../source/number_convert.c -o number_convert.o
stack_static_array.o: ../source/stack_static_array.c ../include/stack_static_array.h
	$(CC) $(CFLAGS) -c ../source/stack_static_array.c -o stack_static_array.o
rpn.o: ../source/rpn.c ../include/rpn.h
	$(CC) $(CFLAGS) -c ../source/rpn.c -o rpn.o
dijkstra_for_rpn.o: ../source/dijkstra_for_rpn.c ../include/dijkstra_for_rpn.h
	${CC} ${CFLAGS} -c ../source/dijkstra_for_rpn.c -o dijkstra_for_rpn.o
main.o: ../source/main.c  ../asm_modules/start.asm ../asm_modules/calls.asm
	nasm -g -f elf ../asm_modules/start.asm -o ../build/start.o
	nasm -g -f elf ../asm_modules/calls.asm -o ../build/calls.o
	$(CC) $(CFLAGS) -c ../source/main.c -o main.o
prog: main.o number_convert.o stack_static_array.o rpn.o dijkstra_for_rpn.o string_operations.o
	ld -m elf_i386 start.o calls.o main.o number_convert.o stack_static_array.o rpn.o dijkstra_for_rpn.o string_operations.o -o prog
