S = input()
count_num = []
count_num.append(0)
for i in range(1,10):
    count_num.append(S.count(str(i)))
def check(S,res):
    check = 0
    for i in range(3):
        x = res.count(res[i])
        if x > count_num[int(res[i])]: return False
    return True

def process(S):
    if len(S) == 1:
        if(int(S) == 8): return True
    elif len(S) == 2:
        if(int(S)%8 == 0 or int(S[::-1])%8 == 0): return True
    for i in range(100,1000):
        if i%8 != 0: continue
        if check(S,str(i)): 
            print(i)
            return True
    return False
if process(S): print('Yes')
else: print('No')