#include <stdio.h>
#include <string.h>

struct date
{
    int day;
    int month;
    int year;
};
struct Employee_info
{
    int id;
    struct date joining_date;
    float salary;
    char name[50];
    char mobile_no[50];
}
employee[200];
int size=0;


int manu()
{
    int choice;
    printf("1. add Employee\n");
    printf("2. Search Employee id\n");
    printf("3. update Employee info\n");
    printf("4. Display average salary\n");
    printf("5. sarch employee id and given joining date\n");
    printf("Enter -1 to exit.\n\n\n\n\n");
    printf("Enter your choice ");
    scanf("%d",&choice);
    printf("\n");

    return choice;
}
// Function no 1
void add_employee()
{
    int i,j,k,flag,num;
    printf("Number of employee to add\n");
    scanf("%d",&num);
    if (num>200)
    {
        printf("wrong input");
    }
    else
    {
        for(i=size;i<size+num;i++)
      {
        printf("Employee number %d\n",i+1);
        printf("Enter id :");
        scanf("%d",&employee[i].id);
        for(j=0;j<i;j++)
        {
            if(employee[i].id==employee[j].id)
            {
                printf("data already exists\n try again");
                scanf("%d",&employee[i].id);
            }

        }
        printf("Enter employee name ");
        fflush(stdin);
        gets(employee[i].name);
        //gets(employee[i].name);
        printf("Enter employee salary ");
        scanf("%f",&employee[i].salary);
        printf("Enter employee mobile number ");
        fflush(stdin);
        gets(employee[i].mobile_no);

        for(j=0;j<i;j++)
        {
          flag=0;
          for(k=0;employee[i].mobile_no[k];k++)
            {
              if(employee[i].mobile_no[k]==employee[j].mobile_no[k])
                    flag++;

            }
            if(flag==k)
            {
                printf("Data exist\n Enter another mobile number ");
                fflush(stdin);
                gets(employee[i].mobile_no);
            }
        }
        printf("Enter employee joining date ");
        scanf("%d %d %d",&employee[i].joining_date.day,&employee[i].joining_date.month,&employee[i].joining_date.year);

        printf("\n\n\n");


    }
    size+=num;
}
}


//function 2
void search_ID()
{
    int search_id,i,flag;
    flag=0;
    printf("Enter the id ");
    scanf("%d",&search_id);
    for(i=0;i<size;i++)
    {
        if(search_id==employee[i].id)
        {
            printf("name:%s.\n",employee[i].name);
            printf("salary:%f\n",employee[i].salary);
            printf("mobile no:%s\n",employee[i].mobile_no);
            printf("joining date:%d %d %d", employee[i].joining_date.day,employee[i].joining_date.month,employee[i].joining_date.year);
            flag++;
        }
    }
    if(flag==0)
    {
        printf("wrong input\nData not found\n");
        return 0;
    }
    else
        return 0;
}

//Fuction 3
void update_info()
{
    int search_id,i,j,k,flag,count=0;
    printf("Enter the id which you want update : ");
    scanf("%d",&search_id);
    for(i=0;i<size;i++)
    {
        if(search_id==employee[i].id)
        {
             printf("Enter employee name ",i+1);
        gets(employee[i].name);
        gets(employee[i].name);
        printf("Enter employee salary ",i+1);
        scanf("%f",&employee[i].salary);
        printf("Enter employee mobile number ",i+1);
        scanf("%s",employee[i].mobile_no);
        for(j=0;j<i;j++)
        {
          flag=0;
          for(k=0;employee[i].mobile_no[k];k++)
            {
              if(employee[i].mobile_no[k]==employee[j].mobile_no[k])
                    flag++;

            }
            if(flag==k)
            {
                printf("Data exist\n Enter another mobile number ");
                scanf("%s",&employee[i].mobile_no);
            }
        }
        printf("Enter employee joining date ");
        scanf("%d %d %d",&employee[i].joining_date.day,&employee[i].joining_date.month,&employee[i].joining_date.year);
        count++;

        }
    }
    if (count==0)
    {
        printf("Invalid id\nData not found\n");
    }
}


//fuction 4
double average_salary()
{
    int i;
    double ave=0;
    for(i=0;i<size;i++)
    {
        ave=ave+employee[i].salary;
    }
    ave/=size;
    printf("%f",ave);
    return ave;
}
void add_employee();
void update_info();
double average_salary();
double max_salary();
void join_date();
void search_id();



void join_date()
{
    int day,month,year;
    int i;
    printf("Enter the date: ");
    scanf("%d%d%d",&day,&month,&year);

    printf("The employee who joined this day you given id no. :\n");
    for(i=0;i<size;i++)
    {
        if(year<employee[i].joining_date.year)
        {
            printf("%d\n",employee[i].id);
        }
        if(year==employee[i].joining_date.year)
        {
            if(month< employee[i].joining_date.month)
            {
                printf("%d\n", employee[i].id);
            }
            else if(month==employee[i].joining_date.month)
            {
                if(day<= employee[i].joining_date.day)
                {
                    printf("%d\n", employee[i].id);
                }
            }
        }
    }
}



int main()
{
    int ch;
     do
     {
    ch=manu();
    if(ch==1)
        add_employee();
    else if(ch==2)
         search_ID();
    else if(ch==3)
       update_info();
    else if(ch==4)
        average_salary();
    else if(ch==5)
        join_date();
    else if(ch==-1)
    {
        printf("Exit");
        return 0;
    }
    else
    {
        printf("Invalid input\n Enter your choice correctly");
    }
     }
    while(ch!=-1);

}
