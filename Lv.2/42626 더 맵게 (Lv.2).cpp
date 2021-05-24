// https://programmers.co.kr/learn/courses/30/lessons/42626

#include <vector>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while (pq.size() >= 2)
    {
        int one = pq.top();
        pq.pop();
        
        if (one >= K)
            return answer;
        
        else
        {
            int two = pq.top();
            pq.pop();
            
            int result = one + two * 2;
            pq.push(result);
            
            ++answer;
        }
    }
    
    return pq.top() >= K ? answer : -1;
}