/*
*�����ַ����г��ֵ���ͬ�ַ���
*
*/
#include <iostream>
#include <cstring>
using namespace std;

//����������ڿ�һ�����飬ֻ������forѭ��,���������֮ǰ�����顣
void removeDuplicate1(char s[])
{
	int len = strlen(s);
	if(len<2) 
		return ;

	int p=0;
	for(int i=0;i<len;++i)
	{
		if(s[i]!=0)
		{
			s[p++] =s[i];	//��Ϊ������ʹ����������ռ䡣
			for(int j=i+1;j<len;++j)
			{
				if(s[j]== s[i])
				{
					s[j] ='\0'; //�����ͬ������Ϊ��/0��
				}
			}
		}
		s[p] ='\0'; //�������ĩβ��Ϊ��/0��
	}

}

/*
*������Կ�һ���������ģ�޹ص����飬��ô������һ������������ÿ���ַ��ĳ��֣�������ASCII�룬
�������СΪ256����������ֻ����һ���ַ���
*/

void removeDuplicate2(char s[])
{
	int len =strlen(s);

	if(len<2)
		return;

	bool c[256];
	memset(c,0,sizeof (c));

	int p=0;
	for(int i=0;i<len;++i)
	{
		if(!c[s[i]])
		{
			s[p++]=s[i];
			c[s[i]] =true;
		}
	}

	s[p] ='/0';
}

/*
����ַ�����С������ֻ��a-z�����ַ���ֻ����Сд��ĸ����ô
����ʹ��int�����е�ÿһλ��������ĸ�ĳ���
*/

void removeDeplicate3(char s[])
{
	int len =strlen(s);

	if(len<2)
		return;

	int check =0,p=0;

	for(int i=0;i<len;++i)
	{
		int v =(int)(s[i]-'a');
		if((check &(1<<v))==0)	//1����vλ��������򣬴Ӷ������Ӧλ��
		{
			s[p++]=s[i];
			check |=(1<<v);		//��Ӧ�Ķ�����λ��Ϊ1
		}
	}
	s[p]='/0';
}

int main()
{
	char s1[] ="abbsasczxzxzzzzxcde";
	char s2 []="aaabbb";
	char s3 []="";
	char s4 []="abababbbascasc";
	char s5 []="121112c1w12901 ";
	removeDuplicate1(s4);
	printf(s4);

	system("PAUSE");

	return 0;

}