def busca(array, x):
    if array[0] > x:
        return False
    
    if array[0] == x:
        return True
    
    left = 1
    right = 1
    
    while(array[right] != "INF"):
        left = right
        right *= 2
        
    mid = 0
    
    while((right-left) > 1):
        mid = left + ((right-left) // 2)
        
        if(array[mid] == "INF"):
            right = mid
        else:
            left = mid
            
    return buscaBinaria(array[0:left+1], x)

def buscaBinaria(array, x):
    mid = 0
    low = 0
    up = len(array)-1
    
    while (low <= up):
        mid = (low + up) // 2
    
        if array[mid] == x:
            return True
        if x < array[mid]:
            up = mid-1
        else:
            low = mid+1
            
    return False