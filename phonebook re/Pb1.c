#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#define MAX_STR 64
#define MAX_PERSON 100

#define FILE_NAME "phonebook.txt"

typedef struct struct_date {
    int year, month, day;
} Sdate;

typedef struct struct_person {
    char name[MAX_STR];
    char telephone[MAX_STR];
    Sdate birthday;
} Sperson;

int check_phone_number(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (!isdigit(str[i])) return 0;
    return 1;
}

char *format_phone_number(char *str)
{
    static char fmt[MAX_STR];
    memset(fmt, 0, MAX_STR);

    if (str[0] == '0') {
        if (str[1] == '2') {
            strncpy(fmt, str, 2);
            str += 2;
        } else {
            strncpy(fmt, str, 3);
            str += 3;
        }
        strcat(fmt, "-");
    }

    return fmt;
}

int check_date_year(int val)
{
    return (val >= 0);
}

int check_date_month(int val)
{
    return (1 <= val && val <= 12);
}

int check_date_day(int val)
{
    return (1 <= val && val <= 31);
}

int check_and_set_date(char *str, Sdate *date)
{
    if (strlen(str) != 8) return 0;
    for (int i = 0; i < 8; i++)
        if(!isdigit(str[i])) return 0;

    date->year = date->month = date->day = 0;
    for (int i = 0; i < 4; i++)
        date->year = date->year*10 + (str[i] - '0');
    for (int i = 4; i < 6; i++)
        date->month = date->month*10 + (str[i] - '0');
    for (int i = 6; i < 8; i++)
        date->day = date->day*10 + (str[i] - '0');

    return check_date_year(date->year) &&
           check_date_month(date->month) &&
           check_date_day(date->day);
}

void printMenu()
{
    printf("\n");
    printf("1. Add a person\n");
    printf("2. Print the list\n");
    printf("3. Name search\n");
    printf("4. Birthday this month!\n");
    printf("5. Sort the phone book\n");
    printf("6. Save the phone book\n");
    printf("7. Load the phone book\n");
    printf("0. Quit the program\n");
    printf("Enter the command: ");
}

int addPerson(Sperson *persons, int num)
{
    if (num >= MAX_PERSON-1) {
        printf("Error: phone book full\n");
        return num;
    }

    printf("\n** Enter a person **\n");
    printf("Enter the name: ");
    gets(persons[num].name);

    while (1) {
        printf("Enter the phone number: ");
        gets(persons[num].telephone);
        if (check_phone_number(persons[num].telephone)) break;
        printf("ERROR: invalid phone number\n");
    }

    while (1) {
        char str[MAX_STR];
        printf("Enter the birthday (yyyymmdd): ");
        gets(str);
        if (check_and_set_date(str, &persons[num].birthday)) break;
        printf("ERROR: invalid date\n");
    }

    return num + 1;
}

void printList(Sperson *persons, int num)
{
    printf("\n** Phone book **\n");
    for (int i = 0; i < num; i++) {
        printf("[%d]", i+1);
        printf("\tName: %s\n", persons[i].name);
        printf("\tTelephone: %s\n", format_phone_number(persons[i].telephone));
        printf("\tBirthday: %d. %d. %d.\n", persons[i].birthday.year, persons[i].birthday.month, persons[i].birthday.day);
    }
}

void nameSearch(Sperson *persons, int num)
{
    int found = 0;
    char str[MAX_STR];
    printf("\nEnter the name to search: ");
    gets(str);

    printf("\n");
    for (int i = 0; i < num; i++) {
        if (strstr(persons[i].name, str)) {
            printf("[%d] %s, %s, %d. %d. %d.\n", i+1,
                    persons[i].name,
                    format_phone_number(persons[i].telephone),
                    persons[i].birthday.year, persons[i].birthday.month, persons[i].birthday.day);
            found++;
        }
    }

    if (0 == found) {
        printf("ERROR: not found birthday\n");
    }
}

void birthdayMonth(Sperson *persons, int num)
{
    int month, found = 0;
    char str[MAX_STR];
    printf("\nEnter the month: ");
    gets(str);
    month = atoi(str);

    printf("\n");
    for (int i = 0; i < num; i++) {
        if (month == persons[i].birthday.month) {
            if (0 == found) {
                printf("Happy Birthdays!!!\n\n");
            }
            printf("[%d] %s, %s, %d. %d. %d.\n", i+1,
                    persons[i].name,
                    format_phone_number(persons[i].telephone),
                    persons[i].birthday.year, persons[i].birthday.month, persons[i].birthday.day);
            found++;
        }
    }

    if (0 == found) {
        printf("ERROR: not found birthday\n");
    }
}

int compareName(const void *a, const void *b)
{
    const Sperson *pa = a;
    const Sperson *pb = b;
    return strcmp(pa->name, pb->name);
}

void sortList(Sperson *persons, int num)
{
    qsort(persons, num, sizeof(Sperson), compareName);
}

void saveList(Sperson *persons, int num)
{
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        printf("ERROR: cannot open 'phonebook.txt'\n");
        return;
    }

    fwrite(&num, sizeof(int), 1, fp);
    fwrite(persons, sizeof(Sperson), num, fp);
    fclose(fp);
}

int loadList(Sperson *persons)
{
    int num = 0;
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("ERROR: cannot open 'phonebook.txt'\n");
        return 0;
    }

    fread(&num, sizeof(int), 1, fp);
    fread(persons, sizeof(Sperson), num, fp);
    fclose(fp);

    return num;
}

int main()
{
    int person_num = 0;
    Sperson persons[MAX_PERSON];

    printMenu();
    while (1) {
        char str[MAX_STR];
        int command;

        fgets(str, MAX_STR, stdin);
        command = atoi(str);

        switch(command) {
        case 0:
            return 0;
        case 1:
            person_num = addPerson(persons, person_num);
            break;
        case 2:
            printList(persons, person_num);
            break;
        case 3:
            nameSearch(persons, person_num);
            break;
        case 4:
            birthdayMonth(persons, person_num);
            break;
        case 5:
            sortList(persons, person_num);
            break;
        case 6:
            saveList(persons, person_num);
        case 7:
            person_num = loadList(persons);
            break;
        default:
            printf("Wrong command. Enter again: ");
            continue;
        }
        printf("\nPress any key to continue...");
        getch();
        printf("\n");
        printMenu();
    }

    return 0;
}
