/*
*���⣺��һ������A[]��ʾ�Ĺ�Ʊ��ֵ�У��ҳ�����������У���LIS����
*���鳤��n������100000������Ԫ��ֵ���� long int ��ʾ��
*Ҫ���txt�����������
*/

//�������DP�㷨���
//����d[i]Ϊ�Ե�i������β�����������г���
//��̬����Ϊ��d[i]=max{1,d[j]+1};����0<j<i,A[j]<A[i]
//����DP�㷨����������һ��nlognʱ�临�ӶȵĽⷨ
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