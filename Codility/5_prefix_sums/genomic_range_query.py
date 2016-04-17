# https://codility.com/programmers/task/genomic_range_query/

def nucleotide_to_index(nucleotide):
    return { 'A': 0,'C': 1, 'G': 2, 'T': 3 }[nucleotide]
    
def solution(S, P, Q):
    counts = [[0] * 4]
    
    for nucleotide in S:
        counts.append(counts[len(counts) - 1][:])
        counts[len(counts) - 1][nucleotide_to_index(nucleotide)] += 1
    
    result = []    
    for i in range(len(P)):
        j = 0
        while counts[Q[i] + 1][j] - counts[P[i]][j] == 0:
            j += 1
    
        result += [j + 1]
        
    return result