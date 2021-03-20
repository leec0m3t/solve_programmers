// https://programmers.co.kr/learn/courses/30/lessons/12977

#include <vector>

using namespace std;

vector<bool> sifter(3000, true);
vector<bool> check;
int answer = 0;

void recursive(vector<int> v, int start, int sum, int cnt)
{
    if (cnt == 3)
    {
        if (sifter[sum] == true)
            answer++;
        
        return;
    }
    
    for (int i = start; i < (int)v.size(); ++i)
    {
        if (check[i] == true)
            continue;
        
        check[i] = true;
        
        recursive(v, i, sum + v[i], cnt + 1);
        
        check[i] = false;
    }
}

int solution(vector<int> nums)
{
    sifter[0] = false;
    sifter[1] = false;
    
    for (int i = 2; i < (int)sifter.size(); ++i)
    {
        if (sifter[i] == false)
            continue;
        
        for (int j = i * 2; j < (int)sifter.size(); j += i)
            sifter[j] = false;
    }
    
    check.resize((int)nums.size(), false);
    
    recursive(nums, 0, 0, 0);

    return answer;
}