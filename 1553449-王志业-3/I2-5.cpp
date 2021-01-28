#include <stdio.h>  
#include <string.h>  
#include <fstream>
using namespace std;
int cot = 0;
ifstream fin;
ofstream fout;
void swap(char &a, char &b)
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}
int finish(char list[], int k, int i)
{
	if (i>k)
	{
		for (int j = k; j<i; j++)
			if (list[j] == list[i])
				return 0;
	}
	return 1;
}
void perm(char list[], int k, int m)
{
	if (k == m)    
	{
		cot++;
		for (int i = 0; i <= m; i++)
			fout<<list[i];
		fout << endl;
	}
	for (int i = k; i <= m; i++)  
	{
		if (finish(list, k, i))
		{
			swap(list[k], list[i]);
			perm(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}
int main()
{
	int i, n;
	fin.open("input.txt", ios::in);
	fin >> n;
	char *a = new char[n];
	for (i = 0; i < n; i++)
		fin >> a[i];
	fin.close();
	fout.open("output.txt", ios::out);
	perm(a, 0, n - 1);
	fout<<cot;
	return 0;
}