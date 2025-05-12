class Solution {
public:
    int hammingWeight(const int &n) 
    {
        int output = 0;
        int bit = 1;

        while(bit)
        {
            if(n & bit)
                output++;

            bit = bit << 1;
        }

        return output;
    }
};