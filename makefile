#   This makefile creates object code and compiles the
#   executable file cntwlc1 which the user will enter to
#   run the program.
#


#Target links object files to create final executable file
cntwlc1: cntwlcFunc.o cntwlc1.o
        gcc cntwlcFunc.o cntwlc1.o -o cntwlc1 -lm



#Target converts following c file(s) to object files including the header file
cntwlc1.o: cntwlc1.c cntwlcFunc.h
        gcc -c cntwlc1.c


#Target converts following c file(s) to object files including the header file
cntwlcFunc.o: cntwlcFunc.c cntwlcFunc.h
        gcc -c cntwlcFunc.c



#Target deletes unnecesary object files
clean:
        rm *.o
