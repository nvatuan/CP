n = int(input())

D = {'Huesca' : 0, 'Eibar' : 0}
while n > 0:
    n -= 1
    ##
    st = str(input().strip())
    D[st] += 1

print(D['Huesca'], D['Eibar'])
