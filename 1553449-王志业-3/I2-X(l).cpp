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
	char *pb = data;           //第一个b的位置   
	char *pc = data + i_size - 1;  //第一个c的位置   
	char *pch = data;          //当前处理的字符位置    
	while (pch != pc)
	{
		if (*pch == '1')      //取第一个非b          
		{
			pch++;
			continue;
		}
		else if (*pch == '0') //取到a 和 第一个b交换   
		{
			Swap(pch, pb);
			pch++;
			pb++;
		}
		else                    //取到c 和 pc前第一个非c交换                   
		{
			while (*pc == '2')    //ccc前第一个非c   
				pc--;

			Swap(pch, pc);      //  

			if (*pch == '0')      //第一个非c是a，在和第一个非b交换   
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