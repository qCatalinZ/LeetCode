class Solution {
public:
    int strStr(const string &haystack,const string &needle) 
    {
        int index=-1;
        int sizeHaystack=haystack.size();   
        int sizeNeedle=needle.size();
        for(int i=0;i<sizeHaystack;++i)
        {
            bool find;
            for(int j=0;j<sizeNeedle;++j)
                if( i+j < sizeHaystack && ( haystack[i+j] == needle[j] ) )
                    find=true;
                else
                {
                    find=false;
                    break;
                }
            if(find)
            {
                index=i;
                break;
            }
        }
        return index;
    }
};