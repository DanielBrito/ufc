# Questão 5 - Lista 4 (Ítalo)

import math

def somatorioC():
    soma = 0
    base = 5    
    
    for i in range(2, 26):
        soma += math.tan((i*math.pi)/(i+1)) - pow(base, 2)
        base += 2
        
    return soma

print("C =", somatorioC())