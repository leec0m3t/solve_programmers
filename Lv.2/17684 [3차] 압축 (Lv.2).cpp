// https://programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> umap;

    int index = 27;

    for (char c = 'A'; c <= 'Z'; ++c)
    {
        string s = "";
        s += c;

        umap[s] = c - 'A' + 1;
    }

    for (int i = 0; i < (int)msg.size(); )
    {
        string prev = "", curr = "";
        int step = 0;

        for (int j = 1; ; ++j)
        {
            curr = msg.substr(i, j);

            if (umap[curr] != 0 && (i + j) == (int)msg.size())
            {
                answer.emplace_back(umap[curr]);
                step = j;
                
                break;
            }

            else if (umap[curr] == 0)
            {
                umap[curr] = index;
                ++index;

                answer.emplace_back(umap[prev]);
                step = j - 1;

                break;
            }

            prev = curr;
        }

        i += step;
    }

    return answer;
}