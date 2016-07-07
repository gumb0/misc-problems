// https://codility.com/programmers/task/min_perimeter_rectangle/

int get_perimeter(int A, int B) {
    return (A + B) * 2;
}

int solution(int N) {
    int min_perimeter = get_perimeter(1, N);
    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            const int perimeter = get_perimeter(i, N / i);
            if (perimeter < min_perimeter)
                min_perimeter = perimeter;
        }
    }
    
    return min_perimeter;
}
