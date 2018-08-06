#include <stdio.h>
#include <string.h>
#include <math.h>

double stringtonumber(char* number){
    double num = 0;
    int pointposition = strlen(number);
    for(int i = 0; i < strlen(number); i++)
        if(number[i] == '.' || number[i] == ','){
            pointposition = i;
            break;
        }
    for(int i = 0; i < strlen(number); i++){
        if(number[i] < '0' || number[i] > '9')
            continue;
        if(i < pointposition)
            num += (number[i] - '0') * pow(10, pointposition - (i + 1));
        else if(i > pointposition)
            num += (number[i] - '0') * pow(10, pointposition - i);
    }
    if(number[0] == '-')
        num *= (double) -1;
    return num;
}

int main(){
    char number[100];
    printf("type some number: ");
    scanf("%[^\n]c", number);
    getchar(); //trash \n
    double n = stringtonumber(number);
    printf("%lf\n", n);
    return 0;
}