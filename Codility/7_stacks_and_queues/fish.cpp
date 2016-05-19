// https://codility.com/programmers/task/fish/

int solution(vector<int> &A, vector<int> &B) {
    vector<int> downstream;
    int upsteamAlive = 0;
    for (size_t i = 0; i < A.size(); ++i)
    {
        if (B[i])
        {
            downstream.push_back(A[i]);
        }
        else
        {
            while (!downstream.empty() && A[i] > downstream.back())
            {
                downstream.pop_back();
            }
            if (downstream.empty())
                ++upsteamAlive;
        }
    }
    
    return upsteamAlive + downstream.size();
}