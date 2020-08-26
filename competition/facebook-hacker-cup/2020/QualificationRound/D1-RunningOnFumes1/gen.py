from random import randint

f = open('stress.txt', 'w')

f.write("4\n")

n = 1000000
for t in range(4):
    f.write("%d %d\n" % (n, randint(n//2, n)))
    c = [str(randint(int(1e8), int(1e9))) for _ in range(n)]
    f.write(' '.join(c))
    f.write('\n')

f.close()