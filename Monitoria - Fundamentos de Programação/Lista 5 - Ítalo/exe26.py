# Lista 4 (Ítalo) - Questao 26

import random

cartao = []

for _ in range(6):
    n = int(input("Digite um número: "))
    cartao.append(n)
    
sorteados = []

terminado = False

while not terminado:
    
    valor = random.randint(0, 10)
    
    if valor not in sorteados:
        sorteados.append(valor)
        
    if len(sorteados)==6:
        terminado = True
    
    
acertos = set(cartao).intersection(sorteados)

print("")

print("Acertos:", acertos)

print("")

print("Números sorteados:", sorteados)
    
print("")

if len(acertos)<=3:
    print("Sem premiacão")
elif len(acertos)==4:
    print("Quadra")
elif len(acertos)==5:
    print("Quina")
else:
    print("Sena")