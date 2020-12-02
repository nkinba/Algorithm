#include <iostream>

using namespace std;

int main(){
	int sum= 0, set=0, preset=0;
	char pre='0';
	char score[13] = {'-',};
	cin.getline(score, 13);
	cout << sizeof(score) <<endl;
	
	for(char c : score){
	
		
		if( '0'<=c && '9'>=c ){
		
			if(pre=='0'){
				sum += set; 
				cout << "set : " << set<<endl;
				preset = set;
				set = 0;
			}
			
			if(c == '1'){   	//1-
				pre ='1';
				set=1;	
			}
			
			else if(c == '0'){
				if(pre == '1'){   //10
					set = 10;
					pre = '0';
				}
				else{			//0
					set=0;
					continue;
				}
			}
			
			else{			//2~9
				set = c-48;
			}
		}
		
		else if(c=='*'){
			set*=2;
			sum+=preset;
		}
		
		else if(c=='#'){
			set*=(-1);
		}
		
		else if(c=='S' || c=='T' || c=='D'){
			if(pre=='1') pre='0';
			
			if(c=='S'){
					cout << "setS : " << set<<endl;

				continue;
			}	
			else if(c=='D'){
								cout << "setD : " << set<<endl;

				set= (set*set);
			}
			else {
				cout << "setT : " << set<<endl;
				set = (set*set*set);
			}
		}	
		
		else {
			sum += set; 
			break;
		}	
	}
	
	
	cout << sum;
	return 0;
}

