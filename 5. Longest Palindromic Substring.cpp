#include <iostream>
#include <string>
using namespace std;

/*
bool verifyPalindrome(const string &s)
{
    if(s.length()<=1)
        return true;
    for(int i=0;i<s.length()/2;++i)
        if( s[i] != s[s.length()-i-1] )
            return false;
    return true;
}

class Solution
{
public:
    string longestPalindrome(const string &s)
    {
        if(verifyPalindrome(s))
            return s;

        if(s.length()<=1)
            return s;

        string longest;

        for(int j=0; j < s.length();++j)
        {
            string aux;
            for(int i=j; i < s.length(); ++i)
            {
                aux=aux+s[i];
                if(verifyPalindrome(aux))
                {
                    if(aux.length()>longest.length())
                    {
                        longest=aux;
                    }
                }
            }
        }
        return longest;
    }
};
*/

string centerPalindrom(const string &s, const int &i)
{
    string center;
    center=center+s[i];
    int l=i-1;        // -1
    int r=i+1;        // +1
    while(l>=0 && r<s.length() && s[l]==s[r])
    {
        string left;
        left=left+s[l];
        string right;
        right=right+s[r];
        center=left+center+right;
        l--;
        r++;
    }
    return center;
}

string evenPalindrom(const string &s, const int &i)
{
    string center;
    center=center+s[i];
    if(i+1 == s.length())
    {
        return center;
    }
    if(s[i]==s[i+1])
        center=center+s[i+1];
    else return center;
    int l=i-1;        // -1
    int r=i+2;        // +1
    while(l>=0 && r<s.length() && s[l]==s[r])
    {
        string left;
        left=left+s[l];
        string right;
        right=right+s[r];
        center=left+center+right;
        l--;
        r++;
    }
    return center;
}

class Solution
{
public:
    string longestPalindrome(const string &s)
    {

        if(s.length()<=1)
            return s;

        string longest;

        for(int i=0; i<s.length();++i)
        {
            string center=centerPalindrom(s,i);
            string even=evenPalindrom(s,i);
            if(longest.length() < center.length() )
            {
                longest=center;
            }
            if(longest.length() < even.length() )
            {
                longest=even;
            }
        }
        return longest;
    }
};

int main()
{
/*
    string left="l";
    string right="r";
    string centre="c";
    centre=left+centre+right;
    cout<<centre<<endl;
    left="z";
    right="y";
    centre=left+centre+right;
    cout<<centre<<endl;
    */
    Solution solutie;
    cout<<solutie.longestPalindrome("sa1basaszzz1");
    return 0;
}
