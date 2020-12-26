def calculate_distance(pos):
    total = 0
    for i in range(1, len(pos)):
        a = pos[i]
        b = pos[i - 1]
        total += ((a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2) ** 0.5
    return total

n, t = map(int, input().split())
positions = [[int(i) for i in input().split()] for x in range(n)]
gps_positions = [positions[0]]
max_t = positions[-1][2]
cur_index = 1
gps_t = t
while gps_t < max_t + 1:
    cur_t = positions[cur_index][2]
    if gps_t <= cur_t:
        percentage = (gps_t - positions[cur_index - 1][2])/(cur_t - positions[cur_index - 1][2])
        gps_positions.append([
            ((positions[cur_index][0] - positions[cur_index - 1][0]) * percentage) + positions[cur_index - 1][0],
            ((positions[cur_index][1] - positions[cur_index - 1][1]) * percentage) + positions[cur_index - 1][1]
            ])
        gps_t += t
    else:
        cur_index += 1
gps_positions.append(positions[-1])

real = calculate_distance(positions)
gps = calculate_distance(gps_positions)
print((real - gps) * 100/real)