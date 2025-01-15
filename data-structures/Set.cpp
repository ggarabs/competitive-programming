#include <bits/stdc++.h>

using namespace std;

int main(){
	set <int> conj;

	conj.insert(5); // Inserção em O(log N)
	conj.insert(12);
	conj.insert(3);
	conj.insert(5); // Não adiciona pois ele já está no conjunto

	// conj = {3, 5, 12}. Set é sempre ordenado
	
	conj.erase(5); // Remoção em O(log N).
	conj.insert(5);
	
	conj.find(5); // Busca em O(log N). Retorna um ponteiro para o elemento.
		     // Se ele não estiver no conjunto, retorna conj.end().

	conj.lower_bound(5); // min [5,+oo) em O(log N)
	conj.upper_bound(5); // min (5,+oo) em O(log N)

	conj.clear(); // Limpa o conjunto em O(N)
	
	for(int i = 0; i < 10; i++) conj.insert(i);

	// Iterar sobre um set. Declara um iterador e depois percorre o set.
	set<int>::iterator pont;

	for(pont = conj.begin(); pont != conj.end(); pont++) cout << *pont << " ";
	cout << endl;

	// Maneira mais concisa:

	for(auto &elem : conj){
		cout << elem << endl;
	}
	
	return 0;
}
