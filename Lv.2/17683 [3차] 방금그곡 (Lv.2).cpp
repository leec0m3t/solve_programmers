// https://programmers.co.kr/learn/courses/30/lessons/17683

#include <string>
#include <sstream>
#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<string, string> table = 
{
    {"C","A"},
    {"C#","B"},
    {"D","C"},
    {"D#","D"},
    {"E","E"},
    {"F","F"},
    {"F#","G"},
    {"G","H"},
    {"G#","I"},
    {"A","J"},
    {"A#","K"},
    {"B","L"}
};

string convert(string s)
{
    int n = (int)s.size();
    string retval = "";
    
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if (i < n - 1 && s[i + 1] == '#')
        {
            retval += table[s.substr(i, 2)];
            ++i;
        }
        
        else
            retval += table[s.substr(i, 1)];
    }
    
    return retval;
}

bool compare(tuple<string, int, int> a, tuple<string, int, int> b)
{
    if (get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);
    
    else
        return get<2>(a) < get<2>(b);
}

string solution(string m, vector<string> musicinfos)
{
    vector<tuple<string, int, int>> musics;
    vector<string> answers;
    
    string answer = "";
    
    m = convert(m);
    
    for (int i = 0; i < (int)musicinfos.size(); ++i)
    {
        istringstream ss(musicinfos[i]);
        
        string from, to, name, note;
        
        getline(ss, from, ',');
        getline(ss, to, ',');
        getline(ss, name, ',');
        getline(ss, note, ',');
        
        int from_hour = ((from[0] - '0') * 10) + (from[1] - '0');
        int from_min = ((from[3] - '0') * 10) + (from[4] - '0');
        
        int to_hour = ((to[0] - '0') * 10) + (to[1] - '0');
        int to_min = ((to[3] - '0') * 10) + (to[4] - '0');
        
        int duration = (to_hour * 60) + to_min - ((from_hour * 60) + from_min);
        
        string real_note = "";
        
        int x = 0;
        
        for (int j = 0; x < duration; ++j)
        {
            real_note += note[j % (int)note.size()];
            x++;
            
            if (note[(j + 1) % (int)note.size()] == '#')
            {
                real_note += note[(j + 1) % (int)note.size()];
                ++j;
            }
        }
        
        real_note = convert(real_note);
        
        if (real_note.find(m) != string::npos)
        {
            musics.emplace_back(make_tuple(name, duration, i));
        }
    }
    
    sort(musics.begin(), musics.end(), compare);
    
    if ((int)musics.size() == 0)
        return "(None)";
    
    else
        return get<0>(musics[0]);
}