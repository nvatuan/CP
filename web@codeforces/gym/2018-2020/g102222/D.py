from math import floor

def f(n):
    if n <= 1:
        return 1
    else:
        return f(n-1) * n;

T = int(input())

def omega(k):
    return f(k) - (f(k-1) * 2) + 2

def answer(k):
    if(n <= 2) :
        return 1
    elif(n == 3):
        return 2
    return int( floor(omega(k)/(k-1)) ) + 1

for i in range(1, T+1):
    n, m = map(int, input().split())
    
    print(f'Case #{i}:', end = " ")


    print('{0:.6f}'.format( answer(n)/omega(n) ), end = " ")

    #print('{0:.6f}'.format( res2 ))