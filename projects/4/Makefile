test : grades 
	./grades <test.txt

grades: grades.c
	gcc -m32 -g -o grades grades.c
	
grades.lst: grades
	objdump -d grades >grades.lst
	
gdb : grades 
	gdb -x dbg.txt grades
	
clean:  
	-rm grades grades.lst
