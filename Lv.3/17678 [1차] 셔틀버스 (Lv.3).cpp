// https://programmers.co.kr/learn/courses/30/lessons/17678

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int str2int(string s)
{
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
        
    return (hour * 60) + minute;
}

string int2str(int val)
{
    ostringstream oss;
    
    int hour = val / 60;
    int minute = val % 60;
    
    oss << setfill('0') << setw(2) << hour;
    oss << ":";
    oss << setfill('0') << setw(2) << minute;
    
    return oss.str();
}

string solution(int n, int t, int m, vector<string> timetable)
{
    string answer = "";
    
    vector<int> shuttle;
    vector<int> tb;
    
    for (const auto& i : timetable)
        tb.emplace_back(str2int(i));
    
    sort(tb.begin(), tb.end());
    
    for (int i = 0; i < n; ++i)
        shuttle.emplace_back(540 + (i * t));
    
    int last = 0;
    bool over = false;
    
    for (int i = 0; i < (int)shuttle.size(); ++i)
    {
        int count = 0;
        auto it = tb.begin();
        
        over = false;
        
        while (it != tb.end() && *it <= shuttle[i])
        {
            cout << *it << " " << count + 1 << endl;
            count++;
            
            if (count >= m)
            {
                if (i == (int)shuttle.size() - 1)
                {
                    last = *it;
                    over = true;
                }
                
                it = tb.erase(it);
                break;
            }
            
            it = tb.erase(it);
        }
        
        if (over == true)
        {
            answer = int2str(last - 1);
            break;
        }
        
        else
        {
            answer = int2str(shuttle[i]);
        }
    }
    
    return answer;
}

