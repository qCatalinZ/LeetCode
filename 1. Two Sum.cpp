#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int &target)
    {
        vector<int> indices(2,0);
        for(int i=0; i < nums.size();++i )
        {
            for(int j=0; j<nums.size();++j)
            {
                if(i==j)
                    j++;
                if(nums[i]+nums[j]==target)
                {
                    indices[0]=i;
                    indices[1]=j;
                    return indices;
                }
            }
        }
        return indices;
    }
};

int main()
{

    return 0;
}
