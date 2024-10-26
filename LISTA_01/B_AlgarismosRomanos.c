#include <stdio.h>
#include <string.h>

void convertToRoman(int num, char *roman) {
    struct {
        int value;
        const char *symbol;
    } romanNumerals[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };
    
    int i = 0;
    roman[0] = '\0'; // Inicializa a string vazia
    while (num > 0) {
        if (num >= romanNumerals[i].value) {
            strcat(roman, romanNumerals[i].symbol);
            num -= romanNumerals[i].value;
        } else {
            i++;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int values[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    
    for (int i = 0; i < n; i++) {
        char roman[20];
        convertToRoman(values[i], roman);
        printf("%s\n", roman);
    }

    return 0;
}
