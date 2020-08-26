def lostMessage(message):
    message.sort()
    message.reverse()

    d = {}
    for s in message:
        if      s[0:2] == "S:":
            d[ s[2:] ] = 1
        elif    s[0:2] == "R:":
            d[ s[2:] ] = 0
    
    for k in d.keys():
        if  d[k] == 1:
            return k[::-1]


m = ["S:ab","S:bc","R:ba"]
print(lostMessage(m))