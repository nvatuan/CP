check = 'a.exe'
jury = 'check.exe'

from random import randint
import os

correct = total = 0

for t in range(0, 100):
    x = randint(1, 10000000)
    total += 1

    m = randint(1, 100000000)
    f = open('in', 'w')
    f.write("%d %d\n" % (x, m))
    f.close

    os.system('echo ' + str(x) + ' ' + str(m) + ' | ' + check + ' > out')
    os.system('echo ' + str(x) + ' ' + str(m) + ' | ' + jury + ' > juryout')

    out = juryout = None
    with open('out','r') as f:
        out = f.read().strip()
    with open('out','r') as f:
        juryout = f.read().strip()

    if out != juryout: print('WRONG: ', x, m)
    else: correct += 1

print('Correct/Total = ', correct, '/', total)    