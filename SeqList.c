#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define INIT_MAX_SIZE 10

typedef int ElemType;

typedef struct {
    ElemType *data;
    int length;
} SqList;

void InitList(SqList *L){
    // 错误：malloc 可能返回 NULL（内存不足时），未检查直接赋值
    // 后续所有操作都会对 NULL 指针解引用，导致程序崩溃
    // L->data = (ElemType*)malloc(sizeof(ElemType) * INIT_MAX_SIZE);
    // L->length = 0;

    // 正确：检查 malloc 返回值，分配失败时安全退出
    L->data = (ElemType *)malloc(sizeof(ElemType) * INIT_MAX_SIZE);
    if (!L->data) {
        L->length = 0;
        return;
    }
    L->length = 0;
}

void DestroyList(SqList *L){
    // 错误：free 后 L->data 变成悬空指针（指向已释放内存）
    // 若再次调用 DestroyList，会 double-free，导致未定义行为
    // if(L) free(L->data);

    // 正确：free 后将指针置 NULL，length 归零
    // free(NULL) 是安全的，这样可以防止 double-free 崩溃
    free(L->data);
    L->data = NULL;
    L->length = 0;
}

bool ListInsert(SqList *L, int i, ElemType e){
    if (i < 1 || i > L->length + 1) return false;
    if (L->length >= INIT_MAX_SIZE) return false;
    for (int j = L->length; j >= i; j--) L->data[j] = L->data[j - 1];
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool ListDelete(SqList *L, int i, ElemType *e){
    if (i < 1 || i > L->length) return false;
    if(e) *e = L->data[i - 1];
    for(int j = i; j <= L->length - 1; j++) L->data[j - 1] = L->data[j];
    L->length--;
    return true;
}

bool ListUpdate(SqList *L, int i, ElemType e){
    if (i < 1 || i > L->length) return false;
    L->data[i - 1] = e;
    return true;
}

bool ListEmpty(SqList *L){
    return L->length == 0;
}

int ListLength(SqList *L){
    return L->length;
}

bool GetElem(SqList *L, int i, ElemType *e){
    if (i < 1 || i > L->length) return false;
    // 判断 e 是否为 NULL，若调用方传入 NULL 则立即崩溃
    // *e = L->data[i - 1];

    // 正确：与 ListDelete 保持一致，判断 e 非 NULL 再写入
    // 调用方可以传 NULL 表示"只检查是否存在，不需要值"
    if (e) *e = L->data[i - 1];
    return true;
}

int LocateElem(SqList *L, ElemType e){
    for (int i = 0; i < L->length; i++){
        if (L->data[i] == e) return i + 1;
    }
    return 0;
}


void TraverseList(SqList *L){
    printf("curr SqList: ");
    for (int i = 0; i < L->length; i++) printf("%d ", L->data[i]);
    printf("\nn=%d",L->length);
}
