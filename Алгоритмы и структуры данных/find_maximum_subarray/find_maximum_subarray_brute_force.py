def find_maximum_subarray_brute_force(mass, low, high):
    if low == high:
        return []
    max_summary = -10000000
    i, j = 0, 0
    while i < (high - low):
        summary = mass[i]
        if summary > max_summary:
            max_summary = summary
        j = i + 1
        while j < (high - low):
            if summary + mass[j] > max_summary:
                summary += mass[j]
                max_summary = summary
            else:
                break
            j += 1
        i += 1
    return max_summary
