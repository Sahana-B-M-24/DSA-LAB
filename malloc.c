#include<stdio.h>
#include<stdlib.h>
void main()
{
int n;
float sum=0;
struct employee{
int id;
char name[30];

float salary;
};
struct employee *ptr;
printf("enter the no of employees");
scanf("%d",&n);
printf("Size of the structure employee: %lu bytes\n", sizeof(struct employee));
ptr=(struct employee *) malloc(n*sizeof(struct employee));
for(int i=0;i<n;i++){
printf("enter the information %d employee",i+1);
printf("\n enter the id:");
scanf("%d",&ptr[i].id );
printf("enter the name:");
scanf("%s",ptr[i].name );
printf("enter the salary:");
scanf("%f",&ptr[i].salary );
}
for(int i=0;i<n;i++){
sum=sum+ptr[i].salary;
}
float a=12*sum;
printf("annual expenditure of %d employees is %f",n,a);
free(ptr);
}
