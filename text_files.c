//Group :03
//Member 1: MD. HASIBUL HASAN HASIB(253-35-645)
//Member 2: Abir Hasan Khan (253-35-313)
//Member 3: Syed Mehedi Hasan Iran (253-35-529)

#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
    int id;
    char name[50];
    float salary;
}EMP;


void create()
{
    EMP e;

    FILE *fp = fopen("employees.txt","a");

    if(fp==NULL)
    {
        perror("fopen");
        return ;
    }

    printf("Enter ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Salary: ");
    scanf("%f", &e.salary);

    fprintf(fp, "%d|%s|%.2f\n", e.id, e.name, e.salary);

    fclose(fp);

    printf("\nEmployee Added Successfully.\n");
}


void read()
{
    EMP e;

    FILE *fp = fopen("employees.txt", "r");

    if(fp == NULL)
    {
        perror("fopen");
        return ;
    }

    printf("\nEmployee Records\n");

    while(fscanf(fp, "%d|%49[^|]|%f",&e.id, e.name, &e.salary) == 3)
    {
        printf("\nID: %d", e.id);
        printf("\nName: %s", e.name);
        printf("\nSalary: %.2f\n", e.salary);
    }

    fclose(fp);
}


void update()
{
    EMP e;
    int id, found = 0;

    FILE *fp = fopen("employees.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL)
    {
        perror("fopen");
        if(fp != NULL) fclose(fp);
        if(temp != NULL) fclose(temp);
        return ;
    }

    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d|%49[^|]|%f",&e.id, e.name, &e.salary) == 3)
    {
        if(e.id == id)
        {
            found = 1;

            printf("Enter New Name: ");
            scanf(" %[^\n]", e.name);

            printf("Enter New Salary: ");
            scanf("%f", &e.salary);
        }

        fprintf(temp, "%d|%s|%.2f\n",e.id, e.name, e.salary);
    }

    fclose(fp);
    fclose(temp);

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if(found)
    {
         printf("\nEmployee Updated Successfully!\n");
    }

    else
    {
        printf("\nEmployee Not Found!\n");
    }

}


void delete()
{
    EMP e;
    int id, found = 0;

    FILE *fp = fopen("employees.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if(fp == NULL || temp == NULL)
    {
        perror("fopen");
        if(fp != NULL) fclose(fp);
        if(temp != NULL) fclose(temp);
        return;
    }

    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d|%49[^|]|%f",
                 &e.id, e.name, &e.salary) == 3)
    {
        if(e.id == id)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%d|%s|%.2f\n",e.id, e.name, e.salary);
    }

    fclose(fp);
    fclose(temp);

    remove("employees.txt");
    rename("temp.txt", "employees.txt");

    if(found)
        printf("\nEmployee Deleted Successfully!\n");
    else
        printf("\nEmployee Not Found!\n");
}


int main()
{
    int choice;

    while(1)
    {
        printf("\nEMPLOYEE MANAGEMENT SYSTEM\n");
        printf("1. Create Employee\n");
        printf("2. Read Employees\n");
        printf("3. Update Employee\n");
        printf("4. Delete Employee\n");
        printf("5. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                create();
                break;

            case 2:
                read();
                break;

            case 3:
                update();
                break;

            case 4:
                delete();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}

