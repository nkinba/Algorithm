#include <bits/stdc++.h>

using namespace std;

// Unstable sort(Library-Quick Sort)
// 6032KB	116ms
typedef pair<int,int> pii; 
typedef pair<pii, string> pps;

pps credits[100000];
int n;

bool func(const pps& a, const pps& b){
	return a.first == b.first ? a.second < b.second : a.first < b.first;
}

int main(void){
	cin >> n;
	for(size_t i=0; i<n; i++){
		cin >> credits[i].first.first >> credits[i].second;
		credits[i].first.second = i;
	}	
	
	sort(credits, credits+n, func);
	for(size_t i=0; i<n; i++)
		cout << credits[i].first.first << " " << credits[i].second << "\n";
	
	return 0;
}

// Stable sort(Selection Sort)
// timeout
//typedef pair<int, string> pis;
//
//pis credits[100000];
//int n;
//
//int main(void){
//	cin >> n;
//	for(size_t i=0; i<n; i++)
//		cin >> credits[i].first >> credits[i].second;
//	for(int i=1; i<n; i++){
//		int age = credits[i].first;
//		int j=i-1;
//		while(j>=0 && credits[j].first > age){
//			swap(credits[j], credits[j+1]);
//			j--;
//		}
//	}
//	for(size_t i=0; i<n; i++)
//		cout << credits[i].first<< " " << credits[i].second << "\n";
//		
//		
//	return 0;
//}

