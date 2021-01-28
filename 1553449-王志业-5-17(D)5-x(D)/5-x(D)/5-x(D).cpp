#include <iostream>
#include <fstream>
using namespace std;

int n;
int *ans;
ifstream fin("input.txt", ios::in);
ofstream fout("output.txt", ios::out);

int Place(int k)
{
	for (int j = 1; j < k; ++j)
		if (abs(k - j) == abs(ans[k] - ans[j]) || ans[j] == ans[k])
			return 0;
	return 1;
}


void BackTrack()
{
	int k;
	k = 1;

	while (k >= 1)  //循环
	{
		
		ans[k] += 1;  //先放在第一个位置
		while ((ans[k] <= n) && !(Place(k)))  //如果不能放
			ans[k] += 1;                      //放在下一个位置
		if (ans[k] <= n)                      //放置完成
		{
			if (k == n)                     //如果已经放完了n个皇后
			{
				for (int i = 1; i <= n; i++)
					fout << ans[i] << " ";
				fout << endl;
				ans[k] = 0;
				k--;
			}

			else                            //没有处理完，让k自加，处理下一个皇后
				k++;
		}                                   //x[k] > n，说明没有合适的位置了
		else
		{
			ans[k] = 0;
			k--;
		}//回溯回去，回到第k-1步
	}
}

void queen()
{
	
	ans = new int [n+1];
	for (int i = 0; i <= n; i++)
		ans[i] = 0;
	BackTrack();

}
int main()
{

	fin >> n;
	queen();

	return 0;
}