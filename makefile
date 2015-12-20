CC= gcc
CFLAGS= -std=c99 -Wall
mainexec: progexam.c mybooklib.c
	$(CC) $(CFLAGS) -o progexam progexam.c mybooklib.c
