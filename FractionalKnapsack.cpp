#include <bits/stdc++.h>
using namespace std;

class Item {
public:
    int weight, value,itemNumber;
    double unitPrice;
};

bool compare(Item a, Item b){
    return a.unitPrice>b.unitPrice;
}

int fractionalKnapsack(vector<Item> &items, int w){
     sort(items.begin(),items.end(),compare);
     int totalProfit = 0;
     for(int i=0;i<items.size();i++){
        double frac = (double )w/(double )items[i].weight;
        if(frac>=1){
            cout<<"Item Number "<<items[i].itemNumber<<" : "<<items[i].weight<<" kg "<<items[i].value<<" Taka "<<endl;
            totalProfit+= (items[i].value);
            w -= items[i].weight;
        }
        else{
            int canBeTaken = frac*items[i].weight;
            int price = canBeTaken*items[i].unitPrice;
            cout<<"Item Number "<<items[i].itemNumber<<" : "<<canBeTaken<<" kg "<<price<<" Taka "<<endl;
            totalProfit+= price;
            w -= canBeTaken;
        }

        if(w==0) break;
     }
    return totalProfit;
}
int main(){
    int n;
    cout<<"Enter the number of item : ";
    cin>>n;
    vector<Item> items(n);
    cout<<"Enter the value and weight of items :";
    for(int i=0;i<n;i++){
        cin>>items[i].weight>>items[i].value;
        items[i].itemNumber = i+1;
        items[i].unitPrice = (double)items[i].value/(double)items[i].weight;
    }
    int w;
    cout<<"Enter the value of the knapsack capacity : ";
    cin>>w;

    int profit = fractionalKnapsack(items,w );

    cout<<"Total Profit : "<<profit<<endl;
    /*for(int i=0;i<n;i++){
        cout<<items[i].weight<<" "<<items[i].value<<"   " <<items[i].unitPrice<<endl;
    }
    */


return 0;

}
