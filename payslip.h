#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SALARY_FILE "salaries.txt"

// Function to generate payslip by searching employee ID
void generatePayslip() {
    char searchID[20];
    struct Employee emp;
    char line[256];
    int found = 0;

    printf("Enter Employee ID to generate payslip: ");
    scanf("%s", searchID);

    FILE *file = fopen(SALARY_FILE, "r");
    if (file == NULL) {
        printf("Error: Salary records not found.\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        if (parseSalaryLine(line, &emp) == 7) {
            if (strcmp(emp.empID, searchID) == 0) {
                found = 1;
                printf("\n======== Payslip ========\n");
                printf("Employee ID   : %s\n", emp.empID);
                printf("Name          : %s\n", emp.name);
                printf("Basic Salary  : %.2f\n", emp.basicSalary);
                printf("Allowance     : %.2f\n", emp.allowance);
                printf("Gross Salary  : %.2f\n", emp.grossSalary);
                printf("Deductions    : %.2f\n", emp.deduction);
                printf("Net Salary    : %.2f\n", emp.netSalary);
                printf("=========================\n");
                break;
            }
        }
    }

    if (!found) {
        printf("No record found for Employee ID: %s\n", searchID);
    }

    fclose(file);
}

// Menu for payslip generation
void payslipMenu() {
    int choice;
    do {
        printf("\n--- Payslip Generation Menu ---\n");
        printf("1. Generate Payslip\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                generatePayslip();
                break;
            case 2:
                printf("Exiting Payslip Module.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);
}

