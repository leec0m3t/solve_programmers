// https://programmers.co.kr/learn/courses/30/lessons/42839

#include <string>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<bool> sifter(9999999, true);
unordered_map<int, bool> umap;

void initSifter()
{
    sifter[0] = false;
    sifter[1] = false;
    
    for (int i = 2; i < sqrt((int)sifter.size()); ++i)
    {
        if (sifter[i] == false)
            continue;
        
        for (int j = i * i; j < (int)sifter.size(); j += i)
            sifter[j] = false;
    }
}

void perm_str(string from, string to, int length)
{
    if ((int)to.size() == length)
    {
        int x = stoi(to);
        
        if (sifter[x] == true)
            umap[x] = true;
        
        return;
    }
    
    for (int i = 0; i < (int)from.size(); ++i)
    {
    	string u = from.substr(0, i) + from.substr(i + 1);
    	string v = to + from[i];
        
        perm_str(u, v, length);
    }
}

int solution(string numbers)
{
    initSifter();
    
    for (int i = 0; i < (int)numbers.size(); ++i)
        perm_str(numbers, "", i + 1);
    
    return (int)umap.size();
}