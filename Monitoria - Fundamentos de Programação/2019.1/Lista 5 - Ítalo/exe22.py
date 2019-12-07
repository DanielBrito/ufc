# Lista 4 (Ítalo) - Questao 22

lista = []

tamanho = int(input("Digite a quantidade de elementos: "))

for i in range(0, tamanho):
    n = int(input("Digite um elemento: "))
    lista.append(n)
    
if(len(lista)==len(set(lista))):
    print("\nTodos os elementos são diferentes")
else:
    print("\nNem todos os elementos são diferentes")