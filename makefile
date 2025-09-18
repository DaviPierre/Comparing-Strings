run:
	gcc -o exe base.c
	./exe
	rm exe

test:
	gcc -o testEXE test.c
	./testEXE
	rm testEXE
