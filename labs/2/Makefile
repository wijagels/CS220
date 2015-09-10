all: factc
.PHONY: clean test

factc: factc.c
	gcc -lquadmath -g -o factc factc.c

test: factc
	./factc


clean:
	rm factc
