all: main

main: main.o stack.o postfix.o shunting_yard.o lex.o
	gcc main.o stack.o postfix.o shunting_yard.o lex.o -o postfix

main.o: main.c
	gcc -c main.c

stack.o: stack.c
	gcc -c stack.c

postfix.o: postfix.c
	gcc -c postfix.c

shunting_yard.o: shunting_yard.c
	gcc -c shunting_yard.c

lex.o: lex.c
	gcc -c lex.c

clean:
	rm *.o postfix

