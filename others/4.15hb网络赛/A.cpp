#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

map<string,string> maps;

int main()
{
	maps["A"] = "Alfa";
	maps["B"] = "Bravo";
	maps["C"] = "Charlie";
	maps["D"] = "Delta";
	maps["E"] = "Echo";
	maps["F"] = "Foxtrot";
	maps["G"] = "Golf";
	maps["H"] = "Hotel";
	maps["I"] = "India";
	maps["J"] = "Juliett";
	maps["K"] = "Kilo";
	maps["L"] = "Lima";
	maps["M"] = "Mike";
	maps["N"] = "November";
	maps["O"] = "Oscar";
	maps["P"] = "Papa";
	maps["Q"] = "Quebec";
	maps["R"] = "Romeo";
	maps["S"] = "Sierra";
	maps["T"] = "Tango";
	maps["U"] = "Uniform";
	maps["V"] = "Victor";
	maps["W"] = "Whiskey";
	maps["X"] = "Xray";
	maps["Y"] = "Yankee";
	maps["Z"] = "Zulu";
	maps["0"] = "Zero";
	maps["1"] = "One";
	maps["2"] = "Two";
	maps["3"] = "Three";
	maps["4"] = "Four";
	maps["5"] = "Five";
	maps["6"] = "Six";
	maps["7"] = "Seven";
	maps["8"] = "Eight";
	maps["9"] = "Nine";
	string s;
	while(cin >> s)
	{
		printf("CQCQCQ tHis Is ");
		cout << s << " ";
		for(int i = 0;i < s.length();i ++)
		{
			string a = "";
			char c = s[i];
			if('a' <= c && c <= 'z') c -= 32;
			a += c;
			cout << maps[a] << " ";
		}
		cout << s << endl;
	}
	return 0;
}



