import time
start = sum(int(x) * 60 ** i for i, x in enumerate(reversed(input().split(':'))))
end = sum(int(x) * 60 ** i for i, x in enumerate(reversed(input().split(':'))))
if start == end:
    print("24:00:00")
elif start < end:
    print(time.strftime('%H:%M:%S', time.gmtime(end - start)))
else:
    print(time.strftime('%H:%M:%S', time.gmtime(86400 - start + end)))