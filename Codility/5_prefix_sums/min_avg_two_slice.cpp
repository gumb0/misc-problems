// https://codility.com/programmers/task/min_avg_two_slice/

int solution(vector<int> &A) {
    int minSumEndingHere = A[0] + A[1];
    int countEndingHere = 2;
    double minSoFar = minSumEndingHere / countEndingHere;
    int minStartingIndex = 0;

    for (size_t i = 2; i < A.size(); ++i)
    {
        const double newAvg = static_cast<double>(minSumEndingHere + A[i]) / (countEndingHere + 1);
        const double avgLastTwo = static_cast<double>(A[i] + A[i - 1]) / 2;

        if (avgLastTwo < newAvg)
        {
            minSumEndingHere = A[i] + A[i - 1];
            countEndingHere = 2;
        }
        else
        {
            minSumEndingHere += A[i];
            ++countEndingHere;
        }
        
        const double minAvgEndingHere = static_cast<double>(minSumEndingHere) / countEndingHere;
        if (minAvgEndingHere < minSoFar)
        {
            minSoFar = minAvgEndingHere;
            minStartingIndex = i - countEndingHere + 1;
        }
    }
    
    return minStartingIndex;
}
