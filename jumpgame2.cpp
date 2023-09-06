#include <bits/stdc++.h>
using namespace std;
// approach bilkul simple hai
// dekho kya krna hai tumko sabse minimum number of jump m array k end tk pahuchna hai

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int farthest = 0;
        int count = 0;
        int jend = 0;
        if (nums.size() == 1)
            return 0;
        // i<size-1 tk hi kyu ja rhe hai kyuki humko bs last lement tk pahuchna hai to maan lo hum i<size rakhte to kya hota maan koi element humko exact  i<n tk pahuchata aur wha pr humko ek max element milta jo farthest s bda hota to mera farthest ka value badh jata aur count v badh jata
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // farthest element nikaal rhe hai
            // kyu kyu ki humko minimum time m array k end tk pahuchna  hai
            farthest = max(farthest, i + nums[i]);
            //  aur isko hum nikaal rhe hai  i+nums[i] kyu kyu ki wha tk to hum already pahuch gye hai
            // aur iska relation thoda past farthest s v hai maa lo
            //  [2,3,1,1,4] maan lo isme tumhara sbse pahla farthest 2 hua aur aage jb hum max nikaalenge agla index pr to hum kya kr eh hai farthest=max(farthest,i+nums[i]); to iss se kya ho rha hai i+nums[i] ka value farthest m ja rha hai to pichla wala kha tk chla 1 index bs chla aur agla farthest humko 1 st index pr mila isliye jitna pahle chla + av ka current element

            if (i == jend)
            {
                jend = farthest;
                count++;
            }
        }
        return count;
    }
};