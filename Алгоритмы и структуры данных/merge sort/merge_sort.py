#p - левая граница, q - середина, r - правая граница
def Merge(mass, p, q, r):
    left = mass[p : q + 1]
    right = mass[q + 1 : r + 1]
    i, j, k = 0, 0, p
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            mass[k] = left[i]
            i += 1
        else:
            mass[k] = right[j]
            j += 1
        k += 1
    while i < len(left):
        mass[k] = left[i]
        i += 1
        k += 1
    while j < len(right):
        mass[k] = right[j]        
        j += 1
        k += 1
    

def MergeSort(mass, p, r):
    if p < r:
        q = (p + r) // 2
        MergeSort(mass, p, q)
        MergeSort(mass, q + 1, r)
        Merge(mass, p, q, r)      
