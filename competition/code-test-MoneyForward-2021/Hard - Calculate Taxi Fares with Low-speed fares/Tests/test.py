# Python 3
ins = [
]

outs = [
]

assert len(ins) == len(outs), "Input and output test data has size mismatched"

import subprocess
import os

correct = 0
for i in range(len(ins)):
    p = subprocess.run(
        ['.\\a.exe'], stdout=subprocess.PIPE,
        input=ins[i], encoding='ascii'
    )
    res = p.stdout.strip()

    if res == outs[i]:
        correct += 1
        print('Test %d: CORRECT' % i)
    else:
        print('## Test %d: INCORRECT' % i)
        print(ins[i])
        print('Expected: \'' + outs[i] + '\', got \'' + res + '\' instead.' )

print ('SOLUTION RAN, CORRECT %d/%d' % (correct, len(ins)))
