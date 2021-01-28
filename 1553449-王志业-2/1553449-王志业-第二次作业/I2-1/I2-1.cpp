#include <iostream>
#include <fstream>
using namespace std;
//将文件中的数读入到数组
int *readin(char *filename,int &len)
{
	fstream fin;
	fin.open(filename, ios::in);
	int *myarray;
	fin >> len;
	myarray = (int*)malloc(len*sizeof(int));
	for (int i = 0; i < len; i++)
	{
		fin >> myarray[i];
	}
	return myarray;
}
//对数组中的数字进行排序
int Partition(int L[], int low, int high) {
	int pivotkey = L[low];
	L[0] = L[low];
	while (low < high) {
		while (low < high && L[high] >= pivotkey) {
			--high;
		}
		L[low] = L[high];
		while (low < high && L[low] <= pivotkey) {
			++low;
		}
		L[high] = L[low];
	}
	L[low] = L[0];
	return low;
}

void Qsort(int L[], int low, int high) {
	if (low < high) {
		int pivotLoc = Partition(L, low, high);
		Qsort(L, low, pivotLoc - 1);
		Qsort(L, pivotLoc + 1, high);
	}
	return;
}

void QuickSort(int L[], int length) 
{
	Qsort(L, 1, length);
}

//寻找重数
void find(int *myarray, int len,int &m,int &n)//m重数，n次数
{
	m = 0;
	n = 0;
	int ntemp=0, mtemp=0;
	for (int i = 0; i < len; i++)
	{
		
		if (mtemp != myarray[i])
		{
			if (ntemp > n)
			{
				n = ntemp;
				m = mtemp;
			}
			mtemp = myarray[i];
			ntemp = 1;
		}
		else
			ntemp++;
	}
}
int main()
{
	int len;
	fstream fout;
	int *myarray;
	char *filename = "input.txt";
	fout.open("output.txt", ios::out);
	myarray = readin(filename, len);
	QuickSort(myarray, len);
	int m,n;
	find(myarray, len, m, n);
	fout << m << endl << n;
	fout.close();
	return 0;
}
