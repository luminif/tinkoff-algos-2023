def gen(callback, n, max, cur, prefix):
    if n == 0:
        callback(*prefix)
        return
    for i in range(1, min(n, max) + 1):
        gen(callback, n - i, i, cur + 1, prefix + [i])

n = int(input())
gen(print, n, n, 0, [])