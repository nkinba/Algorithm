#include <iostream>
#include <deque>
#include <vector>
#include <map>
 
using namespace std;


int R,C;
int JPos; // X 10bits + Y 10bits
deque<int>FPos;

int xdir[4] = {-1,0,1,0};
int ydir[4] = {0,-1,0,1};

map<int,char> Map;

int MinMoves = 1000000;
int Moves = 0;

void print_map(){
	for(int i=0; i<R+2; i++){
		for(int j=0; j<C+2; j++){
			cout << Map[ (i<<10) | (j)] <<" ";
		}
		cout << endl;
	}
}


bool MoveFire(vector<int>& FTrace){
	for(size_t i=0; i<FTrace.size(); i++){
		int Fire = FTrace[i];
		for(size_t dir=0; dir<4; dir++){
			int x = (Fire >> 10) + xdir[dir];
			int y = (Fire & 1023) + ydir[dir];
			char* lookat = &Map[ (x<<10)|y ]; 
			if( *lookat == 'j'){
				*lookat = 'x';
				FPos.push_back(((x<<10)|y));
			} 
			else if( *lookat == '.'){
				*lookat = 'F';
				FPos.push_back(((x<<10)|y));
			}
		}
	}
}

void ReturnFire(vector<int>& FTrace){
	for(size_t i=0; i<FTrace.size(); i++){
		int Fire = FTrace[i];
		char* pos = &Map[Fire];
		if( *pos == 'x'){
			*pos = 'j';
			FPos.push_back(Fire);
		} 
		else if( *pos == 'F'){
			*pos = '.';
			FPos.push_back(Fire);
		}
	}
}

bool ReachEntrance(int JX, int JY){
	return (Map[((JX-1)<<10) | JY] =='0') || (Map[((JX)<<10) | (JY-1)] =='0') || (Map[((JX+1)<<10) | JY ]=='0') || (Map[((JX)<<10) | (JY+1) ]=='0');
}

void Move(){
	
//	print_map();
	int JX = JPos >> 10;  	int JY = JPos & 1023;
//	cout << JX << "  " << JY <<endl;
	if( ReachEntrance(JX,JY) ){
		if(Moves+1 < MinMoves) {
			MinMoves = Moves+1;
		}
		Map[JPos] ='.';
		return;						 	
	}

	vector<int> FTrace; // 현재의 움직이기 전의 불  
	bool FireOn[4] = {0,0,0,0};  
		
	while(!FPos.empty()){  // 불 덱에서 꺼내서 FTrace에 꺼내는데 이 떄 JPos주변으로  가는지 검사한다. 

		int Fire = FPos.front();
		int FireX = Fire>>10; 	
		int FireY = (Fire & 1023);

		for(size_t j=0; j<4; j++){
				int X = JX + xdir[j]; 
				int Y = JY + ydir[j];
				if(FireX == X && FireY == Y){
			 		 FireOn[j] = 1;
				}
		}	
		
		FTrace.push_back(Fire);
		FPos.pop_front();
	}
	
	// 좌 
	if(!FireOn[0] && Map[((JX-1)<<10) | JY] == '.'){
		// 지훈이 뭅 
		if(Moves+1 < MinMoves){
			JPos = (((JX-1)<<10) | JY);
			Map[ (JX << 10) | JY ] = 'j';
			Map[JPos] ='J';
			Moves++;
			//불 뭅
			MoveFire(FTrace);
			Move();		
			Moves--;
		}
	}
	
	// 상 
	if(!FireOn[1] && Map[((JX)<<10) | (JY-1)]  == '.'){
		if(Moves+1 < MinMoves ){
			JPos = ((JX<<10) | (JY-1));
			Map[ (JX << 10) | JY] = 'j';
			Map[JPos] ='J';
			Moves++;
			MoveFire(FTrace);
			Move();	
			Moves--;
		}
	}
	 
	// 우 
	if(!FireOn[2] && Map[((JX+1)<<10) | JY] == '.'){
		if(Moves+1 < MinMoves ){
			JPos = (((JX+1)<<10) | JY);
			Map[ (JX << 10) | JY] = 'j';
			Map[JPos] ='J';
			Moves++;
			MoveFire(FTrace);
			Move();	
			Moves--;
		}
	} 
	
	// 하 
	if(!FireOn[3] && Map[((JX)<<10) | (JY+1) ] == '.'){
		if(Moves+1 < MinMoves ){
			JPos = ((JX<<10) | (JY+1));
			Map[ (JX << 10) | JY] = 'j';
			Map[JPos] ='J';
			Moves++;
			MoveFire(FTrace);
			Move();	
			Moves--;
		} 
	}  

	FPos.clear();
	ReturnFire(FTrace);	
	JPos = ((JX<<10) | JY);
	Map[JPos] ='.';	

}

int main(){
	cin >> R >> C;
	for(int i=0; i<C+2; i++){
		Map[( (0<<10)|(i) )] = Map[( ( (R+1)<<10 ) | (i))] = 48; //'0' 
	}

	for(int i=1; i<=R; i++){
		Map[( (i<<10)|(0) )] = 48; 
		Map[( (i<<10)|(C+1) )] = 48; 
		for(int j=1; j<=C; j++){
			char c;
			cin >>  c;
			if(c == 'J'){
				JPos = ((i<<10)|j);
			}
			else if(c == 'F'){
				FPos.push_back(((i<<10)|j));
			}
			Map[ (i<<10) | (j) ] = c;
		}
	}
//	print_map();

	Move();
	if(MinMoves == 1000000) cout << "Impossible";
	else
		cout << MinMoves;
	
	return 0;
}

