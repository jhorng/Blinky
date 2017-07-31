#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct listElement listElement;
struct listElement{
  listElement *next;
  int value;
};

typedef struct linkedList linkedList;
struct linkedList{
  listElement *head;
  listElement *tail;
};

listElement *initElement(int value);
linkedList *initLinkedList();
void addElement(linkedList *list, listElement *element);
listElement *removeElementFromFront(linkedList *list);

#endif // _LINKEDLIST_H
