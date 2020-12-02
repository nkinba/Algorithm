#include <iostream>
#include <queue>

using namespace std;
int main(){
	unsigned int b = -1;
	cout << b <<endl;
	
	int a[10];
	fill_n(a,10,-1);
	for(int i= 0; i<10; i++)
		cout << a[i]<< " ";
	cout <<endl;
		
	priority_queue< pair<int, int> , vector< pair<int, int> > , greater< pair<int, int> > > pq;
	
	pq.push({5,0});
	pq.push({6,1});
	pq.push({4,2});
	pq.push({2,0});
	pq.push({3,5});
	pq.push({1,2});
	pq.push({3,3});
	while(!pq.empty()) {
        cout << pq.top().first << " "<< pq.top().second <<endl;
        pq.pop();
    }
    		
	return 0;
}
