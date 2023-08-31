// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input
#include <bits/stdc++.h>
using namespace std;
// brute force
// ****intution*****
// int this approch we are sorting the 2d vector and comparing the 2nd element of the first vector fromm the frst element of the second vector

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int start;
        int end;
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++)
        {

            start = intervals[i][0];
            end = intervals[i][1];
            if (!v.empty() && v.back()[1] >= end)
            {
                // if the second element of the current vector is smaller than the the vector stored in v then we will continue
                // compare karne ka koi faayda nhi hai na
                continue;
            }
            for (int j = i + 1; j < n; j++)
            {
                // aur jb v mera end agle vector k first elemet s bda hoga to hum end ko uodate karenge max s kyu ki ho skata hai uska send element end s bda ho
                if (end >= intervals[j][0])
                {
                    end = max(end, intervals[j][1]);
                }
                //  aur jo agr aisa nhi ho rha hai to break kr denge kyu ki ab overlapping sequence nhi bn rha hai
                else
                {
                    break;
                }
            }
            // aur current vector ko pish kr denge
            v.push_back({start, end});
        }
        return v;
    }
};
// optimal solution
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
class Solution
{
    // khud se smjho
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> v;

        sort(intervals.begin(), intervals.end());
        v.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {

            if (v.back()[1] >= intervals[i][0])
            {
                v.back()[1] = max(intervals[i][1], v.back()[1]);
            }
            else
            {
                v.push_back(intervals[i]);
            }
        }
        return v;
    }
};