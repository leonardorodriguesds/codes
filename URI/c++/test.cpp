#include <iostream>
#include <algorithm>

using namespace std;

void permuta(string s, int indice)
{
	if((unsigned)indice == s.size()){
		cout << s << endl;
	} else {
		for(unsigned int i = indice; i < s.size(); i++){
			swap(s[i], s[indice]);
			permuta(s, indice + 1);
		}
	}
}

int main(int argc, char *argv[])
{
	string s("AB");
	
	permuta(s, 0);
	
	return 0;
}
