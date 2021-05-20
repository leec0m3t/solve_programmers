// https://programmers.co.kr/learn/courses/30/lessons/17677

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

int solution(string str1, string str2)
{
    float answer = 0.0f;
    
    transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c){ return tolower(c); });
    transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c){ return tolower(c); });
    
    unordered_map<string, int> umap1;
    
    for (int i = 0; i < (int)str1.size() - 1; ++i)
    {
        if (isalpha(str1[i]) && isalpha(str1[i + 1]))
            umap1[str1.substr(i, 2)]++;
    }
    
    unordered_map<string, int> umap2;
    
    for (int i = 0; i < (int)str2.size() - 1; ++i)
    {
        if (isalpha(str2[i]) && isalpha(str2[i + 1]))
            umap2[str2.substr(i, 2)]++;
    }
    
    if ((int)umap1.size() == 0 && (int)umap2.size() == 0)
        answer = 1.0;
    
    else
    {
        vector<string> uset;
        vector<string> iset;
        
        for (auto it = umap1.begin(); it != umap1.end(); it++)
        {
            int max = it->second > umap2[it->first] ? it->second : umap2[it->first];
            
            for (int i = 0; i < max; ++i)
            {
                uset.emplace_back(it->first);
            }
        }
        
        for (auto it = umap2.begin(); it != umap2.end(); it++)
        {
            int max = it->second > umap1[it->first] ? it->second : umap1[it->first];
            
            if (umap1[it->first] == 0)
            {
                for (int i = 0; i < max; ++i)
                {
                    uset.emplace_back(it->first);
                }
            }
        }
        
        for (auto it = umap1.begin(); it != umap1.end(); it++)
        {
            int min = it->second < umap2[it->first] ? it->second : umap2[it->first];
            
            for (int i = 0; i < min; ++i)
            {
                iset.emplace_back(it->first);
            }
        }
        
        answer = (float)iset.size() / (float)uset.size();
    }
    
    return (int)(answer * 65536);
}