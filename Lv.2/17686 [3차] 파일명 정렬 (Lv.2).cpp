// https://programmers.co.kr/learn/courses/30/lessons/17686

#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cctype>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b)
{
    string a_head = "", b_head = "";
    int a_num = 0, b_num = 0;
    
    string ta = "", tb = "";
    string a_tail = "", b_tail = "";
    
    int flag = 0;
    
    for (int i = 0; i < (int)a.first.size(); ++i)
    {
        if (flag == 0)
        {
            if (a.first[i] < '0' || a.first[i] > '9') a_head += a.first[i];
            else flag = 1;
        }

        if (flag == 1)
        {
            if (a.first[i] >= '0' && a.first[i] <= '9') ta += a.first[i];
            else flag = 2;
        }
            
        if (flag == 2)
        {
            a_tail += a.first[i];
        }
    }
    
    transform(a_head.begin(), a_head.end(), a_head.begin(), ::tolower);
    a_num = stoi(ta);
    
    flag = 0;
    
    for (int i = 0; i < (int)b.first.size(); ++i)
    {
        if (flag == 0)
        {
            if (b.first[i] < '0' || b.first[i] > '9') b_head += b.first[i];
            else flag = 1;
        }

        if (flag == 1)
        {
            if (b.first[i] >= '0' && b.first[i] <= '9') tb += b.first[i];
            else flag = 2;
        }
            
        if (flag == 2)
        {
            b_tail += b.first[i];
        }
    }
    
    transform(b_head.begin(), b_head.end(), b_head.begin(), ::tolower);
    b_num = stoi(tb);
    
    if (a_head != b_head)
        return a_head < b_head;
    
    else if (a_num != b_num)
        return a_num < b_num;
    
    else
        return a.second < b.second;
}

vector<string> solution(vector<string> files)
{
    vector<pair<string, int>> list;
    
    for (int i = 0; i < (int)files.size(); ++i)
        list.emplace_back(make_pair(files[i], i));
    
    sort(list.begin(), list.end(), compare);
    
    vector<string> answer;
    
    for (const auto& i : list)
        answer.emplace_back(i.first);
    
    return answer;
}