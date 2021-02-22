s = str(input())
ev = ''.join([s[i] for i in range(0, len(s), 2)])
od = ''.join([s[i] for i in range(1, len(s), 2)])

print('Yes' if (ev == '' or ev.islower()) and (od == '' or od.isupper()) else 'No')
