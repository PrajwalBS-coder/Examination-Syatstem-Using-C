// C program for the Examination
// Management System
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int option = 0;
int i = 0;
int n = 0;
int j = 0;
float present = 75.00;
char money = 'P';
float tdays = 1;
char c;
// Structure of Student
struct student {
	char name[20];
	int rno;
	char fees;
	float days;
	float attend;
} s[1];
void add(struct student s[]);
void eligibleStudents(struct student s[]);
void execute();
void printStudents(struct student s[]);
void deleteRecord(struct student s[]);
void update(int);
void operation();
void execute()
{
    int a,b;
    printf("\n");
    printf("----------------------------------\n");
	printf(
		" Enter the serial number"
		"to select the option \n");
	printf(" 1. To show Eligible"
		"candidates \n");
	printf(" 2. To delete the "
		"student record \n");
	printf(" 3. To change the "
		"eligibility criteria \n");
	/*printf(" 4. Reset the "
		"eligibility criteria \n");*/
	printf(" 4. Print the list "
		"of all the student \n");
	printf(" Enter 0 to exit \n");
	scanf("%d", &option);
	switch (option)
	{
	case 1:
		eligibleStudents(s);
		execute();
		break;
	case 2:
		deleteRecord(s);
		execute();
		break;
	case 3:printf("1.Change Attendance\t\t 2.Pay fee");
	scanf("%d",&b);

            switch(b)
	{
	    case 2:printf("Enter the roll no");
	    scanf("%d",&a); update(a);
	    break;
       case 1:printf("Old Attendance "
			"required = %f",
			present);
			printf(
			"\n Enter the updated "
			"attendence required \n");
		scanf("%f", &present);
	}


		printf("Eligibility Criteria updated \n");
		execute();

		break;
	/*case 4:
		present = 75.00;
		money = 'P';
		printf("Eligibility creitria reset \n");
		execute();
		break;*/
	case 4:
		printStudents(s);
		execute();
		break;
	case 5:
		execute();
		break;
	case 0:
		operation();
	default:
		printf("Enter number only from 0-4 \n");
		execute();
	}
}
void printStudents(struct student s[])
{
		for (i = 0; i < n; i++) {

		printf("Name of student %s \n",
			s[i].name);
		printf("Student roll number = %d \n",
			s[i].rno);
		printf("Student fees status = %c \n",
			s[i].fees);
		printf("Student number of days "
			"present = %f \n",
			s[i].days);
		printf("Student attendence = %f \n",
			s[i].attend);
	}
}
void update(int a)
{char p;
printf("Enter fee state");
scanf(" %c", &p);
   for (i = 0; i < n; i++)
    {
        if(s[i].rno==a)
        {
            s[i].fees= p;

        }
	}
}



void deleteRecord(struct student s[])
{
	int a = 0;
	printf("Enter the roll number of "
		"the student to delete it ");
	scanf("%d", &a);
	for (i = 0; i <= n; i++)
        {
		if (s[i].rno == (a))
            {
			for (j = i; j < n; j++) {
				strcpy(s[j].name, s[j + 1].name);
				s[j].rno = s[j + 1].rno;
				s[j].fees = s[j + 1].fees;
				s[j].days = s[j + 1].days;
				s[j].attend = s[j + 1].attend;
			}
			printf("Student Record deleted");
		}
	}
}

// Function to print the student
// details of the eligible students
void eligibleStudents(struct student s[])
{
	printf("________________"
		"________________"
		"_______________"
		"_____________ \n");
	printf("Qualified student are  \n");
	for (i = 0; i < n; i++)
        {
		if (s[i].fees =='P'||s[i].fees=='p') {
			if (s[i].attend >= present) {
				printf("Student name = %s \n",
					s[i].name);
				printf("Student roll no. = %d \n",
					s[i].rno);
				printf(" Student fees = %c \n",
					s[i].fees);
				printf(" Student attendence = %f \n",
					s[i].attend);
			}
		}
	}
}
void add(struct student s[50])
{
	printf("Enter the total ");
	printf("number of working days \n");
	scanf("%f", &tdays);
	printf("Enter the number");
	printf("of students \n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		printf("Student number %d \n",
			(i + 1));
		printf("Enter the name of"
			" the student \n");
		scanf("%s", s[i].name);
		printf("Enter the roll number \n");
		scanf(" %d", &s[i].rno);
		printf("Enter the fees of the"
			"student 'P' for paid "
			", 'N' for not paid \n");
		scanf(" %c", &s[i].fees);
again:
		printf("Enter the number of"
			"days the student was "
			"present \n");
		scanf("%f", &s[i].days);
		if(s[i].days>tdays)
        {
            printf("\nAttended day should be lesser than Total Working days..!\n\n");
            goto again;
        }
		s[i].attend = (s[i].days
					/ tdays)
					* 100;
		printf("student attendence = %f \n",
			s[i].attend);
	}
	execute();
}
int main()
{
    printf("\n*********************************************************\n");
    printf("#\tWelcome to Student database registration\t#");
    printf("\n*********************************************************\n");
    printf(" \n");
	operation();
	return 0;
}
void operation()
{
	printf("Enter 0 to exit \n");
	printf("Enter 1 to add student"" record \n");
	scanf("%d", &option);
	switch (option) {
	case 0:
		exit(0);
	case 1:
		add(s);
		break;
	default:
		printf("Only enter 0 or 1");
		execute();
	}
}

