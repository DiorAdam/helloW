
def listPrimes(n: int) -> int:
    p = [1]*n
    ans = []
    for i in range(2,n):
        if p[i]: 
            ans.append(i)
            j = 2
            while j*i<n:
                p[i*j] = 0
                j+=1
    return ans

print(listPrimes(10000)[-10:])
