# Lista 4 (Ítalo) - Questao 11

numeros = [4, 6, 15, 8, 4, 7, 8]
produto = 1

for n in numeros:
    if n%2==1:
        produto*=n

print("Produto dos elementos impares: ", produto)