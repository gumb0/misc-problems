// https://codility.com/programmers/task/max_profit/

int solution(vector<int> &A) {
    int maxProfit = 0;
    int maxProfitEnding = 0;
    for (size_t i = 1; i < A.size(); ++i)
    {
        const int change = A[i] - A[i - 1];
        maxProfitEnding = max(0, maxProfitEnding + change);
        maxProfit = max(maxProfit, maxProfitEnding);
    }
    return maxProfit;
}