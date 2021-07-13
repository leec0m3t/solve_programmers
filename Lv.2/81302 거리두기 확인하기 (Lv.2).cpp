// https://programmers.co.kr/learn/courses/30/lessons/81302

#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <iostream>

using namespace std;

vector<vector<pair<int, int>>> v;

void comb(const vector<pair<int, int>>& origin, vector<pair<int, int>> temp, int n, int last)
{
    if ((int)temp.size() == n)
    {
        v.emplace_back(temp);
        return;
    }
    
    else if ((int)temp.size() == 0)
    {
        for (int i = 0; i < (int)origin.size(); ++i)
        {
            temp.emplace_back(make_pair(origin[i].first, origin[i].second));
            comb(origin, temp, n, i);
            temp.pop_back();
        }
    }
    
    else
    {
        for (int i = last + 1; i < (int)origin.size(); ++i)
        {
            temp.emplace_back(make_pair(origin[i].first, origin[i].second));
            comb(origin, temp, n, i);
            temp.pop_back();
        }
    }
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer((int)places.size(), 0);
    
    for (int i = 0; i < (int)places.size(); ++i)
    {
        vector<pair<int, int>> persons;
    
        for (int j = 0; j < 5; ++j)
        {
            for (int k = 0; k < 5; ++k)
            {
                if (places[i][j][k] == 'P')
                    persons.emplace_back(make_pair(j, k));
            }
        }
        
        v.clear();
        comb(persons, {}, 2, 0);
        
        bool flag = true;
        
        for (int j = 0; (j < (int)v.size()) && flag; ++j)
        {
            auto p1 = v[j][0].first <= v[j][1].first ? v[j][0] : v[j][1];
            auto p2 = v[j][0].first <= v[j][1].first ? v[j][1] : v[j][0];
            
            int dist = abs(p1.first - p2.first) + abs(p1.second - p2.second);
                
            if (dist <= 2)
            {
                bool flag2 = false, flag3 = false;
                
                if (p1.second <= p2.second)
                {
                    for (int k = p1.second; k <= p2.second; ++k)
                    {
                        if (places[i][p1.first][k] == 'X')
                        {
                            flag2 = true;
                            break;
                        }
                    }

                    for (int k = p1.first; k <= p2.first; ++k)
                    {
                        if (places[i][k][p2.second] == 'X')
                        {
                            flag2 = true;
                            break;
                        }
                    }

                    for (int k = p1.first; k <= p2.first; ++k)
                    {
                        if (places[i][k][p1.second] == 'X')
                        {
                            flag3 = true;
                            break;
                        }
                    }

                    for (int k = p1.second; k <= p2.second; ++k)
                    {
                        if (places[i][p2.first][k] == 'X')
                        {
                            flag3 = true;
                            break;
                        }
                    }
                }
                
                else
                {
                    for (int k = p1.second; k >= p2.second; --k)
                    {
                        if (places[i][p1.first][k] == 'X')
                        {
                            flag2 = true;
                            break;
                        }
                    }

                    for (int k = p1.first; k <= p2.first; ++k)
                    {
                        if (places[i][k][p2.second] == 'X')
                        {
                            flag2 = true;
                            break;
                        }
                    }

                    for (int k = p1.first; k <= p2.first; ++k)
                    {
                        if (places[i][k][p1.second] == 'X')
                        {
                            flag3 = true;
                            break;
                        }
                    }

                    for (int k = p1.second; k >= p2.second; --k)
                    {
                        if (places[i][p2.first][k] == 'X')
                        {
                            flag3 = true;
                            break;
                        }
                    }
                }
                
                if (flag2 == false || flag3 == false)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        answer[i] = flag ? 1 : 0;
    }
    
    return answer;
}