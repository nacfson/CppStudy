#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;
int main(void) {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count, problem;
	unordered_map<string, int> pokemons;
	unordered_map<int, string> pokemons2;
	cin >> count >> problem;
	
	for (int i = 0; i < count; i++) {
		string result;
		cin >> result;

		pokemons.emplace(result,pokemons.size()+1);
		pokemons2.emplace(pokemons2.size() + 1, result);
	}

	for (int i = 0; i < problem; i++) {
		string result;
		cin >> result;
		if (isdigit(result[0])) {
			cout << pokemons2[stoi(result)] << '\n';
		}
		else {
			cout << pokemons[result] << '\n';
		}
	}
	return 0;
}