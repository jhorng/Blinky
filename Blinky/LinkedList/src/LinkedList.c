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

void addElement(linkedList *list, listElement *element){
  if(list->head == NULL && list->tail == NULL){
    list->head = element;
    list->tail = element;
  }
  else{
    list->tail->next = element;
    list->tail = element;
  }
}

listElement *removeElementFromFront(linkedList *list){
  if(list->head == NULL){
    printf("link not form!\n");
    return NULL;
  }
  
  listElement *currentElement = malloc(sizeof(listElement));
  
  currentElement = list->head; // currentElement is pointing to the whole list. 
                               // Not extracting the first element.
  if(list->head->next == NULL){
    return currentElement;
  }
  else{
    list->head = list->head->next;    
  }
  
  return currentElement;
}





