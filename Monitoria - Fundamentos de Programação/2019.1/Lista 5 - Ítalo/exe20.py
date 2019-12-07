# Lista 4 (Ítalo) - Questao 20

lista = [-1.7, 3.0, 0.0, 1.5, 0.0, -1.7, 2.3, -1.7]
conjunto = list(set(lista))

for i in range(0, len(conjunto)):
    print(conjunto[i], "ocorre", lista.count(conjunto[i]), " vezes.") 