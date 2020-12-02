// 11053 가장 긴 증가하는 부분 수열의 길이
// 1992kB 0ms 

#include <bits/stdc++.h>

using namespace std;

int n, accs[1000], nums[1000];

//void print(){
//	for(size_t i=0; i<n; i++)
//		cout << accs[i]<< " ";
//	cout << "\n";
//}

int main(){
	cin >> n;
	for(size_t i=0; i<n; i++)
		cin >> nums[i];
	
	accs[0] = 1;	
	for(size_t i=1; i<n; i++){
//		print();
		int m=1;
		for(ssize_t j=i-1; j>=0; j--){
			if(nums[i] > nums[j])
			  m = max(accs[j]+1,m);
		}
		accs[i] = m;
	}	
	
	sort(accs, accs+n);
	cout << accs[n-1];
	
	return 0;
}
