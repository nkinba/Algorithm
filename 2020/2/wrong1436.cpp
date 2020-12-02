//refactoring 하자
 #include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	int acc = 1;
	int det = 0;
	int bas = 9;
	int add = 10;
	
	cin >> n;
	
	while(n > acc){
		det++;
		acc=acc+bas-1+add;
		bas*=10;
		add*=10;
	}
	
	if(det > 0){
		int size =  (bas/10) - 1 + (add/10);
		int target = n- (acc-((bas/10) - 1 + (add/10)))-1;
		vector<int> nums(size);
		int c=0;
		for(int f=0; f<=det; f++){
			int b = det-f; 
			// 앞== 0 뒤 >0
			if(f==0 && b>0){
				for(int i=pow(10,b-1); i<pow(10,b); i++){
					nums[c++]=666*pow(10,b)+i;
					cout << c << " for case 1 " << nums[c-1] <<endl;
				}
			}
			
			//앞>0 뒤> 0
			else if(f >0 && b > 0){
				for(int i=pow(10,f-1); i<pow(10,f); i++){
					int front = stoi(to_string(i)+"666");
					for(int j=front*pow(10,b); j<front*pow(10,b)+pow(10,b); j++){
						nums[c++]=j;
						cout << c << " for case 2 " << nums[c-1] <<endl;
					}
				}				
			}
			
			
			// 앞 >0 뒤 ==0 
			else {
				for(int i=pow(10,f-1); i<pow(10,f); i++){
					string front = to_string(i);
					nums[c++] = stoi(front+"666");
					cout << c << " for case 3 " << nums[c-1] <<endl;
				}
			} 
		}
		sort(nums.begin(), nums.end());	
		cout <<nums[target];
		return 0;	
	}

	cout << 666;
	return 0;
}
