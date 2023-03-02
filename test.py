def fib(n):
    # n = int(input())
    odd = 0
    even = 1
    k = 0
    total = 0
    evensum = []
    while odd<=n and even <= n:
        odd = odd+even
        even = odd+even
        if even % 2 == 0:
            evensum.append(even)
        if odd % 2 == 0:
            evensum.append(odd)
    size = len(evensum)
    while k < size:
        total = evensum[k]+total
        k = k+1
    print(total)
    return total