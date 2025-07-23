TARGETS = main.c tree.c
EXECUTABLE = main.o

make:
	gcc $(TARGETS) -o $(EXECUTABLE)
clean:
	rm -f $(EXECUTABLE)
