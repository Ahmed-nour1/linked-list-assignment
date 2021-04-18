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


struct student {
	char name[20] ;
    int id ;
    int score ;
    int day ;
    int month;
    int year ;

};

//Creating a linked list node
   struct node {
	   struct student* data;
	   struct node* next;
};
   struct node* head = NULL;
   struct node* tail = NULL;


void CreateList();
void InsertAtBegin();
void InsertAtEnd();
void InsertAtMiddle();
void DisplayList();
void DisplayAll();

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	//Taking number of students as input
	   printf("Please enter the number of students");
	   int n;
	   scanf("%d",&n);
	   //Create a linked list
	   CreateList(n);
	   //Insert new student at Beginning
	   InsertAtBegin();
	   //Insert a new student at End
	   InsertAtEnd();
	   //Insert a new student at a certain position
	   InsertAtMiddle();
	   //Display student's data at a certain position
	   DisplayList();
	   //Display all the data
	   DisplayAll();
return 0;
}




//Function to create a linked list
void CreateList(int n){
    struct node* tmp = NULL;
	struct node* helpnode = NULL;
	   //Input the number of students
if(n>0){
	head = (struct node*)malloc(sizeof(struct node));
	head->data = (struct student*)malloc(sizeof(struct student));
	    if(head == NULL)
    {
        printf("Unable to allocate memory.");
        exit(0);
    }
	printf("Input data for student 1 in the order: Name,ID,Score,Date(Day,Month,Year)");
	scanf("%s",(head->data->name));
	scanf("%d",&(head->data->id));
	scanf("%d",&(head->data->score));
	scanf("%d",&(head->data->day));
	scanf("%d",&(head->data->month));
	scanf("%d",&(head->data->year));
	head->next = NULL;
	tmp = head;
	for(int i=2;i<=n;i++){
		helpnode = (struct node*)malloc(sizeof(struct node));
		helpnode->data = (struct student*)malloc(sizeof(struct student));
		if(helpnode == NULL)
        {
            printf("Unable to allocate memory.");
            break;
        }
		printf("Input data for student %d in the order: Name,ID,Score,Date(Day,Month,Year)",i);
		scanf("%s",(helpnode->data->name));
		scanf("%d",&(helpnode->data->id));
		scanf("%d",&(helpnode->data->score));
		scanf("%d",&(helpnode->data->day));
		scanf("%d",&(helpnode->data->month));
		scanf("%d",&(helpnode->data->year));
		helpnode->next = NULL;
		tmp->next = helpnode;
		tmp = tmp->next;
}
	tail = helpnode;
}
else{
	printf("Incorrect input");
}
printf("Data Inserted successfully\n");
return;
}


void InsertAtBegin(){
	struct node* helpnode = NULL;
	helpnode = (struct node*)malloc(sizeof(struct node));
	helpnode->data = (struct student*)malloc(sizeof(struct student));
	printf("Insert data for new student at the beginning in the order: Name,ID,Score,Date(Day,Month,Year)");
	scanf("%s",(helpnode->data->name));
	scanf("%d",&(helpnode->data->id));
	scanf("%d",&(helpnode->data->score));
	scanf("%d",&(helpnode->data->day));
	scanf("%d",&(helpnode->data->month));
	scanf("%d",&(helpnode->data->year));
	helpnode->next = head;
	head = helpnode;
	printf("New student inserted successfully\n");
}

void InsertAtEnd(){
	struct node* helpnode = NULL;
	helpnode = (struct node*)malloc(sizeof(struct node));
	helpnode->data = (struct student*)malloc(sizeof(struct student));
	printf("Insert data for new student at the end in the order: Name,ID,Score,Date(Day,Month,Year)");
	scanf("%s",(helpnode->data->name));
	scanf("%d",&(helpnode->data->id));
	scanf("%d",&(helpnode->data->score));
	scanf("%d",&(helpnode->data->day));
	scanf("%d",&(helpnode->data->month));
	scanf("%d",&(helpnode->data->year));
	tail->next = helpnode;
	helpnode->next = NULL;
	tail = helpnode;
	printf("New student inserted successfully\n");
}

void InsertAtMiddle(){
	struct node* helpnode = NULL;
	struct node* tmp = NULL;
	int position;
	helpnode = (struct node*)malloc(sizeof(struct node));
	helpnode->data = (struct student*)malloc(sizeof(struct student));
	printf("Insert the position to insert the new student");
	scanf("%d",&position);
	printf("Insert data for new student at the chosen position in the order: Name,ID,Score,Date(Day,Month,Year)");
	scanf("%s",(helpnode->data->name));
	scanf("%d",&(helpnode->data->id));
	scanf("%d",&(helpnode->data->score));
	scanf("%d",&(helpnode->data->day));
	scanf("%d",&(helpnode->data->month));
	scanf("%d",&(helpnode->data->year));
	tmp = head;
	for(int i=2;i<=position-1;i++){
		tmp = tmp->next;
	}
	helpnode->next=tmp->next;
	tmp->next = helpnode;
	printf("New student inserted successfully\n");
}

void DisplayList(){
	int position = 0;
	struct node* tmp = NULL;
	tmp = head;
	printf("Please enter the position of the student");
	scanf("%d",&position);
	if(position==1){
		printf("Name: %s\n",head->data->name);
		printf("ID: %d\n",head->data->id);
		printf("Score: %d\n",head->data->score);
		printf("Date of birth: %d/%d/%d\n",head->data->day,head->data->month,head->data->year);

	}
	else{
	for(int i=1;i<=position-1;i++){
		tmp = tmp->next;
	}
	printf("Name: %s\n",tmp->data->name);
	printf("ID: %d\n",tmp->data->id);
	printf("Score: %d\n",tmp->data->score);
	printf("Date of birth: %d/%d/%d\n",tmp->data->day,tmp->data->month,tmp->data->year);

}
	printf("----------------\n");
}

void DisplayAll(){
	struct node* tmp = NULL;
	tmp = head;
	int i =1;
	while(tmp != NULL){
		printf("Name%d: %s\n",i,tmp->data->name);
		printf("ID%d: %d\n",i,tmp->data->id);
		printf("Score%d: %d\n",i,tmp->data->score);
		printf("Date of birth%d: %d/%d/%d\n",i,tmp->data->day,tmp->data->month,tmp->data->year);
		tmp = tmp->next;
		i++;
}
}
