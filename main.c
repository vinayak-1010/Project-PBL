#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Employee {
    char empID[20];
    char name[50];
    float basicSalary;
    float allowance;
    float deduction;
    float grossSalary;
    float netSalary;
};


int parseSalaryLine(const char *line, struct Employee *emp) {
    return sscanf(line, "%[^|]|%[^|]|%f|%f|%f|%f|%f",
                  emp->empID, emp->name,
                  &emp->basicSalary, &emp->allowance, &emp->deduction,
                  &emp->grossSalary, &emp->netSalary);
}


#include "userAuth.h"
#include "calculateSal.h"
#include "payslip.h"
#include "search.h"
void main(){
    authMenu();
    int choice;
    int r=0;
    do{
        printf("\nHello User:\n");
        printf("1. Calculate Sal\n");
        printf("2. Generate payslip\n");
        printf("3. Search Records\n");
        printf("4. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch (choice){
        
        case 1:
        salaryMenu();
            break;
        case 2:
        payslipMenu();
            break;
        case 3:
        searchMenu();
            break;

        case 4:
        printf("exit\n");
            break;

        default:
        printf("Invalid choice.Try again\n");
          
        }

    }while(choice !=4);
}