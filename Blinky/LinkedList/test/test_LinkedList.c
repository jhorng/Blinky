#include "unity.h"
#include "LinkedList.h"
#include <stdlib.h>

void setUp(void){}

void tearDown(void){}

void test_initElement_return_NULL_and_five_given_the_argument_value_is_five(void){
  listElement *element = initElement(5);
  
  TEST_ASSERT_EQUAL(NULL, element->next);
  TEST_ASSERT_EQUAL(5, element->value);
}

void test_initLinkedList_return_NULL_for_both_head_and_tail(void){
  linkedList *list = initLinkedList();
  
  TEST_ASSERT_EQUAL(NULL, list->head);
  TEST_ASSERT_EQUAL(NULL, list->tail);
}

void test_addElement_head_and_tail_link_with_an_element(void){
  linkedList *list = initLinkedList();
  listElement *element = initElement(5);
  
  addElement(list, element);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(5, list->head->value);
  TEST_ASSERT_EQUAL(5, list->tail->value);
}

void test_addElement_with_two_elements_with_value_ten_and_twenty_respectively(void){
  linkedList *list = initLinkedList();
  listElement *element1 = initElement(10);
  listElement *element2 = initElement(20);
  
  addElement(list, element1);
  addElement(list, element2);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(10, list->head->value);
  TEST_ASSERT_EQUAL(20, list->head->next->value);
  TEST_ASSERT_EQUAL(20, list->tail->value);
}

void test_removeElementFromFront_with_list_of_value_five_six_seven_should_return_five(void){
  linkedList *list = initLinkedList();
  listElement *element1 = initElement(5);
  listElement *element2 = initElement(6);
  listElement *element3 = initElement(7);
  listElement *returnElement = malloc(sizeof(listElement));
  
  addElement(list, element1);
  addElement(list, element2);
  addElement(list, element3);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next->next->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(5, list->head->value);
  TEST_ASSERT_EQUAL(6, list->head->next->value);
  TEST_ASSERT_EQUAL(7, list->head->next->next->value);
  TEST_ASSERT_EQUAL(7, list->tail->value);
  
  returnElement = removeElementFromFront(list);
  
  TEST_ASSERT_EQUAL(NULL, returnElement->next);
  TEST_ASSERT_EQUAL(5, returnElement->value);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(6, list->head->value);
  TEST_ASSERT_EQUAL(7, list->head->next->value);
  TEST_ASSERT_EQUAL(7, list->tail->value);
}

void test_removedElementFromFront_add_to_the_back_of_the_list_given_value_one_two_three_would_become_two_three_one(void){
  linkedList *list = initLinkedList();
  listElement *element1 = initElement(1);
  listElement *element2 = initElement(2);
  listElement *element3 = initElement(3);
  listElement *removedElement;
  
  addElement(list, element1);
  addElement(list, element2);
  addElement(list, element3);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next->next->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(1, list->head->value);
  TEST_ASSERT_EQUAL(2, list->head->next->value);
  TEST_ASSERT_EQUAL(3, list->head->next->next->value);
  TEST_ASSERT_EQUAL(3, list->tail->value);
  
  removedElement = removeElementFromFront(list);
  
  addElement(list, removedElement);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next->next->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(2, list->head->value);
  TEST_ASSERT_EQUAL(3, list->head->next->value);
  TEST_ASSERT_EQUAL(1, list->head->next->next->value);
  TEST_ASSERT_EQUAL(1, list->tail->value);
}




