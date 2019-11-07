#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str1;
	getline(cin, str1);
	reverse(str1.begin(), str1.end());//逆置整个字符串
	auto start = str1.begin();//用来遍历字符串
	while (start != str1.end())//遍历字符串
	{
		auto end = start;//用来指向每个单词末尾
		while (end != str1.end() && *end != ' ')//指向单词末尾
			++end;
		reverse(start, end);//逆置单个单词

		if (end == str1.end())//控制start移动，避免越界
			start = end;
		else
			start = end + 1;
	}
	cout << str1 << endl;
	return 0;
}
