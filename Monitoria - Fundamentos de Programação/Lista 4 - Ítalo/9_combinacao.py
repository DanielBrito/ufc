# Questão 9 - Lista 4 (Ítalo)

def fatorial(n):
    fat = 1
    
    for i in range(1, n+1):
        fat *= i
        
    return fat

def combinacao(n,s):
    
    if n<0 or n<s:
        return -1
    else:   
        return (fatorial(n))/(fatorial(s)*(fatorial(n-s)))
    
n = int(input("Digite o valor de n: "))
s = int(input("Digite o valor de s: "))

print("\nC(n,s) =", int(combinacao(n,s)))