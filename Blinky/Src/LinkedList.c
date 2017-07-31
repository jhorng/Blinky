#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

listElement *initElement(char *name, void (*task)(void), uint32_t size){
  listElement *element = malloc(sizeof(listElement));
  if(size < 128){
  		size  = 128;
  	}

  element->name = name;
  element->task = task;
  element->stackSize = size;
  element->stackBegin = (uint8_t *)malloc(size);
  element->execReturnCode = 0xfffffff9;
  element->stackPointer = (uint8_t *)(element->stackBegin + size);
  element->stackPointer -= 64;
  *(uint32_t *)&element->stackPointer[0] = 0x11111111;	// R4
  *(uint32_t *)&element->stackPointer[4] = 0x22222222;	// R5
  *(uint32_t *)&element->stackPointer[8] = 0x33333333;	// R6
  *(uint32_t *)&element->stackPointer[12] = 0x44444444;	// R7
  *(uint32_t *)&element->stackPointer[16] = 0x55555555;	// R8
  *(uint32_t *)&element->stackPointer[20] = 0x66666666;	// R9
  *(uint32_t *)&element->stackPointer[24] = 0x77777777;	// R10
  *(uint32_t *)&element->stackPointer[28] = 0x88888888;	// R11
  *(uint32_t *)&element->stackPointer[32] = 0x99999999;	// R0
  *(uint32_t *)&element->stackPointer[36] = 0xaaaaaaaa;	// R1
  *(uint32_t *)&element->stackPointer[40] = 0xbbbbbbbb;	// R2
  *(uint32_t *)&element->stackPointer[44] = 0xcccccccc;	// R3
  *(uint32_t *)&element->stackPointer[48] = 0xdddddddd;	// R12
  *(uint32_t *)&element->stackPointer[52] = 0xeeeeeeee;	// LR
  *(uint32_t *)&element->stackPointer[56] = (uint32_t)task;	// PC
  *(uint32_t *)&element->stackPointer[60] = 0x21000000;	// xPSR
  return element;
}

linkedList *initLinkedList(){
  linkedList *list = malloc(sizeof(linkedList));
  list->head = NULL;
  list->tail = NULL;
  return list;
}

void addElementToBack(linkedList *list, listElement *element){
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
  listElement *currentElement;
  
  if(list->head == NULL){
    currentElement = NULL;
  }
  else{
    currentElement = list->head; 
    if(list->head->next == NULL){
      list->head = NULL;
      list->tail = NULL;
    }
    else{
      list->head = list->head->next;
      currentElement->next = NULL;
    }
  }
  
  return currentElement;
}

listElement *peepFront(linkedList *list){
  listElement *currentElement;
  
  currentElement = list->head;
  
  return currentElement;
}




