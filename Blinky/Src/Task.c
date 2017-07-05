#include <stdlib.h>
#include "Task.h"

TCB *createThread(char *name, void (*task)(void), uint32_t size){
	if(size < 128){
		size  = 128;
	}

	TCB *tcb = (TCB *)malloc(sizeof(TCB));
	tcb->name = name;
	tcb->task = task;
	tcb->stackSize = size;
	tcb->stackBegin = (uint32_t *)malloc(size);
	tcb->execReturnCode = 0xfffffff9;
	tcb->stackPointer = (uint32_t *)(tcb->stackBegin + size);
	tcb->stackPointer -= 20;
	tcb->stackPointer[0] = 0x11111111;
	tcb->stackPointer[1] = 0x22222222;
	tcb->stackPointer[2] = 0x33333333;
	tcb->stackPointer[3] = 0x44444444;
	tcb->stackPointer[4] = 0x55555555;
	tcb->stackPointer[5] = 0x66666666;
	tcb->stackPointer[6] = 0x77777777;
	tcb->stackPointer[7] = 0x88888888;
	tcb->stackPointer[8] = 0x99999999;
	tcb->stackPointer[9] = 0xaaaaaaaa;
	tcb->stackPointer[10] = 0xbbbbbbbb;
	tcb->stackPointer[11] = 0xcccccccc;
	tcb->stackPointer[12] = 0xdddddddd;
	tcb->stackPointer[13] = 0xeeeeeeee;
	tcb->stackPointer[14] = (void (*)(void))task;
	tcb->stackPointer[15] = 0x21000000;
	return tcb;
}

TCB *initKernel(char *mainThreadName){
	TCB *tcb = (TCB *)malloc(sizeof(TCB));
	tcb->name = mainThreadName;
	tcb->stackBegin = NULL;
	tcb->stackSize = 0;
	return tcb;
}
