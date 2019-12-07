# Lista 4 (Ítalo) - Questao 27

import random

cartela = []

terminado = False

while not terminado:
    
    valor = random.randint(1, 50)
    
    if valor not in cartela:
        cartela.append(valor)
        
    if len(cartela)==10:
        terminado = True

print("Cartela:", cartela)

ganhou = False
sorteados = []
acertos = 0
cont = 1

print("")

while not ganhou:
    
    sorteado = random.randint(1, 50)
    
    if sorteado not in sorteados:
        sorteados.append(sorteado)
        
        print("Rodada", cont,":", sorteado)
        cont+=1
        
        if sorteado in cartela:
            acertos += 1     
            
        if acertos==10:
            print("\nO jogador ganhou!")
            ganhou = True
            break;        