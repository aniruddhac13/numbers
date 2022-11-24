CC=gcc
AR=ar

prime.o: prime.c
	${CC} -c prime.c

test.o: test.c
	${CC} -c test.c

libnum.a: prime.o
	${AR} rcs libnum.a prime.o

testnum: test.o libnum.a
	${CC} -o testnum test.o libnum.a

test: testnum
	./testnum input.txt expout.txt

deploy: libnum.a
	/bin/cp libnum.a /usr/local/lib/numutils/

clean:
	rm *.o libnum.a testnum
