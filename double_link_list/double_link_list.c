
#include "stdio.h"
#include "stdlib.h"

typedef struct Link {
    struct Link* prior;
    int elem;
    struct Link* next;
} link;

link* insertElem(link* p, int elem, int pos);
link* deleElem(link* p, int pos);
link* updateElem(link* p, int newElem, int pos);
int searchElem(link* p, int elem);
int showLink(link* p);

int main(int argc, char** argv)
{
    link* p = (link*)malloc(sizeof(link));
    p->next = NULL;
    p->prior = NULL;
    for (int i = 0; i < 5; i++) {
        insertElem(p, i, i+1);
    }
    insertElem(p, 100, 2);
    showLink(p);
    deleElem(p, 2);
    showLink(p);
    updateElem(p, 20, 4);
    showLink(p);
    searchElem(p, 20);
    return 0;
}

/* <br>
 * 昨夜西风凋碧树，独上高楼，望尽天涯路。
 * 欲寄彩笺兼尺素，山长水阔知何处？
 * </br>
 *  ---------------------------------------------------------------------
 * |        _______________    _______________    _______________        |
 * |       |     |    |    |<-|     |    |    |<-|     |    |    |       |
 * | NULL<-|prior|elem|next|  |prior|elem|next|  |prior|elem|next|->NULL |
 * |       |     |    |    |->|     |    |    |->|     |    |    |       |
 * |        ———————————————    ———————————————    ———————————————        |
 *  ---------------------------------------------------------------------
 */
link* insertElem(link* p, int elem, int pos)
{
    link* temp = p;
    link* insertNode = (link *)malloc(sizeof(link));
    int i;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("wrong position insert!\n");
            goto back;
        }
    }

    insertNode->elem = elem;
    if (temp->next != NULL) {
        temp->next->prior = insertNode;
    }
    insertNode->prior = temp;
    insertNode->next = temp->next;
    temp->next = insertNode;
back:
    return p;
}

/* 
 *  ---------------------------------------------------------------------
 * |        _______________    _______________    _______________        |
 * |       |     |    |    |<-|     |    |    |<-|     |    |    |       |
 * | NULL<-|prior|elem|next|  |prior|elem|next|  |prior|elem|next|->NULL |
 * |       |     |    |    |->|     |    |    |->|     |    |    |       |
 * |        ———————————————    ———————————————    ———————————————        |
 *  ---------------------------------------------------------------------
 */
link* deleElem(link* p, int pos)
{
    link *temp = p;
    link* deleTemp = NULL;
    int i;
    for (i = 1; i < pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("wrong position deleElem!\n");
            goto back;
        }
    }
    deleTemp = temp->next;
    if (deleTemp == NULL) {
        printf("wrong position deleElem!\n");
        goto back;
    }
    temp->next->next->prior = temp;
    temp->next = temp->next->next;
    free(deleTemp);
back:
    return p;
}

link* updateElem(link* p, int newElem, int pos)
{
    link* temp = p;
    int i;
    for (i = 1; i <= pos; i++) {
        temp = temp->next;
        if (temp == NULL) {
            printf("wrong position updateElem!\n");
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
        if(temp->elem == elem) {
            printf("match %d\n", i+1);
            goto back;
        }
        i++;
    }
back:
    return i;
}

int showLink(link* p)
{
    link* temp = p;
    int i = 0;
    while (temp->next) {
        temp = temp->next;
        printf("%d = %d\n", i+1, temp->elem);
        i++;
    }

    printf("========= showLink over| =====\n");
    return i;
}


