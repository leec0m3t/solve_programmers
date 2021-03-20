// https://programmers.co.kr/learn/courses/30/lessons/62048

using namespace std;
long long euclid(long long a, long long b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        
        else
            b -= a;
    }
    
    return a;
}

long long solution(int w,int h)
{    
    long long total = (long long)w * (long long)h;
    long long split = (long long)w + (long long)h - euclid((long long)w, (long long)h);
    
    return total - split;
}