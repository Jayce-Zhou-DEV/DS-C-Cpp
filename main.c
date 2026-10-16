#include "SeqList.h"

int main(){
    SqList L;
    InitList(&L);
    ListInsert(&L,1,10);

    TraverseList(&L);

    DestroyList(&L);
    return 0;
}