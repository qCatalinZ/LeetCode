class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, const int &extraCandies) 
    {
        int size = candies.size();
        vector<bool> result(size);
        int greatest = -1;
        int i;

        for(i = 0; i < size; ++i)
            if( candies[i] > greatest )
                greatest = candies[i];

        for(i = 0; i < size; ++i)
            if( greatest <= candies[i] + extraCandies )
                result[i] = true;

        return result;   
    }
};