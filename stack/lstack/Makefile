MAIN = stack
OBJS = stack_main.o stack.o
.PHONY: clean run
.SUFFIXES: .o .c

all:$(MAIN) run

call: clean all
	
$(MAIN): $(OBJS)
	gcc -Wall -o $(MAIN) $^

.c.o:
	gcc -c $<

run: $(MAIN)
	./$(MAIN)

clean:
	rm $(MAIN) *.o
