# https://codility.com/programmers/task/stone_wall/

def solution(H):
    count = 0
    stack = []
    for h in H:
        while stack and stack[-1] > h:
            stack.pop()
            
        if not stack or stack[-1] < h:
            count += 1
            stack.append(h)
            
    return count