/*
*翻转c风格的字符串
*/
#include <iostream>
#include <cstring>

using namespace std;

void swap(char &a,char &b)
{
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse1(char *s)
{
	if(!s) return;

	char *p =s,*q=s;

	while(*q) ++q;

	--q;//
	while(p<q)
		swap(*p++,*q--);
}

void reverse2(char *s)
{
	int n =strlen(s);

	for(int i=0;i<n/2;++i)
	{
		swap(s[i],s[n-i-1]);
	}
}

int main()
{
	char s[]="12345678346325";
	reverse1(s);
	cout <<s<<endl;

	system("PAUSE");
	return 0;
}