#include <iostream>
#include <fstream>
using namespace std;
int half_gather(int n)
{
	int result = 0;
	if (n == 1)
		return 1;
	if (n == 2 || n == 3)
		return 2;
	for (int i = 1; i <= n / 2; i++)
		result += half_gather(i);
	return 1+result;
}
int main()
{
	fstream fin;
	fin.open("input.txt",ios::in);
	if (!fin.is_open())
		cout << "ERROR in opening the files" << endl;
	int x;
	fin >> x;
	fstream fout;
	fout.open("output.txt", ios::out);
	fout << half_gather(x);
	fout.close();
	fin.close();
	return 0;
}