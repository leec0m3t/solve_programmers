// https://programmers.co.kr/learn/courses/30/lessons/12953

#include <string>
#include <vector>

using namespace std;

int lcm(int a, int b)
{
    int x = a, y = b;
    
    while (x != y)
    {
        if (x > y) x -= y;
        else y -= x;
    }
        
    return a * b / x;
}

int solution(vector<int> arr)
{
    int answer = arr[0];
    
    if ((int)arr.size() == 1)
        return answer;
    
    for (int i = 1; i < (int)arr.size(); ++i)
        answer = lcm(arr[i], answer);
    
    return answer;
}