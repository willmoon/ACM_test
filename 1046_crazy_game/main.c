/*
*�Ѹ�����һ�������д�С���������ֻ�ܰ����ڵ�������������¼��С����������
*/

#include <stdio.h>
#include <stdlib.h>

//#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}

int num_tests,i;	//test������ÿ��test��������Ŀ
int no[3000];		//�洢ÿ��test������

//��ý�������
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
	//printf ("������Ҫ����test�Ĵ�����\n");
	scanf ("%d",&num_tests);
	while(num_tests-- >0)
	{
		//printf("�������%d��test��������Ŀ��\n",j);
		scanf ("%d",&i);
		//printf("��ֱ������%d��test��%d������\n",j,i);

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