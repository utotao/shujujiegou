#include "stdio.h"
#include "stdlib.h"

typedef struct Link_Node {
    struct Link_Node* prev;
    struct Link_Node* next;
    int elem;
} link_node;

typedef struct LINK {
    link_node* head;
    int length;
} link;

#define LIST_HEAD_INIT(name) { &(name), &(name), 0 }

#define LIST_HEAD(name) \
	struct link_node name = LIST_HEAD_INIT(name)

static void __list_add(struct link_node *new, struct link_node *prev,
    struct link_node *next)
{
    new->prev = prev;
    new->next = next;
    prev->next = new;
    next->prev = new;

    return;
}

static void list_add_tail(struct link_node *new, struct link_node *head)
{
    __list_add(new, head->prev, head);
}

link* insertElem(link* p, int elem, int pos)
{

}

link* deleElem(link* p, int pos);
link* updateElem(link* p, int newElem, int pos);
int searchElem(link* p, int elem);
int showLink(link* p);

int main(int argc, char** argv)
{
    LIST_HEAD(p);

    return 0;
}
