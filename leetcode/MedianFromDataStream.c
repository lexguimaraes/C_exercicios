#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
    int* maxHeap;
    int maxSize;
    int maxCapacity;
    int* minHeap;
    int minSize;
    int minCapacity;
} MedianFinder;

int esq(int ind) {
    return ind * 2 + 1;
}

int dir(int ind) {
    return esq(ind) + 1;
}

int pai(int ind) {
    return (ind - 1) / 2;
}

void max_heapify(int* v, int n, int ind) {
    int e = esq(ind);
    int d = dir(ind);
    int maior = ind;
    if (e < n && v[e] > v[maior]) maior = e;
    if (d < n && v[d] > v[maior]) maior = d;
    if (maior != ind) {
        int temp = v[maior];
        v[maior] = v[ind];
        v[ind] = temp;
        max_heapify(v, n, maior);
    }
}

void min_heapify(int* v, int n, int ind) {
    int e = esq(ind);
    int d = dir(ind);
    int menor = ind;
    if (e < n && v[e] < v[menor]) menor = e;
    if (d < n && v[d] < v[menor]) menor = d;
    if (menor != ind) {
        int temp = v[menor];
        v[menor] = v[ind];
        v[ind] = temp;
        min_heapify(v, n, menor);
    }
}

void insert_max_heap(int* heap, int* size, int value) {
    heap[*size] = value;
    (*size)++;
    int i = *size - 1;
    while (i != 0 && heap[pai(i)] < heap[i]) {
        int temp = heap[i];
        heap[i] = heap[pai(i)];
        heap[pai(i)] = temp;
        i = pai(i);
    }
}

void insert_min_heap(int* heap, int* size, int value) {
    heap[*size] = value;
    (*size)++;
    int i = *size - 1;
    while (i != 0 && heap[pai(i)] > heap[i]) {
        int temp = heap[i];
        heap[i] = heap[pai(i)];
        heap[pai(i)] = temp;
        i = pai(i);
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder* new = malloc(sizeof(MedianFinder));
    new->maxHeap = malloc(sizeof(int) * 10);
    new->maxSize = 0;
    new->maxCapacity = 10;
    new->minHeap = malloc(sizeof(int) * 10);
    new->minSize = 0;
    new->minCapacity = 10;
    return new;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
    if (obj->maxSize == 0 || num <= obj->maxHeap[0]) {
        if (obj->maxSize >= obj->maxCapacity) {
            obj->maxCapacity *= 2;
            obj->maxHeap = realloc(obj->maxHeap, sizeof(int) * obj->maxCapacity);
        }
        insert_max_heap(obj->maxHeap, &obj->maxSize, num);
    } else {
        if (obj->minSize >= obj->minCapacity) {
            obj->minCapacity *= 2;
            obj->minHeap = realloc(obj->minHeap, sizeof(int) * obj->minCapacity);
        }
        insert_min_heap(obj->minHeap, &obj->minSize, num);
    }

    if (obj->maxSize > obj->minSize + 1) {
        int value = obj->maxHeap[0];
        obj->maxHeap[0] = obj->maxHeap[obj->maxSize - 1];
        obj->maxSize--;
        max_heapify(obj->maxHeap, obj->maxSize, 0);
        if (obj->minSize >= obj->minCapacity) {
            obj->minCapacity *= 2;
            obj->minHeap = realloc(obj->minHeap, sizeof(int) * obj->minCapacity);
        }
        insert_min_heap(obj->minHeap, &obj->minSize, value);
    } else if (obj->minSize > obj->maxSize) {
        int value = obj->minHeap[0];
        obj->minHeap[0] = obj->minHeap[obj->minSize - 1];
        obj->minSize--;
        min_heapify(obj->minHeap, obj->minSize, 0);
        if (obj->maxSize >= obj->maxCapacity) {
            obj->maxCapacity *= 2;
            obj->maxHeap = realloc(obj->maxHeap, sizeof(int) * obj->maxCapacity);
        }
        insert_max_heap(obj->maxHeap, &obj->maxSize, value);
    }
}

double medianFinderFindMedian(MedianFinder* obj) {
    if (obj->maxSize > obj->minSize) {
        return obj->maxHeap[0];
    } else {
        return (obj->maxHeap[0] + obj->minHeap[0]) / 2.0;
    }
}

void medianFinderFree(MedianFinder* obj) {
    free(obj->maxHeap);
    free(obj->minHeap);
    free(obj);
}

