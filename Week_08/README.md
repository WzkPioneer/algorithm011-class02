学习笔记

# 学习总结

### 本周内容

#### 位运算
左移 `<<`；右移 `>>`；按位或 `|`；按位与 `&`；按位取反 `~`；按位异或 `^`

##### 异或操作
 - `x^0=x`
 - `x^1s=~x`
 - `x^(~x)=1s`
 - `x^x=0`
 - `c=a^b => a^c=b, b^c=a`
 - `a^b^c=a^(b^c)=(a^b)^c`

##### 指定位置的位运算
1. 将x最右边的n位清零：`x&(~0<<n)`
2. 获取x的第n位值（0或者1）：`(x>>N)&1`
3. 获取x的第n位的幂值：`x&(1<<<n)`
4. 仅将第n位置为1：`x|(1<<n)`
5. 仅将第n位置为0：`x&(~(1<<n))`
6. 将x最高位至第n位（含）清零：`x&((1<<n)-1)`

##### 常见位运算技巧
 - 判断奇偶：`x%2==1 => (x&1)==1`  `x%2==0 => (x&1)==0`
 - `x>>1 => x/2`
 - 清零最低位的1：`x=x&(x-1)`
 - 得到最低位的1：`x&-x`
 - `x&~x=>0`

#### 布隆过滤器（Bloom Filter）

由一个很长的二进制向量和一系列随机映射函数构成，可以用于检索一个元素是否在一个集合中。

优点是空间效率和查询时间都远远超过一般的算法，缺点是有一定的误识别率和删除困难。

#### LRU Cache
 - 两个要素：大小、替换策略
 - Hash Table + Double LinkedList
 - O(1)查询 O(1)修改、更新

#### 排序算法
1. 比较类排序：通过比较来决定元素间的相对次序，由于其时间复杂度不能突破O(nlogn)，因此也称为非线性时间比较类排序。
2. 非比较类排序：不通过比较来决定元素间的相对次序，它可以突破基于比较排序的时间下界，以线性时间运行，因此也称为线性时间非比较类排序。

##### 初级排序
1. 选择排序
```c++
#include<iostream>
using namespace std;
int findSmallest (int[],int);
int main ()
{
	int myarray[10] = {11,5,2,20,42,53,23,34,101,22};	
	int pos,temp,pass=0;
    cout<<"\n Input list of elements to be Sorted\n";
    for(int i=0;i<10;i++)
    {
   		cout<<myarray[i]<<"\t";
    } 
    for(int i=0;i<10;i++)
    {
    	pos = findSmallest (myarray,i);
    	temp = myarray[i];
    	myarray[i]=myarray[pos];
    	myarray[pos] = temp; pass++; 
    }
    cout<<"\n Sorted list of elements is\n";
    for(int i=0;i<10;i++)
    {
    	cout<<myarray[i]<<"\t";
    } 
    cout<<"\nNumber of passes required to sort the array: "<<pass; 
    return 0;
}

int findSmallest(int myarray[],int i)
{
    int ele_small,position,j;
    ele_small = myarray[i];
    position = i;
    for(j=i+1;j<10;j++)
    {
    	if(myarray[j]<ele_small)
    	{
    		ele_small = myarray[j];
    		position=j;
    	}
    }
    return position;
}
```
2. 插入排序
```c++
#include <bits/stdc++.h>
using namespace std;

/* Function to sort an array using insertion sort*/ 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
	{
		key = arr[i];
		j = i - 1;
    	/* Move elements of arr[0..i-1], that are  
    	greater than key, to one position ahead  
    	of their current position */
    	while (j >= 0 && arr[j] > key) 
   	 	{  
        	arr[j + 1] = arr[j];  
        	j = j - 1;  
    	}  
    	arr[j + 1] = key;  
	}  
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    	cout << arr[i] << " ";
    	cout << endl; 
}

/* Driver code */ 
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);  
    printArray(arr, n);  
    
    return ;  
}
```
3. 冒泡排序
```c++
#include <bits/stdc++.h> 
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
    }

/* Function to print an array */ 
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
   	 	cout << arr[i] << " ";
    	cout << endl;
}

// Driver code
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}
```

##### 高级排序
 - 快速排序（Quick Sort）
 - 归并排序（Merge Sort）
    1. 把长度为n的输入序列分成两个长度为n/2的子序列
    2. 对这两个子序列分别采用归并排序
    3. 将两个排序好的子序列合并成一个最终的排序序列

 - 堆排序

##### 特殊排序
  - 计数排序
  - 桶排序
  - 基数排序

