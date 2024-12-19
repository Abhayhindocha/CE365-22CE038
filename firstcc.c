#include<stdio.h>
#include<conio.h>

int main()
{
    char str[20];
    scanf("%s",str);

    int i=0;
    while(str[i]=='a'){
        i++;
    }
    if(str[i]=='b' && str[i+1]=='b' && str[i+2]=='\0'){
        printf("Valid string");
    }
    else{
        printf("Invalid string");
    }
}
