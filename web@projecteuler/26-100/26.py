def recurring(x):
    digit = {}
    dividend = 1

    step = 0
    while digit.get(dividend) == None:
        digit[dividend] = step
        dividend = dividend * 10 % x
        if dividend == 0: return 0
        step += 1
    
    return step - digit[dividend]

mx = 0
ia = 0
for i in range(1, 1000):
    #print(i, recurring(i))
    if mx < recurring(i):
        mx = max(mx, recurring(i))
        ia = i

print(ia)
print(mx)
