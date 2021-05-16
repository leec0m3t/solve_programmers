// https://programmers.co.kr/learn/courses/30/lessons/77885

#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (int i = 0; i < (int)numbers.size(); ++i)
    {
        long long num = numbers[i];
        
        if (num % 2 == 0)
            answer.emplace_back(num + 1);
        
        else
        {
            int count = 0;
            
            while ((num & 0b11) != 0b01)
            {
                ++count;
                
                num >>= 1;
            }
            
            ++num;
            
            while (count != 0)
            {
                --count;
                
                num <<= 1;
                ++num;
            }
            
            answer.emplace_back(num);
        }
    }
    
    return answer;
}