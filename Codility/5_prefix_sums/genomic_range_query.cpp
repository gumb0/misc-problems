// https://codility.com/programmers/task/genomic_range_query/

int nucleotideToImpact(char c)
{
    switch(c)
    {
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
        default: return -1;
    }
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    
    vector<vector<int>> counts(S.size() + 1, vector<int>(4));
    
    for (size_t i = 1; i <= S.size(); ++i)
    {
        counts[i] = counts[i - 1];
        ++counts[i][nucleotideToImpact(S[i - 1])];
    }

    vector<int> result;    
    for (size_t i = 0; i < P.size(); ++i)
    {
        int impact = 0;
        while (counts[Q[i] + 1][impact] - counts[P[i]][impact] == 0)
        {
            ++impact;
        }
        result.push_back(impact + 1);
    }
    
    return result;
}
