#include <iostream>  
#include<fstream>  
#include<string>  
using namespace std;

unsigned int mincost = 65535; //设置的初始值,大于可能的费用  
int **c;
int* task;                  //当前作业分配情况:工人i 执行task[i]  
int* bestSolution;          //最优作业分配情况: 工人i执行作业bestSolution[i]  
int* job;                   //记录作业是否已被分配给工人，1表示已分配，0为分配  
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
	assign(1, 0); //从任务1开始分配  
	fout << mincost;
	fin.close();
	fout.close();
	return 0;
}



