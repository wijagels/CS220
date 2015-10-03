all : cwords

cwords : cwords.c 
	gcc -g -o cwords cwords.c
	
test : cwords example.txt
	./cwords <example.txt
	
clean : 
	-rm cwords
