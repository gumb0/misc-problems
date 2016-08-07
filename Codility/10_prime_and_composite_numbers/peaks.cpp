// https://codility.com/programmers/task/peaks/

bool isValidDivision(const vector<size_t>& peaks, size_t k, size_t N)
{
    auto it = peaks.cbegin();
    for (size_t i = 0; i < N; i+= k)
    {
        if (it == peaks.cend())
            return false;
        
        if (*it >= i + k)
            return false;
            
        while (it != peaks.cend() && *it < i + k)
            ++it;
    }
    
    return true;
}

int solution(vector<int> &A) {
    const size_t N{A.size()};
    vector<size_t> peaks;
    for (size_t i = 1; i < N - 1; ++i)
    {
        if (A[i - 1] < A[i] && A[i] > A[i + 1])
            peaks.push_back(i);
    }
    
    for (size_t k = 2; k <= N / 2; ++k)
    {
        if (N % k)
            continue;
            
        if (isValidDivision(peaks, k, N))
            return N / k;
    }

    if (isValidDivision(peaks, N, N))
        return 1;
    
    return 0;    
}