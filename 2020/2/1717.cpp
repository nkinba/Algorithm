#include <cstdio>

using namespace std;

int n,m,op,a,b;
int parents[1000001];

int findRoot(int cur){
	if(parents[cur] == cur) return cur;
	return parents[cur] = findRoot(parents[cur]);
}

void uni(){
	int aR = findRoot(a);
	int bR = findRoot(b);
	
	if(aR < bR) parents[bR] = aR;
	else if(aR > bR) parents[aR] = bR;
	return;
}

void find(){
	int aR = findRoot(a);
	int bR = findRoot(b); 
	printf("%s", ((aR == bR) ? "YES\n" : "NO\n"));
	return;
}

void print(){
	for(int i=0; i<=n; i++)
		printf("%d ", parents[i]);
	printf("\n");
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	
	for(int i=0; i<=n; i++)
		parents[i] = i;
		
	for(int i=1; i<=m; i++){
		scanf("%d%d%d", &op, &a, &b);
		if(!op) uni();
		else find();
//		print();	
	}

	
	return 0;
}
