// https://programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>
#include <utility>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int idx = 0;
    
    int n = (int)number.size();
    int a = 0;
     
    while (a < n - k)
    {
        pair<int, char> p = {idx, number[idx]};

        for (int i = idx; i <= k + a; ++i)
        {
            if (p.second < number[i])
                p = make_pair(i, number[i]);
        }
        
        answer.push_back(p.second);
        idx = p.first + 1;
        
        a++;
    }
    
    return answer;
}