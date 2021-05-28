#include <iostream>

using namespace std;

int n, x, bitSets = 0;
string op;

constexpr unsigned int Hash(const char* str){
    return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * Hash(str + 1) : 8603;
}

void func(){
	switch(Hash(op.c_str()))
	{
		case Hash("add"):
			cin >> x;
			bitSets |= (1<< (x-1));
			break;
		case Hash("check"):
			cin >> x;
			cout << ((bitSets & (1<< (x-1))) ? 1 : 0 )<< "\n";
			break;
		case Hash("remove"):			
			cin >> x;
			bitSets &= ~(1<< (x-1));
			break;
		case Hash("toggle"):
			cin >> x;
			bitSets ^= (1 << (x-1));
			break;
		case Hash("all"):
			bitSets |= ~0;
			break;
		case Hash("empty"):
			bitSets &= 0;
			break;
		default: break;
	}
}	
	
int main(){
   ios_base :: sync_with_stdio(false); 
   cin.tie(NULL); 
   cout.tie(NULL);
   
	cin >> n;
	
	for(size_t i=0; i<n; i++){
		cin >> op;
		func();	
	}
	
	return 0;
}
