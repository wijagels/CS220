test : btree
	./btree 10 21 52 17 18 22 34 12 14 16
	./btree 2 1 3 5

btree : btree.c tree.c tree.h
	gcc -Wall -g -o btree btree.c tree.c

clean :
	-rm btree
