// https://programmers.co.kr/learn/courses/30/lessons/70129

#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer(2, 0);
    
    while (s != "1")
    {
        auto it = s.begin();
        
        while (it != s.end())
        {
            if (*(it) == '0')
            {
                it = s.erase(it);
                answer[1]++;
            }
            
            else
                it++;
        }
        
        int n = (int)s.size();
        s = "";
        
        while (n != 0)
        {
            if (n % 2 == 0)
                s.push_back('0');
            
            else
                s.push_back('1');
            
            n /= 2;
        }
        
        reverse(s.begin(), s.end());
        answer[0]++;
    }
    
    return answer;
}