mass = [int(ind) for ind in input().split()]
n = len(mass)
def insertion_sort(mass):
    count = 0
    for j in range(1, n):
        key = mass[j]
        i = j - 1
        while i >= 0 and mass[i] > key:
            count += 1
            mass[i + 1] = mass[i]
            i -= 1
        mass[i + 1] = key
    return mass

