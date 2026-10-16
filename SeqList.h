#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>

#define INIT_MAX_SIZE 10

typedef int Elemtype;

typedef struct {
    Elemtype *data;
    int length;
} SqList;

bool InitList(SqList *L) {
    L->length = 0;
    L->data = (Elemtype *)malloc(sizeof(Elemtype)*INIT_MAX_SIZE);
    if (!L->data) return false;
    return true;
}

bool DestroyList(SqList *L) {
    if (L == NULL) return false;   // 无效指针，无法销毁
    free(L->data);
    L->data = NULL;
    L->length = 0;
    return true;
}

bool ListInsert(SqList *L, int i, Elemtype data) {
    if (L == NULL || L->data == NULL) return false;
    if (i < 1 || i > L->length + 1) return false;
    if (L->length >= INIT_MAX_SIZE) return false;
    for (int j = L->length; j >= i; j--) L->data[j] = L->data[j - 1];
    L->data[i - 1] = data;
    L->length++;
    return true;
}

void TraverseList(SqList *L) {
    for (int i = 0; i < L->length; i++) printf("%d ",L->data[i]);
}