#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack 
{
    int top;
    char items[MAX_SIZE];
};
void push(struct Stack *s, char item) 
{
    if (s->top == MAX_SIZE - 1) 
	{
        printf("Stack is full\n");
    } else
	{
        s->top++;
        s->items[s->top] = item;
    }
}
char pop(struct Stack *s) 
{
    if (s->top == -1) 
	{
        printf("Stack is empty\n");
        return '\0';
    } else {
        char item = s->items[s->top];
        s->top--;
        return item;
    }
}
int is_operator(char c) 
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char op) 
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    s.top = -1;
    int i = 0, j = 0;
    while (infix[i] != '\0') 
	{
        if(infix[i])
		{
            postfix[j++] = infix[i++];
        } else if (infix[i] == '(')
		{
            push(&s, infix[i++]);
        } else if (infix[i] == ')') 
		{
            while (s.top != -1 && s.items[s.top] != '(') {
                postfix[j++] = pop(&s);
            }
            if (s.top == -1) 
			{
                printf("Invalid expression\n");
                exit(1);
            }
            pop(&s);
            i++;
        } else if (is_operator(infix[i])) 
		{
            while (s.top != -1 && precedence(s.items[s.top]) >= precedence(infix[i])) 
			{
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        } else 
		{
            printf("Invalid character in expression\n");
            exit(1);
        }
    }
    while (s.top != -1) 
	{
        if (s.items[s.top] == '(') 
		{
            printf("Invalid expression\n");
            exit(1);
        }
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}
int main() 
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}