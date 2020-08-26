# Python 3.x
__IO_WITH_FILE = False
__FILE_PREFIX = "MUSHROOM"

import sys
istream = None
ostream = None
## =======================
def solve():
    ## == input
    line = istream.readline();
    m, n, p = map(int, line.split())

    mushroom_forest = [0]*m
    mushroom_amount = [0]*n
    adjacent_list = []

    for i in range(m):
        line = istream.readline()
        mushroom_forest[i] = int(line.split()[0]) - 1
        mushroom_amount[mushroom_forest[i]] = int(line.split()[1])
    
    ## include starting forest
    if mushroom_forest.count(0) == 0:
        mushroom_forest.insert(0, 0)
        m += 1
    
    for i in range(n):
        line = istream.readline()
        adjacent_list.append( list(map(int, line.split())) )
    
    ##  == solve
    min_cost_of = {} # hashmap

    for state in range(0, (1 << m)):
        if state & 1 != 0: ## included first forest
            forests = []
            ### get forest index appeared in set state
            for b in range(m):
                if state & (1 << b) != 0:
                    forests.append(mushroom_forest[b])
            # print(state, forests, sep = ' ')

            r = len(forests)
            ### minimum-spanning tree:
            ### Prim's algo
            cost = 0
            visited = [False] * r
            visited[0] = True
            while True:
                min_edge = None
                candidate = -1
                ##
                for in_tree in range(r):
                    if visited[in_tree]:
                        for not_in_tree in range(r):
                            if not visited[not_in_tree]:
                                u = forests[in_tree]
                                v = forests[not_in_tree]
                                if min_edge == None or adjacent_list[min_edge[0]][min_edge[1]] > adjacent_list[u][v]:
                                    min_edge = [u, v]
                                    candidate = not_in_tree
                ##
                if min_edge == None:
                    break
                else:
                    cost += adjacent_list[min_edge[0]][min_edge[1]]
                    visited[candidate] = True
                ##
                if visited.count(True) == r:
                    break;
            ###
            # print("Cost = ", cost, sep = ' ')
            min_cost_of[state] = cost
    
    # print("Min_cost = ", min_cost_of);
    ##
    ans = 0
    for state in range(0, (1 << m)):
        if state & 1 != 0:
            assert(min_cost_of.get(state) != None)            
            timeleft = p - min_cost_of[state]
            # print("State = ", bin(state), sep = ' ')
            # print("Timeleft = ", timeleft, sep = ' ')

            forests = []
            ### get forest index appeared in set state
            for b in range(m):
                if state & (1 << b) != 0:
                    forests.append(b)
            
            ### 
            divisor = [1] * n
            sub_ans = 0
            r = len(forests)

            while True:
                sub_max = 0; index = -1;

                if timeleft > 0:
                    timeleft -= 1
                    ## 
                    for i in range(r):
                        selected = mushroom_forest[forests[i]]
                        if sub_max < mushroom_amount[selected] // (1 << divisor[selected]):
                            sub_max = mushroom_amount[selected] // (1 << divisor[selected])
                            index = mushroom_forest[forests[i]]

                    if index != -1:
                        sub_ans += sub_max 
                        divisor[index] += 1
                    else:
                        break;
                else:
                    break;
                
                # print(sub_ans, sep = ' ')
            ###
            ans = max(ans, sub_ans)

    ostream.write(str(ans) + "\n")
    return

## =======================
if __name__ == "__main__":
    if __IO_WITH_FILE:
        istream = open(__FILE_PREFIX + ".INP", "r")
        ostream = open(__FILE_PREFIX + ".OUT", "w+")
    else:
        istream = sys.stdin
        ostream = sys.stdout

    solve()

    if __IO_WITH_FILE:
        istream.close()
        ostream.close()
    