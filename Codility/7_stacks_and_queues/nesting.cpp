// https://codility.com/programmers/task/nesting/

#include <vector>

int solution(string &S) {
    // write your code in C++11 (g++ 4.8.2)
    std::vector<char> stack;
    for (char c : S)
    {
        if (c == '(')
            stack.push_back(c);
        else if (!stack.empty() && stack.back() == '(')
            stack.pop_back();
        else
            return 0;
            
    }
    
    return stack.empty() ? 1 : 0;
}
