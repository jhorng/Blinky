#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

typedef struct listElement listElement;
struct listElement{
  listElement *next;
  char *name;
  void (*task)(void);
  uint8_t *stackPointer;
  uint8_t *stackBegin;
  uint32_t stackSize;
  uint32_t execReturnCode;
};

typedef struct linkedList linkedList;
struct linkedList{
  listElement *head;
  listElement *tail;
};

listElement *initElement(char *name, void (*task)(void), uint32_t size);
linkedList *initLinkedList();
void addElementToBack(linkedList *list, listElement *element);
listElement *removeElementFromFront(linkedList *list);
listElement *peepFront(linkedList *list);

#endif // _LINKEDLIST_H
