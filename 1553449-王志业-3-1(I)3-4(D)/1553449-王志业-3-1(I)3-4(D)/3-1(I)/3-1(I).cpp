#include "iostream"
#include "stdio.h"  
#include "string.h"  
#include "fstream"
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
int missionArrange(int *a, int *b, int n)
{
	int ta=0, ans, i, k;
	int *T;
	for (i = 1; i <= n; i++) 
		ta += a[i];
	T = new int[ta + 1];
	for (i = 0; i <= ta; i++)
		T[i] = 0;
	for (k = 1; k <= n; k++)
		for (i = ta; i >= 0; i--)
			if (i >= a[k])
				T[i] = min(T[i - a[k]], T[i] + b[k]);
			else
				T[i] = T[i] + b[k];
	for (i = 0; i <= ta; i++)
		cout << T[i] << " ";
	ans = 0X7FFFFFFF;
	for (i = 0; i <= ta; i++)
		ans = min(ans, max(i, T[i]));
	cout << ans;
	return ans;
	
}

int main()
{
	int i;
	int *a, *b, n;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt", ios::in);
	fout.open("output.txt", ios::out);
	fin >> n;
	a = new int[n+1];
	b = new int[n+1];
	for (i = 1; i <= n; i++)
		fin >> a[i];
	for (i = 1; i <= n; i++)
		fin >> b[i];
	fout << missionArrange(a, b, n);
	return 0;
}