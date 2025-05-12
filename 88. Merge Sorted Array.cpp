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

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i;
        for(i = 0; i < n; ++i)
            nums1[m + i] = nums2[i];

        bubbleSort(nums1);
    }
};