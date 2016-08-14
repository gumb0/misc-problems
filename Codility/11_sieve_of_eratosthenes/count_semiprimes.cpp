vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    vector<int> counters(N + 1);
    for (long long i = 2; i <= N; ++i)
    {
        for (long long j = 2 * i; j <= N; j += i)
            ++counters[j];
            
        for (long long j = i * i, k = 1; j <= N; j *= i, ++k)
            counters[j] += k;
    }

    vector<int> semiprimes_less{0};
        
    for (int i = 1; i <= N; ++i)
    {
        if (counters[i] == 2)
            semiprimes_less.push_back(semiprimes_less[i - 1] + 1);
        else
            semiprimes_less.push_back(semiprimes_less[i - 1]);
    }

    vector<int> result;
    for (int i = 0; i < P.size(); ++i)
    {
        result.push_back(semiprimes_less[Q[i]] - semiprimes_less[P[i] - 1]);
    }
    
    return result;
}
