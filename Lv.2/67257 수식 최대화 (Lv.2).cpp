// https://programmers.co.kr/learn/courses/30/lessons/67257

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
#include <utility>
#include <cmath>

using namespace std;

const int add = 1000;
const int sub = 1001;
const int mul = 1002;

long long solution(string expression)
{
    long long answer = 0;

    vector<pair<long long, int>> token;
    vector<int> op_pos = { 1, 2, 3 };

    string tmp = "";

    for (int i = 0; i < (int)expression.size(); ++i)
    {
        if ('0' <= expression[i] && expression[i] <= '9')
        {
            tmp += expression[i];

            if (i == (int)expression.size() - 1)
                token.emplace_back(make_pair(stoll(tmp), 0));
        }

        else
        {
            token.emplace_back(make_pair(stoll(tmp), 0));
            tmp = "";

            if (expression[i] == '+')
                token.emplace_back(make_pair(add, 0));

            else if (expression[i] == '-')
                token.emplace_back(make_pair(sub, 0));

            else if (expression[i] == '*')
                token.emplace_back(make_pair(mul, 0));
        }
    }

    long long max = LLONG_MIN;

    do
    {
        vector<pair<long long, int>> exp = token;

        for (int i = 1; i < (int)exp.size(); i += 2)
        {
            if (exp[i].first == add) exp[i].second = op_pos[0];
            else if (exp[i].first == sub) exp[i].second = op_pos[1];
            else if (exp[i].first == mul) exp[i].second = op_pos[2];
        }

        for (int i = 1; i <= (int)op_pos.size(); )
        {
            bool flag = true;

            for (int j = 1; j < (int)exp.size(); j += 2)
            {
                if (exp[j].second == i)
                {
                    flag = false;

                    long long result = 0;

                    switch (exp[j].first)
                    {
                    case add:
                        result = exp[j - 1].first + exp[j + 1].first;
                        break;

                    case sub:
                        result = exp[j - 1].first - exp[j + 1].first;
                        break;

                    case mul:
                        result = exp[j - 1].first * exp[j + 1].first;
                        break;
                    }

                    exp[j + 1].first = result;

                    exp.erase(exp.begin() + (j - 1), exp.begin() + (j + 1));
                    break;
                }
            }

            if (flag == true)
                ++i;
        }

        max = abs(exp[0].first) > abs(max) ? abs(exp[0].first) : abs(max);

    } while (next_permutation(op_pos.begin(), op_pos.end()));

    return max;
}