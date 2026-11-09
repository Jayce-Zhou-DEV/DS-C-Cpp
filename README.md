# DS-C-Cpp

> 我的数据结构手写练习仓库 · 用 C / C++ 从零实现每一种数据结构。

![Language](https://img.shields.io/badge/language-C%20%2F%20C%2B%2B-blue)
![Status](https://img.shields.io/badge/status-in%20progress-yellow)

这个仓库记录我长期学习数据结构的过程。每种数据结构都拆成 `.h`（接口）+ `.c`（实现）+ 测试代码三部分，
先写接口、再自己填实现、最后用测试用例和内存检查工具验证。

---

## 📌 写在前面

- **手写优先**：所有实现都自己写，不依赖 STL / 第三方库。
- **逐函数推进**：实现过程中遇到"容易写错的地方"会在代码里用注释标注（先写错误写法，再写正确写法），
  方便日后回看时提醒自己。

## 📂 目录结构

```text
DS-C-Cpp/
├── c/                          # C 版实现（按学习顺序编号）
│   ├── 01_SeqList/             # 顺序表（动态数组）
│   ├── 02_LinkedList/          # 链表   👈 下一个
│   │   ├── singly/             #   单链表（不带头结点）
│   │   ├── singly_head/        #   单链表（带头结点 / 哨兵）
│   │   ├── doubly/             #   双链表（head + tail）
│   │   ├── circular_singly/    #   循环单链表（只存 tail）
│   │   ├── circular_doubly/    #   循环双链表（带头结点）
│   │   └── static/             #   静态链表（数组 + 游标）
│   ├── 03_Stack/               # 栈
│   │   ├── sequential/         #   顺序栈
│   │   ├── linked/             #   链栈
│   │   └── shared/             #   共享栈（两栈共享一维数组）
│   ├── 04_Queue/               # 队列
│   │   ├── circular/           #   循环队列（顺序存储）
│   │   ├── linked/             #   链队列
│   │   └── deque/              #   双端队列
│   ├── 05_String/              # 串
│   │   ├── naive/              #   BF 朴素匹配
│   │   ├── kmp/                #   KMP / next 数组
│   │   └── bm/                 #   BM（坏字符 + 好后缀）
│   ├── 06_Tree/                # 树
│   │   ├── binary_tree/        #   二叉树（遍历 / 线索化）
│   │   ├── bst/                #   二叉搜索树
│   │   ├── avl/                #   AVL 平衡树
│   │   ├── b_tree/             #   B 树 / B+ 树
│   │   └── huffman/            #   哈夫曼树与编码
│   ├── 07_Heap/                # 堆（父目录即叶子：小根/大根只差比较方向，不拆）
│   ├── 08_Graph/               # 图
│   │   ├── adj_matrix/         #   邻接矩阵
│   │   ├── adj_list/           #   邻接表
│   │   ├── orth_list/          #   十字链表（有向图）
│   │   └── adj_multi_list/     #   邻接多重表（无向图）
│   ├── 09_Sort/                # 排序
│   │   ├── insert/             #   直接插入
│   │   ├── binary_insert/      #   折半插入
│   │   ├── shell/              #   希尔
│   │   ├── bubble/             #   冒泡
│   │   ├── quick/              #   快速
│   │   ├── select/             #   简单选择
│   │   ├── heap/               #   堆排序
│   │   ├── merge/              #   归并
│   │   ├── radix/              #   基数
│   │   └── counting/           #   计数
│   └── 10_Search/              # 查找
│       ├── sequential/         #   顺序查找
│       ├── binary/             #   折半查找
│       ├── block/              #   分块查找（索引顺序表）
│       └── hash/               #   哈希表
├── cpp/                        # C++ 版，与 c/ 完全同构镜像
├── build/                      # 编译产物（已被 .gitignore 忽略）
├── main.c                      # 临时试验场：随手验证想法，不参与模块编译
├── README.md
└── .gitignore
```

> 规则：
> - **一个数据结构 = 一个目录**，目录内 `Xxx.h` + `Xxx.c` + `test_Xxx.c` 三件套；
> - **变体 = 子目录**：只有“操作语义真的变了”才拆——遍历终止条件不同、能否 O(1) 拿到前驱、
>   内存模型不同，都属于语义变化，应独立成目录（如 `02_LinkedList` 的六个子目录）；
>   仅改元素类型、加个辅助函数这类变化，不新建目录；
> - **编号即学习顺序**，照着 01 → 10 推进，不需要每次重新决定学什么；
> - 编译产物一律丢进 `build/`，源码目录保持干净。

## ✅ 学习进度


## 🗺️ 学习路线（照着目录编号推进）

- [ ] `01_SeqList` 顺序表 SeqList（动态数组 `SqList`）👈 **下一个学这个**
- [ ] `02_LinkedList` 链表 LinkedList
  - [ ] `singly` 单链表（不带头结点）
  - [ ] `singly_head` 单链表（带头结点 / 哨兵）
  - [ ] `doubly` 双链表（head + tail，已知结点 O(1) 删除）
  - [ ] `circular_singly` 循环单链表（只存 tail）
  - [ ] `circular_doubly` 循环双链表（带头结点）
  - [ ] `static` 静态链表（数组 + 游标）
- [ ] `03_Stack` 栈 Stack
  - [ ] `sequential` 顺序栈
  - [ ] `linked` 链栈
  - [ ] `shared` 共享栈
- [ ] `04_Queue` 队列 Queue
  - [ ] `circular` 循环队列
  - [ ] `linked` 链队列
  - [ ] `deque` 双端队列
- [ ] `05_String` 串
  - [ ] `naive` BF 朴素匹配
  - [ ] `kmp` KMP
  - [ ] `bm` BM
- [ ] `06_Tree` 树
  - [ ] `binary_tree` 二叉树（遍历 / 线索化）
  - [ ] `bst` 二叉搜索树
  - [ ] `avl` AVL 平衡树
  - [ ] `b_tree` B 树 / B+ 树
  - [ ] `huffman` 哈夫曼树
- [ ] `07_Heap` 堆（单目录，不拆）
- [ ] `08_Graph` 图
  - [ ] `adj_matrix` 邻接矩阵
  - [ ] `adj_list` 邻接表
  - [ ] `orth_list` 十字链表
  - [ ] `adj_multi_list` 邻接多重表
- [ ] `09_Sort` 排序
  - [ ] `insert` / `binary_insert` / `shell`
  - [ ] `bubble` / `quick` / `select`
  - [ ] `heap` / `merge` / `radix` / `counting`
- [ ] `10_Search` 查找
  - [ ] `sequential` 顺序查找
  - [ ] `binary` 折半查找
  - [ ] `block` 分块查找
  - [ ] `hash` 哈希表

## 命名约定
两条硬约定（因为各目录不共享头文件，必须靠纪律保证可组合）：

- **函数名带结构前缀**：`SinglyList_Insert` / `DList_Insert` / `CSList_Insert`，避免以后把多个结构链接进同一个程序时符号冲突；
- **返回值统一**：返回 `bool` 的成功 `true` / 失败 `false`；返回 `int` 的成功 `0` / 失败负值，并在各自头文件顶部注明。

## 📝 备注

- 编译产物统一生成在 `build/` 下（`.gitignore` 已忽略），不要提交到仓库；
  如已误提交，可加入 `.gitignore` 的"可执行文件"区并 `git rm --cached <文件名>`。
- 学习笔记和解题思路会随进度补充到这里。