TARGETS = main.c tree.c
EXECUTABLE = main.o
PFLAGS = -lm

make:
	gcc $(TARGETS) -o $(EXECUTABLE) $(PFLAGS)
clean:
	rm -f $(EXECUTABLE)
