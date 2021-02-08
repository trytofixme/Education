def insertion_binary(data):
    for i in range(2, len(data)):
        if mass[i - 1] < mass[i]:
            key = data[i]
            lo, hi = 1, i - 1
            while lo < hi:
                mid = lo + (hi - lo) // 2
                if key < data[mid]:
                    hi = mid - 1
                else:
                    lo = mid + 1
            for j in range(i - 1, lo, -1):
                data[j + 1] = data[j]
            data[lo] = key
    return data
