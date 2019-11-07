#include <iostream>
#include <vector>
using namespace std;

bool JudgeAdd(vector<int> v)//判断是否为递增序列
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] >= v[i + 1])
		{
			return false;
		}
	}
	return true;
}
bool JudgeSub(vector<int> v)//判断是否为递减序列
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		if (v[i] <= v[i + 1])
		{
			return false;
		}
	}
	return true;
}
int Divide(vector<int> &v,int n)//划分子序列
{
	int mid = n / 2;
	int flag = 0;
	int left = 0;
	int right = n - 1;
	vector<int>::iterator vi = v.begin();
	vector<int> v1(vi, vi + mid - 1);
	vector<int> v2(vi + mid, vi + n - 1);
	if (((!JudgeAdd(v1)) || (!JudgeSub(v1))) && ((!JudgeAdd(v2)) || (!JudgeSub(v2))))
	{
		flag += 2;
	}
	else if (!(!JudgeAdd(v1) || !JudgeSub(v1)))
	{
		Divide(v1,v1.size());
	}
	else if (!(!JudgeAdd(v2) || !JudgeSub(v2)))
	{
		Divide(v2, v2.size());
	}
	return flag;
}

int main1()
{
	vector<int> v;
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		v.push_back(m);
	}
	int flag = Divide(v,n);
	cout << flag;
	return 0;
}