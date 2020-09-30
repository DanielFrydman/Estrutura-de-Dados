#ifndef EXERCICIOS_FRYDMAN_HPP
#define EXERCICIOS_FRYDMAN_HPP

#include <iostream>
#include <tuple>
using namespace std;

int exercicio0(const char *nada) {
    return 0;
}

int exercicio1(const char *doisNumeros) {
    int a, b;
    sscanf(doisNumeros, "%d %d", &a, &b);
    int soma = 0;
    for (int i = a; i <= b; i++) soma += i;
    return soma;
}

int exercicio2(const char *listaNumeros) {
    int eleitores, contador, candidato1 = 0, candidato2 = 0, candidato3 = 0, nulo = 0;
    sscanf(listaNumeros, "%d%n", &eleitores, &contador); listaNumeros += contador;

    while (eleitores > 0) {
        int voto;
        sscanf(listaNumeros, "%d%n", &voto, &contador); listaNumeros += contador;
        if (voto == 1) candidato1++;
        else if (voto == 2) candidato2++;
        else if (voto == 3) candidato3++;
        else if (voto == 0) nulo++;
        else continue;
        eleitores--;
    }

    if ((candidato1 > candidato2) && (candidato1 > candidato3)) return 1;
    else if ((candidato2 > candidato1) && (candidato2 > candidato3)) return 2;
    else if ((candidato3 > candidato1) && (candidato3 > candidato2)) return 3;
    else if ((candidato1 == candidato2) || (candidato2 == candidato3) || (candidato1 == candidato3)) return 0;
    else return -1;

    return 0;
}

auto exercicio3(const char* valores){
    int qntNumeros, contador;
    sscanf(valores, "%d%n", &qntNumeros, &contador); valores += contador;
    
    float numeros[qntNumeros-1];
    float soma = 0;
    
    for(int i = 0; i < qntNumeros; i++){
        sscanf(valores, "%f%n", &numeros[i], &contador); valores += contador;
        soma += numeros[i];
    }

    float maximo=numeros[0], minimo=numeros[0];

    for(int i = 0; i < qntNumeros; i++){
        if (numeros[i] > maximo) maximo = numeros[i];
        if (numeros[i] < minimo) minimo = numeros[i];
    }

    float media = soma/qntNumeros;

    typedef tuple <float, float, float, float> teste;
    teste t1(soma, media, maximo, minimo);

    return t1;
}

int exercicio4(const char *notasNomes) {
    int qntAlunos, contador;
    sscanf(notasNomes, "%d%n", &qntAlunos, &contador); notasNomes += contador;

    char nomes[qntAlunos][10];
    float notas[qntAlunos];

    for (int i = 0; i < qntAlunos; i++) {
        sscanf(notasNomes, "%f%n", &notas[i], &contador); notasNomes += contador;
        sscanf(notasNomes, "%s%n", &nomes[i], &contador); notasNomes += contador;
    }

    int k;
    sscanf(notasNomes, "%d", &k);

    if (notas[k - 1] >= 6) return 1;
    else return 0;
}

int exercicio5(const char *numeroParaFatorial) {
    int n = 0;
    int valorFinal = 1;
    sscanf(numeroParaFatorial, "%d", &n);

    for (int i = 1; i <= n; i++) {
        valorFinal *= i;
    }
    return valorFinal;
}

int exercicio6(const char *numeroParaFibo) {
    int k = 0;
    int valorFinal = 1;
    sscanf(numeroParaFibo, "%d", &k);
    int resposta = 0, a = 1, b = 2;

    if ((k == 1) || (k == 2)) return 1;
    else if (k == 3) return 2;
    else {
        for (int i = 3; i < k; i++) {
            resposta = a + b;
            a = b;
            b = resposta;
        }
    }
    return resposta;
}

char exercicio7(const char *rodadasEJogadas) {
    int rodadas, contador;
    sscanf(rodadasEJogadas, "%d %n", &rodadas, &contador); rodadasEJogadas += contador;
    char jogada1, jogada2;
    int vitorias1 = 0, vitorias2 = 0;

    for (int i = 0; i < rodadas; i++) {
        sscanf(rodadasEJogadas, "%c %n", &jogada1, &contador); rodadasEJogadas += contador;
        sscanf(rodadasEJogadas, "%c %n", &jogada2, &contador); rodadasEJogadas += contador;
        if (((jogada1 == 't') && (jogada2 == 'p')) || ((jogada1 == 'p') && (jogada2 == 'd')) || ((jogada1 == 'd') && (jogada2 == 't')))
            vitorias1++;
        else if (((jogada2 == 't') && (jogada1 == 'p')) || ((jogada2 == 'p') && (jogada1 == 'd')) || ((jogada2 == 'd') && (jogada1 == 't')))
            vitorias2++;
    }

    if (vitorias1 > vitorias2) return 'M';
    else if (vitorias2 > vitorias1) return 'J';
    else return 'X';
}

auto exercicio8(const char *valores) {
    int valor1, valor2, contador;

    sscanf(valores, "%d%n", &valor1, &contador); valores += contador;
    sscanf(valores, "%d", &valor2);

    typedef tuple <int, int> tupla;
    tupla t1(valor2, valor1);

    return t1;
}

float exercicio9(const char *quantidadeEValores){
    int quantidade, contador;
    sscanf(quantidadeEValores, "%d%n", &quantidade, &contador); quantidadeEValores += contador;
    float valor=0, mediana=0, aux=0;
    float vetor[quantidade];
    
    for(int i=0; i<quantidade; i++){
        sscanf(quantidadeEValores, "%f%n", &valor, &contador); quantidadeEValores += contador;
        vetor[i] = valor;
    }

    for(int i=0; i<quantidade; i++){
        for(int j=0; j<quantidade; j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }

    if ((quantidade)%2 != 0) mediana = vetor[(quantidade/2)+1];
    else mediana = (vetor[quantidade/2] + vetor[(quantidade/2)+1])/2;

    return mediana;
}

#endif // EXERCICIOS_FRYDMAN_HPP
