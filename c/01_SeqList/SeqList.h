#ifndef SEQLIST_H
#define SEQLIST_H

#include <stdbool.h>

#define SEQLIST_INIT_CAPACITY 16

/* 元素类型 */
typedef int ElemType;

/* 顺序表结构体 */
typedef struct {
    ElemType *data;     /* 指向连续存储空间的首地址 */
    int       length;   /* 当前元素个数，0 ≤ length ≤ capacity */
    int       capacity; /* 可容纳元素的最大个数 */
} SeqList;

/* 元素比较函数：按某种语义判断 a 与 b 是否"相等"，为真返回 true */
typedef bool (*CompareFn)(ElemType a, ElemType b);

/* 元素访问函数：对元素 e 做某种操作，返回 false 表示请求提前结束遍历 */
typedef bool (*VisitFn)(ElemType e);

/* ------------------------------ 构造与销毁 ------------------------------ */

/* L = {}，分配 capacity 个元素单元 */
bool SeqList_Init(SeqList *L, int capacity);

/* 释放存储空间，L 被销毁 */
void SeqList_Destroy(SeqList *L);

/* 清空全部元素，容量不变 */
void SeqList_Clear(SeqList *L);

/* ------------------------------ 状态与访问 ------------------------------ */

/* 返回当前元素个数 */
int SeqList_Length(const SeqList *L);

/* 空表？ */
bool SeqList_IsEmpty(const SeqList *L);

/* 表满？ */
bool SeqList_IsFull(const SeqList *L);

/* 用 *e 返回第 i 个元素 */
bool SeqList_GetElem(const SeqList *L, int i, ElemType *e);

/* 把第 i 个元素置为 e */
bool SeqList_SetElem(SeqList *L, int i, ElemType e);

/* 从表头起查找第一个与 e 满足 compare 关系的元素，*i 返回其位序；未找到则 *i = 0 */
bool SeqList_LocateElem(const SeqList *L, ElemType e, CompareFn compare, int *i);

/* *pre_e 返回 cur_e 的直接前驱（cur_e 为首元素或不存在时返回 false） */
bool SeqList_PriorElem(const SeqList *L, ElemType cur_e, ElemType *pre_e);

/* *next_e 返回 cur_e 的直接后继（cur_e 为尾元素或不存在时返回 false） */
bool SeqList_NextElem(const SeqList *L, ElemType cur_e, ElemType *next_e);

/* -------------------------------- 修改 -------------------------------- */

/* 在第 i 个位置之前插入 e，1 ≤ i ≤ length + 1（i = length + 1 即追加） */
bool SeqList_Insert(SeqList *L, int i, ElemType e);

/* 删除第 i 个元素，用 *e 返回其值，1 ≤ i ≤ length */
bool SeqList_Delete(SeqList *L, int i, ElemType *e);

/* 把容量调整为 new_capacity（new_capacity ≥ length） */
bool SeqList_Reserve(SeqList *L, int new_capacity);

/* -------------------------------- 遍历 -------------------------------- */

/* 按位序 1..length 依次调用 visit */
bool SeqList_Traverse(const SeqList *L, VisitFn visit);

/* ------------------------------ 扩展操作 ------------------------------ */

/* 把非递减有序表 La、Lb 归并到 Lc（Lc 需已初始化），La、Lb 不变 */
bool SeqList_Merge(const SeqList *La, const SeqList *Lb, SeqList *Lc);

/* ------------------------------ 辅助函数 ------------------------------ */

/* 默认比较：a == b */
bool SeqList_Equal(ElemType a, ElemType b);

/* 打印全部元素（调试用） */
void SeqList_Print(const SeqList *L);

#endif /* SEQLIST_H */