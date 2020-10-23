n = int(input())


def fib(num):
    f1 = 0
    f2 = 1
    for _ in range(num):
        f1, f2 = f2, f1 + f2
    return f1


print(fib(n))
