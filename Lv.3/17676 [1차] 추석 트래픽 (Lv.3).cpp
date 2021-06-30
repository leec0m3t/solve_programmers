// https://programmers.co.kr/learn/courses/30/lessons/17676

#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

pair<int, int> parse(string line)
{
    int HOUR = stoi(line.substr(11, 2));
    int MINUTE = stoi(line.substr(14, 2));
    
    double SECOND = stod(line.substr(17, 6));
    double DUR = stod(line.substr(24, (int)line.size() - 24));
    
    int end_time = (HOUR * 60 * 60 * 1000) + (MINUTE * 60 * 1000) + (SECOND * 1000);
    int duration = (DUR * 1000);
    
    return make_pair(end_time + 1 - duration, end_time);
}

int solution(vector<string> lines)
{ 
    vector<pair<int, int>> v;
    map<int, int> m;
    
    for (int i = 0; i < (int)lines.size(); ++i)
    {
        pair<int, int> p = parse(lines[i]);
        
        v.emplace_back(p);
        
        for (int j = p.first; j < p.second + 1000; ++j)
            m[j]++;
    }
    
    sort(v.begin(), v.end());
    
    int answer = 1;
    
    for (int i = 0; i < (int)v.size(); ++i)
    {
        for (int j = v[i].first; j < v[i].first + 1000; ++j)
        {
            answer = answer > m[j] ? answer : m[j];
        }
        
        for (int j = v[i].second; j < v[i].second + 1000; ++j)
        {
            answer = answer > m[j] ? answer : m[j];
        }
    }
    
    return answer;
}