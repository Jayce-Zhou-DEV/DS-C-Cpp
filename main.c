/* ============================================================================
 * main.c —— 测试 / 演示代码 (对应 [TODO-7])
 *
 * 编译(要和 SeqList.c 一起编译):
 *     gcc -Wall -Wextra -g main.c SeqList.c -o seqlist
 *
 * 注意: SeqList.c 目前是空壳骨架, 所有操作都还不做事,
 *       所以现在运行结果会是空的——这是正常的。等每个函数填完实现,
 *       输出会逐步变成下面注释里写的那样。
 * ==========================================================================*/

#include <stdio.h>
#include "SeqList.h"

int main(void) {
    SeqList L;
    InitList(&L);

    /* ---- 基本流程: 期望最终输出  2  3  5  20 ---- */
    PushBack(&L, 2);
    PushBack(&L, 3);
    PushBack(&L, 5);
    PushBack(&L, 20);
    PrintList(&L);

    return 0;
}

/* ----------------------------------------------------------------------------
 * 自测清单(等实现填完后, 逐条取消注释验证; 括号里是期望结果)
 *
 *   PushBack(&L, 77);              // 表 -> 2 3 5 20 77
 *
 *   InsertList(&L, 2, 99);         // 在第 2 个位置插入
 *   PrintList(&L);                 // -> 2 99 3 5 20 77
 *   InsertList(&L, 0, 0);          // ERROR (i 非法, 最小是 1)
 *   InsertList(&L, 100, 0);        // ERROR (i 非法, 最大是 length+1)
 *
 *   ElemType v;
 *   GetElem(&L, 1, &v);            // OK,    v == 2
 *   GetElem(&L, 0, &v);            // ERROR
 *
 *   LocateElem(&L, 5);             // 4      (返回 1-based 位置)
 *   LocateElem(&L, 12345);         // 0      (找不到)
 *
 *   ListDelete(&L, 1, &v);         // OK,  v == 2
 *   PrintList(&L);                 // -> 99 3 5 20 77
 *   ListDelete(&L, 99, &v);        // ERROR
 *
 *   ListLength(&L);                // 5
 *   ListEmpty(&L);                 // 0 (非空)
 *   ClearList(&L);
 *   ListEmpty(&L);                 // 1 (空)
 *   PrintList(&L);                 // 只输出一个换行
 *
 * ---- 边界测试: 把 SeqList.h 里的 MAX_SIZE 临时改成 3, 然后连续
 *      PushBack 4 次 —— 第 4 次必须返回 ERROR, 且不能写越界 ([BUG-2])
 *
 * ---- 内存检查(确认没有越界/非法访问):
 *      gcc -fsanitize=address -g main.c SeqList.c -o seqlist && ./seqlist
 *      或 valgrind ./seqlist
 * -------------------------------------------------------------------------- */
