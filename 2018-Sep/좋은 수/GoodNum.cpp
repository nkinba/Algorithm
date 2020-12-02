#include <iostream>
#include <vector>
#include <algorithm>
//#include <iterator>

using namespace std;

int two_plus(size_t idx, vector<int> v){
    vector<int> ::iterator it = v.begin();
    sort(it, it+idx);

    return false;
}


int main(void){

    int goodNum = 0;

    vector<int> vc = {1,2,1,3,6,4};
    for(size_t i=0; i<vc.size(); ++i){
        if(two_plus(i,vc))
            ++goodNum;
    }

    cout << goodNum << endl;

    return 0;
}
