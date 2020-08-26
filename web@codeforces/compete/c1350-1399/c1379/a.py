__MULTITEST = True

def countStr(s, sub):
    n = len(s)
    counter = 0
    for i in range(0, n - len(sub) + 1):
        flag = True
        for j in range(len(sub)):
            if s[i+j] != sub[j]:
                flag = False
                break
        counter += (1 if flag else 0)
    return counter

def solve():
    n = int(input())
    s = str(input())
    sub = "abacaba"
    
    counter = countStr(s, sub)

    if counter == 1:
        print("YES")
        s = s.replace('?', 'z')
        print(s)
    elif counter > 1:
        print("NO")
    else:
        for i in range(0, n - len(sub) + 1):
            l = list(s)
            flag = True
            for j in range(len(sub)):
                if not (l[i+j] == '?' or s[i+j] == sub[j]):
                    flag = False
                    break
                else:
                    l[i+j] = sub[j]
            if flag:
                counter = countStr(''.join(l), sub)
                if counter == 1:
                    print("YES")
                    print(''.join(l).replace('?', 'z'))
                    return
        print("NO")

### 
if __name__ == "__main__":
    t = (int(input()) if __MULTITEST else 1)
    for tt in range(t):
        solve()