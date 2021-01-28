#include <stdio.h>
#include <iostream>
#include <stdlib.h>  
#include <fstream> 
using namespace std;
void Swap(char *ch1, char *ch2)
{
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}

void part(char *data, int i_size)
{
	char *pb = data;           //��һ��b��λ��   
	char *pc = data + i_size - 1;  //��һ��c��λ��   
	char *pch = data;          //��ǰ������ַ�λ��    
	while (pch != pc)
	{
		if (*pch == '1')      //ȡ��һ����b          
		{
			pch++;
			continue;
		}
		else if (*pch == '0') //ȡ��a �� ��һ��b����   
		{
			Swap(pch, pb);
			pch++;
			pb++;
		}
		else                    //ȡ��c �� pcǰ��һ����c����                   
		{
			while (*pc == '2')    //cccǰ��һ����c   
				pc--;

			Swap(pch, pc);      //  

			if (*pch == '0')      //��һ����c��a���ں͵�һ����b����   
			{
				Swap(pch, pb);
				pb++;
			}

			pch++;
		}

	}
}
int main()
{
	int i;
	ifstream fin;
	ofstream fout;
	fin.open("input.txt", ios::in);
	int size;
	fin >> size;
	char *data = new char[size+1];
	for (i = 0; i<size; i++)
	{
		fin>>data[i];
	}
	data[i] = '\0';
	part(data, size);
	fin.close();
	fout.open("output.txt", ios::out);
	for (i = 0; i<size; i++)
	{
		fout<< data[i];
	}
	fout.close();
	return 0;
}