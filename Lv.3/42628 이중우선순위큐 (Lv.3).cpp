// https://programmers.co.kr/learn/courses/30/lessons/42628

#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations)
{
    map<int, int> m;
    
    for (const auto& i : operations)
    {
        stringstream ss(i);
        
        string op = "";
        int num = 0;
        
        ss >> op >> num;
        
        if (op == "I")
            m[num]++;
        
        else if (num == 1 && (int)m.size() != 0)
        {
            auto it = m.end();
            it--;
            
            it->second--;
            
            if (it->second <= 0)
                m.erase(it);
        }
            
        else if (num == -1 && (int)m.size() != 0)
        {
            auto it = m.begin();
            it->second--;
            
            if (it->second <= 0)
                m.erase(it);  
        }
    }
    
    vector<int> answer(2, 0);
    
    if ((int)m.size() != 0)
    {
        auto s = m.begin();
        auto e = m.end();
        e--;
        
        answer[0] = e->first;
        answer[1] = s->first;
    }
    
    return answer;
}