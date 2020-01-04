#include "stdio.h"
#include "stdlib.h"

#define Elem_Type char

Elem_Type pop(Elem_Type* stack, int* top)
{
    Elem_Type temp;
    temp = stack[*top];
    (*top)--;
    return temp;
}

int push(Elem_Type* stack, Elem_Type elem, int* top)
{
    (*top)++;
    stack[*top] = elem;
    return *top;

}

int disPlayStack(Elem_Type* stack, int* top)
{
    for (int i = *top; i >=0; i--)
        printf("i = %d\n",pop(stack, top));
    return *top;
}
int isMatch(char* str);

int main(int argc, char** argv)
{
    int top = -1;
    Elem_Type* stack = (Elem_Type *)malloc(100*sizeof(Elem_Type));
    for (int i = 0; i < 5; i++) {
        push(stack, i, &top);
    }
    disPlayStack(stack, &top);
    printf("top = %d\n", top);
    char *str = (char *)malloc(100 * sizeof(char));
    printf("input a string :");
    scanf("%s", str);
    printf("str = %s\n", str);
    if (!isMatch(str)) {
        printf("match sucess!\n");
    } else {
        printf("match failed!\n");
    }
    
    return 0;
}

int isMatchSignal(Elem_Type pop_elem,Elem_Type input_elem)
{
    if ((pop_elem == '(' && input_elem == ')') || (pop_elem == '[' && input_elem == ']') ||
        (pop_elem == '{' && input_elem == '}')) {
        goto ismatch;
    } else {
        goto notmatch;
    }
notmatch:
    return -1;
ismatch:
    return 0;
}

int isMatch(char* str)
{
    Elem_Type pop_elem;
    Elem_Type* stack = (Elem_Type *)malloc(100*sizeof(Elem_Type));
    int top = -1;
    
    if (str == NULL) {
        printf("str is null!\n");
        goto error;
    }
    while (*str != '\0') {
        switch (*str) {
            case '(':
            case '[':
            case '{':
                /* left -> push */
                push(stack, *str, &top);
                break;
            case ')':
            case ']':
            case '}':
                /* match top elem */
                if (top == -1)
                    /* stack is empty -> goto error */ {
                    goto error;
                }
                pop_elem = pop(stack, &top);
                if (!isMatchSignal(pop_elem, *str)) {
                    str++;
                    continue;
                } else {
                    goto error;
                }
                break;
        }
        str++;
    }
    if (top == -1)/*statck is empty*/ {
        goto sucess;
    }

error:
    return -1;
sucess:
    return 0;
}



