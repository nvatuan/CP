def solve():
    from sys import stdin
    ins = []
    for line in stdin:
        token = line.split()
        for tok in token:
            ins.append(int(tok))
    
    assert len(ins) == 2, "Test data is ill-formed"

    if ins[0] < ins[1]: print(0)
    else: print(1)

if __name__ == "__main__":
    solve()