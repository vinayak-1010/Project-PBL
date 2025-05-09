#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SALARY_FILE "salaries.txt"

// Function to display employee salary record
void displayEmployeeRecord(const struct Employee *emp) {
    printf("\n--- Employee Record ---\n");
    printf("Employee ID   : %s\n", emp->empID);
    printf("Name          : %s\n", emp->name);
    printf("Basic Salary  : %.2f\n", emp->basicSalary);
    printf("Allowance     : %.2f\n", emp->allowance);
    printf("Gross Salary  : %.2f\n", emp->grossSalary);
    printf("Deductions    : %.2f\n", emp->deduction);
    printf("Net Salary    : %.2f\n", emp->netSalary);
    printf("-------------------------\n");
}

// Function to search by Employee ID
void searchByID() {
    char searchID[20];
    char line[256];
    struct Employee emp;
    int found = 0;

    printf("Enter Employee ID: ");
    scanf("%s", searchID);

    FILE *file = fopen(SALARY_FILE, "r");
    if (!file) {
        printf("Salary record file not found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (parseSalaryLine(line, &emp) == 7) {
            if (strcmp(emp.empID, searchID) == 0) {
                displayEmployeeRecord(&emp);
                found = 1;
                break; // Assuming only one unique ID
            }
        }
    }

    if (!found) {
        printf("No record found for Employee ID: %s\n", searchID);
    }

    fclose(file);
}

// Function to search by Employee Name 
void searchByName() {
    char searchName[50];
    char line[256];
    struct Employee emp;
    int found = 0;

    printf("Enter Employee Name: ");
    getchar(); // clear newline
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // remove newline

    FILE *file = fopen(SALARY_FILE, "r");
    if (!file) {
        printf("Salary record file not found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (parseSalaryLine(line, &emp) == 7) {
            if (strcasecmp(emp.name, searchName) == 0) {
                displayEmployeeRecord(&emp);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("No record found for Employee Name: %s\n", searchName);
    }

    fclose(file);
}

// Search menu
void searchMenu() {
    int choice;
    do {
        printf("\n--- Search Menu ---\n");
        printf("1. Search by Employee ID\n");
        printf("2. Search by Name\n");
        printf("3. Exit Search\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                searchByID();
                break;
            case 2:
                searchByName();
                break;
            case 3:
                printf("Exiting search module.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
}

