# https://codility.com/programmers/task/number_of_disc_intersections/

def solution(A):
    disc_limits = []
    for i in xrange(len(A)):
        disc_limits += [(i - A[i], False)]
        disc_limits += [(i + A[i], True)]
        
    disc_limits = sorted(disc_limits)
        
    open_discs = 0
    intersections = 0
    for disc_limit in disc_limits:
        if disc_limit[1]:
            open_discs -= 1
            intersections += open_discs
            if intersections > 1e7:
                return -1
        else:
            open_discs += 1
    
    return intersections
