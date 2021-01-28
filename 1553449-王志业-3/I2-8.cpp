#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;
int Set(int n, int m)
{
	if ((m > n) || (m == 0))
	{
		return 0;
	}
	else if ((m == 1) || (n == 1) || (m == n))
	{
		return 1;
	}
	else
	{
		return (Set(n - 1, m - 1) + m*Set(n - 1, m));
	}
}


int main()
{
	int n;
	int m;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt", ios::in);
	fin >> n >> m;
	fin.close();
	fout.open("output.txt", ios::out);
	fout << Set(n, m);
	fout.close();
	return 0;
}