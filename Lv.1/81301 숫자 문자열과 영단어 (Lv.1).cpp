// https://programmers.co.kr/learn/courses/30/lessons/81301

#include <string>

using namespace std;

int solution(string s)
{
    string x = "";
    
    for (int i = 0; i < (int)s.size(); )
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            x.push_back(s[i]);
            i++;
        }
            
        else
        {
            if (s[i] == 'z' && s[i + 3] == 'o')
            {
                x.push_back('0');
                i += 4;
            }
            
            else if (s[i] == 'o' && s[i + 2] == 'e')
            {
                x.push_back('1');
                i += 3;
            }
            
            else if (s[i] == 't')
            {
                if (s[i + 2] == 'o')
                {
                    x.push_back('2');
                    i += 3;
                }
                
                else if (s[i + 4] == 'e')
                {
                    x.push_back('3');
                    i += 5;
                }
            }
            
            else if (s[i] == 'f')
            {
                if (s[i + 3] == 'r')
                {
                    x.push_back('4');
                    i += 4;
                }
                
                if (s[i + 3] == 'e')
                {
                    x.push_back('5');
                    i += 4;
                }
            }
            
            else if (s[i] == 's')
            {
                if (s[i + 2] == 'x')
                {
                    x.push_back('6');
                    i += 3;
                }
                
                if (s[i + 4] == 'n')
                {
                    x.push_back('7');
                    i += 5;
                }
            }
            
            else if (s[i] == 'e' && s[i + 4] == 't')
            {
                x.push_back('8');
                i += 5;
            }
            
            else if (s[i] == 'n' && s[i + 3] == 'e')
            {
                x.push_back('9');
                i += 4;
            }
        }
    }
    
    return stoi(x);
}