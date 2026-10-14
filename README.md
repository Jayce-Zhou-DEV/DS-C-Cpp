# DS-C-Cpp

> 我的数据结构手写练习仓库 · 用 C / C++ 从零实现每一种数据结构，一行一行地敲，而不是复制粘贴。

![Language](https://img.shields.io/badge/language-C%20%2F%20C%2B%2B-blue)
![Status](https://img.shields.io/badge/status-in%20progress-yellow)

这个仓库记录我长期学习数据结构的过程。每种数据结构都拆成 `.h`（接口）+ `.c`（实现）+ 测试代码三部分，
先写接口、再自己填实现、最后用测试用例和内存检查工具验证。

---

## 📌 写在前面

- **手写优先**：所有实现都自己写，不依赖 STL / 第三方库。
- **逐函数推进**：代码里用 `[TODO-n]` 标记"还没填的实现"，用 `[BUG-n]` 标记"已发现、待修复的坑"。
  函数体里暂时 `return ERROR;` 只是占位骨架，随着学习进度会被逐个替换成真正的逻辑。
- **严格编译**：坚持 `-Wall -Wextra` 零警告，用 ASan / valgrind 检查越界和非法访问。

## 📂 目录结构

```text
DS-C-Cpp/
├── main.c            # 测试 / 演示代码的入口
├── SeqList.h         # 顺序表：宏、类型定义、函数声明（不含实现）
├── SeqList.c         # 顺序表：函数实现
├── README.md
└── .gitignore        # 忽略编译产物
```

> 每个数据结构都会独立成一组 `Xxx.h` + `Xxx.c` + 对应测试，互不干扰。

## ✅ 学习进度

| 数据结构 | 文件 | 状态 | 说明 |
| :--- | :--- | :---: | :--- |
| 顺序表 SeqList | `SeqList.h` / `SeqList.c` | 🚧 进行中 | 空壳骨架已搭好，实现待填 |

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

## 🧩 代码约定

| 标记 | 含义 |
| :--- | :--- |
| `[TODO-n]` | 待办编号，与实现文件里的注释一一对应 |
| `[BUG-n]`  | 已确认的缺陷位置 |
| `OK` / `ERROR` | 统一的返回状态码 |
| `ElemType` | 元素类型别名，想换类型只改这一行 |

## 🗺️ 学习路线（Roadmap）

- [x] 顺序表 SeqList（骨架 + 测试）
- [ ] 顺序表 SeqList（补全所有实现）
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

- `SeqList`（无后缀）是编译产物，不应提交到仓库；如已误提交，可加入 `.gitignore` 的"可执行文件"区并 `git rm --cached SeqList`。
- 学习笔记和解题思路会随进度补充到这里。
