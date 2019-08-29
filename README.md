最大子矩阵和
===========

# 题目
> 已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。 比如，如下4 * 4的矩阵 0 -2 -7 0 9 2 -6 2 -4 1 -4 1 -1 8 0 -2 的最大子矩阵是 9 2 -4 1 -1 8 这个子矩阵的大小是15。

![image](https://github.com/ShaoQiBNU/Maximum_submatrix_sum/blob/master/images/1.jpeg)

## 输入
> 输入是一个N * N的矩阵。输入的第一行给出N (0 < N <= 100)。在后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）给出矩阵中的N2个整数，整数之间由空白字符分隔（空格或者空行）。已知矩阵中整数的范围都在[-127, 127]。

## 输出
> 测试数据可能有多组，对于每组测试数据，输出最大子矩阵的大小。

```shell
输入：

4
0 -2 -7 0
9 2 -6 2
-4 1 -4  1
-1 8  0 -2

输出：

15
```

## 思路

> 此问题是“最大字段和”问题的推广。要求一个二维矩阵的最大子矩阵，首先要会求一维矩阵的最大子矩阵（即一维数组连续最大和）。
> 假设原二维矩阵的最大子矩阵所在的行为i到j，
  当i = j时，则最大子矩阵为第i行的连续最大和
  当i != j时，现在我们已经直到最大子矩阵的行，要求的是其所在的列
  我们把从第i行到第j行的所有行相加，得到一个只有一行的一维数组，则该一维数组的连续最大和就是最大子矩阵。

![image](https://github.com/ShaoQiBNU/Maximum_submatrix_sum/blob/master/images/2.jpeg)

![image](https://github.com/ShaoQiBNU/Maximum_submatrix_sum/blob/master/images/3.jpeg)

> 求一维数组的连续最大和动态规划问题，设DP[i]=以v[i]元素结尾的连续最大和，则DP[i] = max(DP[i-1] + v[i], v[i])，初始条件为DP[0] = v[0]

## 代码
```C++
#include<cstdio>
#include<cstring>

int n;
int a[110][110];
int b[110];

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                scanf("%d",&a[i][j]);

        int Max = -32767;

        // 循环数组的每一个起始行
        for(int i=0; i<n; i++)
        {

            memset(b, 0, sizeof(b));

            // 数组b表示i~j行，对应列元素的和
            // 将二维动态规划问题转化为一维动态规划问题
            for(int j=i; j<n; j++)
            {
                
                int sum=0;

                for(int k=0; k<n; k++)
                {
                   // 对应列元素的和，累加
                    b[k] += a[j][k];

                    // 针对数组b求最大子段和的动态规划算法
                    sum += b[k];

                    if(sum<b[k]) sum = b[k];

                    if(sum>Max) Max = sum;
                }
            }
        }
        
        printf("%d\n",Max);
    }
    return 0;
}
```

