/*
 * @Author       : foregic
 * @Date         : 2021-07-27 23:36:37
 * @LastEditors  : foregic
 * @LastEditTime : 2021-08-04 03:32:48
 * @FilePath     : \leetcode\test.cpp
 * @Description  : 
 */

#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <unordered_set>
#include <set>

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
                grid[i][j] = 0;
                while (!myqueue.empty())
                {
                    vector<int> top = myqueue.front();
                    if (top[0] - 1 >= 0 && grid[top[0] - 1][top[1]] == 1)
                    {
                        grid[top[0] - 1][top[1]] = 0;
                        myqueue.push({top[0] - 1, top[1]});
                    }
                    if (top[0] + 1 < m && grid[top[0] + 1][top[1]] == 1)
                    {
                        grid[top[0] + 1][top[1]] = 0;
                        myqueue.push({top[0] + 1, top[1]});
                    }
                    if (top[1] - 1 >= 0 && grid[top[0]][top[1] - 1] == 1)
                    {
                        grid[top[0]][top[1] - 1] = 0;
                        myqueue.push({top[0], top[1] - 1});
                    }
                    if (top[1] + 1 < n && grid[top[0]][top[1] + 1] == 1)
                    {
                        grid[top[0]][top[1] + 1] = 0;
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

int minimumTotal(vector<vector<int>> &triangle)
{
    int m = triangle.size();
    vector<vector<int>> a(m + 1, (vector<int>(m + 1, 0)));
    a[1][1] = triangle[0][0];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
            {
                a[i][j] = triangle[i - 1][j - 1] + a[i - 1][j];
                printf("%d,%d:%d\n", i, j, a[i][j]);
                continue;
            }
            if (j == i)
            {
                a[i][j] = triangle[i - 1][j - 1] + a[i - 1][j - 1];
                printf("%d,%d:%d\n", i, j, a[i][j]);
                continue;
            }
            a[i][j] = triangle[i - 1][j - 1] +
                      (a[i - 1][j - 1] < a[i - 1][j] ? a[i - 1][j - 1] : a[i - 1][j]);
            printf("%d,%d:%d\n", i, j, a[i][j]);
        }
    }
    int result = a[m][1];
    for (int i = 1; i <= m; i++)
    {
        result = (result < a[m][i] ? result : a[m][i]);
    }
    return result;
}

int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    const int MAX = 21474836;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, MAX));
    for (int i = 0; i < times.size(); i++)
    {
        graph[times[i][0]][times[i][1]] = times[i][2]; //初始化邻接矩阵
    }
    bool *isVisit = new bool[n + 1]; //节点是否被访问
    for (int i = 1; i <= n; i++)
    {
        isVisit[i] = false;
    }
    int *dp = new int[n + 1]; //起点到节点的距离
    for (int i = 1; i <= n; i++)
    {
        //初始化节点到起点的距离
        dp[i] = graph[k][i];
    }
    for (int i = 1; i <= n; i++)
    {
        int u = -1, temp_min = 100000;
        for (int j = 1; j <= n; j++)
        {
            if (!isVisit[j] && dp[j] < temp_min)
            {
                u = j, temp_min = dp[j];
                cout << u << '\n';
            }
        }
        if (u == -1)
            break;
        isVisit[u] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!isVisit[j] && dp[u] + graph[u][j] < dp[j])
            {
                cout << dp[j] << '=' << dp[u] << '+' << graph[u][j] << '\n';
                dp[j] = dp[u] + graph[u][j];
            }
        }
    }
    int result = -1;
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == MAX)
            continue;
        result = max(result, dp[i]);
    }
    delete[] dp;
    delete[] isVisit;
    return result;
}

vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
{
    int m = mat.size(), n = mat[0].size();
    if (m <= k + 1 && n <= k + 1)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                mat[0][0] += mat[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                mat[i][j] = mat[0][0];
            }
        }
        return mat;
    }
    vector<vector<int>> result(m, vector<int>(n, 0));
    int *a = new int[2 * k + 1];
    for (int i = 0; i <= k; i++)
    {
        a[k + i] = i;
        a[k - i] = -i;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j <= k)
            {
                if (j == 0)
                {
                    for (int t = 0; t <= k; t++)
                    {
                        result[i][j] += mat[i][j + a[t + k]];
                    }
                }
                else
                {
                    result[i][j] = result[i][j - 1] + mat[i][j + a[2 * k]];
                }
            }
            else if (j >= n - k)
            {
                result[i][j] = result[i][j - 1] - mat[i][j - 1 + a[0]];
            }
            else
            {
                result[i][j] = result[i][j - 1] + mat[i][j + a[2 * k]] - mat[i][j - 1 + a[0]];
            }
        }
    }
    mat = result;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j <= k)
            {
                if (j == 0)
                {
                    for (int t = 1; t <= k; t++)
                    {
                        result[j][i] += mat[j + a[t + k]][i];
                    }
                }
                else
                {
                    result[j][i] = result[j - 1][i] + mat[j + a[2 * k]][i];
                }
            }
            else if (j >= m - k)
            {

                result[j][i] = result[j - 1][i] - mat[j - 1 + a[0]][i];
            }
            else
            {
                result[j][i] = result[j - 1][i] + mat[j + a[2 * k]][i] - mat[j - 1 + a[0]][i];
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << ' ';
        }
        cout << '\n';
    }

    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         for(int q=0;q<2*k+1;q++){
    //             for(int w=0;w<2*k+1;w++){
    //                 if((i+a[q]>=0&&i+a[q]<m)&&(j+a[w]>=0&&j+a[w]<n)){
    //                     result[i][j] +=mat[i+a[q]][j+a[w]];
    //                 }
    //             }
    //         }
    //     }
    // }
    return result;
}

int findUnsortedSubarray(vector<int> &nums)
{
    int max_size = nums.size() - 1;
    if (max_size == 0)
        return 0;
    int l = 0, r = max_size;
    int m, t, n;
    if (nums[0] <= nums[1])
    {

        while (l < max_size && nums[l] <= nums[l + 1])
        {
            l++;
        }
        if (l == max_size)
            return 0;
        m = nums[++l], t = l;
        while (l > 0 && m < nums[--l])
        {
        }
        l++;
    }
    else
        l = 0;

    if (nums[max_size] >= nums[max_size - 1])
    {

        while (r >= t && nums[r] >= nums[r - 1])
        {
            r--;
        }
        if (r != t)
        {
            m = nums[--r];
            r++;
            while (r <= max_size && m > nums[r])
            {
                r++;
            }
            r++;
        }
    }
    else
        r = max_size;
    return r - l + 1;
}
 
int main()
{
    vector<vector<int>> nums;
    nums.push_back({2, 6, 8, 10, 3, 19, 13, 14, 15, 16, 17});
    nums.push_back({2, 6, 4, 8, 10, 9, 15});
    nums.push_back({1, 3, 2, 3, 3});
    nums.push_back({1, 2, 3, 4});
    nums.push_back({1, 2, 3, 3, 3});
    nums.push_back({2, 3, 3, 2, 4});
    // std::cout << findUnsortedSubarray(nums[0]) << std::endl;
    // std::cout << findUnsortedSubarray(nums[5]) << std::endl;
    std::cout << findUnsortedSubarray(nums[1]) << std::endl;
    // std::cout << findUnsortedSubarray(nums[2]) << std::endl;
    // std::cout << findUnsortedSubarray(nums[3]) << std::endl;
    // std::cout << findUnsortedSubarray(nums[4]) << std::endl;

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

    // vector<vector<vector<int>>> grid;

    // grid.push_back({{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    //                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //                 {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    //                 {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
    //                 {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
    //                 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    //                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    //                 {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}});
    // // maxAreaOfIsland(grid[0]);
    // vector<vector<int>> g({{1, 1, 0, 0, 0},
    //                        {1, 1, 0, 0, 0},
    //                        {0, 0, 0, 1, 1},
    //                        {0, 0, 0, 1, 1}});
    // maxAreaOfIsland(g);

    // vector<vector<int>> a= {{2},{3,4},{6,5,7},{4,1,8,3}};
    // std::cout<<minimumTotal(a);

    // vector<int *> vec;
    // int q = 2, t = 1;
    // int *a = &q;
    // int *b = &t;
    // vec.push_back(a);
    // vec.push_back(b);
    // if (vec[0] > vec[1])
    // {
    //     cout << "yes";
    // }

    // int *a;
    // *a = 1;

    // vector<vector<int>> times;
    // times.push_back({1, 2, 1});
    // times.push_back({2, 1, 3});
    // cout << networkDelayTime(times, 2, 2);

    // vector<vector<int>> mat;
    // mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // matrixBlockSum(mat, 1);
}