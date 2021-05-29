// https://programmers.co.kr/learn/courses/30/lessons/43162

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    int num = 2;
    
    queue<int> q;
    
    for (int i = 0; i < (int)computers.size(); ++i)
    {
        if (computers[i][i] == 1)
        {
            q.push(i);
            computers[i][i] = num;

            while(!q.empty())
            {
                int val = q.front();
                q.pop();
                
                for (int j = 0; j < (int)computers[val].size(); ++j)
                {
                    if (computers[val][j] == 1)
                    {
                        q.push(j);
                        
                        computers[val][j] = num;
                        computers[j][val] = num;
                    }
                }
            }
            
            num++;
        }
    }
    
    answer = num - 2;
    
    return answer;
}