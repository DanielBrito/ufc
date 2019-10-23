# Questão 10 - Lista 4 (Ítalo)

def fatorial(n):
    fat = 1
    
    for i in range(1, n+1):
        fat *= i
        
    return fat

def permutacao(n, r):
    
    if n<0 or n<r:
        return -1
    else:   
        return fatorial(n)/fatorial(n-r)
    
def combinacao(n,s):
    
    if n<0 or n<s:
        return -1
    else:   
        return (fatorial(n))/(fatorial(s)*(fatorial(n-s)))

def calculaF():
    soma = 0
    
    for i in range(4, 13):
        soma += combinacao(i,2)+permutacao(i+3,2)
        
    return soma

print("F =", calculaF())