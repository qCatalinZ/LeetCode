class Solution {
public:
    int search(const vector<int>& nums, const int &target) 
    {
        int left=0;
        int right=nums.size()-1;

        if(nums[left] == target)
            return left;

        if(nums[right] == target)
            return right;

        // left > right > target
        while( nums[left] > nums[right] && nums[right] > target )
        {
            right--;
            if(nums[right] == target)
                return right;
        }

        // target > left > right
        while( target > nums[left] && nums[left] > nums[right])
        {
            left++;
            if(nums[left] == target)
                return left;
        }

        // left < target < right
        while( nums[left] < target && target < nums[right] )
        {
            left++;
            if(nums[left] == target)
                return left;

            right--;
            if(nums[right] == target)
                return right;
        }

        return -1;    
    }
};