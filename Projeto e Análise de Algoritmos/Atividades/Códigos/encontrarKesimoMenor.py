def kesimoMenorElemento(arr1, arr2, x1, x2, k):
    if arr1[0] == x1:
        return arr2[k]
    
    if arr2[0] == x2:
        return arr1[k]
    
    mid1 = (x1 - arr1[0]) // 2
    mid2 = (x2 - arr2[0]) // 2
    
    if (mid1 + mid2) < k:
        if arr1[mid1] > arr2[mid2]:
            return kesimoMenorElemento(arr1, arr2[:mid2+1], x1, x2, k-mid2-1)
        else:
            return kesimoMenorElemento(arr1[:mid1+1], arr2, x1, x2, k-mid1-1)
    else:
        if arr1[mid1] > arr2[mid2]:
            return kesimoMenorElemento(arr1, arr2, arr1[mid1], x2, k)
        else:
            return kesimoMenorElemento(arr1, arr2, x1, arr2[mid2], k)
    
    
    
arr1 = [1, 3, 7, 15, 20, 30]
arr2 = [2, 9, 13, 14, 21, 50]

m = len(arr1)
n = len(arr2)

k = 4

print(kesimoMenorElemento(arr1, arr2, arr1[m-1] , arr2[n-1], k-1)) # Output: 7