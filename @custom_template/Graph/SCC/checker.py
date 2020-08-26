test = [
    '''
    3 3
    1 2
    2 3
    3 1
    ''', '''
    3 2
    1 2
    2 3 
    ''', '''
    5 5
    1 2
    2 3
    3 1
    3 4
    4 5
    ''', '''
    6 7
    1 2
    2 3
    3 1
    2 4
    4 5
    5 6
    6 4
    ''', '''
    6 8
    1 2
    2 3
    3 1
    2 4
    4 2
    4 5
    5 6
    6 4
    '''
]
jury = [
    "1", "3", "3", "2", "1"
] 

import os

for i in range(len(test)):
    f = open('in', 'w')    
    f.write(test[i])
    f.close()
    os.system('type in | a.exe > out')
    f = open('out', 'r')
    ans = f.read().strip()
    print(ans)

    print('Test #%d' % (i+1), 'Correct!' if ans == jury[i] else 'Wrong!')


    