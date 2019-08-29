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