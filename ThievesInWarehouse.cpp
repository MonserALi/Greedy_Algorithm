#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    string name;
    double weight, value, unitPrice;
};


class Thiev
{
public:
    double capacity, profit;
};

bool compare(Item a, Item b)
{
    return a.unitPrice>b.unitPrice;
}

double fractionalKnapsack(vector<Item> &items, double w)
{
    sort(items.begin(),items.end(),compare);
    double totalProfit = 0;
    for(int i=0; i<items.size(); i++)
    {
        if(items[i].weight>0)
        {
            double frac = w/items[i].weight;
            if(frac>=1)
            {

                cout<<"Taking "<<items[i].name<<" : "<<items[i].weight<<" kg "<<items[i].weight*items[i].unitPrice<<" Taka "<<endl;
                totalProfit+= (items[i].weight * items[i].unitPrice);

                w -= items[i].weight;
                items.erase(items.begin()+i);
                i--;

            }
            else
            {
                double canBeTaken = frac*items[i].weight;
                double price = canBeTaken*items[i].unitPrice;
                cout<<"Taking "<<items[i].name<<" :    "<<canBeTaken<<"kg "<<price<<" Taka "<<endl;
                items[i].weight -= canBeTaken;
                items[i].value -= canBeTaken;
                totalProfit+= price;
                w -= canBeTaken;
            }

            if(w==0) break;
        }
    }
    return totalProfit;
}

void INPUT(vector<Item> &items)
{
    cout<<"Enter the item name, value and weight : ";
    for(int i=0; i<items.size(); i++)
    {
        cin>>items[i].name>>items[i].value>>items[i].weight;
        items[i].unitPrice = items[i].value/items[i].weight;
    }
}
void OUTPUT(vector<Item> items)
{
    for(int i=0; i<items.size(); i++)
    {
        cout<<items[i].name<<"   "<<items[i].value<<"  "<<items[i].weight<<endl;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of items : ";
    cin>>n;
    vector<Item> items(n);
    INPUT(items);
    int k;
    cout<<"Enter the number of thieves : ";
    cin>>k;
    vector <Thiev> thieves(k);
    cout<<"Enter the capacity of each thieves : ";
    for(int i=0; i<k; i++)
    {
        cin>>thieves[i].capacity;
    }

    int countThieves = 0;

    for(int i=0; i<k; i++)
    {
        //cout<<thieves[i].capacity<<"\n\n\n\n\n";
        if(items.size()!=0)
        {
            countThieves++;
            thieves[i].profit = fractionalKnapsack(items,thieves[i].capacity);
            cout<<"Thieve "<<i+1<<" Profit : "<<thieves[i].profit<<endl<<endl;

        }
    }
    if(items.size()==0)
    {
        cout<<"Total "<<countThieves<<" thieves stolen from the warehouse";
    }
    else
    {
        cout<<"Total "<<countThieves<<" thieves Stole from the warehouse.\nStill following items are left "<<endl;
        for(int i=0; i<items.size(); i++)
        {
            cout<<"       "<<items[i].name<<" " <<items[i].weight<<" KG "<<items[i].weight*items[i].unitPrice<<" Taka "<<endl;
        }

    }



    return 0;
}
