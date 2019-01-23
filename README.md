## 数据结构
数据结构是对实际问题中的数据元素及相互间的联系的抽象。一般用线性表来表示常用数据结构，线性表分为顺序存储的顺序表和连式存储的链表。
#### 常用数据结构
在学习算法之前，必须要了解一些常用数据结构的概念。
* 栈：一种特殊串联形式的抽象数据类型，可由链表或数组实现，通过链表或数组的栈顶（Top）指针对数据进行压栈（Push）和出栈（Pop）操作，其特点是LIFO。
* 队列：先进先出（FIFO）的线性表，一般用链表和数组来实现，只允许在后端（back or rear）插入，在前端（front）删除。
* 数组：由相同元素的集合所组成的数据结构，存储在一块连续的内存单元，根据元素的索引可以计算出该元素对应的存储地址。
    
* 链表：由一连串节点组成，每个节点包含任意的实例数据和一个或两个用来指向下一个/上一个节点位置的链接。
* 树：实现抽象数据类型的数据结构，如：二叉树、霍夫曼树。
* 图：表示物件与物件之间的关系，图论的基本研究对象。
* 堆：是计算机科学中一种特别的树状数据结构，也是一种特殊的二叉树。
* 散列表：根据键（key）直接访问内存存储位置的一种数据结构，通过计算一个关于键值的函数，将所需查询的数据映射到表中的一个位置来访问记录，映射函数叫做散列函数，存放记录的数组叫散列表（散列函数和哈希冲突是实现散列表最重要的两个环节）。

## 算法
所谓算法，就是解决问题方案的准确而完整的描述。
#### 运算操作
为了完成各种运算，计算机提供了一套最基本的功能操作：
1. 算术运算：加、减、乘、除；
2. 逻辑运算：与、或、非；
3. 比较运算：大于，小于，等于，不等于；
4. 数据转送：输入、输出，赋值。

#### 算法分析的重要指标
1. 时间复杂度：指算法运行所需要的时间，即算法的时间代价。
2. 空间复杂度：对一个算法在运行过程中所需要的辅助存储空间大小的度量。


## 算法面试题
介绍完理论，可以开始实践了，以下算法题目有很多可以在剑指Offer一书中找到，此文以及所涉及的题目仅供参考，不同的题目有不同的解答方式，切勿死记，一定要基于空间复杂度和时间复杂度再选择对应的算法。

#### 算术运算题
1. 质数
2. 丑数
3. 斐波那契数列

#### 排序
1. 冒泡排序（平均复杂度 O(n^2) 且稳定）
2. 选择排序（平均复杂度 O(n^2) 且稳定）
3. 插入排序（平均复杂度 O(n^2) 且稳定）
4. 快速排序（平均复杂度 O(nlogn) 不稳定）
        
#### 查找
1. 二分法（折半查找，平均复杂度O(logn)）

#### 字符串
1. 字符串翻转
2. 字符串转数字
3. 字符串替换
    
#### 数组
1. 找出重复的数
2. 二维数组的查找
3. 旋转数组中最小的数
4. 数组中出现超过一半的数字
5. 数组中第K大的数
6. 有序数组中某个数出现的次数
7. 调整奇数位位于偶数位前面
#### 链表
1. 删除指定节点
2. 删除重复节点
3. 倒数第K个节点
4. 中间节点
5. 入口节点
6. 翻转链表
7. 合并两个链表
8. 两个链表的首个公共节点
#### 树
1. 前序遍历（递归和非递归）
2. 中序遍历（递归和非递归）
3. 后序遍历（递归和非递归）
4. 根据前序和中序构建二叉树
5. 根据中序和后序构建二叉树
6. 中序遍历的下一个节点
7. 翻转二叉树
8.树的深度
9. 根据中序遍历判断是否是二叉搜索树（BST：Binary Search Tree）
10. 从上到下打印二叉树
    
## 总结
对于从事编程工作的朋友来说，数据结构与算法是编程的基础，也是很多大厂面试的必考题，熟悉算法不仅仅是为了应付面试，算法题巧妙的解决思路有助于帮助我们提高代码的执行效率和丰富解决问题的思路，实乃防治老年痴呆必备之良药，望按需取之，另：各位若有更好的解决思路，欢迎一起学习交流。
- - - 
PS：此文给出的参考代码，不一定是最佳的答案，且以上代码都是基于Xcode环境编写，并提供了一些简单的test case，没有完全覆盖，需注意。若发现有任何Bug，可通过新浪微博“Joelixy_”和GitHub及时与我联系，我会在第一时间修正，喜欢的话请给个star，谢谢！

