#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
struct student
{
int roll_no;
char name[30];
float ca_marks;
};
void create_record()
{
FILE *fp;
struct student s;
fp = fopen("CA_details.txt", "a");
printf("Enter the Roll Number of the Student: ");
scanf("%d", &s.roll_no);
printf("Enter the Name of the Student: ");
scanf("%s", &s.name);
printf("Enter the CA Marks of the Student: ");
scanf("%f", &s.ca_marks);
fwrite(&s, sizeof(s), 1, fp);
printf("\nRecord created successfully!\n\n");
fclose(fp);
}
void search_record()
{
FILE *fp;
struct student s;
int roll_no, found = 0;
fp = fopen("CA_details.txt", "r");
printf("Enter the Roll Number to search: ");
scanf("%d", &roll_no);
while (fread(&s, sizeof(s), 1, fp))
{
if (s.roll_no == roll_no)
{
printf("\nRecord found!\n");
printf("Roll Number: %d\n", s.roll_no);
printf("Name: %s\n", s.name);
printf("CA Marks: %.2f\n\n", s.ca_marks);
found = 1;
break;
}
}
if (found == 0)
{
printf("\nRecord not found!\n\n");
}
fclose(fp);
}
void modify_record()
{
FILE *fp;
struct student s;
int roll_no, found = 0;
fp = fopen("CA_details.txt", "r+");
printf("Enter the Roll Number to modify: ");
scanf("%d", &roll_no);
while (fread(&s, sizeof(s), 1, fp))
{
if (s.roll_no == roll_no)
{
printf("\nRecord found!\n");
printf("Roll Number: %d\n", s.roll_no);
printf("Name: %s\n", s.name);
printf("CA Marks: %.2f\n\n", s.ca_marks);
printf("Enter the new Name of the Student: ");
scanf("%s", &s.name);
printf("Enter the new CA Marks of the Student: ");
scanf("%f", &s.ca_marks);
fseek(fp, -sizeof(s), SEEK_CUR);
fwrite(&s, sizeof(s), 1, fp);
printf("\nRecord modified successfully!\n\n");
found = 1;
break;
}
}
if (found == 0)
{
printf("\nRecord not found!\n\n");
}
fclose(fp);
}
void delete_record()
{
FILE *fp, *temp;
struct student s;
int roll_no, found = 0;
fp = fopen("CA_details.txt", "r");
temp = fopen("temp.txt", "w");
printf("Enter the Roll Number to delete: ");
scanf("%d", &roll_no);
while (fread(&s, sizeof(s), 1, fp))
{
if (s.roll_no != roll_no)
{
fwrite(&s, sizeof(s), 1, temp);
}
else
{
found = 1;
}
}
if (found == 0)
{
printf("\nRecord not found!\n\n");
}
else
{
printf("\nRecord deleted successfully!\n\n");
}
fclose(fp);
fclose(temp);
remove("CA_details.txt");
rename("temp.txt", "CA_details.txt");
}
void display_record()
{
FILE *fp;
struct student s;
fp = fopen("CA_details.txt", "r");
if (fp == NULL)
{
printf("\nError: File could not be opened!\n\n");
return;
}
printf("\nRoll Number\tName\t\tCA Marks\n");
printf("----------------------------------------------\n");
while (fread(&s, sizeof(s), 1, fp))
{
printf("%d\t\t%s\t\t%.2f\n", s.roll_no, s.name, s.ca_marks);
}
printf("\n");
fclose(fp);
}
int main()
{
int choice;
do
{
printf("------- Student CA Evaluator System -------\n\n");
printf("1. Create record\n");
printf("2. Search record\n");
printf("3. Modify record\n");
printf("4. Delete record\n");
printf("5. Display record\n");
printf("6. Exit\n\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice)
{
case 1:
create_record();
break;
case 2:
search_record();
break;
case 3:
modify_record();
break;
case 4:
delete_record();
break;
case 5:
display_record();
break;
case 6:
printf("\nExiting the program...\n\n");
break;
default:
printf("\nInvalid choice! Try again.\n\n");
}
} while (choice != 6);
return 0;
}
