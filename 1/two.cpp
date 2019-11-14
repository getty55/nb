#include <iostream>

bool checkPerm(std::string s1, std::string s2){
	if (s1.size() != s2.size()) return false;

	int chars[256] = {0};
	for (int i = 0; i < s1.size(); ++i){
		++chars[s1[i]];
	}
	for (int i = 0; i < s2.size(); ++i){
		--chars[s2[i]];
		if (chars[s2[i]] < 0) return false;
	}
	return true;	
}

int main(){
	if (checkPerm("Homer", "meHir")) std::cout << "perm\n";
	else std::cout << "not perm\n"; 
}
