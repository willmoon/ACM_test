/*
*给出一定数目动物的size和point，在一定的size下，求最大point。
*****0-1背包问题******
思路：对于Value[i_specices][i_size]而言，其代表i_specices 个物体 放到i_size 大小的背包中。
Value[i_specices][i_size]取最大值时，可分为两种情况：
第一种是i_size无法被完全填满，最大值对应于Value[i_specices-1][i_size]。
第二种是刚好填满，这对应于一个包含一系列刚好填满的可能性的集合，
其中的可能性是指当最后放进包中的物品恰好是size为wj的物品时背包填满并达到最高价值。
而这时的背包价值等于size为wj物品的价值pj和当没有放入该物品时背包的最高价值之和。
对应于Value[i_specices-1][i_size]+pj。

最后应该取两者之间最大值。
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SPECICES 100
#define MAX_AREA 100000

int Value[MAX_SPECICES][MAX_AREA];

int i_species; //动物数目

int i_area;	//方舟面积


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