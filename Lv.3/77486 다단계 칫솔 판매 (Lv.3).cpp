// https://programmers.co.kr/learn/courses/30/lessons/77486

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    map<string, string> en2ref;
    
    for (int i = 0; i < (int)enroll.size(); ++i)
        en2ref[enroll[i]] = referral[i];
    
    map<string, int> benefit;
    
    for (int i = 0; i < (int)seller.size(); ++i)
    {
        string name = seller[i];
        
        int x = amount[i] * 100;
        
        int other = x / 10;
        int me = x - other;
        
        while (name != "-")
        {
            if (other > 0)
            {
                benefit[name] += me;
            }
            
            else
            {
                benefit[name] += x;
                break;
            }
            
            x = other;
            
            other = x / 10;
            me = x - other;
            
            name = en2ref[name];
        }
    }   
        
    vector<int> answer;
    
    for (const auto& i : enroll)
        answer.emplace_back(benefit[i]);
    
    return answer;
}