A = [1, 2, 3, 4, -10]

best_sum = A[0]
max_sum = A[0]

for i in range(1, len(A)):
    if A[i] > best_sum + A[i]:
        best_sum = A[i]
    else:
        best_sum = best_sum + A[i]
    max_sum = best_sum if best_sum > max_sum else max_sum

print(max_sum)
