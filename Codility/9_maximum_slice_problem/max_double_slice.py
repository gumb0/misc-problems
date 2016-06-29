# https://codility.com/programmers/task/max_double_slice_sum/

def solution(A):
    max_ending = [0] * len(A)
    for i in xrange(1, len(A)):
        max_ending[i] = max(0, max_ending[i - 1] + A[i])

    max_starting = [0] * len(A)
    for i in xrange(len(A) - 2, -1, -1):
        max_starting[i] = max(0, max_starting[i + 1] + A[i])
        
    max_double_slice = 0
    for i in xrange(1, len(A) - 1):
        max_double_slice = max(max_double_slice, max_ending[i - 1] + max_starting[i + 1])
        
    return max_double_slice
