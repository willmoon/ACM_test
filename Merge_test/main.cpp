#include "stdio.h"
#include <iostream>

using namespace std;
//���ж�����������a[first...mid]��a[mid...last]�ϲ���
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= m)
		temp[k++] = a[i++];

	while (j <= n)
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		//int mid = (first + last) / 2;	//�������ܻ����

		//int mid =first/2+last /2;

		int mid = ((first & last) + ((first ^ last) >> 1));

		mergesort(a, first, mid, temp);    //�������
		mergesort(a, mid + 1, last, temp); //�ұ�����
		mergearray(a, first, mid, last, temp); //�ٽ������������кϲ�
	}
}

bool MergeSort(int a[])
{
	auto temp = sizeof(a);
	cout<<"--------"<<temp<<endl;

	//int n=sizeof(a)/sizeof(*a);//�ڴ�ʱ ��nΪ1��a��Ϊ�������βΣ�Ϊָ�����͡�,��Ϊ�βλ��˻����������ڴ���֮ǰ���м���

	int n=15;

	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

int main()
{
	int a[]={7,6,5,4,3,24,5,4,4,444,4565,12,321,65000,33};

	if(MergeSort(a))
	{
		auto temp =sizeof(a);
		cout<<"--------"<<temp<<endl;

		int n=sizeof(a)/sizeof(*a);	//��ʱnΪ11

		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<endl;
		}
	}

	system("PAUSE");
	return 0;
}