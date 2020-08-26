def solve():
    n = int(input())
    a = list(map(int, input().split()))
    ##
    best_sum = 0; current_sum = 0;
    best_ans = 0; sub_max = 0;
    for x in a:
        if current_sum + x - sub_max > 0:
            sub_max = max(sub_max, x)
            current_sum = current_sum + x
        else:
            best_ans = max(best_ans, current_sum - sub_max)
            sub_max = 0
            current_sum = 0
        # print(current_sum, sub_max)
    ###
    print( max(best_ans, current_sum - sub_max) )
### 
if __name__ == "__main__":
    t = 1 #int(input())
    for tt in range(t):
        solve()