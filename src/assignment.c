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
#include <stdlib.h>

struct date {
	int day ;
    int month;
    int year ;



};
struct student {
	char* name ;
    int id ;
    struct date dob ;
    int score ;

};

//Creating a linked list node
   struct node {
	   struct student* data;
	   struct node* next;
};

void CreateList(struct student student1);

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);


	/*student1 information */

	struct student student1 ;
	student1.name = "Ahmed Nour";
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

	   //Create a linked list
	   CreateList(student1);

return 0;
}




//Function to create a linked list
void CreateList(struct student student1){
int n = 0;
printf("Please enter the number of students");
scanf("%d",&n);
if(n>0){
	struct node* head = NULL;
	struct node* tmp = NULL;
	struct node* helpnode = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = (struct student*)malloc(sizeof(struct student));
	head->data = &student1;
	head->next = NULL;
	tmp = head;
	for(int i=2;i<=n;i++){
		helpnode = (struct node*)malloc(sizeof(struct node));
		helpnode->data = (struct student*)malloc(sizeof(struct student));
		printf("Input data for node %d in the order: Name,ID,Score,Date(Day,Month,Year)",i);
		scanf("%s",(helpnode->data->name));
		scanf("%d",&(helpnode->data->id));
		scanf("%d",&(helpnode->data->score));
		scanf("%d",&(helpnode->data->dob.day));
		scanf("%d",&(helpnode->data->dob.month));
		scanf("%d",&(helpnode->data->dob.year));
		helpnode->next = NULL;
		tmp->next = helpnode;
		tmp = tmp->next;
}
}
else{
	printf("Incorrect input");
}
return;
}
