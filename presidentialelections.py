MAX_DEL = 2016
INF = pow(10, 9)

n = int(input())
dp = [[INF for i in range(MAX_DEL + 1)] for j in range(n + 1)]
dp[0][0] = 0
total_delegates = 0

for i in range(n):
    d, c, f, u = map(int, input().split())
    total_delegates += d
    votes_needed = (c + f + u) // 2 - c + 1
    for j in range(MAX_DEL + 1):
        if dp[i][j] != INF:
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])

            if votes_needed <= u:
                if votes_needed <= 0 and j + d <= MAX_DEL:
                    dp[i + 1][j + d] = min(dp[i + 1][j + d], dp[i][j])
                elif j + d <= MAX_DEL:
                    dp[i + 1][j + d] = min(dp[i + 1][j + d], dp[i][j] + votes_needed)

need = total_delegates // 2 + 1
min_votes = INF
for i in range(need, MAX_DEL + 1):
    min_votes = min(min_votes, dp[n][i])

if min_votes == INF:
    print('impossible')
else:
    print(min_votes)