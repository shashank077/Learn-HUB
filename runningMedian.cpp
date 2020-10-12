// commented code is for debugging

// Input Format:
// first input -> numTestCase
// for each testcase: 
// 0 -> end 
// -1 -> show median 
// other -> insert element

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
struct cmp{
    bool const operator()(const int &x, const int &y){
        return x>y;
    }
};

class maxheap{
    int root=0;
    vector<int> arrl;
    vector<int> arrr;
public:
	maxheap(){
		root = -1;
		make_heap(arrl.begin(), arrl.end());
		make_heap(arrr.begin(), arrr.end());
	}
    void insert(int x){
        if(root==-1){
            root = x;
            return;
        }
        if(x<=root){
            arrl.push_back(x);
            push_heap(arrl.begin(),arrl.end());
            move();
        }
        else{
            arrr.push_back(x);
            push_heap(arrr.begin(),arrr.end(), cmp());
            move();
        }
    }
    void move(){
        if(arrl.size()==arrr.size()){
            return;
        }
        else if(arrl.size()-arrr.size()==2){
            arrr.push_back(root);
            push_heap(arrr.begin(),arrr.end(), cmp());

            root = arrl.front();
            
            pop_heap(arrl.begin(), arrl.end());
            arrl.pop_back();
            
        }
        else if(arrr.size()-arrl.size()==2){
            arrl.push_back(root);
            push_heap(arrl.begin(),arrl.end());

            root = arrr.front();
            
            pop_heap(arrr.begin(), arrr.end(), cmp());
            arrr.pop_back();

        }
        // for(int i=0 ; i<arrl.size() ; i++)
        // 	cout << arrl[i] << " ";
        // cout << " : " << root << " : ";
        // for(int i=0 ; i<arrr.size() ; i++)
        // 	cout << arrr[i] << " ";
        // cout << endl;
    }
    int median(){
        if(root==-1)    return root;
        int x;
        if(arrl.size() == arrr.size()){
            x = root;
            if(arrl.size()==0){
            	root = -1;
            }
            else{
	            root = arrr.front();
	            pop_heap(arrr.begin(),arrr.end(), cmp());
	            arrr.pop_back();
	        }

	       //  cout << endl;
        // for(int i=0 ; i<arrl.size() ; i++)
        // 	cout << arrl[i] << " ";
        // cout << " : " << root << " : ";
        // for(int i=0 ; i<arrr.size() ; i++)
        // 	cout << arrr[i] << " ";
        // cout << endl;

            return x;
        }
        else if(arrl.size() < arrr.size()){
        	x = root;
        	root = arrr.front();
            pop_heap(arrr.begin(),arrr.end(), cmp());
            arrr.pop_back();

        //     cout << endl;
        // for(int i=0 ; i<arrl.size() ; i++)
        // 	cout << arrl[i] << " ";
        // cout << " : " << root << " : ";
        // for(int i=0 ; i<arrr.size() ; i++)
        // 	cout << arrr[i] << " ";
        // cout << endl;

            return x;
        }
        else{
            x = arrl.front();
            pop_heap(arrl.begin(),arrl.end());
            arrl.pop_back();

        //     cout << endl;
        // for(int i=0 ; i<arrl.size() ; i++)
        // 	cout << arrl[i] << " ";
        // cout << " : " << root << " : ";
        // for(int i=0 ; i<arrr.size() ; i++)
        // 	cout << arrr[i] << " ";
        // cout << endl;

            return x;
        }
        
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,n;  cin >> t;
    
    while(t--){
        maxheap mp;
        cin >> n;
        while(n){
	        if(n==0){
	            continue;
	        }
	        else if(n==-1){
	            cout << "Median: " << mp.median() << endl;
	        }
	        else{
	            mp.insert(n);
	        }
	        cin >> n;
	    }
    }
    return 0;
}

// TESTCASE

// 2
// 5
// -1
// 15
// 1
// 3
// 2
// 8
// -1
// 7
// -1
// 9
// 10
// 6
// 11
// 4
// -1
// -1
// 0
// 1
// 1
// 1
// 1
// 1
// 1
// -1
// -1
// 2
// 2
// -1
// -1
// -1
// 0
