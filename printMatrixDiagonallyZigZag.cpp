#include <iostream>
#include <map>
using namespace std;

//Lets say for now matrix could be of size 1000*1000
int arr[1001][1001];

int main(){
	int t,n;	cin >> t;
	while(t--){
		cin >> n;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> arr[i][j];
			}
		}
		map<int,map<int,int>> mp;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(mp.find(i+j) == mp.end()){
					mp.emplace(i+j,map<int,int>());
				}
				mp[i+j].emplace(j,arr[i][j]);
			}
		}
		for(auto it : mp){
			if(it.first%2==0){
				for(auto jt : it.second){
					cout << jt.second << " ";
				}
			}else{
				for(auto jt=it.second.rbegin() ; jt!=it.second.rend() ; jt++){
					cout << jt->second << " ";
				}
			}
		}
	}
	return 0;
}
