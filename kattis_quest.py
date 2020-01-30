# import heapq

# q = []
# line = int(input())
# for _ in range(line):
#     ip = input().split()
#     if ip[0] == 'add':
#         heapq.heappush(q, (-int(ip[1]), -int(ip[2])))  # max heap
#     else:
#         x = int(ip[1])
#         total = 0
#         tmp = q.copy()
#         while x > 0 and len(tmp) > 0:
#             item = heapq.heappop(tmp)
#             e, g = map(int, item)
#             while len(tmp) > 0 and -e > x:
#                 e, g = map(int, heapq.heappop(tmp))
#             if -e <= x:
#                 total -= g
#                 x += e
#                 q.remove((e, g))
#                 heapq.heapify(q)
#         # while x > 0 and index >= 0:
#         #     e, g = map(int, q[index])
#         #     while index >= 0 and e <= x:
#         #         index -= 1
#         #         e, g = map(int, q[index])
#         #     if e <= x:
#         #         total += g
#         #         x -= e
#         #         q.remove((e, g))
#         #     index -= 1

#         print(total)

# ====================sol 2=========================================

# import heapq

# q = []
# removed = {}
# line = int(input())
# for _ in range(line):
#     ip = input().split()
#     if ip[0] == 'add':
#         heapq.heappush(q, (-int(ip[1]), -int(ip[2])))  # max heap
#     else:
#         x = int(ip[1])
#         total = 0
#         tmp = q.copy()
#         while x > 0 and len(tmp) > 0:
#             e, g = map(int, heapq.heappop(tmp))
#             removed_times = 0 if (e, g) not in removed else removed[(e, g)]
#             if -e > x:
#                 while len(tmp) > 0:
#                     if -e <= x:
#                         if (e, g) not in removed:
#                             break
#                         else:
#                             e_val, g_val = e, g
#                             e, g = map(int, heapq.heappop(tmp))
#                             removed_times -= 1
#                             while removed_times > 0 and e == e_val and g == g_val and len(tmp) > 0:
#                                 e, g = map(int, heapq.heappop(tmp))
#                                 removed_times -= 1
#                             if e == e_val and g == g_val:
#                                 removed_times = 0
#                             else:
#                                 removed_times = 0 if (
#                                     e, g) not in removed else removed[(e, g)]
#                             break
#                     else:
#                         e, g = map(int, heapq.heappop(tmp))
#                         removed_times = 0 if (
#                             e, g) not in removed else removed[(e, g)]
#             if -e <= x and removed_times <= 0:
#                 total -= g
#                 x += e
#                 if (e, g) in removed:
#                     removed[(e, g)] += 1
#                 else:
#                     removed[(e, g)] = 1

#         print(total)
# ====================sol 2=========================================

# ========================= SOL 3 =======================
# import heapq

# q = []
# removed = {}
# line = int(input())
# for _ in range(line):
#     ip = input().split()
#     if ip[0] == 'add':
#         heapq.heappush(q, (-int(ip[1]), -int(ip[2])))  # max heap
#     else:
#         x = int(ip[1])
#         total = 0
#         tmp = q.copy()
#         e_tmp, g_tmp = -1, -1
#         e_add, g_add = -1, -1
#         while x > 0 and len(tmp) > 0:
#             e, g = map(int, heapq.heappop(tmp))
#             if (e, g) == (e_tmp, g_tmp):
#                 if (e_add, g_add) == (e, g):
#                     e_add, g_add = -1, -1
#                     removed_times = 0
#                 else:
#                     removed_times -= 1
#             else:
#                 removed_times = 0 if (e, g) not in removed else removed[(e, g)]
#             if -e <= x:
#                 while removed_times > 0:
#                     if len(tmp) <= 0:  # last item
#                         e = -x - 1  # not to add to total
#                         break
#                     e, g = map(int, heapq.heappop(tmp))
#                     removed_times -= 1
#             if -e <= x and (((e, g) != (e_tmp, g_tmp) and (e, g) not in removed) or ((e, g) == (e_tmp, g_tmp))) and removed_times == 0:
#                 total -= g
#                 x += e
#                 if (e, g) in removed:
#                     removed[(e, g)] += 1
#                 else:
#                     removed[(e, g)] = 1
#                     e_add, g_add = e, g
#             e_tmp, g_tmp = e, g
#             # else -e > x:
#             # do nothing

#         print(total)
# ========================= SOL 4 =======================
# import heapq

# q = []
# line = int(input())
# for _ in range(line):
#     ip = input().split()
#     if ip[0] == 'add':
#         heapq.heappush(q, (-int(ip[1]), -int(ip[2])))  # max heap
#     else:
#         x = int(ip[1])
#         total = 0
#         tmp = []
#         while x > 0 and len(q) > 0:
#             e, g = map(int, heapq.heappop(q))
#             if -e <= x:
#                 total -= g
#                 x += e
#             else:
#                 tmp.append((e, g))
#         print(total)
#         q = tmp + q

# ========================= SOL 4 =======================
import heapq
import itertools
q = []
line = int(input())
for _ in range(line):
    ip = input().split()
    if ip[0] == 'add':
        heapq.heappush(q, (-int(ip[1]), -int(ip[2])))  # max heap
    else:
        x = int(ip[1])
        total = 0
        tmp = []
        while x > 0 and len(list(q)) > 0:
            e, g = map(int, heapq.heappop(q))
            if -e <= x:
                total -= g
                x += e
            else:
                tmp.append((e, g))
        print(total)
        q[0:0] = tmp
