// https://programmers.co.kr/learn/courses/30/lessons/12973

#include <vector>
#include <string>
using namespace std;

int solution(string s)
{
    vector<char> v;
    
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if ((int)v.size() == 0)
        {
            v.emplace_back(s[i]);
        }
        
        else if (v[(int)v.size() - 1] != s[i])
        {
            v.emplace_back(s[i]);
        }
        
        else
        {
            v.pop_back();
        }
    }
    
    if ((int)v.size() == 0)
        return 1;
    
    else
        return 0;
}