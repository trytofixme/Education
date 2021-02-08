def find_maximum_crossing_subarray(mass, low, mid, high):
    left_sum = -100000000
    summary = 0
    max_left = low
    for i in range(mid, low - 1, -1):
        summary += mass[i]
        if summary > left_sum:
            left_sum = summary
            max_left = i

    right_sum = -100000000
    summary = 0
    max_right = high
    for i in range(mid + 1, high + 1):
        summary += mass[i]
        if summary > right_sum:
            right_sum = summary
            max_right = i
    return max_left, max_right, left_sum + right_sum


def find_maximum_subarray(mass, low, high):
    if high == low:
        if len(mass) == 0:
            return []
        return low, high, mass[low]
    else:
        mid = int(low + (high - low) / 2)
        left_low, left_high, left_sum = find_maximum_subarray(mass, low, mid)
        right_low, right_high, right_sum = find_maximum_subarray(mass, mid + 1, high)
        cross_low, cross_high, cross_sum = find_maximum_crossing_subarray(mass, low, mid, high)
        if left_sum >= right_sum and left_sum >= cross_sum:
            return left_low, left_high, left_sum
        elif right_sum >= left_sum and right_sum >= cross_sum:
            return right_low, right_high, right_sum
        else:
            return cross_low, cross_high, cross_sum
