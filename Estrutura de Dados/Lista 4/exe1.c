/*

	> Quantidade de operações para o seguinte vetor [1, 2, 3]:

	1 2 3 (1 compara com 2, não troca) = 1 comparação

	1 2 3 (2 compara com 3, não troca) = 2 comparações

	1 2 3 (vetor já estava ordenado)


	> Mas com um vetor ordenado em ordem decrescente [3, 2, 1], isso não é possível:

	3 2 1 (3 compara com 2, troca) = 1 comparação

	2 3 1 (3 compara com 1, troca) = 2 comparações

	2 1 3 (2 compara com 1, troca) = 3 comparações

	1 2 3 (vetor ordenado com 3 comparações)

*/