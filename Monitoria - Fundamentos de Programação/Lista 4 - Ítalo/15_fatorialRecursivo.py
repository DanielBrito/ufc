# Questão 15 - Lista 4 (Ítalo)

def fatorialRecursivo(n):
    
    if n<=1:
        return 1
    else:
        return n * fatorialRecursivo(n-1)
    
numero = int(input("Digite um numero: "))

print(numero, "! =", fatorialRecursivo(numero))