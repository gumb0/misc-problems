// https://codility.com/programmers/task/triangle/

#include <algorithm>

int solution(vector<int> &A) {
    if (A.size() < 3)
        return 0;
    
    sort(A.begin(), A.end());
    
    for (size_t i = 0; i <= A.size() - 3; ++i)
        if (static_cast<long long>(A[i]) + A[i + 1] > A[i + 2])
            return 1;
        
    return 0;
}