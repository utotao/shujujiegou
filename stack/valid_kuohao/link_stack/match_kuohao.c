#include "stdio.h"
#include "stdlib.h"

#define Elem_Type char

typedef struct node {
    Elem_Type elem;
    struct node* next;
} stack_node;

typedef struct link{
    stack_node* head;
    int length;
} link_stack;

int pop(link_stack* s, Elem_Type *pop_elem);
int push(link_stack* s, Elem_Type elem);
int isEmpty(link_stack* s);
int isMatch(char* str);

int main(int argc, char** argv)
{
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

int push(link_stack* s, Elem_Type elem){
    stack_node* temp = (stack_node *)malloc(sizeof(stack_node));
    if (temp == NULL) {
        printf("malloc push falied!\n");
        return -1;
    }
    temp->next = s->head;
    temp->elem = elem;
    s->head = temp;
    s->length++;
    
    return 0;
}

int pop(link_stack* s, Elem_Type *pop_elem)
{
    if (s->length == 0) {
        printf("statck is empty!\n");
        return -1;
    }
    stack_node* temp = s->head;
    *pop_elem = temp->elem;
    s->head = temp->next;
    free(temp);
    s->length--;
    return 0;
}

int isEmpty(link_stack* s)
{
    if (s->length == 0) {
        return 0;
    } else {
        return -1;
    }
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

int isMatch(char* str) {
    Elem_Type pop_elem;
    link_stack* s = (link_stack *)malloc(sizeof(link_stack));
    s->head = NULL;
    s->length = 0;
    
    if (str == NULL) {
        printf("str is null!\n");
        goto error;
    }
    while (*str != '\0') {
        printf("*str = %c ", *str);
        switch (*str) {
            case '(':
            case '[':
            case '{':
                /* left -> push */
            printf("push\n");
                push(s, *str);
                break;
            case ')':
            case ']':
            case '}':
                /* match top elem */
                if (!isEmpty(s))
                    /* stack is empty -> goto error */ {
                    goto error;
                }
                printf("pop\n");
                pop(s, &pop_elem);
                if (!isMatchSignal(pop_elem,*str)) {
                    printf("match this!\n");
                    str++;
                    continue;
                } else {
                    goto error;
                }
                break;
        }
        str++;
    }
    if (!isEmpty(s))/*statck is empty*/ {
        goto sucess;
    }

error:
    return -1;
sucess:
    return 0;
}


