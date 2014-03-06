/*
*����һ����Ŀ�����size��point����һ����size�£������point��
*****0-1��������******
˼·������Value[i_specices][i_size]���ԣ������i_specices ������ �ŵ�i_size ��С�ı����С�
Value[i_specices][i_size]ȡ���ֵʱ���ɷ�Ϊ���������
��һ����i_size�޷�����ȫ���������ֵ��Ӧ��Value[i_specices-1][i_size]��
�ڶ����Ǹպ����������Ӧ��һ������һϵ�иպ������Ŀ����Եļ��ϣ�
���еĿ�������ָ�����Ž����е���Ʒǡ����sizeΪwj����Ʒʱ�����������ﵽ��߼�ֵ��
����ʱ�ı�����ֵ����sizeΪwj��Ʒ�ļ�ֵpj�͵�û�з������Ʒʱ��������߼�ֵ֮�͡�
��Ӧ��Value[i_specices-1][i_size]+pj��

���Ӧ��ȡ����֮�����ֵ��
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SPECICES 100
#define MAX_AREA 100000

int Value[MAX_SPECICES][MAX_AREA];

int i_species; //������Ŀ

int i_area;	//�������


typedef struct
{
	int i_size;
	int i_point;

}ANIMAL;

ANIMAL animals[MAX_SPECICES];



int getResult(ANIMAL animals[],int i_species,int i_area)
{
	int i,j;

	for(i=0; i<=i_species ;++i)
	{
		for(j=0; j<=i_area ;++j)
		{
			Value [i][j] = (i==0 ? 0 :Value [i-1][j]);

			if(i>0 && j>=animals [i-1].i_size )
			{
				if(Value[i][j] < Value [i-1][j-animals [i-1].i_size] +animals [i-1].i_point)
					Value [i][j]=Value [i-1][j-animals [i-1].i_size ] +animals [i-1].i_point;
			}
		}
	}

	return Value [i_species][i_area];
 
}

int main()
{
	int i;
	while(scanf("%d",&i_species)==1)
	{
		for(i=0;i<i_species ;i++)
		{
			scanf ("%d %d",&animals [i].i_size ,&animals [i].i_point );

		}

		scanf ("%d",&i_area);

		if(i_area >MAX_AREA)
		{
			break;
		}

		printf ("%d\n",getResult (animals ,i_species ,i_area ));
	}
	return 0;
}