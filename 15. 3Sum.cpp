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
            aux[2]==vec[i][2]
        )   search=false;
    }
    return search;
}
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        int head=0,tail=2;
        int size=nums.size();
        while(head+2<size)
        {
            for(int i=head+1; i<tail ;++i)
            {
                if(nums[head]+nums[i]+nums[tail]==0)
                {
                    vector<int> aux{nums[head],nums[i],nums[tail]};
                    if(duplicate(aux,vec))
                        vec.push_back(aux);
                }
            }
            if(tail<size-1) tail++;
            else if(tail==size-1) { head++; tail=head+2; }
        }
        return vec;
    }
};
*/
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        int size=nums.size();
        for(int i=0;i<size-2;++i)
        {
            for(int j=i+1;j<size-1;++j)
            {
                for(int k=j+1;k<size;++k)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> aux{nums[i],nums[j],nums[k]};
                        if(duplicate(aux,vec)) vec.push_back(aux);
                    }
                }
            }
        }
        return vec;
    }
};
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> vec;
        int size=nums.size();
        for(int i=0;i<size-2;++i)
        {
            int start=i+1,finish=size-1;
            while(1)
            {
                if(start==finish) break;
                if(nums[i]+nums[start]+nums[finish]==0)
                {
                    vector<int> aux{nums[i],nums[start],nums[finish]};
                    if(duplicate(aux,vec))  vec.push_back(aux);
                    if(start!=finish-1) finish--;
                }
                if(nums[start]+nums[finish]<-nums[i])  start++;
                else if(nums[start]+nums[finish]>-nums[i]) finish--;
                else if(start!=finish-1) finish--;
                else break;
            }
        }
        return vec;
    }
};