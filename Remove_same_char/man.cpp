/*
*消除字符串中出现的相同字符。
*
*/
#include <iostream>
#include <cstring>
using namespace std;

//如果不允许在开一个数组，只能两次for循环,最后结果存在之前的数组。
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
			s[p++] =s[i];	//因为不允许使用另外数组空间。
			for(int j=i+1;j<len;++j)
			{
				if(s[j]== s[i])
				{
					s[j] ='\0'; //如果相同，则置为‘/0’
				}
			}
		}
		s[p] ='\0'; //最后数组末尾置为‘/0’
	}

}

/*
*如果可以开一个与问题规模无关的数组，那么可以用一个数组来表征每个字符的出现（假设是ASCII码，
则数组大小为256，这样即可只遍历一遍字符）
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
如果字符集更小，比如只是a-z，即字符串只包含小写字母，那么
可以使用int变量中的每一位来表征字母的出现
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
		if((check &(1<<v))==0)	//1左移v位，进行异或，从而标记相应位。
		{
			s[p++]=s[i];
			check |=(1<<v);		//相应的二进制位置为1
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