#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> sortBalls(vector<int> balls){
    
    int j=0;
    unordered_map<int,int> h;
    for(auto v : balls){
        h[v]++;
    }
 
    for(int i=0; i<=2; i++){
        while(h[i]>0){
            balls[j] = i;
            j++;
            h[i]--;
        }
    }
    
    return balls;
}

/* sort 3 balls with Dutch National Flag algo */
vector<int> sortBalls2(vector<int> balls){
    int low=0,mid=0,high=balls.size()-1;

    while(mid<=high){
        if(balls[mid] == 0){
            swap(balls[low], balls[mid]);
            low++;
            mid++;
        }else if(balls[mid] == 1){
            mid++;
        }else if(balls[mid] == 2){
            swap(balls[mid], balls[high]);
            high--;
        }
    }
    
    return balls;
}

/* sort 4 balls with Dutch National Flag Algo */
vector<int> sortBalls3(vector<int> balls){
    int low=0,mid1=0,mid2=0,high=balls.size()-1;

    while(mid2<=high){
        if(balls[mid2] == 0){
            swap(balls[low], balls[mid2]);
            low++;
            if(mid1<low){
                mid1++;
            }
            if(mid2<low){
                mid2++;
            }
        }else if(balls[mid2] == 1){
            swap(balls[mid1], balls[mid2]);
            mid1++;
            mid2++;
        }else if(balls[mid2] == 2){
            mid2++;
        }else if(balls[mid2] == 3){
            swap(balls[high], balls[mid2]);
            high--;
        }
    }
    
    return balls;
}

int main(){

    vector<int> v = {0, 0, 1, 2, 0, 1, 2, 0};
    vector<int> res = sortBalls2(v);
    vector<int> v1 = {0, 3, 1, 2, 0, 1, 2, 0, 3, 2,1,0,3,0,3,2,1};
    vector<int> res1 = sortBalls3(v1);

    for(auto v : res1){
        cout<<v<<", ";
    }
    cout<<endl;
}
