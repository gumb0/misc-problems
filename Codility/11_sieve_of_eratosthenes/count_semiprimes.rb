# https://codility.com/programmers/task/count_semiprimes/

def solution(n, p, q)
  factor_counts = Array.new(n + 1, 0) 
  for i in 2..n
    (2 * i..n).step(i) { |j| factor_counts[j] += 1 }
    
    j = i * i
    while j <= n
      factor_counts[j] += 1
      j *= i
    end
  end
  
  semiprimes_count_less = [ 0 ]
  for factor_count in factor_counts[1..-1]
    if factor_count == 2
      semiprimes_count_less << semiprimes_count_less.last + 1
    else
      semiprimes_count_less << semiprimes_count_less.last
    end
  end

  result = []
  p.zip(q).each do |pe, qe|
    result << semiprimes_count_less[qe] - semiprimes_count_less[pe - 1]
  end
  
  result
end
