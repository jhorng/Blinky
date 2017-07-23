#include "LinkedList.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_initElement_return_NULL_and_five_given_the_argument_value_is_five(void){

  listElement *element = initElement(5);



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((element->next)), (((void *)0)), (_U_UINT)(11), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((element->value)), (((void *)0)), (_U_UINT)(12), UNITY_DISPLAY_STYLE_INT);

}



void test_initLinkedList_return_NULL_for_both_head_and_tail(void){

  linkedList *list = initLinkedList();



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head)), (((void *)0)), (_U_UINT)(18), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail)), (((void *)0)), (_U_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}



void test_addList_head_and_tail_link_with_an_element(void){

  linkedList *list = initLinkedList();

  listElement *element = initElement(5);



  addList(list, element);



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head->next)), (((void *)0)), (_U_UINT)(28), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail->next)), (((void *)0)), (_U_UINT)(29), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((list->head->value)), (((void *)0)), (_U_UINT)(30), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((list->tail->value)), (((void *)0)), (_U_UINT)(31), UNITY_DISPLAY_STYLE_INT);

}



void test_addList_with_two_elements_with_value_ten_and_twenty_respectively(void){

  linkedList *list = initLinkedList();

  listElement *element1 = initElement(10);

  listElement *element2 = initElement(20);



  addList(list, element1);

  addList(list, element2);



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head->next->next)), (((void *)0)), (_U_UINT)(42), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail->next)), (((void *)0)), (_U_UINT)(43), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((list->head->value)), (((void *)0)), (_U_UINT)(44), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((list->head->next->value)), (((void *)0)), (_U_UINT)(45), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((list->tail->value)), (((void *)0)), (_U_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}
