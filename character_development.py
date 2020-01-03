n = int(input())
dp = [[0 for x in range(2)] for y in range(n+1)]


def Eulerian_numbers(n, m):
    if (m >= n) or n == 0:
        return 0
    if m == 0:
        return 1
    if dp[n][m] == 0:
        dp[n][m] = (n-m)*Eulerian_numbers(n-1, m-1) + \
            (m+1)*Eulerian_numbers(n-1, m)
    return dp[n][m]


print(Eulerian_numbers(n, 1))
