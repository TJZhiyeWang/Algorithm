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

	while (k >= 1)  //ѭ��
	{
		
		ans[k] += 1;  //�ȷ��ڵ�һ��λ��
		while ((ans[k] <= n) && !(Place(k)))  //������ܷ�
			ans[k] += 1;                      //������һ��λ��
		if (ans[k] <= n)                      //�������
		{
			if (k == n)                     //����Ѿ�������n���ʺ�
			{
				for (int i = 1; i <= n; i++)
					fout << ans[i] << " ";
				fout << endl;
				ans[k] = 0;
				k--;
			}

			else                            //û�д����꣬��k�Լӣ�������һ���ʺ�
				k++;
		}                                   //x[k] > n��˵��û�к��ʵ�λ����
		else
		{
			ans[k] = 0;
			k--;
		}//���ݻ�ȥ���ص���k-1��
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