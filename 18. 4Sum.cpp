bool duplicate(const vector<int> &aux,const vector<vector<int>> &vec)
{
    int size=vec.size();
    if(size==0)
        return true;
    bool search=true;
    for(int i=0;i<size;++i)
    {
        if(
            aux[0]==vec[i][0] &&
            aux[1]==vec[i][1] &&
            aux[2]==vec[i][2] &&
            aux[3]==vec[i][3]
        )   search=false;
    }
    return search;
}
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, const int &target) 
    {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> output;
        int size=nums.size();
        //if(size<=3) return output;
        int start,finish;
        for(int i=0;i<size-3;++i)
        {
            for(int j=i+1;j<size-2;++j)
            {
                start=j+1;
                finish=size-1;
                while(1)
                {
                    if(start==finish) break;
                    long long int sum=(long long int)nums[i]+(long long int)nums[j]+(long long int)nums[start]+(long long int)nums[finish];
                    if(sum==target)
                    {
                        vector<int> aux{nums[i],nums[j],nums[start],nums[finish]};
                        if(duplicate(aux,output))  output.push_back(aux);
                    }
                    if(sum<target)  start++;
                    else if(sum>target) finish--;
                    else if(start!=finish-1) finish--;
                    else break;
                }
            }
        }
        return output;
    }
};