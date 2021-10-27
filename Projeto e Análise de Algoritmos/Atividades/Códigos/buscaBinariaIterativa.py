def buscaIterativa(a):
    mid = 0
    low = 0
    up = len(a)-1

    while (low <= up):
        mid = (low + up) // 2

        if mid == a[mid]:
            return True
        if mid < a[mid]:
            up = mid-1
        else:
            low = mid+1
            
    return False

a = [-10, -1, 1, 2, 4]

result = buscaIterativa(a) 

if result == True: 
    print("Elemento encontrado") 
else: 
    print("Elemento não encontrado") 
