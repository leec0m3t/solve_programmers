// https://programmers.co.kr/learn/courses/30/lessons/60057

#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 987654321;
    
    if ((int)s.size() == 1)
        return 1;

    for (int i = 1; i <= (int)s.size() / 2; ++i)
    {
        string tmp = s;
        string ret = "";

        while ((int)tmp.size() >= i)
        {
            string token = tmp.substr(0, i);
            int count = 0;

            size_t pos = tmp.find(token);

            while (pos == 0)
            {
                count++;
                tmp = tmp.substr(i);

                pos = tmp.find(token);
            }
            
            ret += (count == 1 ? "" : to_string(count)) + token;
        }

        ret += tmp;

        answer = (int)ret.size() < answer ? (int)ret.size() : answer;
    }

    return answer;
}