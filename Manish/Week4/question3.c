#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 1000

int evalPostfix(char *exp) {
    int stack[MAX];
    int top = -1;

    char *token = strtok(exp, " \t\n");
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack[++top] = atoi(token);
        } else {
            int val2 = stack[top--];
            int val1 = stack[top--];
            switch (token[0]) {
                case '+': stack[++top] = val1 + val2; break;
                case '-': stack[++top] = val1 - val2; break;
                case '*': stack[++top] = val1 * val2; break;
                case '/': stack[++top] = val1 / val2; break;
            }
        }
        token = strtok(NULL, " \t\n");
    }
    return stack[top];
}

int main() {
    int t;
    if (scanf("%d\n", &t) != 1) return 0;
    char line[MAX];
    while (t--) {
        if (fgets(line, sizeof(line), stdin) != NULL) {
            if (strlen(line) <= 1) { // handle potential empty lines
                t++;
                continue;
            }
            printf("%d\n", evalPostfix(line));
        }
    }
    return 0;
}
