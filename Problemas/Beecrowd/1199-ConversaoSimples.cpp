#include <bits/stdc++.h>

using namespace std;

map <char, int> dic;
char dic2[16];

int ConvertHexToDecimal(string num){
	int pt = num.size()-1;
	int pot = 1, ans = 0;

	while(num[pt] != 'x'){
		ans += dic[num[pt]]*pot;
		pt--;
		pot *= 16;
	}

	return ans;
}

string ConvertDecimalToHex(string num_s){
	string ans = "0x";
	stack <char> p;
	int num = 0, pot = 1;

	for(int i = num_s.size()-1; i >= 0; i--){
		num += (num_s[i]-'0')*pot;
		pot *= 10;
	}
	
	while(num > 0){
		p.push(dic2[num%16]);
		num /= 16;
	}

	while(!p.empty()){
		ans += p.top();
		p.pop();
	}

	return ans;	
}

int main(){
	for(char aux = '0'; aux != '9'+1; aux++) dic[aux] = (int)aux-'0';
	for(char aux = 'A'; aux != 'G'; aux++) dic[aux] = (int)aux-'A'+10;
	for(char aux = 'a'; aux != 'g'; aux++) dic[aux] = (int)aux-'a'+10;
	for(int i = 0; i < 10; i++) dic2[i] = '0'+i;
	for(int i = 0; i < 6; i++) dic2[i+10] = 'A'+i;

	string num;
	while(cin >> num){
		if(num[0] == '-') break;
		else if(num.size() > 2 && num[1] == 'x') cout << ConvertHexToDecimal(num) << endl;
		else cout << ConvertDecimalToHex(num) << endl;
	}

	return 0;

}
