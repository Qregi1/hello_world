#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"
#include<stdio.h>
#include<stddef.h>
#include<assert.h>

/*����õĺ���*/
int no_less(HeapType a, HeapType b) {
	return a > b ? 1 : 0;
}

/*С���õĺ���*/
int less(HeapType a, HeapType b) {
	return a < b ? 1 : 0;
}

/*����������*/
void Swap(HeapType* a, HeapType* b) {
	HeapType tmp = *a;
	*a = *b;
	*b = tmp;
}

/*��ʼ��*/
void HeapInit(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	heap->size = 0;
	heap->cmp = less;
}

/*�����һ���������һ��Ԫ���ϸ�*/
void AdjustUp(HeapType data[], size_t size, Compare cmp, size_t index) {
	assert(data);
	size_t cur = index;
	while (cur) {
		size_t f_cur = (cur - 1) / 2;
		if (cmp(data[cur], data[f_cur])) {
			Swap(&data[cur], &data[f_cur]);
		}
		cur = f_cur;
	}
}

void AdjustDown(HeapType data[], size_t size, Compare cmp, size_t index) {
	assert(data);
	size_t parent = index;
	size_t child = parent * 2 + 1;
	/*ֱ��parentΪҶ�ڵ��ʱ��ͽ���ѭ��*/
	while (child < size) {
		//�Ƚ��ӽڵ㣬Ȼ��ó��Ƚ�С�Ľ��
		//��������жϵ�ǰ�����Һ��ӽ���Ƿ����
		if (child + 1 < size && !cmp(data[child], data[child + 1])) {
			child += 1;
		}
		if (!cmp(data[parent], data[child])) {
			//��ʾparent�����ӽڵ�
			Swap(&data[parent], &data[child]);
		}
		else {
			/*��ʾ��ǰ�����С���ӽڵ��,�Ͳ����ټ���������*/
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}


/*С�Ѳ���Ԫ��*/
void HeapInsert(Heap* heap, HeapType value) {
	if (heap == NULL) {
		return;
	}
	if (heap->size >= HEAPMAXSIZE) {
		/*��ʾ�����Ѿ�����*/
		return;
	}
	/*β��һ��Ԫ�أ�Ȼ���ϸ�*/
	size_t cur = heap->size;
	heap->data[heap->size++] = value;
	/*
	while (1) {
		if (cur <= 0) {
			break;
		}
		//ÿ���븸�ڵ�Ƚ�
		//���valueС������1����ѭ��
		size_t f_cur = (cur - 1) / 2;
		if (heap->cmp(heap->data[cur], heap->data[f_cur])) {
			Swap(&heap->data[cur], &heap->data[f_cur]);
		}
		cur = f_cur;
	}
	*/
	AdjustUp(heap->data, heap->size, less, heap->size - 1);
}

/*ȡ�Ѷ�Ԫ��*/
HeapType HeapRoot(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	if (heap->size == 0) {
		return;
	}
	else {
		return heap->data[0];
	}
}

/*ɾ���Ѷ�Ԫ��*/
void HeapErase(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	if (heap->size == 0) {
		/*��ʾ����û��Ԫ��*/
		return;
	}
	/*�ȰѶѶ�Ԫ�غ����һ��λ�õ�Ԫ�ؽ���*/
	Swap(&heap->data[0], &heap->data[heap->size - 1]);
	--heap->size;
	/*Ȼ���ٰѶ������ź�*/
	AdjustDown(heap->data, heap->size, less, 0);
}

/*���п�*/
int HeapEmpty(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	return heap->size == 0 ? 1 : 0;
}

/*��ѵĴ�С*/
size_t HeapSize(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	return heap->size;
}

/*���ٶ�*/
void HeapDestory(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	heap->size = 0;
	heap->cmp = NULL;
}

#if 0
/*
**������
**������С�����������Ҫ���������Ҫ��AdjustUp��AdjustDown��cmp��������no_less
*/
void HeapSort(HeapType data[], size_t size) {
	assert(data);
	if(size == 0 || size == 1) {
		return;
	}
	/*�������鴴��һ��*/
	size_t heap_size = 0;
	/*ֱ���õ�ǰ������жѵĴ���*/
	for (; heap_size < size; ++heap_size) {
		AdjustUp(data, heap_size, less, heap_size);
	}
	
	/*Ȼ�����������������*/
	while (heap_size > 1) {
		/*ÿ�ν�����һ�������һ��*/
		Swap(&data[0], &data[heap_size - 1]);
		--heap_size;
		//Ȼ���ǰ���Ԫ�������ųɶ�
		AdjustDown(data, heap_size, less, 0);
	}
}
#elif 1
void HeapSort(HeapType data[], size_t size) {
	if (size == 0 || size == 1) {
		return;
	}
	/*�ѵ�ǰ������С��*/
	//size�������Ԫ�ظ�����size - 1�ǵ�ǰ���һ��Ԫ�ص��±�λ�ã�Ȼ���� ��1����2���ҵ����һ�����ĸ��ڵ�
	size_t start = (size - 1 - 1) / 2;
	/*��Ϊstart���޷��ų����ͣ����������ѭ���ﲻ��Ϊ0*/
	for (; start > 0; --start) {
		AdjustDown(data, size, less, start);
	}
	AdjustDown(data, size, less, start);

	/*Ȼ�����������������*/
	while (size > 1) {
		/*ÿ�ν�����һ�������һ��*/
		Swap(&data[0], &data[size - 1]);
		--size;
		//Ȼ���ǰ���Ԫ�������ųɶ�
		AdjustDown(data, size, less, 0);
	}
}

#endif