#include <iostream>

void urlify(std::string& str){
    std::string str2 = "";
    for (int i = 0; i < str.size(); ++i){
        while (isspace(str[i])){
            str2 += "%20";
            ++i;
        }
        str2 += str[i];
    }
    str = str2;
}

void urlify2(std::string& str){
    int spaces = 0;
    for (char c : str){
        if (isspace(c)) ++spaces;
    }
    int index = str.size() + spaces * 2;
    str[index] = '\0';
    for (int i = str.size()-1; i >= 0; --i){
        if (isspace(str[i])){
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index -= 3;
        }
        else {
            str[index-1] = str[i];
            index--;
        }
    }
}

void urlify3(char* str, int trueSize){
    int spaces = 0;
    for (int i = 0; i < trueSize; ++i){
        if (isspace(str[i])) ++spaces;
    }
    int index = trueSize + spaces * 2;
    str[index] = '\0';
    for (int i = trueSize-1; i >= 0; --i){
        if (isspace(str[i])){
            str[index-1] = '0';
            str[index-2] = '2';
            str[index-3] = '%';
            index -= 3;
        }
        else {
            str[index-1] = str[i];
            index--;
        }
    }
}

int main(){
    /*std::string s = "Mr Montgomery Burns";
    urlify2(s);*/

    char s[] = {'M','r',' ', 'M','o','n','t','y',' ','B','u','r','n','s'};
    urlify3(s, 14);
    std::cout << s << '\n';
}