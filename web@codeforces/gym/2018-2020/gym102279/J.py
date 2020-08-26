n = input()

l = len(n)
result = '-1'

for i in range(0, l):
    for j in range(i+1, l):
        if i != 0 or (i == 0 and n[j] != '0'):
            newn = n[0:i] + n[j] + n[i+1:j] + n[i] + n[j+1:]
            #print(i, j, newn)
            if newn < n:
                if newn > result:
                    result = newn

print(result)