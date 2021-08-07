// https://programmers.co.kr/learn/courses/30/lessons/82612

using namespace std;

long long solution(int price, int money, int count)
{
    long long diff = (1LL * price * count * (count + 1) / 2) - (long long)money;
    
    return diff >= 0 ? diff : 0;
}