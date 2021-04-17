# Questão 8 - Lista 4 (Ítalo)

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

n = int(input("Digite o valor de n: "))
r = int(input("Digite o valor de r: "))

print("\nP(n,r) =", int(permutacao(n,r)))