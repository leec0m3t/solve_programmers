// https://programmers.co.kr/learn/courses/30/lessons/17680

#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;
    
    for (int i = 0; i < (int)cities.size(); ++i)
    {
        string s = "";
        
        for (int j = 0; j < (int)cities[i].size(); ++j)
            s.push_back(tolower(cities[i][j]));

        bool flag = true;
        int idx = 0;
        
        for (int j = 0; j < (int)cache.size(); ++j)
        {
            if (cache[j] == s)
            {
                flag = false;
                idx = j;
                
                break;
            }
        }
            
        if (flag == true)
        {
            cache.emplace_back(s);
                
            if ((int)cache.size() > cacheSize)
                cache.erase(cache.begin());
                
            answer += 5;
        }
            
        else
        {
            cache.push_back(*(cache.begin() + idx));
            
            if ((int)cache.size() >= cacheSize)
                cache.erase(cache.begin() + idx);
                
            answer += 1;
        }
    }
        
    return answer;
}