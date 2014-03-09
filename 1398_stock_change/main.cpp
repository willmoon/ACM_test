/*
*问题：在一个数组A[]表示的股票数值中，找出最长递增子序列，即LIS问题
*数组长度n不超过100000，数组元素值可用 long int 表示。
*要求从txt读入测试用例
*/

//该题可用DP算法解决
//定义d[i]为以第i个数结尾的最大递增序列长度
//则动态方程为：d[i]=max{1,d[j]+1};其中0<j<i,A[j]<A[i]
//除了DP算法，还可以用一个nlogn时间复杂度的解法
//link:http://www.felix021.com/blog/read.php?1587

#include <iostream>

using namespace std;

long list(long A[],long n)
{
	//2,1,232,23,1,2334354,221,12,
	long* d=new long[n];

	long len =1;

	for(long i=0;i<n;++i)
	{
		d[i]=1;

		for(long j=0;j<i;++j)
		{
			if(A[j]<A[i]&&d[j]+1>d[i])
			{
				d[i]=d[j]+1;
			}
		}

		if(len <d[i])
			len =d[i];
	}

	delete[] d;

	return len;
}

int main()
{
	long a[]={2,1,232,23,1,2334354,221,12};
	long n =sizeof(a)/sizeof(*a);

	cout <<list(a,n)<<endl;

	system("PAUSE");
	return 0;
}