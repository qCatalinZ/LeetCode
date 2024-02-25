int closeContor(const int &output, const int &target)
{
    if(output<target)
        return target-output;
    return output-target;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, const int &target) 
    {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int output=nums[0]+nums[1]+nums[2];
        int sum;
        for(int i=0;i<size-2;++i)
        {
            int start=i+1,finish=size-1;
            while(start!=finish)
            {
                sum=nums[i]+nums[start]+nums[finish];
                if(sum==target)
                {
                    output=sum;
                    break;
                }
                int contorOutput=closeContor(output,target);
                int contorSum=closeContor(sum,target);
                output=(contorSum<=contorOutput)?(sum):(output);
                if(sum<target)  start++;
                else            finish--;
            }
            if(sum==target) break;
        }
        return output;
    }
};