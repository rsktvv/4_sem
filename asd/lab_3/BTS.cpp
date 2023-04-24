#include <iostream>
#include<fstream>
#include<vector>
#include <queue>
#define n 6

using namespace std;

void BFS(int start, int mas[n][n])
{
    int V;
    bool check[n];
    vector<int> components;
    int dist[n];
    int cnt = 0;
    queue <int> q;


     ofstream out("output_3.txt");

    for (int i = 0;i < n;i++)
        check[i] = false;

    for (int i = 0;i < n;i++)
    {
        if (check[i] == true)
            continue;
        q.push(i);


        while (!q.empty())
        {
            V = q.front();
            q.pop();
            if (check[V] == true)
                break;
            components.push_back(V);
            
            
            check[V] = true;
            for (int k = 0;k < n;k++)
            {
                if ((mas[V][k] == 1) && (check[k] != true))
                {
                    q.push(k);
                }
            }
            
        }
        cnt++;
        
        cout << "{";
        for (int l = 0;l < components.size();l++)
        {
           cout << components.at(l)+1<< " ";
            
        }
        cout << "}";
        components.clear();
    }

    cout << "Count = " << cnt;
}


int main()
{
    int matrix[n][n];
    ifstream in;
    in.open("input.txt");



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> matrix[i][j];

        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "Original Data:" << endl;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
   

    BFS(1, matrix);
}
