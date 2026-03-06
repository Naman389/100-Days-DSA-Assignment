#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    if(top == NULL)
    {
        printf("Stack Underflow");
        exit(1);
    }

    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char postfix[])
{
    int i = 0;

    while(postfix[i] != '\0')
    {
        if(postfix[i] == ' ' || postfix[i] == '\n')
        {
            i++;
            continue;
        }

        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            int b = pop();
            int a = pop();

            switch(postfix[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
        i++;
    }

    return pop();
}

int main()
{
    char postfix[100];

    fgets(postfix, sizeof(postfix), stdin);

    printf("%d", evaluate(postfix));

    return 0;
}