# https://codility.com/programmers/task/equi_leader/

def find_leader(A):
    size = 0
    for a in A:
        if size == 0 or last_value == a:
            size += 1
            last_value = a
        else:
            size -= 1
    
    if size == 0:
        return None
    
    return last_value if A.count(last_value) > len(A) / 2 else None

def solution(A):
    leader = find_leader(A)
    if leader == None:
        return 0
        
    counts = []
    count = 0
    for a in A:
        if a == leader:
            count += 1
        counts.append(count)
        
    reverse_count = 0
    equileader_count = 0
    for i in xrange(1, len(A)):
        if A[-i] == leader:
            reverse_count += 1
        
        if counts[-i-1] > (len(A) - i) / 2 and reverse_count > i / 2:
            equileader_count += 1
            
    return equileader_count