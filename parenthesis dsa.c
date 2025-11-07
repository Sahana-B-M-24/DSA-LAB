#include <stdio.h>
#include <string.h>

int pValidation(char str[]) {
    char stack[50];
    int top = -1;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            stack[++top] = str[i];
        } else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (top == -1)
                return 0;

            char last = stack[top--];


            if ((str[i] == ')' && last != '(') ||
                (str[i] == '}' && last != '{') ||
                (str[i] == ']' && last != '[')) {
                return 0;
            }
        }
    }

    return (top == -1);
}

int main() {
    char str[50];

    printf("Enter a sequence of parentheses: ");
    scanf("%s", str);

    if (pValidation(str))
        printf("\nParentheses successfully validated!\n");
    else
        printf("\nParentheses NOT balanced!\n");

    return 0;
}
