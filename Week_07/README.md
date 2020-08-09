学习笔记

本周学习了一些高级数据结构和算法思想比如剪枝思想

字典树

对于字典树而言，思路比较好懂，就是在一颗树上的路径是26个字母，在建树的过程中每个节点有可能都是26个字母，对于commit这个词，第一次搜索的时候就能查到c开头的后面26个可能情况，往复这个思想。就能以0(logn)级复杂度实时查找可能的字符

并查集

并查集的策略也很好理解，建构过程如下：

```c++
 int findFather(int n)    //经过优化的查找，
    {
        if(n==father[n]) return n;
        else 
        {
            int fa=findFather(father[n]);
            father[n]=fa;
            return fa;
        }
    }

    void Unin(int a,int b)
    {
        int fa_a=findFather(a);
        int fa_b=findFather(b);
        if(fa_a!=fa_b)
        {
            father[fa_a]=fa_b;
        }
    }    
```

高级搜索

这是一种思想，更多的是剪枝，看情况。比如如果答案在浅层的树节点，而我们用DFS，很有可能在前期查找了很深的节点而没有正确答案。我们可以优化这个过程。

红黑树和AVL树

都是对树操作的优化，AVL树是平衡二叉查找树，为了优化二叉查找树，省得出现极端情况导致树退化成链表

红黑树的增删改查都是O(logn)