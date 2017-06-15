# Oza Filler - A Saga do Forasteiro Indômito


Repositório para o desenvolvimento do jogo _Oza - Forasteiro_ na matéria de Introdução à Jogos Eletrônicos, Universidade de Brasília.


### Envolvidos no Projeto

* Allan Jefrey (Desenvolvedor - UnB FGA);
* Hugo Alves (Desenvolvedor - UnB FGA);
* Roger Lenke (Desenvolvedor - UnB FGA);
* Murilo Oliveira (Músico - UnB Darcy Ribeiro);
* Marina Rebello (Designer - UnB Darcy Ribeiro);
* Thainá Ferreira (Designer - UnB Darcy Ribeiro).

### Introdução e Objetivos

Oza - Forasteiro é um jogo onde o jogador deve controlar um forasteiro, para coletar joías especiais!

### História

A história é sobre o Personagem CowBoy Outlaw, chamado McCry, do Jogo em Grupo (Azo). McCry é um forasteiro caçador de recompensas, que vive correndo perigos em busca de diversos desafios para provar suas habilidades. Em suas andanças se deparou com uma lenda sobre as gemas do infinito, onde diversos seres poderosos destruiam quem ousasse tentar juntá-las. Tal fato despertou sua curiosidade e uma vontade imensa de encontrá-las, visando o desafio que viria pela frente.

### Características

* Gênero: Plataforma.
* Quantidade de jogadores: Single-player.
* Quantidade de níveis: Um.
* Personagens: Um personagem jogável.

### Personagens

* Um forasteiro do velho oeste, movido por desejos pessoais.

### Objetos

Os objetos presentes no jogo são:
* Obstáculos de pulo.
* Plataformas comuns.
* Buracos.
* Espinhos.
* Jóias, que são coletáveis.

### Estrutura

Utilizar a estrutura do Jogo em Grupo (Azo) para criar uma fase completa, com um personagem jogável. O Player pode se movimentar pela fase com as setas (Andar, Pular, Abaixar), e atacar um inimigo específico que será criado. Será possível também coletar itens na fase, que serão parte do Score do Player ao final. O Player terá 3 Vidas iniciais, podendo encontrar alguma no decorrer da fase. Caso seja derrotado em algum ponto da fase e não tenha mais vidas, deve começar novamente a fase, caso ainda tiver alguma vida, retornará a um checkpoint padrão.

### Controles

O jogador pode:
* Saltar obstáculos (tecla 'w').
* Abaixar (tecla 'S').
* Andar a direita (tecla 'D').
* Andar a esquerda (tecla 'A').

### Dependências

Para executar o jogo com sucesso é necessário possuir instaladas tais dependências:
* CMake 3.5.1
* SDL 2
* SDL_image 2
* SDL_ttf 2
* SDL_mixer 2
* How to build

### Como executar

No terminal do sistema operacional (Linux), utilize os comandos na pasta do clone do projeto:
```
$ mkdir build
```
```
$ cd build
```
```
$ cmake ..
```
```
$ make
```
```
$ ./Oza-Forasteiro
```

### Produto final

Será entregue como produto final:
* Uma fase completa;
* Um personagem jogável;
