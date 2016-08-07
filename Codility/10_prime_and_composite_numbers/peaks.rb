# https://codility.com/programmers/task/peaks/

def is_valid_solution(k, peaks, n)
  peak_index = 0
  (0..n - 1).step(k) do |i|
    return false if peak_index >= peaks.length
    return false if peaks[peak_index] >= i + k
        
    while peak_index < peaks.length and peaks[peak_index] < i + k
      peak_index += 1
    end
  end
  
  true
end

def solution(a)
  n = a.length
  peaks = a[1..n - 1].each_with_index.map { |n, i| i if a[i] > a[i - 1] and a[i] > a[i + 1] }.compact
  
  # puts peaks
  
  for k in 2..n/2
    return n/k if n % k == 0 and is_valid_solution(k, peaks, n)
  end
  
  return 1 if is_valid_solution(n, peaks, n)
  
  0
end
