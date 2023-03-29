//
//  main.c
//  Homework-1
//
//  Created by İbrahim Bayram on 29.03.2023.
//

#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main() {
    setlocale(LC_ALL, "Turkish");
    int a, b, c, d, choice;//Choice is the user's input after menu appears.
    double result;
    char control = '\0'; //Variable to check does user want to calculte again.
    
    //We re using do-while loop to run this codes again when user wants.
    do {
        printf("Enter you integer numbers between 0 abd 100: \n");
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        if (a < 0 || a > 100|| b < 0 || b > 100 || c < 0 || c > 100 || d < 0 || d > 100) {
            printf("Your numbers must be between 0 and 100.Please try again.\n");
            continue;
        }
        printf("Calculations:\n");
        printf("1) result = (2 + b) . a!/c + d \n");
        printf("2) result = b . exp c / a^d \n");
        printf("3) result = log b + ln d . c^3 / a^-2 \n");
        printf("4) result = sin(a + b) .cos(c) / tan(d) \n");
        printf("5) EXIT \n");
        printf("Choose a calculation from this menu\n");
        
        scanf("%d", &choice);
        
        switch (choice){
            case 1:
                if (c == 0) {
                    printf("The Error occured: Division by zero.Please try again");
                    continue;
                }
                result = (2.0 + b) * tgamma(a + 1) / c + d;
                break;
            case 2:
                if (a == 0) {
                    printf("The Error occured: Division by zero.Please try again");
                    continue;
                }
                result = b * exp(c) / pow(a, d);
                break;
            case 3:
                if (a == 0) {
                    printf("The Error occured: Division by zero.Please try again");
                    continue;
                }
                result = log10(b) + log(d) * pow(c, 3) / pow(a, -2);
                break;
            case 4:
                result = sin(a + b) * cos(c) / tan(d);
                break;
            case 5:
                printf("Program is finishing \n");
                return 0;
            default:
                printf("Invalid choice.Please try again.\n");
                continue;
        }
        printf("Result = %.3f \n", result);
        printf("Do you want to perform another calculation ? (Y/N):");
        scanf(" %c", &control);
    
    }while (control == 'y' || control == 'Y');
    //We are asking does the user want to calculate with another number.
    printf("Program terminated");
    return 0;
}

