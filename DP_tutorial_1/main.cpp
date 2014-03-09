/*��̬�滮�㷨��ȫ�����Ž�����ֲ����Ž⣩
*���⣺һ��������n������A[1],A[2],A[3],...,A[N],����
*�ǽ������еĳ��ȡ�
*/
//reference link:http://hawstein.com/posts/dp-novice-to-advanced.html

//һ������d(i)״̬,��ʾǰi��������A[i]��β����ǽ������еĳ��ȡ�
//����״̬ת�Ʒ��̣�������
//Ҫ����d(i)���Ͱ�iǰ��ĸ����������У����һ����������A[i]�����г��ȼ�1��
//��Ȼ��ȡ�����ĳ��ȼ�Ϊd(i),��Ȼ������������������һ����������A[i],
//��ôd[i]=1,���������Ϊһ������Ϊ1�������С�
//״̬ת�Ʒ��̣�d(i)=max{1,d(j)+1},����0<j<i,A[j]<=A[i].
#include <iostream>
using namespace std;

int list(int A[],int n)
{
	//5,3,12,121,1,2,345,22,545
	int *d = new int[n];
	int len =1;
	for(int i=0;i<n;++i)
	{
		d[i] =1;	//��Ϊ��ʽ�е�1

		for (int j=0;j<i;++j)
		{
			if(A[j]<=A[i]&&d[j]+1>d[i])
			{
				d[i] = d[j] +1;//��Ϊ��ʽ�е�d[j] +1
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