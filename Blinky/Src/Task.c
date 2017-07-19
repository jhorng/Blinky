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
	tcb->stackBegin = (uint8_t *)malloc(size);
	tcb->execReturnCode = 0xfffffff9;
	tcb->stackPointer = (uint8_t *)(tcb->stackBegin + size);
	tcb->stackPointer -= 64;
	*(uint32_t *)&tcb->stackPointer[0] = 0x11111111;	// R4
	*(uint32_t *)&tcb->stackPointer[4] = 0x22222222;	// R5
	*(uint32_t *)&tcb->stackPointer[8] = 0x33333333;	// R6
	*(uint32_t *)&tcb->stackPointer[12] = 0x44444444;	// R7
	*(uint32_t *)&tcb->stackPointer[16] = 0x55555555;	// R8
	*(uint32_t *)&tcb->stackPointer[20] = 0x66666666;	// R9
	*(uint32_t *)&tcb->stackPointer[24] = 0x77777777;	// R10
	*(uint32_t *)&tcb->stackPointer[28] = 0x88888888;	// R11
	*(uint32_t *)&tcb->stackPointer[32] = 0x99999999;	// R0
	*(uint32_t *)&tcb->stackPointer[36] = 0xaaaaaaaa;	// R1
	*(uint32_t *)&tcb->stackPointer[40] = 0xbbbbbbbb;	// R2
	*(uint32_t *)&tcb->stackPointer[44] = 0xcccccccc;	// R3
	*(uint32_t *)&tcb->stackPointer[48] = 0xdddddddd;	// R12
	*(uint32_t *)&tcb->stackPointer[52] = 0xeeeeeeee;	// LR
	*(uint32_t *)&tcb->stackPointer[56] = (uint32_t)task;	// PC
	*(uint32_t *)&tcb->stackPointer[60] = 0x21000000;	// xPSR
	return tcb;
}

TCB *initKernel(char *mainThreadName){
	TCB *tcb = (TCB *)malloc(sizeof(TCB));
	tcb->name = mainThreadName;
	tcb->stackBegin = NULL;
	tcb->stackSize = 0;
	return tcb;
}
