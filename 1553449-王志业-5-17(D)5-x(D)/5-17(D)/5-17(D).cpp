#include <iostream>
#include <fstream>
using namespace std;

int **board;  //��¼���񱻼������
int **root;      //��¼������λ��
int **best;
int m, n;             //����Ϊ m * n
int k = 0;                //�����˸���
int bestk = 10000;
int t = 0;            //�����ӵķ������
int t1, t2, more;


void change(int i, int j)
{
	int dx[] = { 0, 1, -1, 0, 0 }; //ԭλ�ü��ĸ�����
	int dy[] = { 0, 0, 0,  1, -1 };
	root[i][j] = 1;  //���û�����
	k++;
	for (int d = 0; d <= 4; d++)     //ԭλ�ü���Χ������
	{
		int p = i + dx[d];
		int q = j + dy[d];
		board[p][q]++;
		if (board[p][q] == 1)
			t++;
	}
}

//�ָ�������ǰ��״̬
void restore(int i, int j)
{
	int dx[] = { 0, 1, -1, 0, 0 }; //ԭλ�ü��ĸ�����
	int dy[] = { 0, 0, 0,  1, -1 };
	root[i][j] = 0;
	k--;
	for (int d = 0; d <= 4; d++)
	{
		int p = i + dx[d];
		int q = j + dy[d];
		board[p][q]--;
		if (board[p][q] == 0)
			t++;
	}
}

void backtrack(int i, int j){ 
	do  {
		j++;
		if (j > m){
			i++;
			j = 1;}
	} while (board[i][j] != 0 && i <= n);
	if (i>n) {
		if (k < bestk){
			bestk = k;
			for (int p = 1; p <= n; p++)			
				for (int q = 1; q <= m; q++)				
					best[p][q] = root[p][q];
			return;}
		else
			return;}
	if (k + (t1 - t) / 5 >= bestk)  //��֦
		return;
	if (i< n - 1 && (k + (t2 - t) / 5 >= bestk))  //��֦
		return;
	if (i<n){
		change(i + 1, j);  //���û����ˣ����ı�״̬
		backtrack(i, j);
		restore(i + 1, j); //���������ˣ����ָ�״̬
	}
	if (j<m && (board[i][j + 1] == 0 || board[i][j + 2] == 0)){
		change(i, j + 1);
		backtrack(i, j);
		restore(i, j + 1);
	}
	if (board[i + 1][j] == 0 && board[i][j + 1] == 0){
		change(i, j);
		backtrack(i, j);
		restore(i, j);
	}
}

void compute(int n,int m)
{
	int i;
	board = new int*[n + 2];
	root = new int*[n + 2];
	best = new int*[n + 2];
	for (i = 0; i <= n + 1; i++)
	{
		board[i] = new int[m + 2];
		root[i] = new int[m + 2];
		best[i] = new int[m + 2];
	}
	more = m / 4 + 1;
	if (m % 4 == 3)
		more++;
	else if (m % 4 == 2)
		more += 2;
	t2 = m * n + more + 4;
	t1 = m * n + 4;
	
	for (i = 0; i <= n+1; i++)
		for (int j = 0; j <= m + 1; j++)
		{
			board[i][j] = 0;
			root[i][j] = 0;
			best[i][j] = 0;
		}
	for (i = 0; i <= n + 1; i++)      //�����һȦΪ1
	{
		board[i][m + 1] = 1;
		board[i][0] = 1;
	}
	for (i = 0; i <= m + 1; i++)
	{
		board[0][i] = 1;
		board[n + 1][i] = 1;
	}
	
	if (n == 1 && m == 1)
	{
		bestk = 1;
		best[1][1] = 1;
	}
	else
		backtrack(1, 0);
}

int main()
{
	ifstream fin("input.txt",ios::in);
	fin >> n>> m;
	compute(n,m);
	ofstream fout("output.txt",ios::out);
	fout << bestk << endl;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			fout << best[i][j] << " ";
		fout << endl;
	}
	fout.close();
	fin.close();
	return 0;
}