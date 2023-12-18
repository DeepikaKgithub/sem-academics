#include <stdio.h>
#include <string.h>
// Define a structure to represent a day
struct Day {
char name[20];
int date;
char activity[100];
};
// Function to create the calendar
void create(struct Day calendar[7]) {
for (int i = 0; i < 7; i++) {
printf("Enter details for %s:\n", calendar[i].name);
printf("Date: ");
scanf("%d", &calendar[i].date);
printf("Activity: ");
scanf(" %[^\n]", calendar[i].activity);
}
}
// Function to read data from the keyboard
void read(struct Day calendar[7]) {
FILE *file = fopen("calendar.txt", "r");
if (file == NULL) {
printf("Error opening the file.\n");
return;
}
for (int i = 0; i < 7; i++) {
fscanf(file, "%d", &calendar[i].date);
fscanf(file, " %[^\n]", calendar[i].activity);
}
fclose(file);
}
// Function to display the calendar
void display(struct Day calendar[7]) {
printf("Calendar for the week:\n");
for (int i = 0; i < 7; i++) {
printf("%s(Date: %d): %s\n", calendar[i].name, calendar[i].date, calendar[i].activity);
}
}
int main()
{
struct Day calendar[7];
// Initialize the names of the days
strcpy(calendar[0].name, "Monday");
strcpy(calendar[1].name, "Tuesday");
strcpy(calendar[2].name, "Wednesday");
strcpy(calendar[3].name, "Thursday");
strcpy(calendar[4].name, "Friday");
strcpy(calendar[5].name, "Saturday");
strcpy(calendar[6].name, "Sunday");
int choice;
printf("1. Create Calendar\n");
printf("2. Read Calendar from File\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
create(calendar);
break;
case 2:
read(calendar);
break;
default:
printf("Invalid choice.\n");
return 1;
display(calendar);
return 0;
}
}