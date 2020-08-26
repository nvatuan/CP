def main():
    a, b = map(int, input().split())
    if a > b:
        print('NO')
    else:
        if a % 2 == b % 2:
            print('YES')
        else:
            if a % 2 == 1:
                if a * 2 <= b:
                    print('YES')
                else:
                    print('NO')
            else:
                print('NO')

t = int(input())
for tt in range(t):
    main()