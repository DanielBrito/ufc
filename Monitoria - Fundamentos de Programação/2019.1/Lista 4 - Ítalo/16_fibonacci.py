# Questão 16 - Lista 4 (Ítalo)

def fibonacci(n): 
    if n==1: 
        return 0
    elif n==2: 
        return 1
    else: 
        return fibonacci(n-1) + fibonacci(n-2) 
  
posicao = int(input("Digite a posicao da sequencia: "))

print(str(posicao) + "o termo da sequencia =", fibonacci(posicao))