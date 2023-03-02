//
// Created by Shishir Garg on 03/08/22.
//
#include<stdio.h>
int main() {
    char name[20];
    int age;
    float salary;
    FILE *fp;
    fp = fopen("emp.txt", "w+");
    printf("Enter Name: ");
    scanf("%s", &name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Salary: ");
    scanf("%f", &salary);
    fprintf(fp, "%s %d %f", name, age, salary);

    printf("\n \n");
    fscanf(fp, "%s %d %f", name, age, salary);
    printf("Name: %s\nAge: %d\nSalary: %f\n", name, age, salary);
}