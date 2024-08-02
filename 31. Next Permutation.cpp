class Solution {
public:

    void swap(int &a, int &b, int &aux)
    {
        aux=a;
        a=b;
        b=aux;
    }

    void nextPermutation(vector<int>& nums) 
    {
        if(nums.size()==1)
            return;

        const int size = nums.size()-1;
        bool case321_123=true;
        int i,index,numFound; // numFound can be aux

        for(i = size; i > 0; --i)
            if(nums[i] > nums[i-1])
            {
                index=i;
                case321_123=false;
                break;
            }

        if(case321_123)
        {
            index = ( size & 1 ) ? size / 2 : size / 2 - 1;
            for(i = 0; i <= index; ++i)
                swap(nums[i], nums[size-i], numFound);
            return;
        }  

        int index2=index;
        numFound=nums[index]; 
        for(i = index+1; i <= size; ++i)
            if( index-1 >= 0 && nums[index-1] < nums[i] && nums[i] < numFound )
            {
                numFound=nums[i];
                index2=i;
            }

        if(index-1 >= 0)
        {
            swap(nums[index-1], nums[index2], numFound);
            sort(nums.begin() + index, nums.end());
        }  
    }
};