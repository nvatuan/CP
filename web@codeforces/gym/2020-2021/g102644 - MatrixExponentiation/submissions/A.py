def matrixMul(A, B):
    assert len(A[0]) == len(B)

    h = len(A)
    w = len(B[0])
    c = len(A[0])
    res = [[0] * w for _ in range(h)]

    for i in range(h):
        for j in range(w):
            for k in range(c):
                res[i][j] += A[i][k] * B[j][k]
    
    return res


def main():
    st = input().split()
    n = int(st[0])
    p = float(st[1])

    happy = [[1, 0]]
    prob = [[1-p, p], [p, 1-p]]

    while n > 0:
        if n % 2 == 1:
            happy = matrixMul(happy, prob)
        prob = matrixMul(prob, prob)
        n //= 2
    
    print("%.9lf" % happy[0][0])

main()