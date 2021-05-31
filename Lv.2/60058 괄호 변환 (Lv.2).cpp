// https://programmers.co.kr/learn/courses/30/lessons/60058

#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string recursive(string s)
{
    if (s == "")
        return s; // 1
    
    string u = "", v = "";
    
    int count_u = 0, count_v = 0;
    
    for (int i = 1; i < (int)s.size(); i += 2)
    {
        count_u = 0, count_v = 0;
        
        for (int j = 0; j <= i; ++j)
            count_u += s[j] == '(' ? 1 : -1;
        
        for (int j = i + 1; j < (int)s.size(); ++j)
            count_v += s[j] == '(' ? 1 : -1;
        
        if ((count_u == 0) && (count_v == 0)) // 2
        {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1, (int)s.size() - i);
            
            break;
        }
    }
    
    stack<char> st;
    bool flag = true;
    
    for (int i = 0; i < (int)u.size(); ++i)
    {
        if (u[i] == '(')
            st.push(u[i]);
        
        else if (u[i] == ')')
        {
            if (!st.empty())
                st.pop();
            
            else
            {
                flag = false;
                break;
            }
        }
    }
    
    if (st.empty() && flag)
    {
        string x = recursive(v); // 3
        u += x; // 3-1
            
        return u;
    }
    
    else // 4
    {
        string x = "";
        
        x += "("; // 4-1
        x += recursive(v); // 4-2
        x += ")"; // 4-3
        
        string y = u.substr(1, (int)u.size() - 2);
        
        for (int i = 0; i < (int)y.size(); ++i)
            y[i] = y[i] == '(' ? ')' : '('; // 4-4
        
        return x + y; // 4-5
    }
}

string solution(string p)
{
    return recursive(p);
}