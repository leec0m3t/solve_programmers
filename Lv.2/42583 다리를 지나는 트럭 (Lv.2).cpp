// https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int n = (int)truck_weights.size();
    
    vector<int> complete;
    vector<pair<int, int>> across;
    
    int total = 0;
    
    while ((int)complete.size() < n)
    {   
        bool flag = false;
        auto itt = across.begin();

        for (auto it = across.begin(); it != across.end(); ++it)
        {
            it->second--;

            if (it->second == 0)
            {
                itt = it;
                flag = true;
            }
        }

        if (flag == true)
        {
            complete.emplace_back(itt->first);

            total -= itt->first;
            across.erase(itt);
        }

        auto it = truck_weights.begin();

        if (it != truck_weights.end() && total + (*it) <= weight && (int)across.size() < bridge_length)
        {
            total += (*it);
            across.emplace_back(make_pair(*it, bridge_length));

            truck_weights.erase(it);
        }

        answer++;
    }

    return answer;
}