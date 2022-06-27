#name of the executable file
EXEC = prog

#all the source files
SRC = $(wildcard *.c)

#all the object files
OBJ =$(SRC:.c=.o)

#$@ : target
#$<: first dependence
#$^ : list of the dependences

all : $(EXEC)

#to create executable files
$(EXEC): $(OBJ)
	gcc -o $@ $^

#to create object files
%.o : %.c
	gcc -o $@ -c $<

#to remove the all the object file in the directory
clean :
	rm -rf *.o

#to remove the executable file 
mrproper : clean
	rm -rf $(EXEC)
