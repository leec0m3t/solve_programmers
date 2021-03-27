// https://programmers.co.kr/learn/courses/30/lessons/68936

#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);

void quad(int sy, int sx, int n, const vector<vector<int>>& arr)
{
    if (n < 1)
    {
        return;
    }
    
    else
    {
        bool flag = true;
        int initValue = arr[sy][sx];
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (arr[sy + i][sx + j] != initValue)
                {
                    flag = false;
                    break;
                }
            }
        }
        
        if (flag == true)
        {
            answer[initValue]++;
        }
        
        else
        {
            quad(sy, sx, n / 2, arr);
            quad(sy, sx + (n / 2), n / 2, arr);
            quad(sy + (n / 2), sx, n / 2, arr);
            quad(sy + (n / 2), sx + (n / 2), n / 2, arr);
        }
        
        return;
    }
}

vector<int> solution(vector<vector<int>> arr)
{
    int n = (int)arr.size();
    
    quad(0, 0, n, arr);
    
    return answer;
}