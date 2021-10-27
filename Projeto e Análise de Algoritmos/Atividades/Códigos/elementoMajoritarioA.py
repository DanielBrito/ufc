def elementoMajoritario(a):
    n = len(a)
    
    if n == 1:
        return a[0]
    if n == 0:
        return None
    
    k = n // 2
    
    elem1 = elementoMajoritario(a[:k])
    elem2 = elementoMajoritario(a[k+1:])
    
    if elem1 == elem2:
        return elem1

    count1 = a.count(elem1)
    count2 = a.count(elem2)

    if count1 > k:
        return elem1
    elif count2 > k:
        return elem2
    else:
        return None