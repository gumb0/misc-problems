// https://codility.com/programmers/task/max_double_slice_sum/

int solution(vector<int> &A) {
    vector<int> maxEndingSums(A.size());
    int maxEnding = 0;
    for (int i = 1; i < A.size() ; ++i)
    {
        maxEnding = max(0, maxEnding + A[i]);
        maxEndingSums[i] = maxEnding;
    }
    
    vector<int> maxStartingSums(A.size());
    int maxStarting = 0;
    for (int i = A.size() - 2; i >= 0 ; --i)
    {
        maxStarting = max(0, maxStarting + A[i]);
        maxStartingSums[i] = maxStarting;
    }
    
    int maxDoubleSliceSum = 0;
    for (size_t i = 1; i < A.size() - 1; ++i)
    {
        const int maxEnding = max(0, maxEndingSums[i - 1]);
        const int maxStarting = max(0, maxStartingSums[i + 1]);
        maxDoubleSliceSum = max(maxDoubleSliceSum, maxEnding + maxStarting);
    }
    
    return maxDoubleSliceSum;
}