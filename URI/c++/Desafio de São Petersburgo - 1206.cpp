#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void list_king(vector<string>*);
void list_king(vector<string>* king){
	unsigned int i;
	for(i = 0; i < (*king).size(); i++){
		cout << (*king)[i] << " ";
	}
	cout << endl;
}

void erase_position(char*, vector<string>*);
void erase_position(char pos[2], vector<string>* list){
	cout << "Remove: " << pos << endl; //Column, line
	vector<string>::iterator index = find((*list).begin(), (*list).end(), pos);
	if (index != (*list).end()) {
		(*list).erase(index);
	}
}

bool check_mate(char *, vector<string>*, char **);
bool check_mate(char *piece, vector<string>* king, char **pieces){
	if(!(*king).size())
		return true;
	char position[2]; //Column, line
	int column, line;
	column = (int)piece[1] - 'a';
	line = (int)piece[2] - '1';
	position[0] = (char)column + '0';
	position[1] = (char)line + '0';
	erase_position(position, king);
	cout << (*king).size() << endl;
	switch(piece[0]){
		case 'P':
		case 'p':
			position[1] = (char)(line - 1) + '0';
			position[0] = (char)(column - 1) + '0';
			erase_position(position, king);
			list_king(king);
			position[0] = (char)(column + 1) + '0';
			erase_position(position, king);
			list_king(king);
			break;
		case 'T':
		case 't':
			position[1] = (char)line + '0';
			break;
	}
	return false;
}

int main(){
	int n;
	while(cin >> n){
		char **pieces = new char*[n];
		char **p_position = new char*[n];
		char _king_[3], _new_[3];
		vector<string> king;
		int i, j;
		for(i = 0; i < n; i++){
			pieces[i] = new char[3];
			p_position[i] = new char[2];
			cin >> pieces[i]; //Column, line
			p_position[i][0] = (int)pieces[i][1] - 'a' + '0'; //column
			p_position[i][1] = (int)pieces[i][2] - 1; //line
		}
		cin >> _king_; //Column, line
		for(i = -1; i < 2; i++){
			if(_king_[1] + i < 'a' || _king_[1] + i > 'h')
				continue;
			for(j = -1; j < 2; j++){
				if( _king_[2] + j < '1' || _king_[2] + j > '8')
					continue;
				_new_[0] = (int)_king_[1] - '1' + i;
				_new_[1] = (int)_king_[2] - 1 + j;
				_new_[2] = '\0'; //Column, line
				king.push_back(_new_);
			}
		}
		cout << "King positions: " << king.size() << endl;
		list_king(&king);
		for(i = 0; i < n; i++){
			if(check_mate(pieces[i], &king, p_position)){
				cout << "SIM" << endl;
				break;
			}
		}
		cout << "Restam: " << king.size() << endl;
		list_king(&king);
	}
	return 0;
}
