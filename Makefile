CC = gcc
CFLAGS = -Wall -pedantic-errors -g -pthread
PROJECTNAME = diagonal_sums

Compile: $(PROJECTNAME).out

$(PROJECTNAME).out: $(PROJECTNAME).o main.o
	$(CC) $(CFLAGS) $^ -o $@

Run: $(PROJECTNAME).out
	./$(PROJECTNAME).out in1.txt out1.txt 10 1

Clean:
	rm -f *.out *.o