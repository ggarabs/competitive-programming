// Curso Noic - Matemática Computacional III
// Crivo de Eratóstenes

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100010;

int eh_primo[maxn]; // -1 => indefinido, 0 => composto e 1 => primo.
                    // Lembre-se de inicializar "eh_primo" com -1, ou na main ou
                    // na própria função crivo, no seu começo.

void crivo(int n){
    // Inicializando "eh_primo" com -1, pois não sabemos nada sobre nenhum número, inicialmente.
    for(int i = 1; i <= n; i++){
        eh_primo[i] = -1;
    }
    
    // Para cada número de 2 até n
    for(int i = 2; i <= n; i++){
            
        // checo se o número atual é indefinido.
        if(eh_primo[i] == -1){
            
            // Se ele for, indico que ele é primo
            eh_primo[i] = 1;
    
            // e que os múltiplos dele são compostos.
            for(int j = i + i; j <= n; j += i){
                eh_primo[j] = 0;
            }
        }
    }
}