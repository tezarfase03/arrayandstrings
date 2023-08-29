#include <bits/stdc++.h>
using namespace std;
// question: question ye keh rha hai ki hume ek triplet find krna hai jiska ki sum 0 ho
// aur wo triplet repeat nhi krna chahiye
// eg:[-1,2,-1]==[-1,-1,2] both ar esame so we can takae only one
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// *******optimal approach*********
// in this approach we are using two pointer approach
// we will sort the array reason for that is to get unique triplet we will not get the same triplet twice
// sorting also helps in the two pointers approach
// where we keep the first pointer i at 0 index j at 1st indeex and k at n-1 index

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // first for loop is for fixing the first pointer
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            // intialising the second and third pointer
            int j = i + 1;
            int k = n - 1;
            // why j<k
            // because we are keeping it in sorted order if it crosses  then it wont be in sorted manner
            while (j < k)
            {
                // [-2,-2,-2,-1,-1,-1,0,0,0,2,2,2]
                //  i  j                       k                      these are the iterators now will get the idea
                int sum = nums[i] + nums[j] + nums[k];
                // here you see we get the benifits of sorting
                // while moving j and k
                // if sum of the triplet is less than the 0 so we will increse j as it is sortedthe j will move to right so that it will increse the value of the sum;
                if (sum < 0)
                {
                    j++;
                }
                // if the sum is greater the k will move to left
                else if (sum > 0)
                {
                    k--;
                }
                // if sum ==0 else will be executed
                else
                {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    result.push_back(v);
                    j++;
                    k--;
                    // these two while loop is to avoid the same element look at the above example you will understand
                    while (j < k && nums[j - 1] == nums[j])
                    {
                        j++;
                    }
                    while (j < k && nums[k + 1] == nums[k])
                    {
                        k--;
                    }
                }
            }
        }
        return result;
    }
};
// better approach but it will give us tle try to understand it by yourself
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> st;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> s;
            for (int j = i + 1; j < n; j++)
            {

                int x = -(nums[i] + nums[j]);
                if (s.find(x) != s.end())
                {
                    vector<int> v = {nums[i], nums[j], x};

                    st.insert(v);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};