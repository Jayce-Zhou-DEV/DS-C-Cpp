#include "SeqList.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* ==========================================================================
 * 统一约定：
 *   - 对外位序 i 从 1 开始，内部下标 = i - 1
 *   - 合法范围：访问类 1 ≤ i ≤ length，插入 1 ≤ i ≤ length + 1
 *   - 状态类操作成功返回 true，失败返回 false，且不破坏原表
 *
 * TODO 完成顺序建议：
 *   [ ] 1. SeqList_Init / SeqList_Destroy / SeqList_Clear
 *   [ ] 2. SeqList_Length / IsEmpty / IsFull
 *   [ ] 3. SeqList_GetElem / SetElem
 *   [ ] 4. SeqList_Insert / Delete（配合 EnsureCapacity 处理扩容）
 *   [ ] 5. SeqList_LocateElem / PriorElem / NextElem
 *   [ ] 6. SeqList_Traverse / Print
 *   [ ] 7. SeqList_Merge（依赖前面全部正确，最后写）
 * ========================================================================== */


/* ------------------------------ 内部辅助 ------------------------------ */

//保证 L 的容量至少为 min_capacity；不足时按倍增策略扩容
static bool SeqList_EnsureCapacity(SeqList *L, int min_capacity) {
    if (L == NULL || min_capacity < 0)      return false;

    // 满足要求就不动内存
    if (min_capacity <= L->capacity)        return true;

    // capacity 为 0（未 Init 或刚 Destroy）时从默认初值起步，否则从现有容量翻倍
    int new_capacity = (L->capacity > 0) ? L->capacity : SEQLIST_INIT_CAPACITY;

    while (new_capacity < min_capacity) {
        if (new_capacity > INT_MAX / 2)     return false;
        new_capacity *= 2;
    }

    // realloc失败时返回 NULL 且"原内存块保持不变"，
    // 使用临时变量接返回值：直接 L->data = realloc(...) 会在失败时丢失旧指针（内存泄漏 + 悬空）
    // 【size_t 强转】new_capacity * sizeof(ElemType) 用 int 相乘可能溢出，先转 size_t 做无符号乘法
    ElemType* new_data = (ElemType*)realloc(L->data, (size_t)new_capacity * sizeof(ElemType));
    if (new_data == NULL) return false;

    // 【成功后统一提交】数据与容量同时更新，保持 length ≤ capacity 的不变式
    L->data     = new_data;
    L->capacity = new_capacity;
    return true;
}

/* ------------------------------ 构造与销毁 ------------------------------ */

bool SeqList_Init(SeqList *L, int capacity) {
    // 失败时 L 被置为"容量 0、未分配"的空表状态，"成功返回 true，失败返回 false"
    if (L == NULL) return false;

    // 先置空表
    L->data     = NULL;
    L->length   = 0;
    L->capacity = 0;

    // capacity <= 0 时使用用默认值
    if (capacity <= 0) capacity = SEQLIST_INIT_CAPACITY;

    ElemType* buffer= (ElemType*)malloc((size_t)capacity * sizeof(ElemType));
    if (buffer == NULL) return false;

    // 分配成功写入成员
    L->data     = buffer;
    L->capacity = capacity;
    return true;
}

void SeqList_Destroy(SeqList *L) {
    if (L == NULL) return;

    // 三件套归零
    free(L->data);
    L->data = NULL;
    L->length = L->capacity = 0;
}

void SeqList_Clear(SeqList *L) {
    /* TODO: 只把 length 归零即可（容量与存储空间保留），
     *       若 ElemType 含指针，需先逐个释放所指对象 */
    (void)L;
}

/* ------------------------------ 状态与访问 ------------------------------ */

int SeqList_Length(const SeqList *L) {
    /* TODO: 防御 L == NULL，返回 0；否则返回 L->length */
    (void)L;
    return 0;
}

bool SeqList_IsEmpty(const SeqList *L) {
    /* TODO: L == NULL 视为空表 / 非法，明确你的选择 */
    (void)L;
    return false;
}

bool SeqList_IsFull(const SeqList *L) {
    /* TODO: length == capacity */
    (void)L;
    return false;
}

bool SeqList_GetElem(const SeqList *L, int i, ElemType *e) {
    /* TODO(1): 校验 L、e 非空，且 1 ≤ i ≤ L->length
     * TODO(2): *e = L->data[i - 1]（注意位序转下标） */
    (void)L;
    (void)i;
    (void)e;
    return false;
}

bool SeqList_SetElem(SeqList *L, int i, ElemType e) {
    /* TODO: 同 GetElem 的范围校验，然后 L->data[i - 1] = e */
    (void)L;
    (void)i;
    (void)e;
    return false;
}

bool SeqList_LocateElem(const SeqList *L, ElemType e, CompareFn compare, int *i) {
    /* TODO(1): 校验 L、i；compare 为 NULL 时退化为 SeqList_Equal
     * TODO(2): 下标 0 → length-1 顺序扫描，命中则 *i = idx + 1 并返回 true
     * TODO(3): 未命中 *i = 0，返回 false */
    (void)L;
    (void)e;
    (void)compare;
    (void)i;
    return false;
}

bool SeqList_PriorElem(const SeqList *L, ElemType cur_e, ElemType *pre_e) {
    /* TODO(1): 先 LocateElem 找位序 k
     * TODO(2): 不存在或 k == 1（首元素无前驱）→ false
     * TODO(3): *pre_e = L->data[k - 2]，返回 true */
    (void)L;
    (void)cur_e;
    (void)pre_e;
    return false;
}

bool SeqList_NextElem(const SeqList *L, ElemType cur_e, ElemType *next_e) {
    /* TODO(1): 先 LocateElem 找位序 k
     * TODO(2): 不存在或 k == length（尾元素无后继）→ false
     * TODO(3): *next_e = L->data[k]，返回 true */
    (void)L;
    (void)cur_e;
    (void)next_e;
    return false;
}

/* -------------------------------- 修改 -------------------------------- */

bool SeqList_Insert(SeqList *L, int i, ElemType e) {
    // 插入位序合法区间是 1..length+1；i = length+1 等价于"在末尾追加"
    if (L == NULL || i < 1 || i > L->length + 1) return false;

    // 先扩容再插入
    if (!SeqList_EnsureCapacity(L, L->length + 1)) return false;
    for (int j = L->length; j >= i; j--) L->data[j] = L->data[j - 1];

    // 对外第 i 个位置 = 内部下标 i - 1
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool SeqList_Delete(SeqList *L, int i, ElemType *e) {
    /* TODO(1): 校验 L != NULL、1 ≤ i ≤ length
     * TODO(2): 若 e != NULL，*e = data[i-1]
     * TODO(3): 下标 j 从 i 递增到 length-1，data[j-1] = data[j]（前移）
     * TODO(4): length-- */
    (void)L;
    (void)i;
    (void)e;
    return false;
}

bool SeqList_Reserve(SeqList *L, int new_capacity) {
    /* TODO(1): 校验 L != NULL、new_capacity ≥ L->length
     * TODO(2): new_capacity 更小时属于缩容，也允许，但要说明是否支持
     * TODO(3): 直接复用 EnsureCapacity 的“分配 + 拷贝 + 释放”逻辑 */
    (void)L;
    (void)new_capacity;
    return false;
}

/* -------------------------------- 遍历 -------------------------------- */

bool SeqList_Traverse(const SeqList *L, VisitFn visit) {
    if (L == NULL || visit == NULL) return false;
    
    for (int j = 0; j < L->length; j++) {
        if (!visit(L->data[j])) return false;
    }
    return true;
}

/* ------------------------------ 扩展操作 ------------------------------ */

bool SeqList_Merge(const SeqList *La, const SeqList *Lb, SeqList *Lc) {
    /* TODO(1): 校验三个指针非空；Lc 已是空表（或先 Clear）
     * TODO(2): SeqList_Reserve(Lc, La->length + Lb->length)
     * TODO(3): i、j 双指针比较，小者先放入 Lc，再把剩余部分整体追加
     * TODO(4): 全程只读 La、Lb */
    (void)La;
    (void)Lb;
    (void)Lc;
    return false;
}

/* ------------------------------ 辅助函数 ------------------------------ */

bool SeqList_Equal(ElemType a, ElemType b) {
    /* TODO: 直接返回 a == b */
    (void)a;
    (void)b;
    return false;
}

void SeqList_Print(const SeqList *L) {
    /* TODO: 打印形如 [1, 2, 3]，空表打印 []，末尾换行 */
    (void)L;
}