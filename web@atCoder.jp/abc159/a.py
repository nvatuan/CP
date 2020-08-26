n, m = map(int, input().split())

def choose_2(x):
    return x * (x - 1) // 2

print(choose_2(n) + choose_2(m))