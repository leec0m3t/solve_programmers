// https://programmers.co.kr/learn/courses/30/lessons/1835

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, vector<string> data)
{
    int answer = 0;
    string s = "ACFJMNRT";
    
    do
    {
        bool flag = true;
        
        for (int j = 0; j < n; ++i)
        {
            int pos_1 = s.find(data[i][0]);
            int pos_2 = s.find(data[i][2]);
            
            char op = data[i][3];
            
            int goal = data[i][4] - '0' + 1;
            int dist = abs(pos_1 - pos_2);
            
            if (op == '<' && dist >= goal)
            {
                flag = false;
                break;
            }
            
            else if (op == '=' && dist != goal)
            {
                flag = false;
                break;
            }
            
            else if (op == '>' && dist <= goal)
            {
                flag = false;
                break;
            }
        }
        
        if (flag == true)
            answer++;
    } while (next_permutation(s.begin(), s.end()));
    
    return answer;
}