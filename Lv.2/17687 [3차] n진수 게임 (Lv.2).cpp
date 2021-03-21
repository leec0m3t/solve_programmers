// https://programmers.co.kr/learn/courses/30/lessons/17687

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string convert_base(int x, int b)
{
    string s = "";
    
    while (x != 0)
    {
        char c = ((x % b) < 10) ? (x % b) + '0' : (x % b) - 10 + 'A';
        s.push_back(c);
        
        x /= b;
    }
    
    reverse(s.begin(), s.end());
    
    return s;
}

string solution(int n, int t, int m, int p)
{
    string result = "0";
    string answer = "";
    
    int idx = 1;
    
    while ((int)result.size() < (t * m))
    {
        result += convert_base(idx, n);
        ++idx;
    }
    
    int i = p - 1;
    int count = 0;
    
    while (count < t)
    {
        answer += result[i];
        
        i += m;
        count++;
    }
    
    return answer;
}