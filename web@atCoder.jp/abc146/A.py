a = ["SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", "?"]
a.reverse()
S = input().strip()

for i, wd in enumerate(a):
    if wd == S:
        print(i)
