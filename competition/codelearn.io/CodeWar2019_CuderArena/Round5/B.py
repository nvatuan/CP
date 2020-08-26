def robotPosition(cmd):
    cmd = cmd.split(',')

    d = 0;
    x = [0, 1, 0, -1]
    y = [1, 0, -1, 0]
    
    coor = [0, 0]

    for s in cmd:
        if      s[0:2] == 'Go':
            #print("Going\n")
            coor[0] += (x[d] * int(s[3:]))
            coor[1] += (y[d] * int(s[3:]))
        elif    s[0:2] == 'TL':
            #print("Turn left\n")
            d = (d - 1) + 4 % 4
        elif    s[0:2] == 'TR':
            #print("Turn right\n")
            d = (d + 1) % 4
        elif    s[0:2] == 'TB':
            #print("Turn back\n")
            d = (d + 2) % 4
    
    return coor


cmd = "Go 2,TL,Go 2"
print(robotPosition(cmd))