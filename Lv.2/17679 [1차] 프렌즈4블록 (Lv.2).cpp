// https://programmers.co.kr/learn/courses/30/lessons/17679

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    bool flag = true;
    
    while (flag)
    {
        vector<vector<bool>> check(m, vector<bool>(n, false));
        flag = false;
        
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                if (board[i][j] != '-' && board[i][j] == board[i][j + 1])
                {
                    if ((board[i][j] == board[i + 1][j]) && (board[i][j + 1] == board[i + 1][j + 1]))
                    {
                        flag = true;
                        
                        check[i][j] = true;
                        check[i + 1][j] = true;
                        check[i][j + 1] = true;
                        check[i + 1][j + 1] = true;
                    }
                }
            }
        }
        
        for (int j = 0; j < n; ++j)   
        {
            for (int i = m - 1; i >= 0; --i)
            {
                if (check[i][j] == true)
                {
                    answer++;
                    board[i][j] = '-';
                }
            }
        }
        
        for (int j = 0; j < n; ++j)   
        {
            for (int i = m - 1; i >= 0; --i)
            {
                if (board[i][j] == '-')
                {
                    for (int k = i - 1; k >= 0; --k)
                    {
                        if (board[k][j] != '-')
                        {
                            board[i][j] = board[k][j];
                            board[k][j] = '-';
                            
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}