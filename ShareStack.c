#define _CRT_SECURE_NO_WARNINGS 1
#include"ShareStack.h"

/*³õÊ¼»¯¹²ÏíÕ»*/
void ShareStackInit(ShareStack* stack) {

	if (stack == NULL) {
		return;
	}
	stack->top1 = -1;
	stack->top2 = STACKMAXSIZE;
}

/*ÍùÕ»ÀïÑ¹ÈëÔªËØ*/
void ShareStackPush(ShareStack* stack, StackType value, int StackNum) {

	if (stack == NULL) {
		return;
	}
	/*ÅÐ¶ÏÕ»Âú*/
	if (stack->top1 + 1 == stack->top2) {
		printf("Õ»ÂúÁË");
		return;
	}
	switch (StackNum) {
	case 1:
		/*Íù×ó±ßµÄÕ»Ñ¹ÈëÔªËØ*/
		++stack->top1;
		stack->data[stack->top1] = value;
		break;
	case 2:
		--stack->top2;
		stack->data[stack->top2] = value;
		break;
	default:
		exit(0);
		break;
	}
}

/*³öÕ»Ò»¸öÔªËØ*/
void ShareStackPop(ShareStack* stack, int StackNum) {

	if (stack == NULL) {
		return;
	}

	switch (StackNum) {
	case 1:
		if (stack->top1 == -1) {
			printf("Õ»1Îª¿Õ");
			return;
		}
		--stack->top1;
		break;
	case 2:
		if (stack->top2 == STACKMAXSIZE) {
			printf("Õ»2Îª¿Õ");
			return;
		}
		++stack->top2;
		break;
	default:
		break;
	}
}


/*´òÓ¡Õ»*/
void PrintStack(ShareStack* stack, int StackNum, char* msg) {

	if (stack == NULL) {
		return;
	}
	switch (StackNum) {
	case 1:

		if (stack->top1 == -1) {
			printf("Õ»Îª¿Õ\n");
			return;
		}
		printf("%s\n", msg);
		printf("[top]->");
		int index = stack->top1;

		while (index != -1) {
			printf("[%c]->", stack->data[index]);
			--index;
		}
		printf("[bottom]\n\n");

		break;
	case 2:

		if (stack->top2 == STACKMAXSIZE) {
			printf("Õ»Îª¿Õ\n");
			return;
		}
		printf("%s\n", msg);
		printf("[top]->");
		int index2 = stack->top2;

		while (index2 != STACKMAXSIZE) {
			printf("[%c]->", stack->data[index2]);
			++index2;
		}
		printf("[bottom]\n\n");
		break;
	default:
		break;
	}
}

/*È¡Õ»¶¥ÔªËØ*/
StackType ShareStackGetTopValue(ShareStack* stack, int StackNUm) {

	if (stack == NULL) {
		return;
	}
	switch (StackNUm) {
	case 1:
		if (stack->top1 == -1) {
			printf("Õ»1Îª¿Õ");
			return;
		}
		return stack->data[stack->top1];
		break;
	case 2:
		if (stack->top2 == STACKMAXSIZE) {
			printf("Õ»2Îª¿Õ");
			return;
		}
		return stack->data[stack->top2];
		break;
	default:
		break;
	}
}

/*Ïú»ÙÕ»*/
void ShareStackDestory(ShareStack* stack, int StackNum) {

	if (stack == NULL) {
		return;
	}
	switch (StackNum) {
	case 1:
		stack->top1 = -1;
		break;
	case 2:
		stack->top2 = STACKMAXSIZE;
		break;
	case 3:
		stack->top1 = -1;
		stack->top2 = STACKMAXSIZE;
		break;
	default:
		break;
	}
}