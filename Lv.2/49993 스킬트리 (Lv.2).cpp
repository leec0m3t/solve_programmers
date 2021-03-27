// https://programmers.co.kr/learn/courses/30/lessons/49993

#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    
    for(int i = 0; i < (int)skill_trees.size(); ++i)
    {
        bool flag = true;
        int prev = -1;
        
        for (int j = 0; j < (int)skill_trees[i].size(); ++j)
        {
            if (flag == false)
                break;
            
            for (int k = 0; k < (int)skill.size(); ++k)
            {
                if (skill_trees[i][j] == skill[k])
                {  
                    if (prev == k - 1)
                    {
                        prev = k;
                        continue;
                    }
                    
                    else
                    {
                        flag = false;
                        break;
                    }
                }
            }
        }
        
        if (flag == true)
            answer++;
    }
    
    return answer;
}