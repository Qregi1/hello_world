#define _CRT_SECURE_NO_WARNINGS 1
#include"ShareStack.h"

/*��ʼ������ջ*/
void ShareStackInit(ShareStack* stack) {

	if (stack == NULL) {
		return;
	}
	stack->top1 = -1;
	stack->top2 = STACKMAXSIZE;
}

/*��ջ��ѹ��Ԫ��*/
void ShareStackPush(ShareStack* stack, StackType value, int StackNum) {

	if (stack == NULL) {
		return;
	}
	/*�ж�ջ��*/
	if (stack->top1 + 1 == stack->top2) {
		printf("ջ����");
		return;
	}
	switch (StackNum) {
	case 1:
		/*����ߵ�ջѹ��Ԫ��*/
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

/*��ջһ��Ԫ��*/
void ShareStackPop(ShareStack* stack, int StackNum) {

	if (stack == NULL) {
		return;
	}

	switch (StackNum) {
	case 1:
		if (stack->top1 == -1) {
			printf("ջ1Ϊ��");
			return;
		}
		--stack->top1;
		break;
	case 2:
		if (stack->top2 == STACKMAXSIZE) {
			printf("ջ2Ϊ��");
			return;
		}
		++stack->top2;
		break;
	default:
		break;
	}
}


/*��ӡջ*/
void PrintStack(ShareStack* stack, int StackNum, char* msg) {

	if (stack == NULL) {
		return;
	}
	switch (StackNum) {
	case 1:

		if (stack->top1 == -1) {
			printf("ջΪ��\n");
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
			printf("ջΪ��\n");
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

/*ȡջ��Ԫ��*/
StackType ShareStackGetTopValue(ShareStack* stack, int StackNUm) {

	if (stack == NULL) {
		return;
	}
	switch (StackNUm) {
	case 1:
		if (stack->top1 == -1) {
			printf("ջ1Ϊ��");
			return;
		}
		return stack->data[stack->top1];
		break;
	case 2:
		if (stack->top2 == STACKMAXSIZE) {
			printf("ջ2Ϊ��");
			return;
		}
		return stack->data[stack->top2];
		break;
	default:
		break;
	}
}

/*����ջ*/
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