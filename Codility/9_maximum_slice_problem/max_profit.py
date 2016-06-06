# https://codility.com/programmers/task/max_profit/

def solution(A):
    max_profit_ending = 0
    max_profit = 0
    for i in xrange(1, len(A)):
        change = A[i] - A[i - 1]
        max_profit_ending = max(0, max_profit_ending + change)
        max_profit = max(max_profit, max_profit_ending)
    
    return max_profit
