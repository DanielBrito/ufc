# Questão 17 - Lista 4 (Ítalo)

def soma(n):
    
    if n==1:
        return 1
    else:
        return n + soma(n-1)
    
n = int(input("Digite o valor de n: "))

print("Soma(n) =", soma(n))