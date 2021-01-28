#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;
ofstream fout;


class set {
	friend set setsum(int n, int* x, int c);
public:
	int Bound(int i);
	void Backtrack(int i);
	void Print();
private:
	int c;//要求的数
	int n;//集合元素的个数
	int *num;//集合元素数组
	int *pans;//当前的答案
	int **ans;//答案二维数组
	int psum;//当前和
	int ansnum;//当前答案数
};

int set::Bound(int i)
{
	int b = psum;
	while (i <= n)
	{
		b += num[i];
		i++;
	}
	return b;
}

void set::Print()
{
	for (int i = 0; i < ansnum; i++)
	{
		for (int j = 1; j <= n; j++)
			if(ans[i][j]==1)
				fout << num[j] << " ";
		fout << endl;
	}
}
set setsum(int n, int *x, int c)
{
	set K;
	K.ansnum = 0;
	K.c = c;
	K.n = n;
	K.num = x;
	K.pans = new int[n + 1];
	K.ans = NULL;
	for (int j = 1; j <= n; j++)
		K.pans[j] = 0;
	K.psum = 0;
	K.Backtrack(1);
	delete[]K.pans;
	
	//cout << K.ansnum;
	
	return K;
}
void set::Backtrack(int i)
{
	if (i > n||psum==c) {
		if (psum == c)
		{
			
			ansnum++;
			int **temp=ans;
			ans = new int*[ansnum];
			for (int j = 0; j < ansnum-1; j++)
			{
				ans[j] = new int[n + 1];
				memcpy(ans[j], temp[j], sizeof(int)*(n + 1));
			}
			ans[ansnum - 1] = new int[n + 1];
			for (int j = 1; j <= n; j++)
				ans[ansnum-1][j] = pans[j];
			for (int j = 0; j < ansnum - 1; j++)
				delete[] temp[j];
			if(temp)
				delete[] temp;
			
		}
		return;
	}
	if (psum + num[i] <= c) {
		psum += num[i];
		pans[i] = 1;
		Backtrack(i + 1);
		psum -= num[i];
		pans[i] = 0;
	}
	if (Bound(i + 1) >= c)
	{
		pans[i] = 0;
		Backtrack(i + 1);
		
	}
		
}

int main()
{
	fin.open("input.txt", ios::in);
	fout.open("output.txt", ios::out);
	int n, *x, c;
	fin >> n >> c;
	x = new int[n + 1];
	for (int i = 1; i <= n; i++)
		fin >> x[i];
	set K;
	K = setsum(n, x, c);
	K.Print();
	
	return 0;
}