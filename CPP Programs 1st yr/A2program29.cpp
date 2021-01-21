#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct Card{
    int num=0;
    char suit;
};
int main(){
    int A[52];
    for(int i=0;i<52;i++)
        A[i]=i+1;
    srand(time(0));
    for(int i=0;i<52;i++){
        int r = i + rand()%52-i;
        int temp=A[i];
        A[i]=A[r];
        A[r]=temp;
    }
    for(int k=0;k<52;k++){
        cout<<A[k]<<" ";
    }
    int nwin=0;
    cout<<"\nEnter the card number(1-Ace,11-Jack,12-Queen,13-King)"
    <<" and Suit(C-Clubs,S-Spades,H-hearts,D-diamonds)\n";
    for(int n=0;n<52;n++){
        Card Pred;
        cout<<"\nEnter your "<<n+1<<" prediction: ";
        cin>>Pred.num>>Pred.suit;
        //cout<<Pred.num<<" "<<Pred.suit;
        if(Pred.suit=='S')
            Pred.num+=13;
        else if(Pred.suit=='H')
            Pred.num+=26;
        else if(Pred.suit=='D')
            Pred.num+=39;
        //cout<<Pred.num<<endl;
        if(Pred.num==A[n]){
            cout<<"\nYour prediction was correct. Bravo!";
            nwin++;
        }else{
            cout<<"\nYour prediction was incorrect...Try Again.";
        }
    }
    cout<<"\nYou won "<<nwin<<" times and the computer won "<<52-nwin<<" times.";
}
