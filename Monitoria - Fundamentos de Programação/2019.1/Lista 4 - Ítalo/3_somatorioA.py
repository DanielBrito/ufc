# Questão 3 - Lista 4 (Ítalo)

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

numero = int(input("Digite um numero: "))

print("A(n) =", somatorioA(numero))