#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int c(int m, int n)//pick m from n
{
	int mul = 1, mul1 = 1;
	int i;
	for (i = 0; i < m; i++)
	{
		mul *= (n - i);
	}
	for (i = m; i > 0; i--)
	{
		mul1 *= i;
	}
	if (!mul1)
		return 0;
	return mul / mul1;

}
int main()
{
	fstream fin, fout;
	fin.open("input.txt", ios::in);
	fout.open("output.txt", ios::out/*|ios::_Noreplace*/);
	if (!fin.is_open())
		cout << "error in opening the file\\" << endl;
	if (!fout.is_open())
		cout << "error in opening the file" << endl;
	int ph_num;
	char phrase[6];
	fin >> ph_num;//ph_num读入的短语总数
re:	while (ph_num > 0)
	{
		fin >> phrase;
		int i,len,sum=0;
		len = strlen(phrase);
		for (i = 1; i < len; i++)//找该字符串短的所有短语
		{
			sum += c(i, 26);
		}
		int j;
		int sub[6];
		sub[0] = phrase[0] - 'a';
		
		for (i = 1; i < len; i++)//找到首个字符串和a的差值，其他字符和前一个字符的差值
		{
			sub[i] = phrase[i] - phrase[i - 1]-1;
		}
		for(i=0;i<len;i++)
		{
			if(sub[i]<0)
			{
				ph_num--;
				fout<<"wrong"<<endl;
				goto re;
			}
			
		 } 

		for (i = 0; i < len; i++)
		{
			for (j = 1; j <= sub[i]; j++)
			{
				if(i==0)
					sum += c(len - i - 1, 'z' - 'a' - j + 1);
				else
				    sum += c(len - i - 1,'z'-phrase[i-1]- j);
			}
		}
		fout << sum+1 << endl;
		ph_num--;

	}
	fin.close();
	fout.close();
	return 0;

}
