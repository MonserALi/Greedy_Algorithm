#include <bits/stdc++.h>
using namespace std;

class Question{
public:
    int marks, time, questionNumber,done;
    double ratio;

};

bool compare(Question v1, Question v2){
    return (v1.ratio>v2.ratio);
}

int MaximizeMark(vector<Question> &questions, int m, int t, vector<Question>&answered){

    sort(questions.begin(),questions.end(),compare);

    int res = 0;
    for(int i=0;i<questions.size();i++){
        double frac = (double)t/questions[i].time;
        if(frac>=1){
            questions[i].done = 100;
            answered.push_back(questions[i]);
            res+=questions[i].marks;
            t -= questions[i].time;
            questions.erase(questions.begin()+i);
            i--;

        }
        else{
            double minutes = questions[i].time * frac;
            questions[i].time -= minutes;
            int ans = minutes * questions[i].ratio;
            questions[i].done = ans * 100 / questions[i].marks;
            questions[i].marks -= ans;
            res+=ans;
            t -= minutes;

            answered.push_back(questions[i]);
            answered[answered.size()-1].marks = ans;

        }

        if(t==0){
            break;
        }
    }

    return res;

}

int main(){
    int m,t,n;
    cin>>m>>t>>n;
    vector<Question> questions(n);
    for(int i=0;i<n;i++){
        cin>>questions[i].marks>>questions[i].time;
        questions[i].questionNumber = i+1;
        questions[i].ratio =(double)questions[i].marks/questions[i].time;
    }

    vector<Question> answered;
    int totalMarkAlone = MaximizeMark(questions,m,t,answered);

    cout<<"Maximum "<<totalMarkAlone<<" marks answering alone"<<endl;

    for(Question q:answered){
        cout<<"ques "<<q.questionNumber<<"  "<<q.done<<"% done -- "<<q.marks<<" marks"<<endl;
    }

    int totalMarkWithFriend = 0;
     totalMarkWithFriend = totalMarkAlone + MaximizeMark(questions,m,t,answered);
    cout<<"Maximum " <<totalMarkWithFriend<<" marks answering with a friend"<<endl;


return 0;

}

