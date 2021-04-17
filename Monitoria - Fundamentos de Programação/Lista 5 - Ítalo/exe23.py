# Lista 4 (Ítalo) - Questao 23

listaA = [1, 2, 3, 4, 5]
listaB = [5, 4, 3, 2, 1]

intersecao = set(listaA).intersection(listaB)

if(len(intersecao)==len(listaA) or len(intersecao)==len(listaB)):
    print("Os elementos das listas são iguais")
else:
    print("Os elementos das listas são diferentes")