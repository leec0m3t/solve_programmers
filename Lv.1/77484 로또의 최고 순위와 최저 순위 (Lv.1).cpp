// https://programmers.co.kr/learn/courses/30/lessons/77484

#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    int alt = 0;
    int correct = 0;
    
    for (int i = 0; i < (int)lottos.size(); ++i)
    {
        if (lottos[i] == 0)
        {
            ++alt;
            continue;
        }
        
        for (int j = 0; j < (int)win_nums.size(); ++j)
        {
            if (lottos[i] == win_nums[j])
            {
                ++correct;
                break;
            }
        }
    }
    
    vector<int> answer(2, 0);
    
    answer[0] = (alt + correct) == 0 ? 6 : 7 - (alt + correct);
    answer[1] = correct == 0 ? 6 : 7 - correct;
    
    return answer;
}