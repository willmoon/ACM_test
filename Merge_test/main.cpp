#include "stdio.h"
#include <iostream>

using namespace std;
//将有二个有序数列a[first...mid]和a[mid...last]合并。
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
		//int mid = (first + last) / 2;	//这样可能会溢出

		//int mid =first/2+last /2;

		int mid = ((first & last) + ((first ^ last) >> 1));

		mergesort(a, first, mid, temp);    //左边有序
		mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}

bool MergeSort(int a[])
{
	auto temp = sizeof(a);
	cout<<"--------"<<temp<<endl;

	//int n=sizeof(a)/sizeof(*a);//在此时 ，n为1：a作为数组名形参，为指针类型。,作为形参会退化，因此最好在传入之前进行计算

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

		int n=sizeof(a)/sizeof(*a);	//此时n为11

		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<endl;
		}
	}

	system("PAUSE");
	return 0;
}