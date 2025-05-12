class Solution {
public:

    void bubbleSort(vector<int>& v) 
    {
        int n = v.size();
        bool swapped;
        for (int i = 0; i < n - 1; ++i) 
        {
            swapped = false; 
            for (int j = 0; j < n - i - 1; ++j) 
            {
                if (v[j] > v[j + 1]) 
                {
                    swap(v[j], v[j + 1]);
                    swapped = true;
                }
            }

            if (!swapped) break;
        }
    }

    int singleNumber(vector<int>& nums) 
    {
        int output;
        bool st;
        int size = nums.size();
        bubbleSort(nums);

        int j;
        for(int i = 0; i < size; ++i)
        {
            st = true;
            for(j = 0; j < size; ++j)
            {
                if(i == j)  continue;

                if(nums[i] == nums[j])
                {
                    st = false;
                    break;
                }
            }

            if(st)
            {
                output = nums[i];
                break;
            }
        }

        return output;
    }
};