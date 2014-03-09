#include <string>
#include <stdio.h>
#include <stdlib.h>

using std::string;

int main()
{
	string temp = "  hello  world!!!";

	bool flag =false;

	for(auto it =temp.begin();it != temp.end();++it)
	{
		/*if(isspace(*it))
		{
		flag=true;
		continue;
		}

		if(flag||it==temp.begin())
		{
		*it = toupper(*it);
		flag =false;
		}*/

		if(it==temp.begin()||isspace(*(it-1)))//不能为--it，会死循环
		{
			*it = toupper(*it);
		}

	}

	printf(temp.c_str());

	system("PAUSE");

	return 0;
}
