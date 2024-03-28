class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int size=digits.size()-1;
        digits[size]++;
        for(int i=size;i>=0;--i)
        {
            if(digits[i]<10)
                break;
            digits[i]=0;
            if(i==0)
                break;
            digits[i-1]++;
        }
        if(digits[0]==0)
        {
            digits.push_back(0);
            digits[0]=1;
        }
        return digits;    
    }
};