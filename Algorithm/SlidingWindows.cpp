#include<string>
#include<unordered_map>
using namespace std;

//leetcode 76
string slidingWindow(string s, string t)
{
    unordered_map<char, int> need, window;
    for(char c:t)
        need[c]++;
    int left=0, right=0;
    int match=0;
    int start=0, min=INT_MAX;
    while(right<s.size())
    {
        char c=s[right];
        right++;
        if(need.count(c))
        {
            window[c]++;
            if(window[c]==need[c])
            {
                match++;
            }
        }
        while(match==needs.size())
        {
            if(right-left<min)
            {
                min=right-left;
                start=left;
            }
            char d=s[left];
            left++;
            if(needs.count(d))
            {
                if(window[d]==needs[d])
                    match--;
                window[d]--;
            }

        }
    }
    if(min==INT_MAX)
        return "";
    return s.substr(start, min);
}