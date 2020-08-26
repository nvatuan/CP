def solve():
    s = str(input())
    ##
    ans = 1001
    indx = s.find('0');
    if (indx == -1):
        ans = 0
    if s[indx:].count('0') + indx == len(s):
        ans = 0
    ans = min(ans, s[indx:].count('0') - (1 if s[-1] == '0' else 0))
    ans = min(ans, s[indx:].count('1')) 

    indx = s.find('1');
    if (indx == -1):
        ans = 0
    if s[indx:].count('1') + indx == len(s):
        ans = 0
    ans = min(ans, s[indx:].count('1') - (1 if s[-1] == '1' else 0))
    ans = min(ans, s[indx:].count('0'))

    indx = s.rfind('0');
    indx += 1;
    ans = min(ans, s[:indx].count('0') - (1 if s[0] == '0' else 0))
    ans = min(ans, s[:indx].count('1'))

    indx = s.rfind('1');
    indx += 1;
    ans = min(ans, s[:indx].count('1') - (1 if s[0] == '1' else 0))
    ans = min(ans, s[:indx].count('0'))
    print(ans)



if __name__ == "__main__":
    t = int(input())
    #t = 1
    for tt in range(t):
        solve()