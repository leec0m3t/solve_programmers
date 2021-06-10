// https://programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>

using namespace std;

int diff_x(int from, int to, int n)
{
    int a = 0, b = 0;

    if (from < to)
    {
        a = from;
        b = to;
    }

    else
    {
        a = to;
        b = from;
    }

    return ((b - a) < (a + n - b)) ? b - a : a + n - b;
}

int diff_y(char c)
{
    return ((c - 'A') < ('Z' + 1 - c)) ? c - 'A' : 'Z' + 1 - c;
}

int solution(string name)
{
    int answer = 0;
    int curpos = 0;
    int count = 0;
    int goal = 0;

    vector<bool> v((int)name.size(), true);

    for (int i = 0; i < (int)name.size(); ++i)
    {
        if (name[i] == 'A')
            v[i] = false;
        
        else
            goal++;
    }

    while (count != goal)
    {
        int t1 = curpos, t2 = curpos;
        int c1 = 0, c2 = 0;

        while (v[t1] == false && c1 <= goal)
        {
            t1 = (t1 + 1) % (int)v.size();
            c1++;
        }

        while (v[t2] == false && c2 <= goal)
        {
            t2 = (t2 - 1) >= 0 ? t2 - 1 : t2 + (int)v.size() - 1;
            c2++;
        }
        
        if (diff_x(curpos, t1, (int)name.size()) <= diff_x(curpos, t2, (int)name.size()))
        {
            answer += diff_x(curpos, t1, (int)name.size());

            curpos = t1;

            v[t1] = false;
            count++;

            answer += diff_y(name[t1]);
        }

        else
        {
            answer += diff_x(curpos, t2, (int)name.size());

            curpos = t2;

            v[t2] = false;
            count++;
            
            answer += diff_y(name[t2]);
        }
    }

    return answer;
}