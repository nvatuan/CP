from math import sin, pi

n, a = map(int, input().split())
R = a / 2 / sin(pi/n)
print(R*R*pi)
