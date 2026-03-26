#include <iostream>
#include <vector>
using namespace std;

bool G[10][10][10];
vector<pair<int, int>> Q;
vector<pair<int, int>> P;

void printing()
{
    for (const auto &p : Q)
    {
        int i = p.first, j = p.second;
        cout << i << "," << j << " : ";
        for (int z = 1; z <= 9; z++)
        {
            if (!G[i][j][z])
            {
                cout << z << " ";
            }
        }
        cout << "\n";
    }
}

void fill(int i, int j, int z)
{
    for (int k = 0; k < 9; k++)
    {
        G[i][k][z] = true;
        G[k][j][z] = true;
    }
    i = (i / 3) * 3;
    j = (j / 3) * 3;
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            G[i + k][j + l][z] = true;
        }
    }
}

void solve()
{
    printing();
    
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 0)
            {
                Q.push_back(make_pair(i, j));
            }
            else
            {
                fill(i, j, tmp);
            }
        }
    }



    for (int k = 0; k < Q.size(); k++)
    {
        int i = Q[k].first;
        int j = Q[k].second;
        int sum = 0;
        for (int z = 1; z <= 9; z++)
        {
            if (!G[i][j][z])
            {
                sum++;
            }
        }
        P.push_back(make_pair(k, sum));
    }
    sort(P.begin(), P.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    
    
    solve();
}
/*
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 0 0 0
6 4 3 7 8 1 0 0 0
2 5 8 3 9 4 0 0 0
*/