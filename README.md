
# Descrição do algoritmo

O algoritmo tem como objetivo ler ou gerar um arquivo ".data" de um labirinto composto por uma estrutura de n matrizes, e depois percorrer o labirinto simulando um 
personagem que se movimenta aleatoriamente entre as posições (x,y) livres. O programa finaliza quando o personagem coleta os itens presentes no caminho até que todo 
o caminho tenha sido percorrido e que o personagem tenha voltado para a sua posição inicial ou também pode ser finalizando quando o personagem fica sem vida devido aos 
perigos encontrados no Labirinto.

# Como foi desenvolvido

O código foi desenvolvido em linguagem C, utilizando três arquivos: Labirinto.h, Labirinto.c e main.c. O arquivo Labirinto.h contém as definições de structs 
utilizadas para representar as matrizes e o personagem, além das declarações das funções utilizadas no programa. O arquivo Labirinto.c contém as implementações das 
funções declaradas no arquivo Labirinto.h. Já o arquivo main.c é responsável por chamar a função Initiation() que inicia o programa.

# Regras Propostas

- Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).

- Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.

- Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.

- O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas conforme exercício anterior. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.

- Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.

# Funções 

- Initiation(): função responsável por iniciar o programa, exibir o menu e chamar as funções correspondentes de acordo com a escolha do usuário.
- GenerateMatrix(): função responsável por gerar as matrizes aleatórias e armazená-las em um arquivo de texto.
- PrintMatrix(): função responsável por imprimir as matrizes geradas na tela.
- ReadMatriz(): função responsável por ler as matrizes presentes no arquivo "input.data" e armazená-las em uma estrutura de dados.
- Jornada(): função responsável por percorrer o labirinto e executar o jogo.

# Funcionamento

O programa inicia solicitando ao usuário que escolha uma das opções disponíveis no menu. Caso o usuário escolha a opção 1, o programa gera matrizes quadradas 
aleatórias e as armazena em um arquivo de texto chamado "input.data". Em seguida, é chamada a função Jornada() que é responsável por percorrer todas as matrizes 
geradas e executar o jogo.Caso o usuário escolha a opção 2, o programa lê as matrizes presentes no arquivo "input.data" e as armazena em uma estrutura de dados. 
Novamente, a função Jornada() é chamada para percorrer todas as matrizes lidas.
A função Jornada() é responsável por executar o jogo em cada uma das matrizes. Para isso, ela percorre a matriz aleatoriamente escolhendo uma posição livre e
avaliando se é possível se mover para ela. Caso seja possível, a função atualiza as informações do personagem (número de passos dados, itens coletados, perigos 
enfrentados e posições exploradas) e o jogo continua. Caso contrário, o personagem permanece na mesma posição e o jogo continua. O jogo termina quando todas as 
posições da matriz tiverem sido exploradas ou o personagem ficar sem vida.

## Labirinto

### Tabela de Símbolos

| Símbolo              | Significado                                                                                                             | 
| ---------------------| -------------------------------------------------------------------------------------------------                       |
|  #                   | `Parede`   O personagem não consegue passar por essa casa                                                               |
|  *                   | `Perigo`   O personagem perde 1 de vida ao passar por essa casa                                                         |
| 1,2,3,4,5            | `Item`     O personagem pega 1 item ao passar por essa casa, ao colocar 4 itens em sua bolsa ele ganha 1 de vida        |
| 0                    | `Vazio`    O personagem anda nessa casa, mas não pega item                                                              |

O labirinto é composto por N matrizes, onde cada matriz é uma sala do jogo. O personagem inicia sua jornada na sala 0 no ponto (0,0).
O personagem consegue passar de uma sala para a outra atráves de portais que são localizados nas linhas e colunas extremas das salas. O personagem passa para outra sala 
aleatória mas na mesma posição da sala anterior, existe a chance do personagem ser teletranspotado para uma parede, se isso acontecer o personagem voltará para a sala
de antes.

### Estrutura de sala
![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/img_4.png)
- ![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/color1.png) - **Zona passável:**
O personagem consegue passar por essa área
- ![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/color2.png) - **Zona Bloqueada:**
O personagem não consegue passar por essa área
- ![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/color3.png) - **Zona Portal:**
O personagem passa para outra sala que estiver com área roxa na mesma posição que essa
- ![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/color4.png) - **Zona Portal Bloqueado:**
O personagem não consegue passar por essa área e também não consegue teletransportar de outra sala para essa área

# Exemplo de Saída Gerado

![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/img_1.png)
![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/img_2.png)
![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/img_3.png)

Nesse exemplo podemos ver que inicialmente foi gerado 4 matrizes (Esse tamanho está pré-definido para geração de matrizes em QuantMatrizes no código Labirinto.h.), o usuário decidiu o tamanho  4x4 e o labirinto foi imprimido na tela, depois se iniciou o caminho feito pelo personagem e por fim é mostrado os dados da jornada.

# Exemplo de Entrada

![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/img_5.png)
Aquí podemos ver um exemplo de arquivo input.data, na primeira linha tem 3 números inteiros, esses servem para configurar as estruturas do Labirinto, 
o primeiro e o segundo número representam as linhas e colunas das matrizes (Esses números precisam ser iguais pois está configurado para matrizes quadradas.) e o terceiro número representa a quantidade de matrizes.
As linhas seguintes são as matrizes que serão lidas, elas precisam estar separadas por espaços como é mostrado nesse exemplo.

## Resultado da Entrada acima

![This is an image](https://github.com/RafaelReisyzx/Labirinto-Recorrente/blob/main/imgs/img_6.png)
Podemos ver que nesse exemplo o personagem conseguiu sobreviver, pois não havia perigo no labirinto

# Discussão

Uma das principais questões que surgem em relação a este problema é o custo computacional da solução proposta. A escolha aleatória de movimentos pode levar a uma grande quantidade de tentativas frustradas e, consequentemente, a um elevado tempo de execução. 
Outra questão relevante é a eficácia da estratégia randômica adotada. Embora essa abordagem possa parecer intuitiva, ela pode não ser a mais adequada para resolver o problema proposto. Em vez disso, uma abordagem mais sistemática, que leve em consideração fatores como a posição atual do personagem e a localização dos itens e perigos no labirinto, pode ser mais eficiente.
Em geral, É importante avaliar cuidadosamente a solução proposta em relação ao seu custo computacional e eficácia, a fim de garantir que ela possa ser aplicada de forma prática e eficiente.

# Conclusão:

O problema apresentado trata de um desafio em que um garoto se encontra perdido em um labirinto e deve encontrar uma saída enquanto coleta itens e evita perigos. A solução proposta envolve a leitura de matrizes a partir de um arquivo e a escolha aleatória de movimentos, que podem ser bloqueados por paredes ou reduzir a vida do personagem.
Em resumo, a regra randômica utilizada para movimentar o personagem pode ter um alto custo computacional em labirintos muito grandes, 
já que pode levar um tempo considerável para encontrar o caminho correto. A solução apresentada se mostrou eficiente em labirintos de tamanho moderado.
Dessa forma, é possível concluir que o algoritmo desenvolvido é uma solução interessante para visualizar e testar o custo computacional de acordo com o tamanho da entrada. 

# Compilação e Execução

A pasta do repositorio possui um arquivo Makefile que contém as instruções para compilar e executar. Para usar essas instruções, você pode usar o terminal do seu sistema
operacional e navegar até o diretório raiz do projeto.

Existem três comandos principais que você pode usar no Makefile:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

Em resumo, para executar o programa, você precisa navegar até o diretório raiz do projeto e executar o comando make para compilar o programa e, em seguida, 
executar o comando make run para executá-lo.Se você precisar limpar a compilação anterior, pode usar o comando make clean antes de executar a compilação.
