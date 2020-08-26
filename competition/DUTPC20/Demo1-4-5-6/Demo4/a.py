import sys

data = []
for line in sys.stdin:
    line = line.strip()
    for x in line.split():
        data.append(int(x))

print(data[0] * data[1])