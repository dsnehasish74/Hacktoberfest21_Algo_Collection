func fibonacci(_ n: Int, _ a:Int=0, _ b:Int=1) -> Int{
    if n==0 { return a }
    if n==1 { return b }
    return fibonacci(n-1, b, a+b)
}

for i in 0...12 {
    print(fibonacci(i))
}
