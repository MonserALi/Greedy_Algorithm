#include<bits/stdc++.h>
using namespace std;

class Activity{
public:
    string name;
    int start_time;
    int finish_time;

};

comp(Activity a, Activity b){
    return a.finish_time < b.finish_time;
}

vector<Activity> SelectActivity(Activity *clubs, int n, int gap){
    sort(clubs,clubs+n, comp);
    vector<Activity> selected;
     selected.push_back(clubs[0]);
     for(int i=1;i<n;i++){
        if((selected[selected.size()-1].finish_time)+gap <= clubs[i].start_time){
            selected.push_back(clubs[i]);
        }
     }


    return selected;
}

int main(){
    int n;
    cout<<"Enter the number of clubs: ";
    cin>>n;
    Activity clubs[n];
    cout<<"Enter the name start time and duration of clubs: "<<endl;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int a, b;
        cin>>a>>b;
        clubs[i].name = s;
        clubs[i].start_time = a;
        clubs[i].finish_time = a+b;
    }
    int gap;
    cout<<"Enter the time for gap: ";
    cin>>gap;

    vector<Activity> selected;
    selected  = SelectActivity(clubs, n, gap);
    cout<<"Total selected Clubs : "<<selected.size()<<endl;
    cout<<"Selected Clubs : "<<endl;
    for(int i=0;i<selected.size();i++){
        cout<<selected[i].name<<endl;
    }

}
