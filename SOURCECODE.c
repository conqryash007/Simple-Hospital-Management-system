/*

YASH GUPTA B420066

Under the guidance of
Prof. Bharati Mishra

*/

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

//CREATED A STRUCTURE NAMED Patient_Record
struct Patient_Record
{
    //member of structure
    char name[30];
    char disease[30];
    int cabin_no;
    long long phone_no;
    int age;
}
x[100];

//Global declaration
int n;
int i;
int j=0;
int a=0;
int sum=0;
int g;
int flag;
int num;

//delcaration of function
void extract();
void Edit_file();
void add();
void view();
void search();
void edit();
void del();
void show();

int main()
{
    extract();//calling of function read.
    //local variable
    int choice;
    int i;
    int q;

     printf("* ************************** *\n");
    printf("* *------------------------* *\n");
    printf("* *________________________* *\n");
    printf("* *    CODING CONQUERORS   * *\n");
    printf("* *________________________* *\n");
    printf("* *------------------------* *\n");

    printf("\n\n");

    printf("******************************\n");
    printf("*                            *\n");
    printf("* ************************** *\n");
    printf("* *------------------------* *\n");
    printf("* *________________________* *\n");
    printf("* *                        * *\n");
    printf("* *---    YASH GUPTA    ---* *\n");
    printf("* *                        * *\n");
    printf("* ************************** *\n");
    printf("* ************************** *\n");    
    printf("*                            *\n");
    printf("******************************\n");

    printf("\n\n");

    printf("*******************************************\n");
    printf("*******************************************\n");
    printf("*                                         *\n");
    printf("*    HOSPITAL MANAGEMENT SYSTEM           *\n");
    printf("*                                         *\n");
    printf("*                                         *\n");
    printf("*******************************************\n");
    printf("*******************************************\n\n\n");


    //local variable
    int k;
    int space;

    //loop for printing pattern
    for (i = 1; i <= 5; ++i)
    {
        k=0;
        for (space = 1; space <= 10 - i; ++space) {
        printf("  ");
    }
    while (k != 2 * i - 1)
    {
         printf("* ");
         ++k;
    }

        printf(" \n");
    }

    while(choice != 6)//Loop condition until choice entered is not equal to 6
    {

        printf("----------------------------------------------\n");
        printf("|   \t**ENTER THE COMMAND**                |\n");
        printf("|                                            |\n");
        printf("|   \t1. ADD NEW PATIENT DETAILS           |\n");
        printf("|   \t2. VIEW PATIENT INFORMATION          |\n");
        printf("|   \t3. SEARCH PATIENT                    |\n");
        printf("|   \t4. EDIT INFORMATION                  |\n");
        printf("|   \t5. DELETE INFORMATION                |\n");
        printf("|   \t6. EXIT                              |\n");
        printf("|                                            |\n");
        printf("----------------------------------------------\n\n");
        printf("   \tCOMMAND SELECTED : ");

        scanf("%d",&choice);//choice for option

        fflush(stdin);// used to clear the buffer or stream
        switch(choice)
        {
        case 1 : system("cls"); //Used for clearing the screen
                 add();//function call
                 break;

        case 2 : system("cls"); //Used for clearing the screen
                 view();//function call
                 break;

        case 3 : system("cls"); //Used for clearing the screen
                 search();//function call
                 break;

        case 4 : system("cls"); //Used for clearing the screen
                 edit();//function call
                 break;

        case 5 : system("cls"); //Used for clearing the screen
                 del();//function call
                 break;

        case 6 : Edit_file();//function call
                 break;

        default : system("cls"); //Used for clearing the screen
                printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
    return 0;
}//main

//Definition
/*====FUNCTION - 1---> extract()=====*/

void extract()
{
    //the file pointer points to the file
    //fopen function is used to open a file
    FILE *ptr = fopen("PATIENTFILE.txt","r");//the file is opened in read mode
    if(ptr == NULL)
    {
        //If the file does not exist
        //it will create file
        //We can use it in next execution of the program
        ptr = fopen("PATIENTFILE.txt","w");
        fclose(ptr);//it is used to close the opened file
        printf("CAUTION!!\nNO FILE FOUND\nCREATING A FILE PATIENTFILE.txt\nExiting...\n\n\n");
        return ;
    }

    //fread function is used to read a file
    //the fread functions returns the number of elements read successfully
    //this number is stored in num
    num = fread(&x, sizeof(struct Patient_Record),100, ptr);
    fclose(ptr);
}

//Definition
/*====FUNCTION - 2---> Edit_file()=====*/

void Edit_file()
{
    //the file pointer points to the file
    //fopen function is used to open a file
    FILE *ptr = fopen("PATIENTFILE.txt","w");//the file is opened in write mode
    if(ptr == NULL)
    {
        printf("Error");
        exit(1);
    }
    //the fwrite function is used to edit the file
    fwrite(x, sizeof(struct Patient_Record),num, ptr);

    fclose(ptr);//it is used to close the opened file
    return;
}

//Definition
/*====FUNCTION - 3---> add() =====*/

//Function to add the details of the patient
void add()
{
    printf("\n\n");
    printf("Data already stored on system : %d\n\n",num);//details of patient already present
    printf("Enter the number of patient details to be entered  : ");//no. of details to be entered
    scanf("%d",&n);//input
    sum = n + num ;

    for(i = num , j = 0 ; i<sum ; i++)//input details of patient
    {
        printf("\n");

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's Name : ");
        gets(x[i].name);//input name

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's disease : ");
        gets(x[i].disease);//input disease

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's the age : ");
        scanf("%d",&x[i].age);//input age

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's cabin no : ");
        scanf("%d",&x[i].cabin_no);//input cabin_no

        fflush(stdin);// used to clear the buffer or stream
        printf("Enter patient's phone number : ");
        scanf("%lld",&x[i].phone_no);//input phone_no

        fflush(stdin);// used to clear the buffer or stream
        printf("\n");
        j++;
        a++;
        num++;
    }
}

//Definition
/*====FUNCTION - 4---> view() =====*/

//function to view the details of the patients
void view()
{
    for(i=0; i<num; i++)//to show all the details on screen of the patients
    {
        printf("\n");
        printf("Serial Number : %d\n",i);
        printf("Name : ");
        puts(x[i].name);
        printf("Disease : ");
        puts(x[i].disease);
        printf("Cabin no : %d\n",x[i].cabin_no);
        printf("Phone number : 0%lld\n",x[i].phone_no);
        printf("Age : %d",x[i].age);
        printf("\n\n");
    }
}

//Definition
/*====FUNCTION - 5---> edit() =====*/

void edit()// function for editing patient detail
{
    int q,p;
    fflush(stdin);// used to clear the buffer or stream

    printf("Do you want to edit details of patient?\n");
    printf("SELECT A OPTION\n\n");
    printf("1.Name\n");
    printf("2.Disease\n");
    printf("3.Age\n");
    printf("4.Cabin\n");
    printf("5.Phone no.\n\n");
    printf("OPTION SELECT : ");

    scanf("%d",&q);//option select

    if(q<=5)
    {
        printf("Enter the SERIAL NO. of that patient (0 - %d) : ",num-1);
        scanf("%d",&p);//serial number

        // for matching patient id and then making changes
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new name : ");//to modify the name
                gets(x[p].name);

            }
            else if(q==2)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Disease : ");//to modify the Disease
                gets(x[p].disease);
            }
            else if(q==3)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Age : ");//to modify the Age
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Cabin no : ");//to modify the Cabin no
                scanf("%d",&x[p].cabin_no);
            }

            else if(q==5)
            {
                fflush(stdin);// used to clear the buffer or stream
                printf("Enter the new Phone no : ");//to modify the Phone no
                scanf("%lld",&x[p].phone_no);
            }
        }
        else//error message on invalid entry
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else//error message on invalid entry
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}

//Definition
/*====FUNCTION - 6---> search() =====*/

void search()
{
    int s,h,f;
    char u[100];// temp variable for matching
    printf("By what title you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Cabin no.\n5.Phone no.\n6.Age\n\n");
    printf("OPTION SELECT : ");
    scanf("%d",&h);
    if(h==1)// search by serial no
    {
        printf("Enter Serial number of the patient : ");
        scanf("%d",&s);
        if(s<num)// printing details
        {
            printf("\n");
            printf("Serial Number : %d\n",s);
            printf("Name : ");
            puts(x[s].name);
            printf("Disease : ");
            puts(x[s].disease);
            printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[s].cabin_no,x[s].phone_no,x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");//error message on invalid entry
    }
    else if(h==2)//  search by name
    {
        int f=1;
        fflush(stdin);// used to clear the buffer or stream
        printf("Enter your name : ");
        gets(u);
        fflush(stdin);// used to clear the buffer or stream
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)// compare and find name and print details
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                f=0;

            }
        }
        if(f==1)
            printf("\nNot Found\n");//error message on invalid entry



    }
    else if(h==3)// search by disease name
    {
        int f=1;
        fflush(stdin);// used to clear the buffer or stream
        printf("Enter Disease : ");
        gets(u);
        fflush(stdin);// used to clear the buffer or stream
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                f=0;
            }


        }
        if(f==1)
            printf("\nNot Found\n");//error message on invalid entry


    }
    else if(h==4)
    {
        int o=1;
        int f=1;
        printf("Enter Cabin number : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].cabin_no)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                o=0;
            }

        }
        if(o==1)
            printf("Not Found\n\n");//error message on invalid entry

    }
    else if(h==5)
    {
        int o = 1;
        long long f=1;
        printf("Enter Phone number : ");
        scanf("%lld",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].phone_no)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                o=0;
            }

        }
        if(o==1)
            printf("Not Found");//error message on invalid entry
    }
    else if(h==6)
    {
        int o = 1;
        int f=1;
        printf("Enter Age : ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("Serial Number : %d\n",g);
                printf("Name : ");
                puts(x[g].name);
                printf("Disease : ");
                puts(x[g].disease);
                printf("Cabin no : %d\nPhone number : 0%lld\nAge : %d",x[g].cabin_no,x[g].phone_no,x[g].age);
                printf("\n\n");
                o=0;
            }

        }
        if(o==1)
            printf("Not Found\n\n");//error message on invalid entry

    }
    else
        printf("\n\nInvalid input\n\n");//error message on invalid entry


}

//Definition
/*====FUNCTION - 7---> del() =====*/

// for deleting record of patient
void del()
{
    int f,h;
    printf("Enter the SERIAL NUMBER of the patient that you want to delete : ");
    scanf("%d",&f);
    if(f<num)// to remove the whole record
    {       //it copies the data of (n+1)th storaged values to nth stored values

        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease");
        printf("\n4.Remove age\n5.Remove Cabin\n6.Remove phone number\n\n OPTION SELECT : ");

        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].cabin_no=x[f+1].cabin_no;
                x[f].phone_no=x[f+1].phone_no;
                f++;
            }
            num--;
        }
        else if(h==2)// to remove name and in place of it display DELETED.
        {
            strcpy(x[f].name,"DELETED");

        }
        else if(h==3)// to remove disease and in place of it display DELETED.
        {
            strcpy(x[f].disease,"DELETED");
        }
        else if(h==4)// to remove age and in place of it display 0.
        {
            x[f].age=0;
        }
        else if(h==5)// to remove cabin and in place of it display 0.
        {
            x[f].cabin_no=0;
        }
        else if(h==6)// to remove phone no and in place of it display 0.
        {
            x[f].phone_no=0;
        }

    }
    else
        printf("\n\nInvalid Serial number\n");

}
