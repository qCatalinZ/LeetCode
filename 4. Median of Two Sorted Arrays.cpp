#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
     //   nums1.shrink_to_fit();
     //   nums2.shrink_to_fit();
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        if( nums1.size()&1 )
            return nums1[nums1.size()/2];
        return (double)( nums1[nums1.size()/2] + nums1[ (nums1.size()/2)-1 ] )/2;
    }
};

int main(){}
