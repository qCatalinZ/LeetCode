#define noElement 101
class Solution {
public:
    int removeElement(vector<int>& nums, const int &val) 
    {
        int k=0;
        int size=nums.size();
        for(int i=0;i<size;++i)
            if(nums[i]==val)
                nums[i]=noElement;
            else k++;
        std::sort(nums.begin(),nums.end());
        return k;
    }
};