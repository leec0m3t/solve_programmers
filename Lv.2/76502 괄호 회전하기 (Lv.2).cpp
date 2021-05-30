// https://programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    for (int i = 0; i < (int)s.size(); ++i)
    {
        string temp = s.substr(i, (int)s.size() - i) + s.substr(0, i);
        
        stack<char> st;
        bool flag = true;
        
        for (int j = 0; j < (int)temp.size(); ++j)
        {
            if (temp[j] == '[' || temp[j] == '{' || temp[j] == '(')
                st.push(temp[j]);
            
            else if (temp[j] == ']')
            {   
                if (!st.empty() && st.top() == '[')
                    st.pop();
                
                else
                {
                    flag = false;
                    break;
                }
            }
            
            else if (temp[j] == '}')
            {
                if (!st.empty() && st.top() == '{')
                    st.pop();
                
                else
                {
                    flag = false;
                    break;
                }
            }
            
            else if (temp[j] == ')')
            {
                if (!st.empty() && st.top() == '(')
                    st.pop();
                
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if (st.empty() && flag)
            answer++;
    }
    
    return answer;
}