/*动态规划算法（全局最优解包含局部最优解）
*问题：一个序列有n个数：A[1],A[2],A[3],...,A[N],求出最长
*非降子序列的长度。
*/
//reference link:http://hawstein.com/posts/dp-novice-to-advanced.html

//一、定义d(i)状态,表示前i个数中以A[i]结尾的最长非降子序列的长度。
//二、状态转移方程？？？？
//要想求d(i)，就把i前面的各个子序列中，最后一个数不大于A[i]的序列长度加1，
//，然后取出最大的长度即为d(i),当然，如果各个子序列最后一个数都大于A[i],
//那么d[i]=1,即它自身成为一个长度为1的子序列。
//状态转移方程：d(i)=max{1,d(j)+1},其中0<j<i,A[j]<=A[i].
#include <iostream>
using namespace std;

int list(int A[],int n)
{
	//5,3,12,121,1,2,345,22,545
	int *d = new int[n];
	int len =1;
	for(int i=0;i<n;++i)
	{
		d[i] =1;	//置为上式中的1

		for (int j=0;j<i;++j)
		{
			if(A[j]<=A[i]&&d[j]+1>d[i])
			{
				d[i] = d[j] +1;//置为上式中的d[j] +1
			}
		}

		if(d[i]>len)
			len=d[i];
	}

	delete[] d;

	return len;
}

int main()
{
	int a[]={5,3,12,121,1,2,345,22,545};

	int n=sizeof(a)/sizeof(*a);

	cout<<list(a,n)<<endl;

	system("PAUSE");

	return 0;
}