学习笔记

# 一、哈希表

​		对于哈希表这个数据结构，C++提供了两种实现：map和unordered_map，都可以充当字典的功能。

## 		1、map

​		对于map而言，其查询、插入、删除操作的时间复杂度都是O(logn)。此外，map的key需要定义operator <，对于一般的数据类型已被系统实现，若是用户自定义的数据类型，则要重新定义该操作符。

## 		2、unordered_map

​		unordered_map和map类似，都是存储的key-value的值，可以通过key快速索引到value。不同的是unordered_map不会根据key的大小进行排序，存储时是根据key的hash值判断元素是否相同，即unordered_map内部元素是无序的。unordered_map的底层是一个防冗余的哈希表（开链法避免地址冲突）。unordered_map的key需要定义hash_value函数并且重载operator ==

​		哈希表最大的优点，就是把数据的存储和查找消耗的时间大大降低，时间复杂度为O(1)；而代价仅仅是消耗比较多的内存。哈希表的查询时间虽然是O(1)，但是并不是unordered_map查询时间一定比map短，因为实际情况中还要考虑到数据量，而且unordered_map的hash函数的构造速度也没那么快，所以不能一概而论，应该具体情况具体分析。

# 二、树、二叉树、二叉搜索树、堆

​		对于二叉树这种数据结构非常常见，比如我们电脑的文件系统，就是一种树形结构。二叉树的常见面试题，有基本的四种遍历、对于二叉树的各种操作等。一般而言，二叉树的四种遍历的时间复杂度是O(n)级，n为二叉树的节点个数，因为所以遍历都是只访问节点一遍。

## 		1、二叉树的前序、层序遍历

我们首先来实现前序遍历，中序和后序用的是类似的思想，不再赘述

```c++
void preTra(TreeNode* root)
{
    if(root)
    {
        cout<<root->val<<endl;     //第一个访问节点数据
        preTra(root->left);
        preTra(root->right);
    }
}
```

再来看看层序的code:

```c++
void levleTra(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* now=q.front();
        q.pop();
        cout<<now->val<<endl;
        q.push(now->left);
        q.push(now->right);
    }
}
```



## 		2、二叉树遍历的非递归的实现

主要的思路就是模拟递归，用栈来做辅助，先写一个前序遍历的code:

```C++
void preTra(TreeNode* root)
{
    stack<TreeNode*> stack;
    stack.push(root);
    while(!stack.empty())
    {
        while(root)
        {
            cout<<root->val<<endl;
            stack.push(root->left);
            root=root->left;
        }
        stack.pop();
        stack.push(root->right);
    }
}
```

## 3、二叉堆

对于堆这种数据结构，跟内存中的堆不是一个概念，这里的堆是一个完全二叉树，并且其特性有两种：

大顶堆、小顶堆。C++对于堆的实现是priority_queue，优先队列这种容器。当然响应的优先队列队首则为队列的最大值或者最小值，对于每次插入元素或者做了改动，其会自动调整堆的结构，来满足堆的特性。声明如下:

```c++
priority_queue<typename > name;
```

对于常见操作的时间复杂度:

1、push()

入队的操作，时间复杂度是O(logN)

2、top()

获取队首的值，时间复杂度是O(1)

3、pop()

出队的操作，时间复杂度是O(logN)

总结：二叉堆经常见于求取TopK元素类型的题目，或者动态获取区间最值的题目。