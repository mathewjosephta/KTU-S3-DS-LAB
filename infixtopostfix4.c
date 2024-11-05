/* Exp4 : Write a program to convert infix expression to postfix expression using Stack */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to return precedence of operators
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Function to return associativity of operators
char associativity(char c) {
    if (c == '^')  // Right-associative
        return 'R';
    return 'L';  // Left-associative
}

// The main function to convert infix expression to postfix expression
void infixToPostfix(char s[]) {
    char result[1000];
    int resultIndex = 0;
    int len = strlen(s);
    char stack[1000];
    int stackIndex = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // If the scanned character is an operand (letter or digit), add it to the output string.
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result[resultIndex++] = c;
            result[resultIndex++] = ' ';  // Add a space between operands (optional for clarity)
        }
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (c == '(') {
            stack[++stackIndex] = c;
        }
        // If the scanned character is an ‘)’, pop and add to the output string from the stack
        // until an ‘(‘ is encountered.
        else if (c == ')') {
            while (stackIndex >= 0 && stack[stackIndex] != '(') {
                result[resultIndex++] = stack[stackIndex--];
                result[resultIndex++] = ' ';  // Optional: Space for clarity
            }
            stackIndex--; // Pop '('
        }
        // If an operator is scanned
        else {
            // Pop operators from the stack with higher or equal precedence (taking associativity into account)
            while (stackIndex >= 0 && (prec(s[i]) < prec(stack[stackIndex]) ||
                                       (prec(s[i]) == prec(stack[stackIndex]) && associativity(s[i]) == 'L'))) {
                result[resultIndex++] = stack[stackIndex--];
                result[resultIndex++] = ' ';  // Optional: Space for clarity
            }
            stack[++stackIndex] = c;
        }
    }

    // Pop all the remaining operators from the stack
    while (stackIndex >= 0) {
        result[resultIndex++] = stack[stackIndex--];
        result[resultIndex++] = ' ';  // Optional: Space for clarity
    }

    result[resultIndex] = '\0';  // Null-terminate the result string
    printf("Postfix Expression: %s\n", result);
}

// Driver code
int main() {
    char exp[1000];

    // Input from the user
    printf("Enter the infix expression: ");
    scanf("%s", exp);  // Use %s to read a single word expression

    // Function call
    infixToPostfix(exp);

    return 0;
}

//SAMPLE OUTPUT
/*
Enter the infix expression: a+b*(c^d-e)^(f+g*h)-i
Postfix Expression: a b c d ^ e - f g h * + ^ * + i -
*/

