# https://codility.com/programmers/task/min_avg_two_slice/

def solution(A):
    min_avg_ending_here = float(A[0] + A[1]) / 2
    count_min_ending_here = 2
    min_so_far = min_avg_ending_here
    min_starting_index = 0
    
    for i in xrange(2, len(A)):
        new_avg = (min_avg_ending_here * count_min_ending_here + A[i]) / (count_min_ending_here + 1)
        avg_last_two = float(A[i - 1] + A[i]) / 2
        
        if avg_last_two < new_avg:
            min_avg_ending_here = avg_last_two
            count_min_ending_here = 2
        else:
            min_avg_ending_here = new_avg
            count_min_ending_here += 1
            
        if min_avg_ending_here < min_so_far:
            min_so_far = min_avg_ending_here
            min_starting_index = i - count_min_ending_here + 1
            
    return min_starting_index