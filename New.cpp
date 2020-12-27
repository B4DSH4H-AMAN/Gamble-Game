#include <bits/stdc++.h>
using namespace std;


void Shuffle(pair<string, string> CreatDeck[]){
        // Using Random Shuffle function to randomly change the postion of data inside array
        random_shuffle(CreatDeck, CreatDeck+52);
}

int UserInput(){
        // Taking User Data
        cout << "ENTER YOUR CARD NUMBER FROM 1-52: ";
        int Input;
        // Storing in Input
        cin >> Input;
        // Decrementing it by 1 becuase Array start with 0
        return Input-1;
}
pair<string, string> Response(int Input,pair<string, string> CreateDeck[]){
        // Creating 2D Array and Inserting value inside Card and Suits.
        cout << "HE DRAWS: " << CreateDeck[Input].second << " OF " << CreateDeck[Input].first << "\n";
        // Returning the Inserted Data Array by this function
        return CreateDeck[Input];
}

int main(){
        // Using Srand to insure random function don't repeat the same random values each time
        srand(time(0));
        // Initializing 2D Array
        pair<string, string> Deck[52];
        // Inserting Suits and Cards to make a Deck
        string Suit[] = {"Spade","Heart","Diamond","Club"};
        string Card[] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

        // For loop to initialize value in all the 4 Suits with 13 cards
        for(int i = 0; i < 4; i++){
                for(int j = 0; j < 13; j++){
                        Deck[13*i + j] = {Suit[i], Card[j]};
                }
        }
        // For storing the PlayerScores for Comparing it for declaring winner
        int PlayerScore1 = 0, PlayerScore2 = 0;
        // For loop which run up to 3 time to so that we can play 3 rounds
        for(int i = 1; i <= 3; i++){
                cout << "\n**********************************************\n";
                cout << "\nROUND: " << i << endl;
                // Calling Shuffle Function to shuffle the Deck
                Shuffle(Deck);
                cout << "PLAYER ONE'S PLAYING: " <<  endl;
                // Setting return value from Userinput Function inside Input1
                int Input1 = UserInput();
                // Setting the return value from Response Function inside Response1
                pair<string, string> Response1 = Response(Input1,Deck);

                cout << "PLAYER SECOND PLAYING: " << endl;
                int Input2 = UserInput();
                pair<string, string> Response2 = Response(Input2,Deck);
                // Declaring Playercard and Playersuit and Decrementing it by 1
                int PlayerCard1 = -1, PlayerCard2 = -1;
                int PlayerSuit1 = -1, PlayerSuit2 = -1;
                // Fetching Data from respose1.first and taking suit value and setting inside Playersuit1
                for(int j=0; j<4; j++){
                        if(Response1.first == Suit[j]){
                                PlayerSuit1 = j;
                        }
                        if(Response2.first == Suit[j]){
                                PlayerSuit2 = j;
                        }
                }
                // Fetching Data from Response.second to get the card Data and setting the value of Card insdie Playercard
                for(int j=0; j<12; j++){
                        if(Response1.second == Card[j]){
                                PlayerCard1 = j;
                        }
                        if(Response2.second == Card[j]){
                                PlayerCard2 = j;
                        }
                }
                // If both Card value are same we need to check the suit for declaring the winner
                if(PlayerCard1 == PlayerCard2){
                        if(PlayerSuit1 < PlayerSuit2){
                                cout << "PLAYER ONE WINS THE ROUND " << i <<endl;
                        }else{
                                cout << "PLAYER SECOND WINS THE ROUND " << i <<endl;
                        }
                // Comparing Player card to declare winner according to card rank
                }else if(PlayerCard1 > PlayerCard2){
                        cout << "PLAYER ONE WINS THE ROUND " << i <<endl;
                        PlayerScore1++;
                }else {
                        cout << "PLAYER SECOND WINS THE ROUND " << i << endl;
                        PlayerScore2++;
                }
                // Displaying the Score of Both Players
                cout << "SCORE OF PLAYER ONE: "<< PlayerScore1 << endl;
                cout << "SCORE OF PLAYER TWO: "<< PlayerScore2 << endl;
                cout << "\n**********************************************\n";
        }
        // Comparing Player round score and One who has more round win, Wins the Game
        if(PlayerScore1 > PlayerScore2){
                cout <<"\nPLAYER ONE WINS THE GAME" << endl;
        }else
        {
                cout <<"\nPLAYER SECOND WINS THE GAME" << endl;
        }
}

