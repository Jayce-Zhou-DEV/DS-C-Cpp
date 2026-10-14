/* ============================================================================
 * SeqList.c —— 顺序表(顺序存储的线性表) 实现文件
 *
 * 本文件只放"函数实现": 不含 main, 也不重复定义结构体。
 * 类型 / 宏 / 函数原型全部来自 SeqList.h。
 *
 * 当前状态: 空壳骨架。每个函数体只有 TODO 提示 + 占位返回值,
 *           等你逐个把逻辑填进去(把 return ERROR; 换成真正的实现)。
 *
 * 待办清单:
 *   [TODO-3] PushBack / InsertList                        —— 插入
 *   [TODO-5] ListDelete                                   —— 删除
 *   [TODO-5] GetElem / LocateElem                         —— 查找
 *   [TODO-6] ListLength / ListEmpty / ClearList / PrintList —— 查询与输出
 *   [BUG-1]  PrintList 的循环条件必须是 < , 不能是 <=
 *   [BUG-2]  插入前必须判满: if (L->length >= MAX_SIZE) return ERROR;
 *
 * 编译(实现填完后):
 *     gcc -Wall -Wextra -g main.c SeqList.c -o seqlist
 * ==========================================================================*/

#include "SeqList.h"

/* ========================= 初始化 / 销毁 ========================= */

/* 初始化顺序表。 */
void InitList(SeqList *L) {
    L->length = 0;
    /* [TODO-6] 建议顺手清零, 调试时能一眼看出哪些位置还没用过:
     *     for (int i = 0; i < MAX_SIZE; i++) L->data[i] = 0; */
}

/* ============================= 插入 ============================== */

/* [TODO-3] 尾插: 在表尾追加元素 e。成功返回 OK, 表满返回 ERROR。O(1)。
 * 步骤提示:
 *   1) [BUG-2] 先判满: if (L->length >= MAX_SIZE) return ERROR;
 *   2) L->data[L->length] = e;
 *   3) L->length++;
 *   4) return OK;                                        */
int PushBack(SeqList *L, ElemType e) {
    (void)L;
    (void)e;                 /* 占位: 避免 "未使用参数" 警告 */
    return ERROR;            /* TODO: 换成真正的实现 */
}

/* [TODO-3] 按位置插入: 在第 i 个位置(1 <= i <= L->length + 1)插入 e,
 * 原第 i 个及其后的元素整体后移一位。成功 OK; i 非法或表满 ERROR。O(n)。
 * 步骤提示:
 *   1) if (i < 1 || i > L->length + 1) return ERROR;    // i 非法
 *   2) if (L->length >= MAX_SIZE)      return ERROR;    // 表满
 *   3) for (int j = L->length; j >= i; j--)              // 从后往前搬, 防覆盖
 *          L->data[j] = L->data[j - 1];
 *   4) L->data[i - 1] = e;                               // 注意下标是 i-1
 *   5) L->length++;
 *   6) return OK;                                        */
int InsertList(SeqList *L, int i, ElemType e) {
    (void)L;
    (void)i;
    (void)e;
    return ERROR;            /* TODO */
}

/* ============================= 删除 ============================== */

/* [TODO-5] 按位置删除: 删除第 i 个元素(1 <= i <= L->length), 用 *e 带出被删的值
 * (*e 允许传 NULL, 表示不关心被删的值)。成功 OK / i 非法 ERROR。O(n)。
 * 步骤提示:
 *   1) if (i < 1 || i > L->length) return ERROR;
 *   2) if (e != NULL) *e = L->data[i - 1];
 *   3) for (int j = i; j < L->length; j++)               // 从前往后搬, 覆盖被删位
 *          L->data[j - 1] = L->data[j];
 *   4) L->length--;
 *   5) return OK;                                        */
int ListDelete(SeqList *L, int i, ElemType *e) {
    (void)L;
    (void)i;
    (void)e;
    return ERROR;            /* TODO */
}

/* ============================= 查找 ============================== */

/* [TODO-5] 按位取值: 用 *e 带出第 i 个元素(1 <= i <= L->length)。O(1)。
 * 步骤提示: 校验 i; *e = L->data[i - 1]; return OK;        */
int GetElem(const SeqList *L, int i, ElemType *e) {
    (void)L;
    (void)i;
    (void)e;
    return ERROR;            /* TODO */
}

/* [TODO-5] 按值查找: 返回第一个值等于 e 的元素位置(1-based), 找不到返回 0。O(n)。
 * 步骤提示:
 *   for (int k = 0; k < L->length; k++)
 *       if (L->data[k] == e) return k + 1;    // 返回值是 1-based
 *   return 0;                                             */
int LocateElem(const SeqList *L, ElemType e) {
    (void)L;
    (void)e;
    return ERROR;            /* TODO */
}

/* ======================== 状态查询 ============================== */

/* [TODO-6] 返回元素个数。O(1)。  提示: return L->length;   */
int ListLength(const SeqList *L) {
    (void)L;
    return ERROR;            /* TODO */
}

/* [TODO-6] 空表返回 1, 否则返回 0。O(1)。  提示: return L->length == 0; */
int ListEmpty(const SeqList *L) {
    (void)L;
    return ERROR;            /* TODO */
}

/* [TODO-6] 清空表: 仅置 length = 0, 不释放已分配的空间。O(1)。 */
void ClearList(SeqList *L) {
    (void)L;
    /* TODO: L->length = 0; */
}

/* ============================= 输出 ============================== */

/* [TODO-6] 打印整个表。
 * [BUG-1] 循环条件必须是 i < L->length !!
 *         写成 i <= L->length 会多打印一个未初始化的 data[length],
 *         也就是你当初运行结果里最后那个莫名其妙的数字。
 * 步骤提示:
 *   for (int i = 0; i < L->length; i++) printf("%d\t", L->data[i]);
 *   printf("\n");                                        */
void PrintList(const SeqList *L) {
    (void)L;
    /* TODO */
}