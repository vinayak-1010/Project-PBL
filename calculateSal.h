#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define SALARY_FILE "salaries.txt"

// Function to calculate salary
void calculateSalary(struct Employee *emp) {
    emp->grossSalary = emp->basicSalary + emp->allowance;
    emp->netSalary = emp->grossSalary - emp->deduction;
}

// Function to input and process salary for one employee
void processEmployeeSalary() {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%s", emp.empID);

    printf("Enter Employee Name: ");
    getchar(); // Clear newline
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = '\0'; // Remove newline

    printf("Enter Basic Salary: ");
    scanf("%f", &emp.basicSalary);

    printf("Enter Allowance: ");
    scanf("%f", &emp.allowance);

    printf("Enter Deductions: ");
    scanf("%f", &emp.deduction);

    calculateSalary(&emp);

    // Save to file
    FILE *file = fopen(SALARY_FILE, "a");
    if (file == NULL) {
        printf("Error opening salary file.\n");
        return;
    }

    fprintf(file, "%s|%s|%.2f|%.2f|%.2f|%.2f|%.2f\n",
        emp.empID, emp.name,
        emp.basicSalary, emp.allowance, emp.deduction,
        emp.grossSalary, emp.netSalary);

    fclose(file);

    // Display slip
    printf("\n--- Salary Slip ---\n");
    printf("Employee ID: %s\n", emp.empID);
    printf("Name: %s\n", emp.name);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("Allowance: %.2f\n", emp.allowance);
    printf("Gross Salary: %.2f\n", emp.grossSalary);
    printf("Deductions: %.2f\n", emp.deduction);
    printf("Net Salary: %.2f\n", emp.netSalary);
}

// Menu function for salary calculation module
void salaryMenu() {
    int choice;
    do {
        printf("\n--- Salary Calculation Menu ---\n");
        printf("1. Calculate & Save Employee Salary\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                processEmployeeSalary();
                break;
            case 2:
                printf("Exiting Salary Module.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 2);
}

