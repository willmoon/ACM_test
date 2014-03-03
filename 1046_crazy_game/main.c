/*
*把给定的一列数进行从小到大的排序（只能把相邻的数交换），记录最小交换次数。
*/

#include <stdio.h>
#include <stdlib.h>

//#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

int num_tests,i;	//test次数、每个test的数的数目
int no[3000];		//存储每次test的数列

//获得交换次数
int sort(int no[],int len)
{
	int tem,m,n;

	int result =0;

	for(n=len-1;n>0;n--)
	{
		for(m=0;m<n;m++)
		{
			if (no[m]>no[m+1])
			{
				tem=no[m+1];
				no[m+1]=no[m];
				no[m]=tem;

				result ++;
			}
		}
	}

	return result ;

}

int main()
{
	int j=1;
	int m;
	//printf ("请输入要进行test的次数：\n");
	scanf ("%d",&num_tests);
	while(num_tests-- >0)
	{
		//printf("请输入第%d次test的数的数目：\n",j);
		scanf ("%d",&i);
		//printf("请分别输入第%d次test的%d个数：\n",j,i);

		for(m=0;m<i;m++)
		{
			scanf ("%d",&no[m]);
		}

		printf("%d\n",sort (no,i));

		j++;
	}

	//system ("PAUSE");

	return 0;
}