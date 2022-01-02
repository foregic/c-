/*
 * @Author       : foregic
 * @Date         : 2021-08-08 22:29:57
 * @LastEditors  : foregic
 * @LastEditTime : 2021-08-08 23:10:33
 * @FilePath     : \leetcode\28.cc
 * @Description  : 
 */

#include <iostream>
#include <cstring>

using std::string;

void getnext(const string &needle, int *&next)
{
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < needle.size() - 1)
    {
        if (k == -1 || needle[j] == needle[k])
        {
            k++;
            j++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
int strStr(string haystack, string needle)
{

    int *next = new int[needle.size() + 1];
    int m = haystack.size(), n = needle.size();
    int index = 0, j = 0;
    getnext(needle, next);
    while (index < m && j < needle.size())
    {
        if (j == -1 || haystack[index] == needle[j])
        {
            ++index;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == needle.size())
        return index - j;
    else
        return -1;
}
int KMP(const string &text, const string &str) //text表示主串，str表示模式串
{

    int m = text.size(), n = str.size();
    int *next = new int[str.size() + 1];
    getnext(str, next); //求解next数组
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (j == -1 || text[i] == str[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j == n)
    {
        return i - j; //返回模式串在主串的起始位置
    }
    else
    {
        return -1; //没有找到返回-1
    }
}

int main()
{
    string haystack("hello");
    string needle("ll");
    printf("%d,%d,%d\n", -1, needle.size(), -1 < needle.size());
    if (-1 < needle.size())
    {
        printf("-1<2\n");
    }
    else
    {
        printf("-1>=2\n");
    }

    printf("%d\n", strStr(haystack, needle));
}