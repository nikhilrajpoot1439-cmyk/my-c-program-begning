//https://www.alpharithms.com/s3/assets/img/ascii-chart/ascii-table-alpharithms-scaled-1024x610.jpg




#include<stdio.h>

int main(){
    // 97 to 122
    char ch;
    printf("Enter character\n");
    scanf("%c" , &ch);
    // printf("The character is %c\n" , ch); 
if(ch >= 97 && ch <= 120){
    printf("The character is lowercase");
}
else{
    printf("The character is not lowercase");
}
return 0;
}