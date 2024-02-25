#include <vector>
string number(const char &l)
{
    switch(l)
    {
        case '2':
            return "abc";
        case '3':
            return "def";
        case '4':
            return "ghi";
        case '5':
            return "jkl";
        case '6':
            return "mno";
        case '7':
            return "pqrs";
        case '8':
            return "tuv";
    }
    return "wxyz";
}

class Solution {
public:
    vector<string> letterCombinations(const string &digits) 
    {
        vector<string> combinations;
        int size=digits.size();
        string *digit=new string[size];
        for(int i=0;i<size;++i)
            digit[i]=number(digits[i]);
        switch(size)
        {
            case 0:
                return combinations;
            case 1:
                for(int i=0;i<digit[0].size();++i)
                {
                    string aux;
                    aux=aux+digit[0][i];
                    combinations.push_back(aux);
                }
                return combinations;
            case 2:
                for(int i=0;i<digit[0].size();++i)
                {
                    string aux;
                    aux=aux+digit[0][i];
                    for(int j=0;j<digit[1].size();++j)
                    {
                        string aux1=aux;
                        aux1=aux1+digit[1][j];
                        combinations.push_back(aux1);
                    }
                }
                return combinations;
            case 3:
                for(int i=0;i<digit[0].size();++i)
                {
                    string aux;
                    aux=aux+digit[0][i];
                    for(int j=0;j<digit[1].size();++j)
                    {
                        string aux1=aux;
                        aux1=aux1+digit[1][j];
                        for(int k=0;k<digit[2].size();++k)
                        {
                            string aux2=aux1;
                            aux2=aux2+digit[2][k];
                            combinations.push_back(aux2);
                        }
                    }
                }
                return combinations;
        }
        for(int i=0;i<digit[0].size();++i)
        {
            string aux;
            aux=aux+digit[0][i];
            for(int j=0;j<digit[1].size();++j)
            {
                string aux1=aux;
                aux1=aux1+digit[1][j];
                for(int k=0;k<digit[2].size();++k)
                {
                    string aux2=aux1;
                    aux2=aux2+digit[2][k];
                    for(int l=0;l<digit[3].size();++l)
                    {
                        string aux3=aux2;
                        aux3=aux3+digit[3][l];
                        combinations.push_back(aux3);
                    }
                }
            }
        }
        
        return combinations;
    }
};