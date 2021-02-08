def binary_search(mass, val):
    if len(mass) == 0:
        return '0-size array'
    #if sorted(mass) != mass and sorted(mass, reverse = True) != mass:
    #    return 'incorrect input'
    left = -1
    right = len(mass)
    check_sort = True if mass[0] < mass[1] else False
    while left + 1 < right:
        mid = int(left + (right - left)/2)
        if val == mass[mid] or mass[mid - 1] == val:
            while mass[mid - 1] == val and mid != 0:
                mid -= 1
            return mid
        if val > mass[mid] ^ check_sort:
            left = mid
        else:
            right = mid
    return 'value not in mass'


if __name__ == '__main__':
    try:
        mass = [int(ind) for ind in input().split()]
        val = int(input())
    except:
        print('incorrect input!!!')
    print(binary_search(mass, val))
