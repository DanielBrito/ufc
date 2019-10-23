# Questão 1 - Lista 4 (Ítalo)

def fatorial(n):
    fat = 1
    
    for i in range(1, n+1):
        fat *= i
        
    return fat

numero = int(input("Digite um numero: "))

print(numero,"! =",fatorial(numero))