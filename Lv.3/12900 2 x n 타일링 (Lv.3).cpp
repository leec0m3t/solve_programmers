// https://programmers.co.kr/learn/courses/30/lessons/12900

#include <vector>

using namespace std;

const int MOD = 1000000007;

int solution(int n)
{
    int answer = 0;
    
    int prev = 1, curr = 2;
    
    if (n == 1)
        return 1;
    
    else if (n == 2)
        return 2;
    
    else
    {
        for (int i = 3; i <= n; ++i)
        {
            int temp = prev + curr;
            
            prev = curr;
            curr = temp;
            
            curr %= MOD;
        }
        
        return curr;
    }
}