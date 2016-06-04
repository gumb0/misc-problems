// https://codility.com/programmers/task/equi_leader/

#include <algorithm>
#include <memory>

std::unique_ptr<int> findLeader(const vector<int>& A) {
    int size = 0;
    int lastValue = 0;
    for (int a : A)
    {
        if (size == 0 || a == lastValue)
        {
            ++size;
            lastValue = a;
        }
        else
        {
            --size;
        }
    }

    if (size == 0)
        return nullptr;

    return std::count(A.begin(), A.end(), lastValue) > A.size() / 2 ? 
        std::unique_ptr<int>(new int(lastValue)) : 
        nullptr;
    
}

int solution(vector<int> &A) {
    std::unique_ptr<int> leader = findLeader(A);
    if (!leader)
        return 0;

    int leaderCount = 0;
    vector<int> leaderCounts;
    for (int a : A)
    {
        if (a == *leader)
            ++leaderCount;
        leaderCounts.push_back(leaderCount);
    }
    
    int leaderReverseCount = 0;
    int equileaderCount = 0;
    for (size_t i = A.size() - 1; i > 0; --i)
    {
        if (A[i] == *leader)
            ++leaderReverseCount;
            
        if (leaderReverseCount > (A.size() - i) / 2 && leaderCounts[i - 1] > i / 2)
            ++equileaderCount;
    }
    return equileaderCount;
}
