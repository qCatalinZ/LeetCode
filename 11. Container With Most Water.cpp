#include <iostream>
#include <vector>
using namespace std;

/// REZOLVARE IN o(N x N)
/*
int max(int a, int b)
{
    return (a>=b) ? a : b;
}

class Solution
{
public:
    int maxArea(const vector<int>& height)
    {
        int maxArea=0;

        for( int start = 0 ; start < (int)height.size() ; ++start )
        {
            int end=start+1;
            while(end < (int)height.size() )
            {
                int min = (height[start] >= height[end]) ? height[end] : height[start];
                maxArea = max(maxArea,(end-start)*min);
                // prelaucrare arie
                end++;
            }
        }

        return maxArea;
    }
};
*/


int max(int a, int b)
{
    return (a>=b) ? a : b;
}

class Solution
{
public:
    int maxArea(const vector<int>& height)
    {
        int maxArea=0;
        int start = 0, end = (int)height.size()-1;

        while(/*end < (int)height.size() && start < (int)height.size() &&*/ start < end )
        {
            bool condition=true;
            int min = (height[start] >= height[end]) ? height[end] : height[start];
            maxArea = max(maxArea,(end-start)*min);
            // prelaucrare arie
            if(height[start] <= height[end] )
            {
                start++;
                condition=false;
            }
            else if(height[start] > height[end] )
            {
                end--;
                condition=false;
            }

            if(condition)
            {
                break;
            }

        }

        return maxArea;
    }
};


int main()
{

    return 0;
}
