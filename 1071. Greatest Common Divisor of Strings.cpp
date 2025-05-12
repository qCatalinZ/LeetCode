class Solution {
public:

    bool verifyDivisor(const string &s1, const string &s2)
    {
        int size1 = s1.size();
        int size2 = s2.size();

        int j;
        for(int i = 0; i < size1; i = i + size2)
            for(j = 0; j < size2; ++j)
                if(s1[j + i] != s2[j])
                    return false;
        return true;
    }

    string addCurrentLength(const string &str1, const int &len)
    {
        string output = "";
        for(int i=0; i <= len; ++i)
            output = output + str1[i];
        return output;
    }

    string gcdOfStrings(const string &str1, const string &str2) 
    {
        const int size1 = str1.size();
        const int size2 = str2.size();

        int i;
        string t;
        string output = "";
        if( size1 <= size2 )
        {
            for(i = 0; i < size1; ++i)
            {
                t = addCurrentLength(str1, i);
                if( verifyDivisor(str1, t) && verifyDivisor(str2, t) )
                    output = t;
            }
            return output;
        }

        for(i = 0; i < size2; ++i)
        {
            t = addCurrentLength(str2, i);
            if( verifyDivisor(str1, t) && verifyDivisor(str2, t) )
                output = t;
        }
        return output;
    }
};