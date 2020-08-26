a = 3; b = 5;

for i in range(0, 30):
    print(i, end = ' ')
print('')
for i in range(0, 30):
    print(i%a%b, end = ' ')
print('')
for i in range(0, 30):
    print(i%b%a, end = ' ')
print('')