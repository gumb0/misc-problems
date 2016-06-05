// https://codility.com/programmers/task/dominator/

#include <algorithm>

int solution(vector<int> &A) {
    int lastValue = 0;
    int size = 0;
    for (int a : A)
    {
        if (size == 0 || lastValue == a)
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
        return -1;
        
    return std::count(A.begin(), A.end(), lastValue) > A.size() / 2 ?
        std::find(A.begin(), A.end(), lastValue) - A.begin() : 
        -1;
}