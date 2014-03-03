/*
*给出一定数目动物的size和point，在一定的size下，求最大point。
*/

#include <stdio.h>
#include <stdlib.h>

int i_species; //动物数目

int i_area;	//方舟面积

typedef struct
{
	int i_size;
	int i_point;

	float f_pps;
}ANIMAL;

ANIMAL animals[100];


//把动物按pps（point per size）从小到大排序
void sort(ANIMAL animals[],int i_species)
{
	int m,n;
	ANIMAL tem;
	for(n=i_species-1;n>0;n--)
	{
		for(m=0;m<n;m++)
		{
			if (animals[m].f_pps >animals[m+1].f_pps )
			{
				tem=animals[m+1];
				animals[m+1]=animals[m];
				animals[m]=tem;
			}
		}
	}
}



int getResult(ANIMAL animals[],int i_species,int i_area)
{
	int i;

	int total_area =0;
	int total_point =0;

	for(i=i_species-1;i>=0;i--)
	{
		if((total_area +=animals [i].i_size )<=i_area )
		{
			total_point +=animals [i].i_point ;
		}
		else
		{
			total_area -=animals [i].i_size ;
		}
	}

	if(i_area >total_area)
	{
		
	}
	else
	{
		return total_point ;
	}
}

int main()
{
	int i;
	while(scanf("%d",&i_species)==1)
	{
		for(i=0;i<i_species ;i++)
		{
			scanf ("%d%d",&animals [i].i_size ,&animals [i].i_point );
			animals [i].f_pps =(animals [i].i_point +0.0)/animals [i].i_size ;

		}

		scanf ("%d",&i_area);

		if(i_area >100000)
		{
			break;
		}

		sort (animals ,i_species);

		printf ("%d",getResult (animals ,i_species ,i_area ));
	}
	return 0;
}