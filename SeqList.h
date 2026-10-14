/* ============================================================================
 * SeqList.h —— 顺序表(顺序存储的线性表) 接口声明
 *
 * 拆文件方案(对应 [TODO-7]):
 *     SeqList.h   <- 本文件: 宏 + 类型定义 + 函数声明(不含任何实现)
 *     SeqList.c   <- 函数实现, 只需 #include "SeqList.h"
 *     main.c      <- 测试代码, 只需 #include "SeqList.h"
 *
 * 编译方式(对应 [TODO-9]):
 *     gcc -Wall -Wextra -g main.c SeqList.c -o seqlist
 *     或用 Makefile: make / make clean
 *
 * 标记说明:
 *     [TODO-n] 待办编号, 与 SeqList.c 里的注释一一对应
 *     [BUG-n]  已确认的缺陷位置
 * ==========================================================================*/
#ifndef SEQLIST_H
#define SEQLIST_H

/* ========================== 宏与类型 [TODO-4] ============================== */
/* 消灭魔法数字与硬编码类型: 以后想把 int 换成结构体, 只改 ElemType 一行。 */

#define MAX_SIZE 10          /* 顺序表最大容量(原来是散落各处的魔法数字 10) */
#define OK       1           /* 操作成功 */
#define ERROR    0           /* 操作失败 */

typedef int ElemType;        /* 元素类型别名 */

/* ============================ 结构体定义 [TODO-8] ========================== */
/* 静态版: 容量在编译期固定。
 *
 * 将来做"动态顺序表"时, 把数组换成指针并增加 capacity 字段, 例如:
 *
 *     typedef struct SeqList {
 *         ElemType *data;       // 动态数组, 由 malloc 分配
 *         int       length;     // 当前元素个数
 *         int       capacity;   // 当前已分配的容量
 *     } SeqList;
 *
 * 同时所有只读操作的形参已是 const SeqList *, 无需再改。 */
typedef struct SeqList {
    ElemType data[MAX_SIZE];  /* [BUG-2] 有了 MAX_SIZE, 满表判断才有正确依据 */
    int      length;          /* 当前元素个数; 合法下标 0 .. length-1 */
} SeqList;

/* ======================= 初始化 / 销毁 ======================= */

/* 初始化顺序表: 置 length = 0。
 * [TODO-6] 实现时建议顺手把 data[] 清零, 便于调试时辨认"未使用"的位置。 */
void InitList(SeqList *L);

/* [TODO-8] 动态版才需要释放内存; 静态版可先不实现。 */
/* void DestroyList(SeqList *L); */

/* ============================ 插入 [TODO-3] ================================ */

/* 尾插: 在表尾追加元素 e。
 * 返回: 成功 OK / 表满 ERROR。  时间复杂度 O(1)。
 * 注意: 你原来的 ListInsert 实际做的就是这个。 */
int PushBack(SeqList *L, ElemType e);

/* 按位置插入: 在第 i 个位置(1 <= i <= L->length + 1)插入 e,
 * 原第 i 个及其后的元素整体后移一位。
 * 返回: 成功 OK / i 非法或表满 ERROR。  时间复杂度 O(n)。 */
int InsertList(SeqList *L, int i, ElemType e);

/* ============================ 删除 [TODO-5] ================================ */

/* 按位置删除: 删除第 i 个元素(1 <= i <= L->length), 用 *e 带出被删元素
 * (*e 允许传 NULL 表示不关心被删的值)。
 * 返回: 成功 OK / i 非法 ERROR。  时间复杂度 O(n)。 */
int ListDelete(SeqList *L, int i, ElemType *e);

/* ============================ 查找 [TODO-5] ================================ */

/* 按位取值: 用 *e 带出第 i 个元素(1 <= i <= L->length)。
 * 返回: 成功 OK / i 非法 ERROR。  时间复杂度 O(1)。 */
int GetElem(const SeqList *L, int i, ElemType *e);

/* 按值查找: 返回第一个值等于 e 的元素位置(1-based); 找不到返回 0。
 * 时间复杂度 O(n)。 */
int LocateElem(const SeqList *L, ElemType e);

/* ========================= 状态查询 [TODO-6] =============================== */

/* 返回元素个数。  O(1) */
int ListLength(const SeqList *L);

/* 空表返回 1, 否则返回 0。  O(1) */
int ListEmpty(const SeqList *L);

/* 清空表: 仅置 length = 0, 不释放已分配的空间。  O(1) */
void ClearList(SeqList *L);

/* ============================ 输出 [TODO-6] ================================ */

/* 打印整个表。
 * [BUG-1] 实现时循环条件必须是 i < L->length, 不能写成 <= 。
 * 入参用 const 指针, 避免拷贝整个数组(原代码是按值传递)。 */
void PrintList(const SeqList *L);

#endif /* SEQLIST_H */
