def elementoMajoritarioB(a, e=None):
    n = len(a)
     
    if n == 0:
        return e
     
    pares = []
     
    if n % 2 == 1:
        e = a[-1]
         
    for i in range(0, n-1, 2):
        if a[i] == a[i+1]:
            pares.append(a[i])
            
    majoritario = elementoMajoritarioB(pares, e)
     
    if majoritario is None:
        return None
     
    nMajoritario = a.count(majoritario)
     
    if 2*nMajoritario > n or (2*nMajoritario == n and majoritario == e):
        return majoritario
     
    return None
 
a = [1, 2, 1, 3, 5, 1, 1, 1]

print(elementoMajoritarioB(a))