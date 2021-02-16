# Python 3
ins = [
    '12', '123678', '1.1', '01', '0.010',
    '111222333444', '101100111', '63542', '99', '10', '100', '110', '100101', '512315123',
    '1234.0', '1.', '123.44', '3.1415926', '10.01', '111222333444.56789', '1-2', '1.1.1.2', '1..', '2.30.',

    '00.123', '0.000', '19.1'
]

outs = [
    'Twelve', 'One hundred twenty three thousand six hundred seventy eight', 'One point one', '-1', 'Zero point zero one zero',
    
    'One hundred eleven billion two hundred twenty two million three hundred thirty three thousand four hundred forty four', 
    'One hundred one million one hundred thousand one hundred eleven',
    'Sixty three thousand five hundred forty two',
    'Ninety nine',
    'Ten',
    'One hundred',
    'One hundred ten',
    'One hundred thousand one hundred one',
    'Five hundred twelve million three hundred fifteen thousand one hundred twenty three',

    'One thousand two hundred thirty four point zero',
    '-1',
    'One hundred twenty three point four four',
    'Three point one four one five nine two six',
    'Ten point zero one',
    'One hundred eleven billion two hundred twenty two million three hundred thirty three thousand four hundred forty four point five six seven eight nine', 
    '-1',
    '-1',
    '-1',
    '-1',

    '-1', 'Zero point zero zero zero', 'Nineteen point one'
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
