// https://codility.com/programmers/task/count_factors/

#include <math.h>

int solution(int N) {
    int sqrtN = ceil(sqrt(N));
    int count = 0;
    for (int i = 1; i < sqrtN; ++i)
    {
        if (N % i == 0)
            count += 2;
    }
    
    if (sqrtN * sqrtN == N)
        ++count;
        
    return count;
}
