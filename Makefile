CFLAG=-Wall -Wextra -pedantic -std=c99 -Wswitch-enum -Wmissing-prototypes -Wno-missing-braces -fno-strict-aliasing

main: main.c lexer.c
	cc main.c -o main $(CFLAG) lexer.c


