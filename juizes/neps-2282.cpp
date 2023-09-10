#include <iostream>

using namespace std;

int main(){
    string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	
	if(s1==s2 || s1==s3 || s2==s3)
		cout << "N" << endl;
	else
		cout << "S" << endl;

    return 0;
}
