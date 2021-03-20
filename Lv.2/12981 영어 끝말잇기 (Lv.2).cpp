// https://programmers.co.kr/learn/courses/30/lessons/12981

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer(2, 0);
    unordered_map<string, bool> umap;
    
    string prev = words[0];
    
    int idx = 0;
    
    for (int i = 0; i < (int)words.size(); ++i)
    {
        if (umap.find(words[i]) != umap.end())
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            
            break;
        }
        
        else if ((prev[(int)prev.size() - 1] != words[i][0]) && (i > 0))
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            
            break;
        }
        
        else
        {
            prev = words[i];
            umap[words[i]] = true;
        }
    }
    
    return answer;
}