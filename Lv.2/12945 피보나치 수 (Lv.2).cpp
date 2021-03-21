// https://programmers.co.kr/learn/courses/30/lessons/12945

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    const int MOD = 1234567;
    
    if (n == 1) return 1;
    else if (n == 2) return 1;
    
    else
    {
        int a = 1, b = 1;
        int answer = 0;
        
        for (int i = 3; i <= n; ++i)
        {
            answer = (a + b) % MOD;
            
            a = b;
            b = answer;
        }
        
        return answer;
    }
}