# SeqList ADT

```
ADT SeqList {

    数据对象：
        D = { a(i) | a(i) ∈ ElemType, i = 1, 2, ..., n, n ≥ 0 }

    数据关系：
        R1 = { <a(i-1), a(i)> | a(i-1), a(i) ∈ D, i = 2, ..., n }
        D 中元素按逻辑次序排成一条线性表：除首元素 a(1) 无直接前驱、
        尾元素 a(n) 无直接后继外，每个元素 a(i)（2 ≤ i ≤ n）有且仅有一个
        直接前驱 a(i-1) 和一个直接后继 a(i+1)。
        物理实现上，元素依逻辑次序连续存放在一段地址连续的存储单元中
        （内部下标 0, 1, ..., n-1），逻辑相邻即物理相邻，故支持按下标随机存取。

    约定
        1. 容量 capacity 为顺序表最多可容纳的元素个数；长度 length 为当前元素个数，
           恒有 0 ≤ length ≤ capacity。
        2. 位置（序号、秩，rank / position）i 从 1 开始计数，与内部数组下标的换算关系为
           “下标 = i - 1”。访问类操作要求 1 ≤ i ≤ length；插入操作合法范围放宽为
           1 ≤ i ≤ length + 1（此时表示追加到表尾）。
        3. 空表：length == 0；表满：length == capacity。有效数据区为下标区间 [0, length-1]。
        4. ElemType 为可赋值、可比较的元素类型；元素之间的比较由 compare 函数给出语义。
        5. 凡返回状态的操作，成功返回 OK / true；失败（越界、表满、空表等）返回
           ERROR / false，且保证原有数据不被破坏。
        6. 按位序取值与置值的时间复杂度为 O(1)；插入、删除需移动元素，
           平均移动 n/2 个元素，时间复杂度为 O(n)。
        7. 存储空间一次性分配，容量不足时按倍增策略（如 2 倍）扩容，
           单次扩容为 O(n)，但均摊代价为 O(1)。

    基本操作：

        SeqList_Init(&L, capacity)
            初始条件：capacity ≥ 0，L 尚未初始化。
            操作结果：构造一个空的顺序表 L，分配 capacity 个元素单元的连续存储空间，
                      置 length = 0、capacity = capacity。

        SeqList_Destroy(&L)
            初始条件：顺序表 L 已存在。
            操作结果：释放 L 所占用的存储空间，L 被销毁，不再可用。

        SeqList_Clear(&L)
            初始条件：顺序表 L 已存在。
            操作结果：删除 L 中的全部元素，置 length = 0，容量 capacity 保持不变。

        SeqList_Length(L)
            初始条件：顺序表 L 已存在。
            操作结果：返回 L 中当前元素的个数 length。

        SeqList_IsEmpty(L)
            初始条件：顺序表 L 已存在。
            操作结果：若 L 为空表（length == 0）则返回 true，否则返回 false。

        SeqList_IsFull(L)
            初始条件：顺序表 L 已存在。
            操作结果：若 L 已满（length == capacity）则返回 true，否则返回 false。

        SeqList_GetElem(L, i, &e)
            初始条件：顺序表 L 已存在且 1 ≤ i ≤ length。
            操作结果：用 e 返回 L 中第 i 个元素的值。

        SeqList_SetElem(&L, i, e)
            初始条件：顺序表 L 已存在且 1 ≤ i ≤ length。
            操作结果：将 L 中第 i 个元素的值置为 e。

        SeqList_LocateElem(L, e, compare, &i)
            初始条件：顺序表 L 已存在，compare 为元素比较函数（缺省为相等比较）。
            操作结果：从表头起查找第一个与 e 满足 compare 关系的元素；
                      若存在，用 i 返回其位序并返回 true；否则置 i = 0 并返回 false。

        SeqList_PriorElem(L, cur_e, &pre_e)
            初始条件：顺序表 L 已存在。
            操作结果：若 cur_e 是 L 中的元素且不是首元素，用 pre_e 返回其直接前驱并返回 true；
                      否则返回 false。

        SeqList_NextElem(L, cur_e, &next_e)
            初始条件：顺序表 L 已存在。
            操作结果：若 cur_e 是 L 中的元素且不是尾元素，用 next_e 返回其直接后继并返回 true；
                      否则返回 false。

        SeqList_Insert(&L, i, e)
            初始条件：顺序表 L 已存在且 1 ≤ i ≤ length + 1。
            操作结果：在 L 的第 i 个位置之前插入新元素 e，表长加 1。
                      若 i = length + 1，则 e 成为新的尾元素；
                      若表已满，则先按倍增策略扩容，再完成插入；
                      原第 i 至第 length 个元素依次后移一个位置。

        SeqList_Delete(&L, i, &e)
            初始条件：顺序表 L 已存在且非空，1 ≤ i ≤ length。
            操作结果：删除 L 的第 i 个元素，用 e 返回其值，表长减 1；
                      原第 i+1 至第 length 个元素依次前移一个位置。

        SeqList_Reserve(&L, new_capacity)
            初始条件：顺序表 L 已存在且 new_capacity ≥ length。
            操作结果：将 L 的容量调整为 new_capacity，原有元素的相对次序保持不变。

        SeqList_Traverse(L, visit)
            初始条件：顺序表 L 已存在，visit 为元素访问函数。
            操作结果：按位序 1 到 length 依次对每个元素调用 visit；
                      若某次调用返回 false，则遍历提前终止并返回 false，否则返回 true。

        SeqList_Merge(La, Lb, &Lc)
            初始条件：有序表 La、Lb 已存在，且元素均按非递减次序排列。
            操作结果：将 La 与 Lb 归并为有序表 Lc，Lc 中元素仍按非递减次序排列，
                      同时 La、Lb 保持原状不变。

} ADT SeqList
```
