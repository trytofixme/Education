def find_maximum_subarray(mass, low, high):
    curr_sum = 0
    max_sum = 0
    start_index = low
    for end_index in range(high):
        curr_sum += mass[end_index]
        if curr_sum > max_sum:
            max_sum = sum(mass[start_index:end_index + 1])
        if curr_sum < 0:
            curr_sum = 0
            start_index = end_index + 1
    return max_sum
