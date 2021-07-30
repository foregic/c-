
#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <unordered_set>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s2.size() < s1.size())
    {
        return false;
    }
    unordered_set<char> m2;
    for (int i = 0; i < s1.size(); i++)
    {
        m2.insert(s2[i]);
    }
    int right = s1.size();
    int left = 0;
    while (right != s2.size())
    {
        int j = 0;
        while (m2.find(s1[j]) != m2.end())
        {
            j++;
            if (j == right)
            {
                return true;
            }
            else
            {
                j = 0;
                break;
            }
            cout << "a\n";
        }
        cout << s2[left] << "--" << s2[right - 1] << endl;
        m2.insert(s2[right]);
        right++;
        m2.erase(s2[left]);
        left++;
        cout << s2[left] << "----" << s2[right - 1] << endl
             << endl;
    }
    return false;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max = 0;
    int m = grid.size(), n = grid[0].size();
    queue<vector<int>> myqueue;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int temp = 0;
                myqueue.push({i, j});
                grid[i][j]=0;
                while (!myqueue.empty())
                {
                    vector<int> top = myqueue.front();
                    if (top[0] - 1 >= 0 && grid[top[0] - 1][top[1]] == 1)
                    {
                        grid[top[0] - 1][top[1]] =0;
                        myqueue.push({top[0] - 1, top[1]});
                    }
                    if (top[0] + 1 < m && grid[top[0] + 1][top[1]] == 1)
                    {
                        grid[top[0] + 1][top[1]]=0;
                        myqueue.push({top[0] + 1, top[1]});
                    }
                    if (top[1] - 1 >= 0 && grid[top[0]][top[1] - 1] == 1)
                    {
                         grid[top[0]][top[1] - 1]=0;
                        myqueue.push({top[0], top[1] - 1});
                    }
                    if (top[1] + 1 < n && grid[top[0]][top[1] + 1] == 1)
                    {
                        grid[top[0]][top[1] + 1]=0;
                        myqueue.push({top[0], top[1] + 1});
                    }
                    printf("[%d,%d] ", top[0], top[1]);
                    temp++;
                    myqueue.pop();
                }
                printf("\n");
                max = (max > temp ? max : temp);
            }
        }
    }
    return max;
}

int main()
{
    // int m = 2, n = 2, r = 1, c = 4;
    // int a[5] = {0};
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("%d,%d ", (i * n + j) / c, (i * n + j) % c);
    //     }
    // }

    // unordered_set<int>a;
    // for(int i=0;i<5;i++){
    //     a.insert(i);

    // }
    // if(a.find(3)!=a.end()){
    //     cout<<"yes\n";
    // }
    // if(a.find(6)==a.end()){
    //     cout<<"no\n";
    // }

    // cout << checkInclusion("aba", "baba");

    // queue<vector<int>> a;
    // for (int i = 0; i < 5; i++)
    // {
    //     a.push({i, i + 1});
    // }

    // while (!a.empty())
    // {
    //     cout << a.front()[0] << ' ' << a.front()[1] << endl;
    //     a.pop();
    // }

    vector<vector<vector<int>>> grid;

    grid.push_back({{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                    {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}});
    // maxAreaOfIsland(grid[0]);
    vector<vector<int>> g({{1, 1, 0, 0, 0},
                           {1, 1, 0, 0, 0},
                           {0, 0, 0, 1, 1},
                           {0, 0, 0, 1, 1}});
    maxAreaOfIsland(g);
}