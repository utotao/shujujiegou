#include "stdio.h"
#include "stdlib.h"

typedef struct Link {
    int elem;
    struct Link* next;
} link;

link* insertElem(link* p, int elem, int pos);
link* deleElem(link* p, int pos);
link* updateElem(link* p, int newElem, int pos);
int searchElem(link* p, int elem);
int showLink(link* p);

int main(void)
{
    link* p = (link*)malloc(sizeof(link));
    p->next = NULL;
    int i;
    for (i = 0; i < 5; i++) {
        insertElem(p, i+1, i+1);
    }
    showLink(p);
    for (i = 0; i < 5; i++) {
        updateElem(p, i+2, i+1);
    }
    showLink(p);
    deleElem(p, 1);
    showLink(p);
    searchElem(p, 4);
    return 0;
}

link* insertElem(link* p, int elem, int pos)
{
    link* temp = p; /* temp指向头结点 */
    link* insertNode = (link*)malloc(sizeof(link));
    insertNode->next = NULL;
    int i;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("wrong position insert!\n");
            goto back;
        }
    }
    insertNode->elem = elem;
    insertNode->next = temp->next;
    temp->next = insertNode;
back:
    return p;
}

link* deleElem(link* p, int pos)
{
    link* temp = p; /* temp指向头结点 */
    int i;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("wrong position insert!\n");
            goto back;
        }
    }
    link *deleNode = temp->next;
    if (deleNode == NULL) {
        printf("wrong position!\n");
        goto back;
	}
    temp->next = deleNode->next;
    free(deleNode);
back:
    return p;
}

link* updateElem(link* p, int newElem, int pos)
{
    link* temp = p; /* temp指向头结点 */
    int i;
    for (i = 1; i <= pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("wrong position insert!\n");
            goto back;
        }
    }
    temp->elem = newElem;
back:
    return p;
}

int searchElem(link* p, int elem)
{
    link* temp = p;
    int i = 0;
    while (temp->next) {
        temp = temp->next;
        if (temp->elem == elem) {
            printf("match number %d\n", temp->elem);
            i++;
            goto back;
        }
    }
    printf("======= not find. over! =====\n");
back:
    return i;
}

int showLink(link* p){
    link* temp = p;
    int i = 0;
    while (temp->next) {
        temp = temp->next;
        printf("%d = %d\n", i+1, temp->elem);
        i++;
    }
    printf("======= show over =====\n");
    return i;
}


