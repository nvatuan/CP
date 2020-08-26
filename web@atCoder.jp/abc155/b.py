N = int(input())
A = list(map(int, input().split()))

logic = True
for a in A:
    logic &= ((a % 2 == 1) or (a % 3 == 0 or a % 5 == 0))

print("APPROVED\n" if logic else "DENIED\n")
