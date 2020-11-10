// Nicholas DeRoss 
// CS130 
// Fall 2017
//
// Wanna play some craps? 
// Program 5 
// 
// This program simulates a game of craps based on random number 
//  generation, and is able to keep track of bets 
// 


#include <iomanip>
#include <iostream>
#include <string>  
#include <cmath>
#include <fstream>
#include <stdlib.h>    
#include <time.h>
#include <ctime>
#include <cstdlib> 


using namespace std;


int GetBalance (int balance);

// Purpose: Takes in the balance from the user, validates it 
// 
// Preconditions: NA
// 
// Postconditions: Desired balance to start game with 
// 




int RollDie (int totalRoll); 

// Purpose: Does the equivilant of one roll of the dice 
// 
// Preconditions: NA
// 
// Postconditions: Sum of two numbers 1-6, first roll 
// 



int GetWager (int wager, int balance); 


// Purpose: Gets the desired ammount of money on the line for a single game, validates it  
// 
// Preconditions: NA
// 
// Postconditions: Ammount to be wagered on roll 
// 


bool RunGame (int totalRoll, bool didWin); 

// Purpose: Will take in the dice roll and determine if the user has won or not  
// 
// Preconditions: int totalRoll
// 
// Postconditions: bool didWin returned 
// 



void RandomMessage (); 

// Purpose: Will print out a random message based on a number randomly generated 
// 
// Preconditions: None 
// 
// Postconditions: A randomly generated message printed to screen 
// 



bool RollPoint (int totalRoll, int totalTwo, bool didWin); 


// Purpose: This function will be called to from within RunGame if 
//          the user rolls a "point" value.
// 
// Preconditions: int totalRoll
// 
// Postconditions: bool didWin 
// 



int BalanceChange (bool didWin, int wager, int balance); 


// Purpose:  This function will change the users balance based on if they 
//             won the game or not. 
// 
// Preconditions: bool didWin, int wager
// 
// Postconditions: variable "balance" increased or decreased 
// 




int main (void) {

int wager; // Ammount to be wagered 
bool didWin; // If the user has won or lost 
int totalRoll; // First roll 
int balance; // Balance of bank 
char answer; // User entered to continue or exit 

cout << endl; 
 

 balance = GetBalance (balance); // Balance is stored 
 
 answer = 'Y'; // Loop is primed 
 
                                    do { wager = GetWager (wager, balance);  // Wager is stored 
									
										RandomMessage (); // Random messgae is displayed 
					   
										totalRoll = RollDie (totalRoll); // First dice roll 
					   
										didWin = RunGame (totalRoll, didWin); // Game is run 
										
											if (didWin == true) { cout << "Congrats!" << endl; } // Message if game is won 
	
                                         	else 
	
                                         	if (didWin == false) { cout << "Sorry about that!" << endl;} // Message if game is lost 
										
					   
										balance = BalanceChange (didWin, wager, balance); // Balance change 
										
										cout << endl; 
										
										cout << "Your current balance is: " << balance << endl; // Current balance displayed 
										
										cout << endl; 
										
											if (balance <= 0) { cout << "Thats a bust!" << endl;  // Ends the game if the user busts 
										                   return 0; } 
					   
										cout << "Would you like to play again? Y or N?" << endl; // Checks if user wants to play again 
										
										cin >> answer; 
										
										
										if (answer == 'N') {return 0;} // Exits game is user wants to 
										
										
										
                              }  while ((balance > 0) or (answer != 'N')); // Loop conditions to keep the game running until 
							                                               //  the user wants to exit, or they "bust" and 
																		   //   their balance is 0 
										
	return 0; 
	
}
                     



int GetBalance (int balance) // Stores the balance, only called to once 

{ cout << "Please enter the balance you would like to play with: "; 

  
  cin >> balance; // Balance is taken in and stored 
  
  if (balance <= 0) { while (balance <= 0) {

                       cout << endl; 
					   cout << "Your balance cannot be negative or zero. " << endl; // Validates the balance 
                       cout << endl; 
					   cout << "Please enter your balance: "; 
                       cin >> balance ; } 
                     }
					   
  else 
	  
  cout << endl; 
	  
  return balance; 
  
} 


int GetWager (int wager, int balance) 

{ cout << "Please enter the wager for this game: "; 

cin >> wager; //Wager is taken in and stored 

if (wager > balance) { while (wager > balance) {

                       cout << endl; 
					   cout << "Your wager can not be more than your balance." << endl; 
                       cout << endl; 
					   cout << "Please enter your wager: "; 
                       cin >> wager; } 
                     }
					   
else 		

  cout << endl; 
  
  return wager; } 
  
  
  
  
  void RandomMessage () 
  
 { int randomNumber; 
  
     
	 
     randomNumber = (rand() % 6 + 1); // Random number generated 
  
	 
	 switch (randomNumber) { 
	 
	 // These statements are based on which number is generated, and will print randomly //
	 //   based on that.  //
	 
	 case (1):  cout << "Wow, big spender over here! Bada Bing Bada Boom!" << endl; 
	            break; 
	 
	 case (2): cout << "If I catch you cheating, you'll be sleeping with the fishes." << endl; 
	           break; 
			   
	case (3): cout << "Lets hope you don't regret that bet." << endl; 
	          break; 
			  
			  
	case (4) : cout << "Cmon baby daddy needs a new pair of shoes!" << endl; 
	           break; 
			   
	case (5) : cout << "May the odds be ever in your favor." << endl; 
	           break; 
			   
	case (6): cout << "Go ahead, bet it all, i'm sure it'll work out fine!" << endl; 
	           break; 
			   
	                     }
						 
 return; } 
 
 
 int RollDie (int totalRoll) // This function simulates the first roll of the dice in the game 
 
 { 
   int rollOne; 
   int rollTwo;    
   
   srand(time(0));
	 
    rollOne = (rand() % 6 + 1); 
	
	rollTwo = (rand() % 6 + 1); 
	
	totalRoll = rollOne + rollTwo; 
	
	cout << rollOne << " + " << rollTwo << " -> " << totalRoll << endl; 
	
	
    return totalRoll; } 
	
	
	bool RunGame (int totalRoll, bool didWin) // This function will take in the first roll and determine if 
	                                          //  the user has already won or lost. If the user has rolled a 
											  //  point value, the function RollPoint will be called.
											   
	
	{ 
	    
	    int totalTwo; 
	    
	    switch (totalRoll) 
	
   	{  case (2): cout << "You lose!" << endl; 
	             didWin = false; 
	             return didWin; 
				 break; 
	
	   case (3) : cout << "You lose!" << endl; 
	             didWin = false; 
	             return didWin; 
				 break; 
	   
	   case (4): cout << "Your point is -> " << totalRoll;
	             didWin = RollPoint (totalRoll,totalTwo, didWin);  
                 break; 	
	             
				 
	  case (5): cout << "Your point is -> " << totalRoll; 
	            didWin = RollPoint (totalRoll,totalTwo, didWin);  
                break; 	
				                                                                   // This block prints a message to the screen based on the first roll.
	  case (6): cout << "Your point is -> " << totalRoll;                          // 
	                                                                               // If the user rolls a point value the point is displayed 
																				   //
         																		   // If it is a win or loss, that is displayed instead. 
	            didWin = RollPoint (totalRoll,totalTwo, didWin);  
                break; 	
	  
	  case (7): cout << "You win!" << endl; 
	            didWin = true; 
				break; 
	  
	  case (8): cout << "Your point is -> " << totalRoll;
                didWin = RollPoint (totalRoll,totalTwo, didWin);  
                break; 				
	  
	  case (9): cout << "Your point is -> " << totalRoll;
                didWin = RollPoint (totalRoll,totalTwo, didWin);  
                break; 	
	  
	  
	  case (10): cout << "Your point is -> " << totalRoll; 
	             didWin = RollPoint (totalRoll,totalTwo, didWin);  
                 break; 
	  
	  case (11): cout << "You win!" << endl; 
	            didWin = true; 
				break; 
	  
	  case (12): cout << "You lose!" << endl; 
	             didWin = false;  
				 break; 
	} 
	
	return didWin; } 
	
	
	bool RollPoint (int totalRoll, int totalTwo, bool didWin) // This function rolls the point value until the user either 
	                                                          //  matches their point, or rolls a 7. This function is only called to 
															  //  in the event of roll one being a point value. The value didWin is returned 
															  //  to main whether this function has been utilized or not. 
															  //
															  // I'm gonna be honest here this part is very spaghetti code-y but I had to go through like 
															  //  five different solutions to get it to work properly and there is some holdout code im afraid to
															  //   get rid of. 
	
	
	{ 
      int pointRollOne; 
      int pointRollTwo;
      int pointRollTotal;
	  int point;
	  int dieOne;
	  int dieTwo; 
	  int roll; 
   
    
	 
    pointRollOne = (rand() % 6 + 1); 
	
	pointRollTwo = (rand() % 6 + 1); 
	
	pointRollTotal = pointRollOne + pointRollTwo; 
	
	cout << endl;
	
	cout << pointRollOne << " + " << pointRollTwo << " -> " << pointRollTotal << endl; 
	
	if (totalRoll == pointRollTotal) { cout << totalRoll << " = " << pointRollTotal << endl; 
	                            cout << endl; 
								cout << "Congratulations, you win!" << endl; 
	                            didWin = true;} 
								
	else 
		
	
	if (pointRollTotal == 7)

		{ cout << "You rolled a seven on a point, that's a loss!" << endl; 
		  cout << endl;
		  didWin = false;} 
	
	else 
	
	if (totalRoll != pointRollTotal)
	
	{
	
	
	
	point = totalRoll; 
	
	 do                      // I know having a do while loop here is kinda clunky but I made sure that 
	                         //  its only used when absolutley neccasary. 
            {

                dieOne= (rand()%6)+1; 
				
				// Rolls dice again 
                
                dieTwo= (rand()%6)+1;
                
                roll = dieOne+dieTwo;

                cout << dieOne << " + "<< dieTwo <<" -> "<< roll << endl;  // This part is only ever used in the event of a point roll 

                if(roll==point) {didWin = true;}
                    
                else 
                
                if(roll==7) { cout << "You rolled a seven on a point, that's a loss!" << endl; 
				              cout << endl; 
				              didWin = false; }
                
                    
                else if(roll!=7 and roll!=point)
                
			    didWin = false; } while (roll!=point and roll!=7);

	
	}
	

	
	return didWin;} 
	
	
	
	
	int BalanceChange (bool didWin, int wager, int balance) { 
	    
	    int winInt; // This honestly could have been a bool value but I had to replace it 
		           //    cause things keep breaking. 
	    
	    if (didWin == true) { winInt = 1;}                            // This function changes the users balance value 
		                                                               // and returns said value to main. 
	    
	    if (didWin == false) {winInt = 2;} 
	
	{ switch (winInt) { case (1) : (balance = balance + wager); 
	                                   break; 
									
						case (2) : (balance = balance - wager); 
                     	             break; }
						
	return balance;} }
	
	
	
	

	