# // https://codility.com/programmers/task/fish/

def solution(A, B):
    downstream = []
    upstream_alive = 0
    
    for i in xrange(len(A)):
        if B[i]:
            downstream.append(A[i])
        else:
            while downstream and A[i] > downstream[len(downstream) - 1]:
                del downstream[len(downstream) - 1]
            
            if not downstream:
                upstream_alive += 1
                
    return upstream_alive + len(downstream)