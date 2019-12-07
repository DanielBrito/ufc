# Lista 4 (Ítalo) - Questao 28

import random

jogadas = int(input("Quantas vezes deseja lançar o dado? "))

lancamentos = []

for _ in range(jogadas):
    n = random.randint(1, 6)
    lancamentos.append(n)
    
print("Lançamentos: ", lancamentos)
    
faces = list(set(lancamentos))

for i in range(len(faces)):
    print("A face", faces[i], "apareceu", lancamentos.count(faces[i]), "vezes")
    