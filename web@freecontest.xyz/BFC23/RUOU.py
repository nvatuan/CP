n = int(input())
alco = 'ABSINTH, TEQUILA, VODKA, WHISKEY, WINE, BEER, BRANDY, CHAMPAGNE, GIN, RUM, SAKE'.split(', ')

ans = 0
for i in range(n):
    response = str(input()).strip()
    try:
        response = int(response)
        if response < 18:
            ans += 1
    except ValueError:
        if response in alco:
            ans += 1

print(ans)