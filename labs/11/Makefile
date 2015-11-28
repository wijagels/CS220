test: target testhex.txt
	./target <testhex.txt

showHex : testhex.txt
	od -t x1z testhex.txt

testhex.txt : test.txt makeHex
	./makeHex <test.txt >testhex.txt

target : target.c
	gcc -g -Wall -m32 -o target target.c

makeHex : makeHex.c
	gcc -g -Wall -m32 -o makeHex makeHex.c

gdb: target testhex.txt
	gdb -x dbg.txt target

target.asm.txt : target
	objdump -d target >target.asm.txt

clean:
	-rm target target.asm.txt testhex.txt makeHex
