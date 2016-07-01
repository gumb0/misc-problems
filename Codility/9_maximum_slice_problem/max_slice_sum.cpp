// https://codility.com/programmers/task/max_slice_sum/


int solution(vector<int> &A) {
    int current_sum = A[0];
    int max_sum = current_sum;
    
    for (size_t i = 1; i < A.size(); ++i) {
        current_sum = max(current_sum + A[i], A[i]);
        max_sum = max(max_sum, current_sum);
    }
    
    return max_sum;
}