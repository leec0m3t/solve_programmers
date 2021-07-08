// https://programmers.co.kr/learn/courses/30/lessons/81301

#include <string>
#include <vector>
#include <cctype>

using namespace std;

int solution(string s)
{
    const vector<string> digit =
    {
        "zero",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    
    string x = "";
    
    int i = 0;
    int n = (int)s.size();
    
    while (i < n)
    {
        if (isdigit(s[i]))
        {
            x.push_back(s[i]);
            ++i;
        }
        
        else
        {
            for (int j = 0; j < 10; ++j)
            {
                if (s.substr(i, (int)digit[j].size()) == digit[j])
                {
                    x.push_back(j + '0');
                    i += (int)digit[j].size();
                    
                    break;
                }
            }
        }
    }
    
    return stoi(x);
}