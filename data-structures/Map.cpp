#include <bits/stdc++.h>

using namespace std;

int main(){
	map <int, int> mp;

    mp.insert({10, 20}); // Inserção em O(log N)

	// Map é sempre ordenado
	
	mp.erase(10); // Remoção em O(log N).
    mp.insert({10, 20});

	mp.find(5) != mp.end(); // Busca em O(log N). Retorna um ponteiro para o elemento.
		     // Se ele não estiver no conjunto, retorna conj.end().
    mp.count(5);
	
	// Iterar sobre um map. Declara um iterador e depois percorre o map.
	map<int, int>::iterator pont;

	for(pont = mp.begin(); pont != mp.end(); pont++) cout << pont->first << " " << pont->second;
	cout << endl;

	// Maneira mais concisa:
	for(auto &[key, value] : mp) cout << key << " " << value << endl;
	
	return 0;
}
