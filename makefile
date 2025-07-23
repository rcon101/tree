TARGETS = main.c tree.c
EXECUTABLE = main

make:
	gcc $(TARGETS) -o $(EXECUTABLE)
clean:
	rm -f $(EXECUTABLE)
