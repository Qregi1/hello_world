#define _CRT_SECURE_NO_WARNINGS 1

#include"Heap.h"
#include<stdio.h>
#include<stddef.h>
#include<assert.h>

/*大堆用的函数*/
int no_less(HeapType a, HeapType b) {
	return a > b ? 1 : 0;
}

/*小堆用的函数*/
int less(HeapType a, HeapType b) {
	return a < b ? 1 : 0;
}

/*交换两个数*/
void Swap(HeapType* a, HeapType* b) {
	HeapType tmp = *a;
	*a = *b;
	*b = tmp;
}

/*初始化*/
void HeapInit(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	heap->size = 0;
	heap->cmp = less;
}

/*这里把一个堆中最后一个元素上浮*/
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
	/*直到parent为叶节点的时候就结束循环*/
	while (child < size) {
		//比较子节点，然后得出比较小的结点
		//这里必须判断当前结点的右孩子结点是否存在
		if (child + 1 < size && !cmp(data[child], data[child + 1])) {
			child += 1;
		}
		if (!cmp(data[parent], data[child])) {
			//表示parent大于子节点
			Swap(&data[parent], &data[child]);
		}
		else {
			/*表示当前结点是小于子节点的,就不用再继续往下了*/
			break;
		}
		parent = child;
		child = parent * 2 + 1;
	}
}


/*小堆插入元素*/
void HeapInsert(Heap* heap, HeapType value) {
	if (heap == NULL) {
		return;
	}
	if (heap->size >= HEAPMAXSIZE) {
		/*表示数组已经满了*/
		return;
	}
	/*尾插一个元素，然后上浮*/
	size_t cur = heap->size;
	heap->data[heap->size++] = value;
	/*
	while (1) {
		if (cur <= 0) {
			break;
		}
		//每次与父节点比较
		//如果value小，返回1进入循环
		size_t f_cur = (cur - 1) / 2;
		if (heap->cmp(heap->data[cur], heap->data[f_cur])) {
			Swap(&heap->data[cur], &heap->data[f_cur]);
		}
		cur = f_cur;
	}
	*/
	AdjustUp(heap->data, heap->size, less, heap->size - 1);
}

/*取堆顶元素*/
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

/*删除堆顶元素*/
void HeapErase(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	if (heap->size == 0) {
		/*表示现在没有元素*/
		return;
	}
	/*先把堆顶元素和最后一个位置的元素交换*/
	Swap(&heap->data[0], &heap->data[heap->size - 1]);
	--heap->size;
	/*然后再把堆重新排好*/
	AdjustDown(heap->data, heap->size, less, 0);
}

/*堆判空*/
int HeapEmpty(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	return heap->size == 0 ? 1 : 0;
}

/*求堆的大小*/
size_t HeapSize(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	return heap->size;
}

/*销毁堆*/
void HeapDestory(Heap* heap) {
	if (heap == NULL) {
		return;
	}
	heap->size = 0;
	heap->cmp = NULL;
}

#if 0
/*
**堆排序
**这里是小堆排序，如果需要大堆排序，需要把AdjustUp和AdjustDown的cmp函数换成no_less
*/
void HeapSort(HeapType data[], size_t size) {
	assert(data);
	if(size == 0 || size == 1) {
		return;
	}
	/*先用数组创建一个*/
	size_t heap_size = 0;
	/*直接用当前数组进行堆的创建*/
	for (; heap_size < size; ++heap_size) {
		AdjustUp(data, heap_size, less, heap_size);
	}
	
	/*然后对这个数组进行排序*/
	while (heap_size > 1) {
		/*每次交换第一个和最后一个*/
		Swap(&data[0], &data[heap_size - 1]);
		--heap_size;
		//然后把前面的元素重新排成堆
		AdjustDown(data, heap_size, less, 0);
	}
}
#elif 1
void HeapSort(HeapType data[], size_t size) {
	if (size == 0 || size == 1) {
		return;
	}
	/*把当前数组变成小堆*/
	//size是数组的元素个数，size - 1是当前最后一个元素的下标位置，然后再 减1除以2，找到最后一个结点的父节点
	size_t start = (size - 1 - 1) / 2;
	/*因为start是无符号长整型，所以在这个循环里不能为0*/
	for (; start > 0; --start) {
		AdjustDown(data, size, less, start);
	}
	AdjustDown(data, size, less, start);

	/*然后对这个数组进行排序*/
	while (size > 1) {
		/*每次交换第一个和最后一个*/
		Swap(&data[0], &data[size - 1]);
		--size;
		//然后把前面的元素重新排成堆
		AdjustDown(data, size, less, 0);
	}
}

#endif