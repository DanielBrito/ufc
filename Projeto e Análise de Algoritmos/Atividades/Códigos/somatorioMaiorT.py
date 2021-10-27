import sys

def somatorioMaiorT(a, t):
    
    soma = 0
    l = sys.maxsize
    n = len(a)
 
    esq = 0
 
    for dir in range(n):
        soma += a[dir]
 
        while soma > t and esq <= dir:
            l = min(l, dir - esq + 1)

            soma -= a[esq]
            esq += 1
 
    return l != sys.maxsize