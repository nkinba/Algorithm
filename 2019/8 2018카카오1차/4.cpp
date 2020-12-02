/* 셔틀 코드 - 윤수 */ 
#include <iostream>
#include <fstream>
#include <queue>
#include <iomanip>

using namespace std;
//	N 	 	T			M
int runTime, runInterv, crewMaxNumOnTheShuttle;  
ifstream ifs;

int compare (const void * a, const void * b)
{
	pair<int,int> front = (*(pair<int,int> *)a);
	pair<int,int> back = (*(pair<int,int> *)b);
	if(front.second - back.second)
		return 1;	
    else
   		return front.first - back.first;
   
}

void Leave(queue<int>& waitingCrews, int leavingTime, int& crewRemain){
	int seats = crewMaxNumOnTheShuttle;
	int waitings = waitingCrews.size();	
	
	while(seats!=0 && waitings!=0){
		waitingCrews.pop();
		--seats;
		--crewRemain;
	}
	--runTime;
	return;
}

string toTimeFormat(int number){
	string str =  to_string(number/100) + ":" + to_string(number%100) ;
	return str;	
}

int main(void){
	
	ifs.open("2.txt");
	
	int CornGetOnTheShuttle = 900;
	
	int crewNum = 0;
	
	int* arrival = new int[2000]; // 각 크루의 도착 시간  
	
	ifs >> runTime >> runInterv >> crewMaxNumOnTheShuttle;

	int* departure = new int[runTime];  // 셔틀의 출발 시간 

	while(!ifs.eof()){
		int hour, min;
		char* time = new char[6];
		ifs >> time;
		hour = (time[0]-'0')*10 + (time[1]-'0');
		min = (time[3]-'0')*10 + (time[4]-'0');
		if((hour*100 + min) != 2359)				// 23시 59분은 안가겠다는거로 생각. 
			arrival[crewNum++] = hour*100 + min;
	}
	
	for(size_t i=0; i<runTime; ++i){
		int hour = 9, min = 0;
		min += (runInterv*i);
		if(min>=60){
			hour+= (min/60); min=(min%60);
		}
		departure[i] = hour*100 + min;
	}
	
	int timeNum = crewNum + runTime; 

	pair<int,int> TIMETABLE[timeNum]; // 모든 시간들의 배열 
	for(size_t i=0; i<crewNum; ++i){
		TIMETABLE[i] = {arrival[i],0};		// 크루의 시간은 0
	}
	for(int i=0; i<runTime;  ++i)
		TIMETABLE[crewNum+i] = {departure[i],1};	// 셔틀의 시간은 1 로 구분한다. 
	
	delete[] arrival;
	delete[] departure;
		 
	qsort(TIMETABLE, timeNum, sizeof(pair<int,int>), compare);		// 시간 순으로 정렬	 
	
	for( int i=0; i<runTime+crewNum; ++i)
		cout << TIMETABLE[i].first<<" " << TIMETABLE[i].second <<endl;

	queue<int> waitingCrews;
	for(pair<int,int> elem : TIMETABLE){ 	// 시간 순으로 훑훑	 (크루 + 셔틀) 

		if(!elem.second){ 		// 크루가 줄을 선다 
		
		//------콘의 선택은?-----------//
			
			// 출근 해야 하는 경우 
			if(crewNum >= runTime*crewMaxNumOnTheShuttle){ 
			 // 남은 셔틀보다  타야 하는 크루의 수가 더 많거나 같을 경우 콘은 못타므로 1분 더 일찍 선다. 
				CornGetOnTheShuttle = elem.first - 1;
				if(CornGetOnTheShuttle%100 == 99) 
					CornGetOnTheShuttle -= 40;
				break;
			}
			else if(runTime==1 && elem.first>=900){ // 그건 아닌데(탈 자리는 있는데)  막차면? 
 				CornGetOnTheShuttle = elem.first; // 같이 탑시다. 
				break;
			} 
			
			// 아직 늦장 부려도 된다면 	
			else 
				waitingCrews.push(elem.first); // 크루를 대기열에 추가 
		}
	
	     //-------------------------------// 
	
	
		else{		// 셔틀옴  
				if(runTime==1){  // 막차 
 			 		CornGetOnTheShuttle = elem.first;
					break;
				} 
				else{
					if(runInterv==60)
						CornGetOnTheShuttle += 100;
					else CornGetOnTheShuttle += runInterv;
					Leave(waitingCrews, elem.second , crewNum); // 가능한 만큼 크루들을 태워보냄  
				}
			} 
		}
		
		cout << std::setw(5) << std::setfill('0')<< toTimeFormat(CornGetOnTheShuttle);	
}
	
