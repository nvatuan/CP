def main():
    q, n = map(int, input().split())
    for _ in range(q):
        a = list(map(int, input().split()))
        a.sort()

        mid = 2**(n-1)
        if a[0] <= mid and a[1] > mid:
            print('yes')
        else:
            print('no')

main()