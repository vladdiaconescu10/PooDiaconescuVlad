#include <iostream>
#include <fstream>
using namespace std;
ifstream f("in.txt");
int convert(char n) {
	return (int)n;
}
int main()
{
	int s = 0, n;
	while (!f.eof()) {
		f >> n;
		n = convert(n);
		cout << n << endl;
		s = s + n;
	}
	cout << s;
	f.close();
}