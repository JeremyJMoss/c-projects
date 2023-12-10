#include <stdio.h>

int stringLen(char string[]){
    int count = 0;

    while(string[count] != '\0'){
        count++;
    }
    return count;
}

void stringConcat(char string1[], char string2[], char result[]){
    int index = 0;
    for (int i = 0; i < stringLen(string1); ++i){
        result[index] = string1[i];
        index++;
    }
    for (int i = 0; i < stringLen(string2); ++i){
        result[index] = string2[i];
        index++;
    }
    result[index] = '\0';
}

int main(){
    char word[] = "hello ";
    char word2[] = "world";
    char result[stringLen(word) + stringLen(word2) + 1];
    
    printf("%d\n", stringLen(word));
    
    stringConcat(word, word2, result);

    printf("Concatenated string: %s\n", result);
    return 0;
}