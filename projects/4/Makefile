test : grades
	./grades <test.hex

grades: grades.c exploit.c
	gcc -m32 -g -fno-stack-protector -o grades grades.c
	gcc -m32 -g -O0 -c -fno-stack-protector exploit.c grades.c
	gcc -m32 -g -O0 -S -fno-stack-protector exploit.c
	#gcc -m32 -g -c -fno-stack-protector grades.c
	gcc -m32 -g -fno-stack-protector -o egrades grades.o exploit.o

grades.lst: grades
	objdump -d grades >grades.lst

gdb : grades
	gdb -x dbg.txt grades

clean:
	-rm grades grades.lst
