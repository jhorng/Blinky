#include "LinkedList.h"
#include "unity.h"


void setUp(void){}



void tearDown(void){}



void test_initElement_return_NULL_and_five_given_the_argument_value_is_five(void){

  listElement *element = initElement(5);



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((element->next)), (((void *)0)), (_U_UINT)(12), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((element->value)), (((void *)0)), (_U_UINT)(13), UNITY_DISPLAY_STYLE_INT);

}



void test_initLinkedList_return_NULL_for_both_head_and_tail(void){

  linkedList *list = initLinkedList();



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head)), (((void *)0)), (_U_UINT)(19), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail)), (((void *)0)), (_U_UINT)(20), UNITY_DISPLAY_STYLE_INT);

}



void test_addElement_head_and_tail_link_with_an_element(void){

  linkedList *list = initLinkedList();

  listElement *element = initElement(5);



  addElement(list, element);



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head->next)), (((void *)0)), (_U_UINT)(29), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail->next)), (((void *)0)), (_U_UINT)(30), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((list->head->value)), (((void *)0)), (_U_UINT)(31), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((list->tail->value)), (((void *)0)), (_U_UINT)(32), UNITY_DISPLAY_STYLE_INT);

}



void test_addElement_with_two_elements_with_value_ten_and_twenty_respectively(void){

  linkedList *list = initLinkedList();

  listElement *element1 = initElement(10);

  listElement *element2 = initElement(20);



  addElement(list, element1);

  addElement(list, element2);



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head->next->next)), (((void *)0)), (_U_UINT)(43), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail->next)), (((void *)0)), (_U_UINT)(44), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((list->head->value)), (((void *)0)), (_U_UINT)(45), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((list->head->next->value)), (((void *)0)), (_U_UINT)(46), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((list->tail->value)), (((void *)0)), (_U_UINT)(47), UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head->next->next->next)), (((void *)0)), (_U_UINT)(61), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail->next)), (((void *)0)), (_U_UINT)(62), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((list->head->value)), (((void *)0)), (_U_UINT)(63), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((list->head->next->value)), (((void *)0)), (_U_UINT)(64), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((list->head->next->next->value)), (((void *)0)), (_U_UINT)(65), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((list->tail->value)), (((void *)0)), (_U_UINT)(66), UNITY_DISPLAY_STYLE_INT);



  returnElement = removeElementFromFront(list);



  UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((returnElement->value)), (((void *)0)), (_U_UINT)(70), UNITY_DISPLAY_STYLE_INT);





  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->head->next->next)), (((void *)0)), (_U_UINT)(73), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((list->tail->next)), (((void *)0)), (_U_UINT)(74), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((list->head->value)), (((void *)0)), (_U_UINT)(75), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((list->head->next->value)), (((void *)0)), (_U_UINT)(76), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((7)), (_U_SINT)((list->tail->value)), (((void *)0)), (_U_UINT)(77), UNITY_DISPLAY_STYLE_INT);

}
