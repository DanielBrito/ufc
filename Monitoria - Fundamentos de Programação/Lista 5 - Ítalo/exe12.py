# Lista 4 (Ítalo) - Questao 12

numeros = [15, 25, 71, 65, 33, 91, 110, 55]
contMult = 0
soma = 0

for n in numeros:
    if n%5==0:
        contMult+=1
        soma+=n

print("Media dos elementos multiplos de 5: ", soma/contMult)