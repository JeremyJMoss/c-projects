#include <stdio.h>
#include <stdbool.h>

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

bool stringCompare(char string1[], char string2[]){
    if (stringLen(string1) != stringLen(string2)){
        return false;
    }
    int index = 0;
    while (string1[index] != '\0' || string2[index] != '\0'){
        if (string1[index] != string2[index]){
            return false;
        }
        index++;
    }
    return true;
}

int main(){
    char word[] = "hello ";
    char word2[] = "world";
    char word3[] = "hello ";
    char result[stringLen(word) + stringLen(word2) + 1];
    
    printf("%d\n", stringLen(word));
    
    stringConcat(word, word2, result);

    printf("Concatenated string: %s\n", result);

    bool result1 = stringCompare(word, word2);

    bool result2 = stringCompare(word, word3);

    printf("%d\n%d\n", result1, result2);

    return 0;
}