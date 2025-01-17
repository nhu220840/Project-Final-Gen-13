program: FindTheOldestStudent.o FindTheYoungestStudent.o ProjectFinal.o
	gcc FindTheOldestStudent.o FindTheYoungestStudent.o ProjectFinal.o -o program

FindTheOldestStudent.o: FindTheOldestStudent.c FindTheOldestStudent.h
	gcc -c FindTheOldestStudent.c

FindTheYoungestStudent.o: FindTheYoungestStudent.c FindTheYoungestStudent.h
	gcc -c FindTheYoungestStudent.c

ProjectFinal.o: ProjectFinal.c
	gcc -c ProjectFinal.c

clean:
	rm *.o program