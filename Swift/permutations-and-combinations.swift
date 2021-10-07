
func factorial(_ n: Int, _ a: Int=1) -> Int {
    if n==0 { return 1 }
    if n==1 { return a }
    return factorial(n-1, n*a)
}

func combinations(n: Int, r: Int) -> Int {
    return factorial(n)/(factorial(r)*factorial(n-r))
}

func permutations(n: Int, r: Int) -> Int {
    return factorial(n)/factorial(n-r)
}

print(factorial(10))
print(combinations(n: 8, r: 4))
print(permutations(n: 8, r: 4))
