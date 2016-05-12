// https://codility.com/programmers/task/number_of_disc_intersections/

#include <algorithm>

int solution(vector<int> &A) {
    // y=0 axes intersection x-coordinate and "right side" flag pairs
    vector<pair<int64_t, bool>> discLimits;
    for (size_t i = 0; i < A.size(); ++i)
    {
        discLimits.push_back(make_pair(i - A[i], false));
        discLimits.push_back(make_pair(i + A[i], true));
    }
    
    sort(discLimits.begin(), discLimits.end());
    
    int intersections = 0;
    int openDiscs = 0;
    for (pair<int64_t, bool> limit : discLimits)
    {
        if (limit.second)
        {
            --openDiscs;
            intersections += openDiscs;
            if (intersections > 1e7)
                return -1;
        }
        else
        {
            ++openDiscs;
        }
    }
    
    return intersections;
}
