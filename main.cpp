 #include<iostream>     // include two libraries
 #include<cstdlib>
 using namespace std;
 int main()             // main() starts the actual program 
 {
    bool token = 1;
    cout << "The goal of the game is to remove the last object." << endl;
    // ----------- Beginning of the main game loop ----------------
    do
    {
    int num_objects = 23; 
    int current_player = 1; 
    int move;
    bool said1, said2, said3 = false;

    do {                                      
       if (current_player == 1) {    // conditional: if
            cout << "Player 1 enter your move (1-3): ";  // output
            cin >> move;                 // input
            while (move < 1 || move > 3 || move > num_objects){
               cout << "Illegal move. \nEnter a new move (1-3): ";
               cin >> move;
            }
       }
       //if not player 1, and if 2,3, or 4, then magic, left the rand code untouched. perfectly effiecient
        else if(num_objects ==2)
        {
            move = 2;
            cout << "Computer removed " << move << endl;
        } 
        else if(num_objects == 3)
        {
            move = 3;
            cout << "Computer removed " << move << endl;
        }
        else if(num_objects == 4)
        {
            move = 1;
            cout << "Computer removed " << move << endl;
        }
       else {                          // else part of conditional
            do {                         // make sure move is legal
               move =  1+ rand() % 3;    // random computer move
            } while (move < 1 || move > 3 || move > num_objects);
            cout << "Computer removed " << move << endl;
       }
       if(16 < num_objects < 20 && said1 == false)
       {
           cout << "Just getting started!" << endl;
           said1 = true;
       }
       else if(5 < num_objects < 10 && said2 == false)
       {
           cout << "Who's going to win? Nobody knows!" << endl;
           said2 = true;
       }
       else if(1 <= num_objects <= 4 && said3 == false)
       {
           cout << "We're down to the wire!" << endl;
           said3 = true;
       }
       num_objects = num_objects - move;  // implement the move
       cout << num_objects << " objects remaining.\n";
       cout << "Objects: \n";
       for(int i = 0  ; i <= num_objects-1; i++)
       {
           cout << "#";
       }
       cout << endl;
       current_player = (current_player + 1) % 2;  // switch players
   } while (num_objects > 0 && token == 1);                    
   // ------------  end of the game loop --------------------------
   //You have to switch players again or else it says the loser is the winner
   current_player = (current_player + 1) % 2;
   cout << "Player " << current_player << " wins!!!\n";
   cout << "Player " << (current_player + 1) % 2 << " loses :(";
   //Really rudimentary, and I could make it better, but it's fast
   cout << "Play again? (1 for Y/0 for N)" << endl;
   cin >> token;
    }while(token == 1 );
   cin.ignore();
   cout << "\nPress enter to quit.\n";
   cin.ignore();
   return 0;
}