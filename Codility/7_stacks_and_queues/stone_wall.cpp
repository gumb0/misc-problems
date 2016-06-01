// https://codility.com/programmers/task/stone_wall/

int solution(vector<int> &H) {
    vector<int> stack;
    int count = 0;
    for (int h : H)
    {
        while (!stack.empty() && h < stack.back())
            stack.pop_back();

        if (stack.empty() || h > stack.back())
        {
            stack.push_back(h);
            ++count;
        }
    }
    
    return count;
}