CC = gcc

run:
	${CC} -o run main.c && ./run

delete:
	rm run