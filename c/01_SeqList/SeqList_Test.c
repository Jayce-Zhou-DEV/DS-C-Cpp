#include "SeqList.h"
#include "SeqList.c"

#include <stdio.h>

/* visit 回调：打印元素，永远继续 */
static bool PrintElem(ElemType e) {
    printf("%d ", e);
    return true;
}

int main(){
    SeqList L;
    SeqList_Init(&L, 100);
    SeqList_Insert(&L, 1, 46);
    SeqList_Insert(&L, 2, 91);
    SeqList_Insert(&L, 3, 13);
    SeqList_Insert(&L, 4, 41);
    SeqList_Insert(&L, 5, 52);

    SeqList_Traverse(&L, PrintElem);
    printf("\n");

    SeqList_Destroy(&L);
}