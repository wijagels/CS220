all: bug_1 bug_2 bug_3 bug_4 bug_5

bug_1 : bug_1.c
	gcc -g -Wall -o bug_1 bug_1.c
	
test1 : bug_1
	./bug_1	
	
vg1 : bug_1
	valgrind --leak-check=full --show-reachable=yes ./bug_1	

bug_2 : bug_2.c
	gcc -g -Wall -o bug_2 bug_2.c

test2 : bug_2
	./bug_2
	
vg2 : bug_2
	valgrind --leak-check=full --show-reachable=yes ./bug_2		
	
bug_3 : bug_3.c
	gcc -g -Wall -o bug_3 bug_3.c

test3 : bug_3
	./bug_3
	
vg3 : bug_3
	valgrind --leak-check=full --show-reachable=yes ./bug_3
	
bug_4 : bug_4.c
	gcc -g -Wall -o bug_4 bug_4.c

test4 : bug_4
	./bug_4
	
vg4 : bug_4
	valgrind --leak-check=full --show-reachable=yes ./bug_4
	
bug_5 : bug_5.c
	gcc -g -Wall -o bug_5 bug_5.c	
	
test5 : bug_5
	./bug_5
	
vg5 : bug_5
	valgrind --leak-check=full --show-reachable=yes ./bug_5
	
gdb5 : bug_5
	gdb -x dbg.txt bug_5	
		
clean:
	-rm bug_1 bug_2 bug_3 bug_4 bug_5
