all:findstat.c
	gcc findstat.c

run:
	./a.out

clean:
	rm *.txt;
