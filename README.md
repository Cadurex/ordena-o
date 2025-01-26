Bubble Sort:
Compara elementos consecutivos do vetor e os troca se estiverem fora de ordem. Este processo é repetido até que o vetor esteja ordenado.
Simples de implementar.
Ineficiente para grandes volumes de dados.

Quick Sort:
Escolhe um pivô, particiona o vetor em dois subvetores com base no pivô (elementos menores à esquerda e maiores à direita) e ordena recursivamente as partes.
Muito eficiente em prática para grandes volumes de dados.
Requer uma boa escolha de pivô para evitar o pior caso.

Escolha de Pivôs no Quick Sort
A escolha do pivô é crucial para o desempenho do Quick Sort. Um pivô mal escolhido pode causar um desequilíbrio no particionamento, resultando em uma complexidade de 𝑂(𝑛2)O(n 2).

Pivô fixo (simples):
Escolher o primeiro ou o último elemento como pivô.
Simples de implementar, mas pode levar ao pior caso se os dados já estiverem ordenados ou quase ordenados.

Pivô aleatório:
Escolhe aleatoriamente um elemento do vetor como pivô.
Reduz significativamente a probabilidade de ocorrer o pior caso.

Mediana de três elementos:
Escolhe o pivô como a mediana entre o primeiro, o último e o elemento do meio.
Ajuda a balancear o particionamento em muitos casos práticos.

Mediana de uma amostra maior:
Calcula a mediana de uma amostra de 𝑘 
k elementos do vetor.
Melhora ainda mais o balanceamento, mas aumenta o custo de escolher o pivô.
