# Questão 7 - Lista 4 (Ítalo)

import math

def fatorial(n):
    fat = 1
    
    for i in range(1, n+1):
        fat *= i
        
    return fat

def somatorioA(n):
    soma = 0
    
    for i in range(1, n+1):
        soma += fatorial(i);
        
    return soma

def somatorioB():
    soma = 0
    
    for i in range(1, 51):
        soma += math.pi / math.sqrt(i)
        
    return 7 + soma

def somatorioC():
    soma = 0
    base = 5    
    
    for i in range(2, 26):
        soma += math.tan((i*math.pi)/(i+1)) - pow(base, 2)
        base += 2
        
    return soma

def somatorioD():
    soma = 0
    radicando = 10
    
    for i in range(1, 61):
        soma += fatorial(i)/(math.sqrt(radicando))
        radicando += 3
        
    return soma

def calculaI(n):
    resultado = (somatorioA(n)+pow(somatorioB(),4))/(math.sqrt(3)-somatorioC())+(5/somatorioD())
    return resultado

n = int(input("Digite o valor de n: "))

print("I =", calculaI(n))