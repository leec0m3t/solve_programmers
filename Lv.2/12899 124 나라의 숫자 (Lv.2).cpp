// https://programmers.co.kr/learn/courses/30/lessons/12899

#include <string>
#include <algorithm>
using namespace std;

string solution(int n)
{
    string answer = "";

    while (n != 0)
    {
        answer.push_back((n % 3 == 0) ? '4' : n % 3 + '0');
        n = (n % 3 == 0) ? n / 3 - 1 : n / 3;
    }

    reverse(answer.begin(), answer.end());

    return answer;
}