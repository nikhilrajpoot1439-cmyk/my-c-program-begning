/*

Array and Strings .....> It holds Similar data(int, float, char)
Structure can holds ......> Dissimilar Data 


A C structure can be create as follow

struct employee
{
int code;
float salary;
char name[20];
};  >>>> Semicolon(;) is important


We can use these user defined data types as follow

struct employee e1;
strcpy(e1.name, "Nikhil");
e1. code = 101;
e1.salary = 2445555;

So a structure in C is a collection of Variables of different types under a single name 

.....>>>>>>>>>########### Why Use Structure >>>>>>>.....?

We can create the data types in the employee structure seprately but when the number of properties in a structure increases , it becomes difficult for us to create data variables without structures. >>>>> IN a NUTSHELLS

>a. Structure keep the data organized 
>b. Structure make data management easy for the programmer




....>>>>>>>>>>>>>>>>>>>########## ARRAY OF STRUCTURE :->>>>>>>>>>>>>>..........
Just like an array of integer, character , float ...we can create a array of Structure.

................SYNTAX.............
struct employee facebook[100];
facebook[o].code = 100;
facebook[1].code = 101; ...... and so on


...>>>>>>>>>>>>>>>>>>>########## INITIALIZING STRUCTURE :->>>>>>>>>>>>>>.........
Structures can also be initialized as follow :-

................SYNTAX.............
struct employee Nikhil = {"Nikhil", 76, 7655.876};
struct employee Tula = {"Tula", 65, 765544.98};

...>>>>>>>>>>>>>>>>>>>########## STRUCTURE IN MEMORY:->>>>>>>>>>>>>>.........
Structure are stored in contigious memory location . For the structure"e1" of type struct employee , memory layout looks like :
>>>>>>>>>>>>>>>>>>>>>>>>code : - address is 78810
>>>>>>>>>>>>>>>>>>>>>>>>NAME: - address is 78814
>>>>>>>>>>>>>>>>>>>>>>>>salary : - address is 78818


...>>>>>>>>>>>>>>>>>>>########## POINTER TO  STRUCTURE:->>>>>>>>>>>>>>.........

     A structure to pointer can be created as follow :
     ................SYNTAX.............
     struct employee *ptr;
     ptr = &e1;

     printf("%d", *(ptr).code)

*/