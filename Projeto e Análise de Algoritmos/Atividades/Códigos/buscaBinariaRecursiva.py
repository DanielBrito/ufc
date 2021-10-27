def buscaRecursiva(a, low, up):      
    if up >= low: 
        mid = (low+up) // 2
        
        if mid == a[mid]: 
            return True
        if mid > a[mid]: 
            return buscaRecursiva(a, (mid+1), up) 
        else: 
            return buscaRecursiva(a, low, (mid-1)) 
    return False

a = [-10, -1, 1, 2, 4]

result = buscaRecursiva(a, 0, len(a)-1) 

if result == True: 
    print("Elemento encontrado") 
else: 
    print("Elemento não encontrado") 
