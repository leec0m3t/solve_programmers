// https://programmers.co.kr/learn/courses/30/lessons/12905

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    
    int columns = (int)board.size();
    int rows = (int)board[0].size();
    
    if (columns == 1 && rows == 1)
        return board[0][0] == 0 ? 0 : 1;
    
    for (int i = 1; i < columns; ++i)
    {
        for (int j = 1; j < rows; ++j)
        {
            if (board[i][j] == 1)
            {
                board[i][j] = min({board[i - 1][j - 1], board[i][j - 1], board[i - 1][j]}) + 1;
                
                if (board[i][j] > answer)
                    answer = board[i][j];
            }
        }
    }
    
    return answer * answer;
}