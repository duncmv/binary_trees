# 0x1D. C - Binary trees

> This project was on ...
`C`
`Group project
Algorithm`
`Data structure`

## Background Context

- A binary tree is a tree data structure in which each node can have at most two children, known as the left child and the right child. These children are ordered; the left child is typically smaller than the parent, and the right child is typically larger.
- Binary trees are commonly used for implementing binary search trees, expression trees, and in many algorithms such as binary tree traversals (inorder, preorder, postorder), binary tree searches, and balancing algorithms like AVL trees and Red-Black trees.

### Full Binary Tree

- A full binary tree is a type of binary tree in which every node has either zero or two children. In other words, every internal node (non-leaf node) has exactly two children.
- The leaves of a full binary tree are at the same level, meaning all paths from the root to the leaves have the same length.
- Full binary trees are commonly used in tree-based data structures and algorithms. They provide efficient storage and retrieval of data.

```markdown
     1
   /   \
  2     3
 / \   / \
4   5 6   7
```

#### Non-Full Binary Tree

```markdown
     1
   /   \
  2     3
 / \     \
4   5     6
```

### Complete Binary Tree

- A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.
- The last level of a complete binary tree is filled from left to right without any gaps.
- Complete binary trees are used in heap data structures, particularly in binary heaps, because they provide efficient access and storage. They are also used in Huffman coding, priority queues, and other applications.

```markdown
        1
       / \
      2   3
     / \ /
    4  5 6

```

### Perfect Binary Tree

- Here, each node has exactly two or zero children
- Internal nodes (i.e non-leaf nodes) have exactly two children
- All leaf nodes (external nodes) are at the same level or depth.
- A perfect binary tree combines the properties of both full and complete binary trees together.
- Perfect binary trees are balanced by definition, meaning the height of the tree is logarithmic with respect to the number of nodes. This property makes them efficient for searching and other operations.

```maths
num_of_nodes = 2^(height + 1) - 1
```

```markdown
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  / \
 8   9

        5
       / \
      3   7
     / \ / \
    1  4 6  9
   /
  0

```

### I learnt about

- What is a binary tree
- What is the difference between a binary tree and a Binary Search Tree
- What is the possible gain in terms of time complexity compared to linked lists
- What are the depth, the height, the size of a binary tree
- What are the different traversal methods to go through a binary tree
- What is a complete, a full, a perfect, a balanced binary tree

## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A `README.md` file, at the root of the folder of the project, is mandatory
- Your code should use the `Betty` style. It will be checked using `betty-style.pl` and `betty-doc.pl`
- You are not allowed to use global variables
- No more than 5 functions per file
- You are allowed to use the standard library
- In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called `binary_trees.h`
- Don’t forget to push your header file
- All your header files should be include guarded

### GitHub

**There should be one project repository per group. If you clone/fork/whatever a project repository with the same name before the second deadline, you risk a 0% score.**

## More Info

### Data structures

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

#### Basic Binary Tree

```C
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
```

#### Binary Search Tree

```C
typedef struct binary_tree_s bst_t;
```

#### AVL Tree

```C
typedef struct binary_tree_s avl_t;
```

#### Max Binary Heap

```C
typedef struct binary_tree_s heap_t;
```

**Note**: For tasks 0 to 23 (included), you have to deal with simple binary trees. They are not BSTs, thus they don’t follow any kind of rule

### Print function

To match the examples in the tasks, you are given [this function](https://github.com/alx-tools/0x1C.c)

This function is used only for visualization purposes. You don’t have to push it to your repo. It may not be used during the correction

## Environment

- Language: C
- OS: Ubuntu 20.04 LTS
- Compiler: gcc 9.3.0
- Style guidelines: [Betty and Betty Docs](https://github.com/alx-tools/Betty)

## Files

- 0-binary_tree_node.c
- 1-binary_tree_insert_left.c
- 2-binary_tree_insert_right.c
- 3-binary_tree_delete.c
- 4-binary_tree_is_leaf.c
- 5-binary_tree_is_root.c
- 6-binary_tree_preorder.c
- 7-binary_tree_inorder.c
- 8-binary_tree_postorder.c
- 9-binary_tree_height.c
- 10-binary_tree_depth.c
- 11-binary_tree_size.c
- 12-binary_tree_leaves.c
- 13-binary_tree_nodes.c
- 14-binary_tree_balance.c
- 15-binary_tree_is_full.c
- 16-binary_tree_is_perfect.c
- 17-binary_tree_sibling.c
- 18-binary_tree_uncle.c

> Each file contains the solution to a task in the project.

<!-- markdownlint-disable-next-line -->
#### Credits

Work is owned and maintained by [Duncan T. Asiimwe](https://github.com/duncmv) and [Michael C. Iyke](https://github.com/michaeliyke).

## Acknowledgement

All work contained in this project was completed as part of the curriculum for Alx. ALX is a leading technology training provider, built to accelerate the careers of young Africans through the technology and professional skills that enable them to thrive in the digital economy. The program prepares students for careers in the tech industry using project-based peer learning. For more information, [visit](https://www.alxafrica.com/).
