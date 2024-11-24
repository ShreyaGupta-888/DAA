//Convert uppercase string to lowercase using for loop.

#include <stdio.h>

void convertToLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
    
        if (str[i] >= 'A' && str[i] <= 'Z') {
            
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char str[100];

    
    printf("Enter a string (uppercase): ");
    fgets(str, sizeof(str), stdin); 
    
    convertToLowercase(str);

    
    printf("String in lowercase: %s\n", str);

    return 0;
}