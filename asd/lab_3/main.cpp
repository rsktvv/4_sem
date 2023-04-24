#include <iostream>
#include<fstream>
#include<vector>
#include <queue>
#define n 6



void BFS(int start, int mas[n][n])
{
    int V;
    bool check[n];
    std::vector<int> components;
    int cnt = 0;
    std::queue <int> q;


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
        
        std::cout << "{";
        for (int l = 0;l < components.size();l++)
        {
            std::cout << components.at(l)+1<< " ";
            
        }
        std::cout << "}";
        components.clear();
    }

    //out << "Count = " << cnt;
}


int main()
{
    int matrix[n][n];
    std::ifstream in;
    in.open("input.txt");
    bool c[n];
    int k=0;
    std::queue <int> a;
    std::vector<int> comp;
    int o;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            in >> matrix[i][j];
            std::cout << matrix[i][j] << " ";
        }
        c[i] = false;
        std::cout << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (c[i] == true)
            continue;
        a.push(i);

        while (!a.empty())
        {
            o = a.front();
            a.pop();
            if (c[o] == true)
                break;
            comp.push_back(o);

            c[o] = true;
            for (int p = 0; p < n; p++)
            {
                if ((matrix[o][p] == 1) && (c[p] != true))
                {
                    a.push(p);
                }
            }
        }
        k++;

        std::cout << "{";
        for (int l = 0; l < comp.size(); l++)
            std::cout << comp.at(l) + 1 << " ";
        std::cout << "}";
        comp.clear();
    }
    std::cout << std::endl << k;

 
}
