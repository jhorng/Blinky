#include "unity.h"
#include "LinkedList.h"

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

void test_addList_head_and_tail_link_with_an_element(void){
  linkedList *list = initLinkedList();
  listElement *element = initElement(5);
  
  addList(list, element);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(5, list->head->value);
  TEST_ASSERT_EQUAL(5, list->tail->value);
}

void test_addList_with_two_elements_with_value_ten_and_twenty_respectively(void){
  linkedList *list = initLinkedList();
  listElement *element1 = initElement(10);
  listElement *element2 = initElement(20);
  
  addList(list, element1);
  addList(list, element2);
  
  TEST_ASSERT_EQUAL(NULL, list->head->next->next);
  TEST_ASSERT_EQUAL(NULL, list->tail->next);
  TEST_ASSERT_EQUAL(10, list->head->value);
  TEST_ASSERT_EQUAL(20, list->head->next->value);
  TEST_ASSERT_EQUAL(20, list->tail->value);
}



