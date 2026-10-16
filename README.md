# DS-C-Cpp

> 我的数据结构手写练习仓库 · 用 C / C++ 从零实现每一种数据结构，一行一行地敲，而不是复制粘贴。

![Language](https://img.shields.io/badge/language-C%20%2F%20C%2B%2B-blue)
![Status](https://img.shields.io/badge/status-in%20progress-yellow)

这个仓库记录我长期学习数据结构的过程。每种数据结构都拆成 `.h`（接口）+ `.c`（实现）+ 测试代码三部分，
先写接口、再自己填实现、最后用测试用例和内存检查工具验证。

---

## 📌 写在前面

- **手写优先**：所有实现都自己写，不依赖 STL / 第三方库。
- **逐函数推进**：实现过程中遇到"容易写错的地方"会在代码里用注释标注（先写错误写法，再写正确写法），
  方便日后回看时提醒自己。
- **严格编译**：坚持 `-Wall -Wextra` 零警告，用 ASan / valgrind 检查越界和非法访问。

## 📂 目录结构

```text
DS-C-Cpp/
├── main.c            # 测试 / 演示代码的入口
├── SeqList.h         # 顺序表：类型定义 + 函数声明
├── SeqList.c         # 顺序表：函数实现（动态数组版 SqList）
├── README.md
└── .gitignore        # 忽略编译产物
```

> 每个数据结构都会独立成一组 `Xxx.h` + `Xxx.c` + 对应测试，互不干扰。

## ✅ 学习进度

| 数据结构 | 文件 | 状态 | 说明 |
| :--- | :--- | :---: | :--- |
| 顺序表 SeqList | `SeqList.h` / `SeqList.c` | ✅ 已完成 | 动态数组版 `SqList`，含增删改查 + 内存管理 |

### 顺序表已实现接口

| 函数 | 功能 | 时间复杂度 |
| :--- | :--- | :---: |
| `InitList` | 初始化（`malloc` 分配空间） | O(1) |
| `DestroyList` | 销毁并释放内存 | O(1) |
| `ListInsert` | 按位置插入 | O(n) |
| `ListDelete` | 按位置删除，带回被删元素 | O(n) |
| `ListUpdate` | 按位置修改 | O(1) |
| `GetElem` | 按位取值 | O(1) |
| `LocateElem` | 按值查找，返回 1-based 位置 | O(n) |
| `ListLength` / `ListEmpty` | 求长度 / 判空 | O(1) |
| `TraverseList` | 遍历打印 | O(n) |

## 🔧 编译与运行

以顺序表为例（`SeqList.c` 必须和 `main.c` 一起编译）：

```bash
# 普通编译（开启全部警告）
gcc -Wall -Wextra -g main.c SeqList.c -o seqlist

# 运行
./seqlist
```

### 内存检查（推荐每次实现完都跑一遍）

```bash
# 方式一：AddressSanitizer（快）
gcc -fsanitize=address -g main.c SeqList.c -o seqlist && ./seqlist

# 方式二：valgrind
valgrind --leak-check=full ./seqlist
```

## 🧩 约定与易错点

| 项 | 说明 |
| :--- | :--- |
| 返回值 | 操作类函数统一返回 `bool`：`true` 成功 / `false` 失败 |
| `ElemType` | 元素类型别名，想换类型只改这一行 |
| 下标 | 对外接口用 **1-based** 位置 `i`，内部数组下标 `i - 1` |

实现顺序表时踩过 / 特意规避的坑，记录在代码注释里：

- **`malloc` 要判空**：内存分配失败返回 `NULL`，不检查就直接解引用会崩溃。
- **`free` 后置空指针**：释放后把 `L->data = NULL`，避免二次 `free`（double-free）。
- **出参指针要判 `NULL`**：`GetElem` / `ListDelete` 的 `e` 允许传 `NULL`，写入前先判断。
- **移动元素方向**：插入从后往前搬（防覆盖），删除从前往后搬。

## 🗺️ 学习路线（Roadmap）

- [x] 顺序表 SeqList（动态数组 `SqList`）
- [ ] 单链表 LinkedList
- [ ] 栈 Stack
- [ ] 队列 Queue
- [ ] 串 / KMP
- [ ] 树（二叉树 / 二叉搜索树）
- [ ] 堆 / 优先队列
- [ ] 图（邻接矩阵 / 邻接表）
- [ ] 排序算法
- [ ] 查找算法

## 📝 备注

- 根目录下的 `SeqList`、`main`（无后缀）都是编译产物，不应提交到仓库；
  如已误提交，可加入 `.gitignore` 的"可执行文件"区并 `git rm --cached <文件名>`。
- 学习笔记和解题思路会随进度补充到这里。
