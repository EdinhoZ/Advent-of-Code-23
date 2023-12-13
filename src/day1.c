#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 300

int main(){
    FILE *input = fopen("../inputs/day1.txt", "r");
    char str[MAX_SIZE];
    int sum = 0;

    if(input == NULL){
        perror("Input file does not exist");
        return(-1);
    }

    while(fgets(str, sizeof(str), input)){
        int length = strlen(str);
        int first = -1, last = -1;
        for(int i = 0; i < length; i++){
            if(isdigit(str[i])){
                if(first == -1){
                    first = str[i] - '0';
                    last = str[i] - '0';
                }else{
                    last = str[i] - '0';
                }
            }
        }
        sum += (first * 10 + last);
    }

    printf("%d\n", sum);
    fclose(input);

    return 0;
}