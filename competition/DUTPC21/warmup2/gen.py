n = t = (int)(1e5)
k = 1
f0 = [1]

m = (int)(1e5)
h = {}

edge = []

from random import randint as rnd
for i in range(m):
    while True:
        a = rnd(1, n)
        b = rnd(1, n)
        if a == b: continue
        if h.get((a,b)) == None:
            edge.append( (a,b) )
            h[a] = b
            h[b] = a
            break

F = open("in", "w")
F.write('%d %d %d\n' % (n, k, t))
F.write("1\n")
F.write(f"{m}\n");
for x in edge:
    F.write(f"{x[0]} {x[1]}\n")

F.close()

