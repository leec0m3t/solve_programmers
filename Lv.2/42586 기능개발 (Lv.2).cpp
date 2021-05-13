// https://programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    while ((int)progresses.size() != 0)
    {
        int done_task = 0;
        
        for (int i = 0; i < (int)progresses.size(); ++i)
            progresses[i] += speeds[i];
        
        auto it = progresses.begin();
        auto itt = speeds.begin();
        
        while(it != progresses.end())
        {
            if (*it >= 100)
            {
                it = progresses.erase(it);
                itt = speeds.erase(itt);
                
                ++done_task;
            }
            
            else
                break;
        }
        
        if (done_task != 0)
            answer.emplace_back(done_task);
    }
    
    return answer;
}