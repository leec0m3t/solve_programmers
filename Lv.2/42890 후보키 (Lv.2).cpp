// https://programmers.co.kr/learn/courses/30/lessons/42890

#include <string>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    int n = (int)relation[0].size();
    
    vector<bool> z;
    
    for (int i = 0; i < (1 << n); ++i)
    {
        unordered_map<string, bool> umap;
        bitset<32> bit(i);
        
        bool flag = true;
        
        for (int j = 0; j < (int)relation.size(); ++j)
        {
            string tmp = "";
            
            for (int k = 0; k <= n; ++k)
            {
                if (bit.test(k) == 1)
                {
                    tmp += relation[j][k];
                }
            }
            
            if (umap[tmp] == true)
            {
                flag = false;
                break;
            }
            
            else
            {
                umap[tmp] = true;
            }
        }
        
        if (flag == true)
        {
            bool flag_2 = true;
            
            for (int j = 0; j < n; ++j)
            {
                if (bit.test(j) == 0)
                    continue;
                
                unordered_map<string, int> umap_2;
                bool flag_3 = true;
                
                for (int k = 0; k < (int)relation.size(); ++k)
                {
                    string tmp_2 = "";
                    
                    for (int l = 0; l < n; ++l)
                    {
                        if (l != j && bit.test(l) == 1)
                        {
                            tmp_2 += relation[k][l];
                        }
                    }
                    
                    if (umap_2[tmp_2] == true)
                    {
                        flag_3 = false;
                        break;
                    }
                    
                    else
                    {
                        umap_2[tmp_2] = true;
                    }
                }
                
                if (flag_3 == true)
                {
                    flag_2 = false;
                    break;
                }
            }
            
            if (flag_2 == true)
                answer++;
        }
    }
    
    return answer;
}