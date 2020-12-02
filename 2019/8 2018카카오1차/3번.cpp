/* 캐시 코드 - 윤수  */ 
#include <iostream>
#include <string.h> 
using namespace std;

int time = 0;
int cSize;
bool hasRoom;

void LRU(char ** cache, int * used_time, char * city) {
    int max = 0,
    maxIdx = 0;
    size_t i;
    for (i = 0; i < cSize; ++i) {
    
	    if (strcmp(cache[i], "-") == 0) {
            cout << cache[i] << " to " << city << endl;
            strcpy(cache[i], city);
            used_time[i] = 0;
            break;
        }
        
        if (used_time[i] > max) {
            maxIdx = i;
            max = used_time[i];
        }
    }
    
    if ( (i == cSize) && hasRoom) {
       cout << "city : " << city << " idx : " << maxIdx << " miss" << endl;
        used_time[maxIdx] = 0;
        strcpy(cache[maxIdx], city);
    }
    time += 5;
    cout << "now : " << time << endl;
    return;
}
int main() {
  
    cin >> cSize;
    cin.ignore();
  
    (cSize != 0) ? (hasRoom = true) : (hasRoom = false);
  
    char * cache[cSize];
  	int used_time[cSize];
  	char city[20];

    for(size_t i = 0; i < cSize; ++i) {
        cache[i] = new char[20];
        strcpy(cache[i], "-");
    }
    
    
    if(hasRoom) fill(used_time, used_time+cSize,0 );
        
    while (cin.getline(city, 20)) {
        if (strcmp(city, "\0") == 0) 
            break;
        
        size_t i;
        
		for (i = 0; i < cSize; ++i) {
            if (strcmp(cache[i], city) == 0) {
                cout << "city : " << city << " idx : " << i << "hit" << endl;
                time += 1;
                used_time[i] = 0;
                break;
            }
        }
        
        if (i == cSize) 
            LRU(cache, used_time, city);
        
        for (int & i : used_time) 
            ++ i;
            
	}
    cout << time;
	
	return 0;
	
}
