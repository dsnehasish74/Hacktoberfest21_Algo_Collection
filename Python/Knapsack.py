value = [10, 40, 20, 30]
weight = [60, 40, 100, 120]
W = 50
n = len(value)
A = [[0 for x in range(W + 1)] for x in range(n + 1)]
for i in range(n + 1):
  for w in range(W + 1):
     if i == 0 or w == 0:
        A[i][w] = 0
     elif weight[i-1] <= w:
        A[i][w] = max(value[i-1] + A[i-1][w-weight[i-1]], A[i-1][w])
     else:
        A[i][w] = A[i-1][w]
print(A[n][W])
