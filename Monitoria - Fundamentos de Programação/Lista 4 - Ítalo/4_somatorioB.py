# Questão 4 - Lista 4 (Ítalo)

import math

def somatorioB():
    soma = 0
    
    for i in range(1, 51):
        soma += math.pi / math.sqrt(i)
        
    return 7 + soma

print("B =", somatorioB())