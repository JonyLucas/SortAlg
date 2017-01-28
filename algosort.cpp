/**
*
*   Aluno: João Lucas Fabião Amorim
*   Matricula: 11409560
*   APA 2016.2 - Trabalho 02 / Unidade 01
*   Descrição: Trabalho de APA que consiste em implementar e testar os seguintes algoritmos de ordenação - Insertion Sort, Selection Sort,
*   Quick Sort, Merge Sort, Heap Sort.
*
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>

using namespace std;

void insertion_sort(int vetor[], int size);
void selection_sort(int vetor[], int size);
void quick_sort(int vetor[],int ini, int fim);
void merge_sort(int vetor[], int size, int ini, int fim);
void merge(int vetor[], int size, int ini, int meio, int fim);
void heap_sort(int vetor[], int size);
void max_heap(int vetor[], int ind, int n);
void exibe_lista(int vetor[], int size);
bool ordenado(int vetor[], int size);

ofstream osfile("schedule.csv", ios::app);

int main(int argc, char* argv[]) {

    int tam, arg = 0; /*arg = 0 - Valor default*/
    bool show = true;/*valor default*/

    clock_t start_time;
    double time;
    
    ifstream infs;

    switch(argc){
        case 2:
            infs.open(argv[1], ifstream::in);
            break;

        case 3:
            infs.open(argv[1], ifstream::in);
            arg = atoi(argv[2]);            
            break;

        case 4:

            infs.open(argv[1], ifstream::in);
            arg = atoi(argv[2]);
            string opt_show(argv[3]);
            
            if(!opt_show.compare("false") || !opt_show.compare("f") || !opt_show.compare("0"))
                show = false;
            else
                show = true;

    }

    if(infs.is_open()){
        infs >> tam;

    }else{

        cin >> tam;

    }

    int vetor[tam], vetor_insert[tam], vetor_select[tam], 
        vetor_quick[tam], vetor_merge[tam], vetor_heap[tam];

    if(infs.is_open()){

        for(int i = 0; i < tam; i++){

            infs >> vetor[i];

            vetor_insert[i] = vetor_select[i] = vetor[i];
            vetor_quick[i] = vetor_merge[i] = vetor_heap[i] = vetor[i];

        }

    }else{
        for(int i = 0; i < tam; i++){
            
            cin >> vetor[i];

            vetor_insert[i] = vetor_select[i] = vetor[i];
            vetor_quick[i] = vetor_merge[i] = vetor_heap[i] = vetor[i];

        }
    }

    if(show) { exibe_lista(vetor, tam); }

    switch(arg){

        case 1:

            start_time = clock();
            insertion_sort(vetor_insert, tam);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_insert, tam)){
                cout << "vetor insertion" << endl;
                if(show) exibe_lista(vetor_insert, tam);
                osfile << time << ", 0, 0, 0, 0"; /**"Vetor insertion - Tempo decorrido(s): "*/
            }

            break;

        case 2:

            start_time = clock();
            selection_sort(vetor_select, tam);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_select, tam)) {
                cout << "vetor selection" << endl;
                if(show) exibe_lista(vetor_select, tam);
                osfile << "0, " << time << ", 0, 0, 0";
            }

            break;

        case 3:

            start_time = clock();
            quick_sort(vetor_quick, 0, tam-1);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_quick, tam)) {
                cout << "vetor quick" << endl;
                if(show) exibe_lista(vetor_quick, tam);
                osfile << "0, 0, " << time << ", 0, 0";
            }

            break;

        case 4:

            start_time = clock();
            merge_sort(vetor_merge, tam, 0, tam-1);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_merge, tam)) {
                cout << "vetor merge" << endl;
                if(show) exibe_lista(vetor_merge, tam);
                osfile << "0, 0, 0, "<< time << ", 0";
            }

            break;

        case 5:

            start_time = clock();
            heap_sort(vetor_heap, tam);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_heap, tam)) {
                cout << "vetor heap" << endl;
                if(show) exibe_lista(vetor_heap, tam);
                osfile << "0, 0, 0, 0, " << time;
            }

            break;

        case 0:

            start_time = clock();
            insertion_sort(vetor_insert, tam);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_insert, tam)){
                cout << "vetor insertion" << endl;
                if(show) exibe_lista(vetor_insert, tam);
                osfile << time << ", ";;
            }

            start_time = clock();
            selection_sort(vetor_select, tam);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_select, tam)) {
                cout << "vetor selection" << endl;
                if(show) exibe_lista(vetor_select, tam);
                osfile << time << ", ";
            }

            start_time = clock();
            quick_sort(vetor_quick, 0, tam-1);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_quick, tam)) {
                cout << "vetor quick" << endl;
                if(show) exibe_lista(vetor_quick, tam);
                osfile << time << ", ";
            }

            start_time = clock();
            merge_sort(vetor_merge, tam, 0, tam-1);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_merge, tam)) {
                cout << "vetor merge" << endl;
                if(show) exibe_lista(vetor_merge, tam);
                osfile << time << ", ";
            }

            start_time = clock();
            heap_sort(vetor_heap, tam);
            time = (double)(clock() - start_time)/CLOCKS_PER_SEC;

            if(ordenado(vetor_heap, tam)) {
                cout << "vetor heap" << endl;
                if(show) exibe_lista(vetor_heap, tam);
                osfile << time;
            }

            break;

        default:
            cout << "Operacao invalida" << endl;

    }

    osfile << "\n";

    infs.close();
    osfile.close();

    return 0;
}

void insertion_sort(int vetor[], int size){ /**Metodo Insertion sort**/

    if(size <= 1){ /**Verifica o tamanho do vector**/
        return ;
    }

    int key;

    for(int j = 1; j < size; j++){
        key = vetor[j];
        int i = j - 1;
        while(vetor[i] > key && i >=0){
            vetor[i+1] = vetor[i];
            i--;
        }

        vetor[i + 1] = key;

    }

}

void selection_sort(int vetor[], int size){

    int min, aux;

    for(int i = 0; i < size; i++){
        min = i;

        for(int j = i + 1; j < size; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }

        if(min != i){
            aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }

}

void quick_sort(int vetor[], int ini, int fim){ /**Metodo quick sort com o pivo na posicao central do array*/

    if(ini >= fim){
        return ;
    }

    int aux, i = ini, j = fim;

    int pospivo = ((fim - ini)/2) + ini;
    int pivo = vetor[pospivo];

    while(i <= j){

        while(vetor[i] <= pivo && i < fim) i++;
        while(vetor[j] >= pivo && j > ini) j--;


        if(i == fim && j == fim){ /**Caso o pivo seja o maior elemento do array*/

            aux = vetor[pospivo];
            vetor[pospivo] = vetor[fim];
            vetor[fim] = aux;
            quick_sort(vetor, ini, fim - 1);
            break;

        }else if(i == ini && j == ini){ /**Caso o pivo seja o menor elemento*/

            aux = vetor[pospivo];
            vetor[pospivo] = vetor[ini];
            vetor[ini] = aux;
            quick_sort(vetor, ini + 1, fim);
            break;

        }else if(j < i){
            if(j < pospivo && i < pospivo){

                /**Caso os dois indices estiverem a esquerda da pos do pivo,
                 * entao troca o elemento i(que é maior do que o pivo) com o pivo
                 * Dessa forma os elementos maiores ficarao a direita do pivo*/
                aux = vetor[i];
                vetor[i] = pivo;
                vetor[pospivo] = aux;
                quick_sort(vetor, ini, i - 1);
                quick_sort(vetor, i + 1, fim);
                break;

            }else if(j > pospivo && i > pospivo){

                /**Caso os dois indices estiverem a direita da pos do pivo,
                 * entao troca o elemento j(que é menor do que o pivo) com o pivo
                 * Dessa forma os elementos menores ficarao a direita do pivo*/
                aux = vetor[j];
                vetor[j] = pivo;
                vetor[pospivo] = aux;
                quick_sort(vetor, ini, j - 1);
                quick_sort(vetor, j + 1, fim);
                break;

            }else if(j == pospivo - 1 && i == pospivo + 1){ /**Caso os indices estejao entre a posicao do pivo, isto e, ele e o elemento do meio, utilize o quick_sort com o pivo no fim*/

                quick_sort(vetor, ini, pospivo - 1);
                quick_sort(vetor, pospivo + 1, fim);
                break;

            }else{ /**Caso ocorra numeros repetidos entre o meio --- if( j < pospivo - 1 || i > pospivo + 1 )*/
                quick_sort(vetor, ini, pospivo - 1);
                quick_sort(vetor, pospivo + 1, fim);
            }
        }else{
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    return ;
}

void merge_sort(int vetor[], int size, int ini, int fim){

    if(ini < fim){
        int meio = (fim + ini)/2;
        merge_sort(vetor, size, ini, meio);
        merge_sort(vetor, size, meio + 1, fim);
        merge(vetor, size, ini, meio, fim);
    }
}

void merge(int vetor[], int size, int ini, int meio, int fim){

    int aux[size];

    for(int i  = ini; i <= fim; i++){
        aux[i] = vetor[i];
    }

    int i = ini, j = meio + 1, k = ini;

    while(i <= meio && j <= fim){
        if(aux[i] <= aux[j]){
            vetor[k] = aux[i];
            i++;
        }else{
            vetor[k] = aux[j];
            j++;
        }

        k++;
    }

    while(i <= meio){
        vetor[k] = aux[i];
        i++;
        k++;
    }

    while(j <= fim){
        vetor[k] = aux[j];
        j++;
        k++;
    }
}

void heap_sort(int vetor[], int size){
    int n = size - 1, aux;

    for(int i = n/2; i >= 0; i--){
        max_heap(vetor, i, n);
    }

    for(int i = n; i > 0; i--){
        aux = vetor[i];
        vetor[i] = vetor[0];
        vetor[0] = aux;
        n--;
        max_heap(vetor, 0, n);
    }
}

void max_heap(int vetor[], int ind, int n){
    int max = ind, aux;
    int left = ind * 2;
    int right = ind * 2 + 1;

    if(left <= n && vetor[left] > vetor[max]){
        max = left;
    }

    if(right <= n && vetor[right] > vetor[max]){
        max = right;
    }

    if(max != ind){
        aux = vetor[ind];
        vetor[ind] = vetor[max];
        vetor[max] = aux;
        max_heap(vetor, max, n);
    }
}

void exibe_lista(int vetor[], int size){

    for(int i = 0; i < size; i++){
        cout << "Elemento[" << i << "]: " << vetor[i] << endl;
        //cout << vetor[i] << endl;
    }
    cout << endl;
}

bool ordenado(int vetor[], int size){

    for(int i = 0; i < size - 1; i++){
        if(vetor[i] > vetor[i+1]){
            return false;
        }
    }

    return true;
}
