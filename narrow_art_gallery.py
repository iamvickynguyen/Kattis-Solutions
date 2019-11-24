# magic DP
# Input:
#   the gallery (only a subarray of the gallery from 0 to curr is analized)
#   the number of rooms to be closed
#   the end index of the sub array
#   the room closed in the previouse (upper) row, if any
# Output:
#   the max value one can obtain, in the subarray
from sys import stdin


def G(gallery, close, curr, prev):
    if DP[close][curr][prev] is None:
        # inorder to sovle the problem, we consider 2 cases
        # case 1:
        #   we close k - 1 rooms under the [0, curr - 1] subarry
        #   then we close one in the curr-th row, so in total k rooms are closed
        # case 2:
        #   we close k rooms in the subarray and the problem is solved, if possible
        #
        # if we need to close some rooms
        #
        #   case 1 {
        #   if in the previous row, the room 0 is closed
        #       have to close room 0
        #   if in the previous row, the room 1 is closed
        #       have to close room 1
        #   if in the previous row, no rooms are closed
        #       close either room 0 or room 1
        #       take the max
        #   } case 1
        #
        #   case 2 {
        #   if we have enough rows to do case 2
        #       try to close k rooms in the subarray
        #       take the max out of case 1 and 2
        #   } case 2
        #   else we can't leave all k rooms to the lower subarray
        #       just take case 1 as the result
        #
        # else we don't need to close rooms
        #   the max value is the sum of all rooms in the subarray
        if close:
            if prev == 0:
                case1 = G(gallery, close - 1, curr - 1, 0) + gallery[curr][1]
            elif prev == 1:
                case1 = G(gallery, close - 1, curr - 1, 1) + gallery[curr][0]
            else:
                close0 = G(gallery, close - 1, curr - 1, 0) + gallery[curr][1]
                close1 = G(gallery, close - 1, curr - 1, 1) + gallery[curr][0]
                case1 = max(close0, close1)
            if close <= curr:
                case2 = G(gallery, close, curr - 1, 2) + \
                    gallery[curr][0] + gallery[curr][1]
                result = max(case1, case2)
            else:
                result = case1
        else:
            result = 0
            for i in range(curr + 1):
                result += gallery[i][0] + gallery[i][1]
        DP[close][curr][prev] = result
    return DP[close][curr][prev]


# read the first line (N, k)
# while N != 0
#   take the next N lines as the gallery g
#   init DP
#   print the result
#   read a new line (N, k)
N, k = [int(x) for x in stdin.readline().split()]
while N:
    g = [[int(x) for x in stdin.readline().split()] for _ in range(N)]
    DP = [[[None] * 3 for _ in range(N)] for __ in range(k + 1)]
    print(G(g, k, N - 1, 2))
    N, k = [int(x) for x in stdin.readline().split()]
