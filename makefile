run:
	gcc -o exe base.c
	./exe
	rm exe

test:
	gcc -o testEXE test.c
	time ./testEXE
	rm testEXE

hugeTest:
	gcc -o TEST base.c
	time ./TEST < teste_grande.txt
	rm TEST
