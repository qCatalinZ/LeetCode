class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, const int &target) 
    {
        int size=nums.size();
        vector<int> vec{-1, -1};

        if(size == 0)
            return vec;

        int left=0, right=nums.size()-1;

        // left < target < right
        while(nums[left] <= target && target <= nums[right])
        {
            // check left
            if(nums[left] == target)
            {
                vec[0]=left;
                vec[1]=left;
                while(left+1 < size && nums[left+1] == target)
                {
                    vec[1]=left+1;
                    left++;
                }
                break;
            }

            // check right
            if(nums[right] == target)
            {
                vec[1]=right;
                vec[0]=right;
                while(right-1 >= 0 && nums[right-1] == target)
                {
                    vec[0]=right-1;
                    right--;
                }
                break;
            }
            left++;
            right--;
        }

        // target < left < right || left < right < target
        return vec;    
    }
};