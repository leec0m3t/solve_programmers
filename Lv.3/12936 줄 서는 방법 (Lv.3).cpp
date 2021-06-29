// https://programmers.co.kr/learn/courses/30/lessons/12936

#include <vector>

using namespace std;

vector<int> solution(int n, long long k)
{
    vector<int> answer;
    vector<bool> check(n + 1, true);

    long long result = 1;

    long long tk = k;
    int tn = n;

    for (long long i = 1; i <= n; ++i)
        result *= i;

    do
    {
        vector<int> remain;

        for (int i = 1; i <= n; ++i)
        {
            if (check[i] == true)
                remain.emplace_back(i);
        }

        long long x = (tk - 1) / (result / tn);

        check[remain[x]] = false;
        answer.emplace_back(remain[x]);

        tk -= x * (result / tn);
        result /= tn;
        tn--;

    } while (tn >= 1);

    return answer;
}