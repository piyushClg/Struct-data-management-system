#include <stdio.h>
struct student {
    int rollNo;
   char name[50];
   int marks;
};

// function prototype
void create(struct student s[100], int n);
void display(struct student s[100], int n);
int append(struct student s[100], int n);
void modify(struct student s[100], int n);
void search(struct student s[100], int n, int ele);
void sort(struct student s[100], int n);
int main() {
    
    int i, n, ele, op;
    struct student s[100];
    
    do {
        printf("\n 1.create \n 2.display \n 3.Append \n 4.Modify \n 5.Search \n 6.Sort \n 7.exit");
        printf("\n Enter your option: ");
        scanf("%d", &op);
        
        switch(op) {
            case 1:
                printf("Enter total of students: ");
                scanf("%d",&n);
                create(s, n);
                break;
            case 2:
                display(s, n);
                break;
            case 3:
                n = append(s, n);
                break;
            case 4:
                //modify
                modify(s, n);
                break;
            case 5:
                //search
                printf("\nEnter the roll number you want to search: ");
                scanf("%d", &ele);
                search(s, n, ele);
                break;
            case 6:
                //sort
                sort(s, n);
                break;
        }
    }while(op != 7);
            
        
   return 0;
}

void display(struct student s[100], int n) {
    int i;
    printf("Displaying Information:\n");
    printf("Roll Number\tName\t\tMarks");
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t\t%s\t\t%d", s[i].rollNo, s[i].name, s[i].marks);
    
    }
   
   
}

void create(struct student s[100], int n) {
    int i;
    for(i = 0; i < n; i++)
    {
        printf("\nEnter information of student %d:\n",i+1);
        printf("Enter name: ");
        scanf("%s", s[i].name);
        
        printf("Enter roll number: ");
        scanf("%d", &s[i].rollNo);
        
        printf("Enter marks: ");
        scanf("%d", &s[i].marks);
    }
}

int append(struct student s[100], int n) {
    int i;
    i = n;
    printf("\nEnter information of student %d:\n",i+1);
    printf("Enter name: ");
    scanf("%s", s[i].name);
        
    printf("Enter roll number: ");
    scanf("%d", &s[i].rollNo);
        
    printf("Enter marks: ");
    scanf("%d", &s[i].marks);
    
    n++;
    return n;
}

void search(struct student s[100], int n, int ele) {
    int i, j = 0;
    for(i = 0; i < n; i++)
        if (s[i].rollNo == ele) {
            printf("Roll Number\tName\t\tMarks");
            printf("\n%d\t\t%s\t\t%d", s[i].rollNo, s[i].name, s[i].marks);
            j++;
        }
    
    if (j == 0)
        printf("\nSorry Roll number not found :(");
}

void modify(struct student s[100], int n) {
    int i, j = 0, ele;
    display(s, n);
    printf("\nEnter Roll number of the record you wanna modify: ");
    scanf("%d", &ele);
    for(i = 0; i < n; i++)
        if (s[i].rollNo == ele) {
            printf("Roll Number\tName\t\tMarks");
            printf("\n%d\t\t%s\t\t%d", s[i].rollNo, s[i].name, s[i].marks);
            printf("\nEnter new Roll number: ");
            scanf("%d", &s[i].rollNo);
            printf("\nEnter new Name: ");
            scanf("%s", &s[i].name);
            printf("\nEnter new marks: ");
            scanf("%d", &s[i].marks);
            printf("\nModified records are: \n");
            display(s, n);
            j++;
        }
    
    if (j == 0)
        printf("\nSorry Roll number not found :(");
    
}

void sort(struct student s[100], int n)
    {
  int i,j;
  struct student temp;
  printf("\nSorting by Roll number:\n");
  for(i=1;i<n;i++)
  { for(j=0;j<n-i;j++)
    {
     if(s[j].rollNo>s[j+1].rollNo)
       {
        temp=s[j];
        s[j]=s[j+1];
        s[j+1]=temp;
       }
    }

   }
   display(s, n);
    }

