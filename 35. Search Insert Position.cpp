class Solution {
public:
    int searchInsert(vector<int>& nums, const int &target) 
    {
        if(target<=nums[0])
            return 0;
        int size=nums.size(),stop=size-1;
        if(target>nums[stop])
            return size;

        int index,start=0;
        if(nums[start]==target)
            return start;
        if(nums[stop]==target)
            return stop;
        start++;
        stop--;
        while(1)
        {
            if(nums[start]==target)
            {
                index=start;
                break;
            }
            else if(nums[stop]==target)
            {
                index=stop;
                break;
            }
            if( nums[start-1] < target && target < nums[start] )
            {
                index=start;
                break;
            }
            if( nums[stop] < target && target < nums[stop+1] )
            {
                index=stop+1;
                break;
            }
            stop--;
            start++;
        }

        return index;
    }
};