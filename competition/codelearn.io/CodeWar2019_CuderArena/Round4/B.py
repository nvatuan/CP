import string

def convertString(s):
    ic = {};    ci = {};
    ic[0] = 'z'
    for i, c in enumerate(string.ascii_letters[0:26]):
        ic[i+1] = c
        ci[c] = i+1
    ##
    if s[0].isalpha():
        num = 0
        for c in s:
            num = (num*26 + ci[c]);
            
        s = str(num)[::-1]
        return (','.join([s[i:i+3] for i in range(0, len(s), 3)]))[::-1]
    else:
        s = int(s)
        word = ''
        #
        while s > 0:
            word = ic[(s % 26)] + word
            if s % 26 == 0:
                s //= 26
                s -= 1
            else:
                s //= 26


        return word
        
    


