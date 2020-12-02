#include <bits/stdc++.h>

#define count first
#define val second

using namespace std;

typedef pair<int,int> pii;

int average;
int middle;
int frequent;
int numRange;

int n, inp, sum=0;

int inputs[500000];
int counts[8001]= {0,};
vector<pii> accs(8001);

bool func(const pii& a,const pii& b){
	return ( (a.count == b.count )
			 ? (a.val >  b.val ) 
			 : (a.count < b.count)
		    );
}

int main(){
	
	cin >> n;

	for(size_t i=0; i<n; i++){
		cin >> inp; 
		sum += inp;
		inputs[i]=inp;
		counts[inp+4000]++;
	}
	
	sort(inputs, inputs+n);
		
	int j = 0;
	for(int i=0; i<8001; i++){
		if(counts[i] != 0){
			accs[j++] = pii(counts[i], i-4000);
		}
	}

	sort(accs.begin(), accs.begin()+j, func);
	
	average = round((double)sum/(double)n);
	middle = inputs[n/2];
	frequent = (  ( j>1 )
		 		? (
					(accs[j-1].count == accs[j-2].count ) 
					? ( accs[j-2].val )
					: ( accs[j-1].val )
	  			  ) 
				: accs[j-1].val
			   );

	numRange = inputs[n-1] - inputs[0];
	
	cout << average << "\n";
	cout << middle << "\n";
	cout << frequent << "\n";
	cout << numRange;
	return 0;	

}
