#include <iostream>  
#include<fstream>  
#include<string>  
using namespace std;

unsigned int mincost = 65535; //���õĳ�ʼֵ,���ڿ��ܵķ���  
int **c;
int* task;                  //��ǰ��ҵ�������:����i ִ��task[i]  
int* bestSolution;          //������ҵ�������: ����iִ����ҵbestSolution[i]  
int* job;                   //��¼��ҵ�Ƿ��ѱ���������ˣ�1��ʾ�ѷ��䣬0Ϊ����  
int n;//num of jobs

void assign(int k, unsigned int cost)
{
	int i;
	if (k > n && cost < mincost)
	{
		mincost = cost;
		for (i = 1; i <= n; i++)
			bestSolution[i] = task[i];
		
	}
	else
	{
		
		for (i = 1; i <= n; i++)
		{
			if (job[i] == 0 && cost + c[k][i] < mincost)
			{
				
				job[i] = 1; task[k] = i;
				assign(k + 1, cost + c[k][i]);
				job[i] = 0; task[k] = 0;
			}
		}
	}
}

int main()
{
	ifstream fin("input.txt",ios::in);
	ofstream fout("output.txt", ios::out);
	fin >> n;
	c = new int*[n+1];
	for (int i = 0; i <= n; i++)
		c[i] = new int[n+1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			fin >> c[i][j];
	task = new int[n+1];
	bestSolution = new int[n+1];
	job = new int[n+1];
	for (int i = 0; i <= n; i++)
	{
		task[i] = 0;
		bestSolution[i] = 0;
		job[i] = 0;
	}
	assign(1, 0); //������1��ʼ����  
	fout << mincost;
	fin.close();
	fout.close();
	return 0;
}



