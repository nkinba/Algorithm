#include <iostream>
#include <map>
#include <algorithm>

#include <Fstream>

using namespace std;

typedef pair<char,int> pci;
typedef pair<int,char> pic;

pci Letters[100000]; //알파벳과 문자열에서의 초기 인덱스 
map<int, char> LetterIndex; // (인덱스 ,알파벳)을 (key, value) 형태로 저장 
	
char spick[50000], hpick[50000];
int sn = 0;
int hn = 0;
int N; // 짝수 

void game(){
	int rest = N;
	int right = N; 
	char s,h;
	while(rest > 0){
//		cout << "rest : " << rest  << " / right : " << right <<endl;
		//--------s-------------------------------------
		for( ;right>=1; right--){ 	// 문자열 우측으로 부터 문자를 map에서 탐색해서 안골라진 게 있으면 걔로 결정. 
			if(LetterIndex[right-1]){
				
//				cout << "SPICK is " << LetterIndex[right-1]<<endl;
					
				spick[sn++] = LetterIndex[right-1];
				LetterIndex.erase(right-1);
				right--;
				rest--;
				break;
			}
		}
			
		//--------h-------------------------------------
		for(size_t i=rest; i>=1; i--){
			int Lidx = Letters[i].second;
			if(LetterIndex[Lidx]){
				
//				cout << "HPICK is " << LetterIndex[Lidx]<<endl;;

				hpick[hn++] = LetterIndex[Lidx];
				rest--;
				if(Lidx == right-1) right--;
				break;
			}
		}
	
	}
	cout << "SN , HN : " << sn << " " << hn <<endl;
	size_t i;
	for(i=0; i<sn; i++)
	{
		if(spick[i] < hpick[i]){
			cout << "NE" <<endl;
			break;
		}
		else if(spick[i] > hpick[i]){
			cout << "DA" <<endl;
			break;
		}
	}	
	if(i==sn) cout << "NE" <<endl;
		
	for(size_t i=0; i<sn; i++)
		cout << spick[i];
	cout <<endl;
	for(size_t i=0; i<hn; i++)
		cout << hpick[i];
	cout <<endl;
}

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0); 
	
	ifstream ifs("2871tc.txt");
	
	char c;
//	cin >> N;
	ifs>>N;
	
	for(size_t i=0; i<N; i++){
//		cin >> c;
		ifs>>c;
		Letters[i] = pci(c,i);
		LetterIndex.insert(pic(i,c));
	}
	ifs.close();
	sort(Letters, Letters+N, greater<pci>());
	
//	for (auto i=0; i<N; i++)
//    {
//        std::cout << Letters[i].first << " is " << Letters[i].second <<endl;
//    }
//	cout <<endl;
//	for (auto const& entry: LetterIndex)
//    {
//        std::cout << entry.first << " is " << entry.second <<endl;
//    }
	
	game();
	
	return 0;
}
