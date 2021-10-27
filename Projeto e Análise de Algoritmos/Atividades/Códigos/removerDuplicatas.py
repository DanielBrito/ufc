def mergeSort(arr):
  if len(arr) > 1:

    mid = len(arr)//2

    L = arr[:mid]
    R = arr[mid:]

    mergeSort(L)
    mergeSort(R)

    i = j = k = 0

    while i < len(L) and j < len(R):
        if L[i] < R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
            
        k += 1

    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1

    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1
      
def removerDuplicatas(arr):
    n = len(arr)
    
    if n==1 or n==0:
        return arr
    
    result = []
    
    for i in range(0, n-1):
        if(arr[i] != arr[i+1]):
            result.append(arr[i])

    result.append(arr[n-1])
    
    return result
    