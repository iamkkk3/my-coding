#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	double total_money_input;
	int num_people;
	
	cout<<"请输入红包总金额（元）："<<endl;
	if(!(cin>>total_money_input))return 0;
	
	cout<<"请输入红包个数："<<endl;
	cin>>num_people;
	
	int remaining_money=total_money_input * 100;
	int remaining_people=num_people;
	
	if(remaining_money<remaining_people){
		cout<<"老板，金额过小，不够每人一分钱！\n";
		return 0; 
	}
	
	vector<double> result;
	srand(time(0));
	
	for(int i=0;i<num_people-1;i++){
		int max_money=(remaining_money/remaining_people)*2;
		
		int grab_money=1;
		if(max_money>1){
			grab_money=rand()%(max_money-1)+1;
		}
		
		result.push_back(grab_money/100.0);
		
		remaining_money-=grab_money;
		remaining_people--;
	}
	
	result.push_back(remaining_money/100.0);
	
	double max_val=0;
	int lucky_king=0;
	
	cout<<"\n---红包派发结果---\n";
	for(int i=0;i<result.size();i++){
		cout<<"第"<<setw(2)<<i+1<<"人抢到："<<fixed<<setprecision(2)<<setw(5)
		<<result[i]<<"元\n";
		
		if(result[i]>max_val){
			max_val=result[i];
			lucky_king=i;
		} 
	}
	
	cout<<"--------------------\n";
	cout << "运气王是第 " << lucky_king + 1 
	<< " 个人，狂揽 " << max_val << " 元！\n";
	
	
	return 0;
} 
