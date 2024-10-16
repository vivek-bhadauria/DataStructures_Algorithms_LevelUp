#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

class CarLocation{
    public:
        string name;
        int x;
        int y;

        CarLocation(string name, int x, int y){
            this->name = name;
            this->x = x;
            this->y = y;
        }

        void display(){
            cout<<name<<" : "<<x<<", "<<y<<endl;
        }

        int distance(){
            return x*x + y*y;
        }
};

class CompareDistance{
    public:
        bool operator()(CarLocation a, CarLocation b){
            return a.distance() < b.distance();
        }
};

vector<CarLocation> findClosestCabs(vector<CarLocation*> v, int k){

    priority_queue<CarLocation, vector<CarLocation>, CompareDistance> heap;/*max heap*/
    vector<CarLocation> res;
    int i=0;
    for(auto curr : v){
        CarLocation currCar = *curr;
        if(i<k){
            heap.push(currCar);
            i++;
            continue;
        }
        CarLocation currTop = heap.top();
        if(currTop.distance() > currCar.distance()){
            heap.pop();
            heap.push(currCar);
        }
    }

    while(!heap.empty()){
        res.push_back(heap.top());
        heap.pop();
    }
    
    reverse(res.begin(), res.end());
    return res;
}


int main(){

    vector<CarLocation*> v;
    v.push_back(new CarLocation("C1", 1, 1));
    v.push_back(new CarLocation("C2", 2, 1));
    v.push_back(new CarLocation("C3", 3, 2));
    v.push_back(new CarLocation("C4", 0, 1));
    v.push_back(new CarLocation("C5", 2, 3));
    
    vector<CarLocation> res = findClosestCabs(v, 3);
    cout<<"Closest Cabs : ";
    for(auto c : res){
        cout<<c.name<<" ";
    }
}