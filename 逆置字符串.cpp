#include <iostream>
#include <string>
using namespace std;


int main()
{
	string str1;
	getline(cin, str1);
	reverse(str1.begin(), str1.end());//���������ַ���
	auto start = str1.begin();//���������ַ���
	while (start != str1.end())//�����ַ���
	{
		auto end = start;//����ָ��ÿ������ĩβ
		while (end != str1.end() && *end != ' ')//ָ�򵥴�ĩβ
			++end;
		reverse(start, end);//���õ�������

		if (end == str1.end())//����start�ƶ�������Խ��
			start = end;
		else
			start = end + 1;
	}
	cout << str1 << endl;
	return 0;
}
