#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/* 정렬 사용해보기 !*/ 
using namespace std;

typedef long long ll;
int U, N;
ll sum=0;
pair<int,int>* P;
//int* is_check;
//map<int, int> dot_index;
//map<int, int> dot_number_per_col;

int get_proper_size(int max_len, int beg_idx){
//	is_check[i] = true;

	ll size = max_len;
	pair<int, int> beg = P[beg_idx];
	//----------------------------------------------
	size_t i; 

	for(i=beg_idx+1; i<N; i++){
		pair<int,int> dot = P[i];
		
		int y_gap = dot.second - beg.second;
		int x_gap = dot.first - beg.first;
		if(size < x_gap ) break;
		if(y_gap < 0 ) continue;
		
		
		int box_len = max(x_gap, y_gap);
		
		if( size > box_len ) {
			size = box_len;
			if(box_len == x_gap) break;
		}
	}
	
	return size;
}

bool func(pair<int,int> A, pair<int,int> B){
	if (A.first < B.first) return true;
	else if(A.first == B.first) return A.second < B.second;
	else return false;
}

int main(void){
	ifstream ifs;
	ifs.open("tc.txt");

	ifs >> U >> N;	
	//cin >> U >> N;	
	P = new pair<int ,int>[N];

	//----------data input--------
	for(size_t i=0; i<N; i++){
		int x,y;
	//	cin >> x >> y;
		ifs >> x >> y;
		P[i] = make_pair(x,y);
	}
	
	
	//---------x axis sorting--------
	sort(P, P+N, func);
		

	//--------processing-------------
	for(size_t i=0; i<N; i++){
		int max_len = U - max(P[i].first, P[i].second);
		sum += get_proper_size(max_len, i);
	}
	
	cout << sum;
	
	return 0;
}
