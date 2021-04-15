/*
 ============================================================================
 Name        : assignment.c
 Author      : ahmed.n
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

struct date {
	int day ;
    int month;
    int year ;



};
struct student {
	char name [20] ;
    int id ;
    struct date dob ;
    int score ;

};

int main() {

	/*student1 information */

	struct student student1 ;
	strcpy(student1.name ,"Ahmed ismail" ) ;
	student1.id=20016;
	student1.dob.day=20;
	student1.dob.month=5;
	student1.dob.year=2000;
	student1.score=80;

	/*print student1 info*/

	   printf( "student 1 Name : %s\n", student1.name);
	   printf( "student 1 id : %d\n",   student1.id);
	   printf( "student 1 date of birth : %d", student1.dob.day);
	   printf("/%d",student1.dob.month);
	   printf("/%d\n",student1.dob.year);

	   printf( "student 1 score: %d\n", student1.score);

	return 0;
}
