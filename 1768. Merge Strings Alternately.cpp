class Solution {
public:

    string mergeAlternately(const string &word1, const string &word2) 
    {
        string output = "";

        int size1 = word1.size();
        int size2 = word2.size();

        if(size1 == size2)
            for(int i = 0; i < size1; ++i)
                output = output + word1[i] + word2[i];
        else if(size1 < size2)
        {
            int i;
            for(i = 0; i < size1; ++i)
                output = output + word1[i] + word2[i];
            for(i = size1; i < size2; ++i)
                output = output + word2[i];
        }
        else // size1 > size2 
        {
            int i;
            for(i = 0; i < size2; ++i)
                output = output + word1[i] + word2[i];
            for(i = size2; i < size1; ++i)
                output = output + word1[i];
        }

        return output;    
    }
};