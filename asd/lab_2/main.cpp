#include <iostream>
#include <fstream>
#include <queue>
#define n 6

int main()
{
	std::ifstream in;
	in.open("input.txt");
	

	std::queue <int> a;
	int matrix[n][n];
	bool c[n];
	int d[n];
	int t;
	a.push(0);


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			in >> matrix[i][j];
			//std::cout << matrix[i][j] << " ";
		}
		//std::cout << std::endl;
		d[i] = -1;
		c[i] = false;
	}
	d[0] = 0;
	
	while (!a.empty())
	{
		t = a.front();
		std::cout << "1 " << t << std::endl;
		a.pop();
		c[t] = true;
		for (int i = 0; i < n; i++)
			if (matrix[t][i] == 1 && c[i] != true)
			{
				a.push(i);
				d[i] = d[t] + 1;
				std::cout << "2 " << a.front() << std::endl;
				
			}
	}

	std::cout << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << i + 1 << " " << d[i] << std::endl;
}