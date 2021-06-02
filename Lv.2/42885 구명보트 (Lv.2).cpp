// https://programmers.co.kr/learn/courses/30/lessons/42885

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end(), greater<int>());
    
    int h_id = 0;
    int l_id = (int)people.size() - 1;
    
    int answer = 0;
    
    while (h_id <= l_id)
    {
        if (people[h_id] + people[l_id] <= limit)
        {
            answer++;
            
            h_id++;
            l_id--;
        }
        
        else
        {
            answer++;
            
            h_id++;
        }
    }
    
    return answer;
}