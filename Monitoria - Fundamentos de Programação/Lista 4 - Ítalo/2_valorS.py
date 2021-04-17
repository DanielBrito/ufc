# Questão 2 - Lista 4 (Ítalo)

def fatorial(n):
    fat = 1
    
    for i in range(1, n+1):
        fat *= i
        
    return fat

def valorS(n):
    s = 0
    
    for i in range(1, n+1):
        s += pow(i, 2) / fatorial(i)
        
    return s+5;

numero = int(input("Digite um numero: "))

print("S =", valorS(numero))