// https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const int& x, const int& y)
{
    string a = to_string(x) + to_string(y);
    string b = to_string(y) + to_string(x);
    
    return stoi(a) > stoi(b);
}

string solution(vector<int> numbers)
{
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    for (const auto& i : numbers)
        answer += to_string(i);
    
    bool flag = true;
    
    for (const auto& i : answer)
    {
        if (i != '0')
        {
            flag = false;
            break;
        }
    }
    
    if (flag == true)
        return "0";
    
    return answer;
}