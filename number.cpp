#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void decimalToOther(int decimal);
void binaryToDecimal(char binary[]);
void octalToDecimal(char octal[]);
void hexadecimalToDecimal(char hex[]);

int main() {
    int choice, decimal;
    char input[100];

    while (1) {
        printf("\n=== Number Conversion System ===\n");
        printf("1. Decimal to Binary, Octal, Hexadecimal\n");
        printf("2. Binary to Decimal\n");
        printf("3. Octal to Decimal\n");
        printf("4. Hexadecimal to Decimal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a Decimal number: ");
                scanf("%d", &decimal);
                decimalToOther(decimal);
                break;

            case 2:
                printf("Enter a Binary number: ");
                scanf("%s", input);
                binaryToDecimal(input);
                break;

            case 3:
                printf("Enter an Octal number: ");
                scanf("%s", input);
                octalToDecimal(input);
                break;

            case 4:
                printf("Enter a Hexadecimal number: ");
                scanf("%s", input);
                hexadecimalToDecimal(input);
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to convert Decimal to Binary, Octal, Hexadecimal
void decimalToOther(int decimal) {
    printf("Binary: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (decimal >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");

    printf("Octal: %o\n", decimal);
    printf("Hexadecimal: %X\n", decimal);
}

// Function to convert Binary to Decimal
void binaryToDecimal(char binary[]) {
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++) {
        if (binary[i] == '1')
            decimal = (decimal << 1) | 1;
        else if (binary[i] == '0')
            decimal = decimal << 1;
        else {
            printf("Invalid binary number.\n");
            return;
        }
    }
    printf("Decimal: %d\n", decimal);
}

// Function to convert Octal to Decimal
void octalToDecimal(char octal[]) {
    int decimal = 0, i = 0;
    while (octal[i] != '\0') {
        if (octal[i] >= '0' && octal[i] <= '7') {
            decimal = decimal * 8 + (octal[i] - '0');
            i++;
        } else {
            printf("Invalid octal number.\n");
            return;
        }
    }
    printf("Decimal: %d\n", decimal);
}

// Function to convert Hexadecimal to Decimal
void hexadecimalToDecimal(char hex[]) {
    int decimal = 0, i = 0;
    while (hex[i] != '\0') {
        if (hex[i] >= '0' && hex[i] <= '9')
            decimal = decimal * 16 + (hex[i] - '0');
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            decimal = decimal * 16 + (hex[i] - 'A' + 10);
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            decimal = decimal * 16 + (hex[i] - 'a' + 10);
        else {
            printf("Invalid hexadecimal number.\n");
            return;
        }
        i++;
    }
    printf("Decimal: %d\n", decimal);
}


