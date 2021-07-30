/*
 * @Author       : foregic
 * @Date         : 2021-07-30 09:58:50
 * @LastEditors  : foregic
 * @LastEditTime : 2021-07-30 11:47:28
 * @FilePath     : \leetcode\BFS-DFS.cpp
 * @Description  : 广度优先搜索和深度优先搜索，题目来源于LeetCode（733和695）
 */

#include <vector>
#include <queue>
using std::queue;
using std::vector;
/**
 * @description  : 图像渲染，上下左右四个方向上与给定坐标相连的点渲染成指定的颜色，与指定坐标相连的点的上下左右四个方向上的点也都渲染成指定的颜色
 * @param         {vector<vector<int>>} &image
 * @param         {int} sr
 * @param         {int} sc
 * @param         {int} newColor
 * @return        {vector<vector<int>>}
 */
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int m = image.size(), n = image[0].size();
    int originColor = image[sr][sc];
    queue<vector<int>> myqueue;
    myqueue.push({sr, sc});
    while (!myqueue.empty())
    {
        vector<int> ft = myqueue.front();
        if (ft[1] + 1 < n && image[ft[0]][ft[1] + 1] == originColor)
        {
            myqueue.push({ft[0], ft[1] + 1});
        }
        if (ft[0] + 1 < m && image[ft[0] + 1][ft[1]] == originColor)
        {
            myqueue.push({ft[0] + 1, ft[1]});
        }
        if (ft[0] - 1 >= 0 && image[ft[0] - 1][ft[1]] == originColor)
        {
            myqueue.push({ft[0] - 1, ft[1]});
        }
        if (ft[1] - 1 >= 0 && image[ft[0]][ft[1] - 1] == originColor)
        {
            myqueue.push({ft[0], ft[1] - 1});
        }
        image[ft[0]][ft[1]] = -1;
        myqueue.pop();
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (image[i][j] == -1)
                image[i][j] = newColor;
        }
    }
    return image;
}

/**
 * @description  : dfs深度优先搜索,
 * @param         {vector<vector<int>>} &grid
 * @param         {int} i
 * @param         {int} j
 * @return        {int}
 */
int dfs(vector<vector<int>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
        return 0;
    grid[i][j] = 0;
    return 1 + dfs(grid, i, j + 1) + dfs(grid, i, j - 1) + dfs(grid, i + 1, j) + dfs(grid, i - 1, j);
}

/**
 * @description  : 一个二维矩阵，由0和1组成，一个岛屿由上下左右方向上相连的点组成，返回岛屿的最大面积
 * @param         {vector<vector<int>>} &grid
 * @return        {int}
 */
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int max = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] != 0)
            {
                int temp = dfs(grid, i, j);
                max = (max > temp ? max : temp);
            }
        }
    }
    return max;
}