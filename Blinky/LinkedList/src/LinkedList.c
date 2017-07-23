#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

listElement *initElement(int value){
  listElement *element = malloc(sizeof(listElement));
  element->next = NULL;
  element->value = value;
  return element;
}

linkedList *initLinkedList(){
  linkedList *list = malloc(sizeof(linkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void addList(linkedList *list, listElement *element){
  if(list->head == NULL && list->tail == NULL){
    list->head = element;
    list->tail = element;
  }
  else{
    list->tail->next = element;
    list->tail = element;
  }
}