# Questão 6 - Lista 4 (Ítalo)

import math

def fatorial(n):
    fat = 1
    
    for i in range(1, n+1):
        fat *= i
        
    return fat

def somatorioD():
    soma = 0
    radicando = 10
    
    for i in range(1, 61):
        soma += fatorial(i)/(math.sqrt(radicando))
        radicando += 3
        
    return soma

print("D =", somatorioD())