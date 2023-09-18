#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


using namespace std;

string translateToString(int number)
{
    string cardSort;
    switch(number){
        case 1:
            cardSort = "Hjerter";
            break;
        case 2:
            cardSort = "Kløver";
            break;
        case 3: 
            cardSort = "Ruter";
            break;
        case 4:
            cardSort = "Spar";
            break;
    };
    return cardSort;
};

void printArray(vector<vector<int>> myVector)
{
    for(int x = 0;x<myVector.size();x++){
        for(int i = 0;i<myVector[x].size();i++){
            if(i == 1 || i == 2){
                cout << translateToString(myVector[x][i]) << "  ";
            } else{
                cout << myVector[x][i] << "  ";
            }
        }
        cout << endl;
    }
};
int totalDeck(vector<vector<int>> myVector, int total)
{
    for(int x = 0;x<myVector.size();x++){
        total += myVector[x][0];
    }
    return total;
};


//hjerter, kløver, ruter og spar


int main(){

    srand((unsigned) time(NULL));
    srand(time(0)); 
    vector<vector<int>> deck
    {
        {1+rand()%13, 1+rand()%4},
        {1+rand()%13, 1+rand()%4}
    };
    vector<vector<int>> enemy_deck
    {
        {1+rand()%13, 1+rand()%4},
        {1+rand()%13, 1+rand()%4}
    };
    bool gameloop = true;

    int total = 0;
    int enemy_total = 0;
    int input;
    
    
    while(gameloop)
    {
        cout << "This is your cards:" << endl;
        printArray(deck);
        cout << "This is the first card from enemy deck: " << endl;
        for(int x = 0;x<2;x++){
            if(x == 1){
                cout << translateToString(enemy_deck[0][x]);
            } else{
                cout << enemy_deck[0][x] << "  ";
            }
        } 
        cout << endl <<"Do you want to add a card? 1 for yes, 0 for no" << endl;
        cin >> input;
        if(input == 1){
            deck.push_back({1+rand()%13, 1+rand()%4});
        } else{
            enemy_total += totalDeck(enemy_deck, enemy_total);  
            total += totalDeck(deck, total);
            cout << enemy_total << endl;
            
            cout << "This is your total score: " << total << endl;
            if(enemy_total > total){
                cout << "You lost against the house" << endl;
            } else{
                cout << "You won agains the house" << endl;
            }
            return 0;
        };
        
       
    }
    



    return 0;
}
