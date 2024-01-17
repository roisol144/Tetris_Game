#include "Controller.h"
#include "Board.h"
#include <windows.h>
using namespace std;


void Controller::playGame()
{
	this->player1.resetScore();
	this->player2.resetScore();
	this->printScoreBoard();
	this->gameStatus = true;
	this->player1.initBoard();
	this->player2.initBoard();
	this->player1.drawBoard();
	this->player2.drawBoard(22);
	this->player1.setPlayerName("Player 1");
	this->player2.setPlayerName("Player 2");
	this->player2.setGap(22);
	//char keyPressed;
	// 
	this->player1.createNextTetrimino();
	this->player2.createNextTetrimino();
	while (this->gameStatus)
	{
		/*
		if (tetro1 == nullptr || tetro1->getIsMoving() == false) {
			tetro1 = this->player1.createNextTetrimino();
		}
		if (tetro2 == nullptr || tetro2->getIsMoving() == false) {
			tetro2 = this->player2.createNextTetrimino();
		}
		*/
		//Point pointsToRotate[4];
		//Point* pointsArrTemp;
		//char rotateArr[4];
		//char rotateCounterArr[4];

		if (player1.getCurrTetro()->getIsMoving() == false) {
			delete(player1.getCurrTetro());
			player1.createNextTetrimino();
			//tetro1 = this->player1.createNextTetrimino();
		}
		if (player2.getCurrTetro()->getIsMoving() == false) {
			delete(player2.getCurrTetro());
			player2.createNextTetrimino();
			//tetro2 = this->player2.createNextTetrimino();
		}

		
		/*
		char downArr1[4] = { this->player1.getCharFromBoard(tetro1->getTetromino()[0].getX(),tetro1->getTetromino()[0].getY() + 1),
							this->player1.getCharFromBoard(tetro1->getTetromino()[1].getX(),tetro1->getTetromino()[1].getY() + 1),
							this->player1.getCharFromBoard(tetro1->getTetromino()[2].getX(),tetro1->getTetromino()[2].getY() + 1),
							this->player1.getCharFromBoard(tetro1->getTetromino()[3].getX(),tetro1->getTetromino()[3].getY() + 1) };

		

		char rightArr1[4] = { this->player1.getCharFromBoard(tetro1->getTetromino()[0].getX() + 1,tetro1->getTetromino()[0].getY()),
							this->player1.getCharFromBoard(tetro1->getTetromino()[1].getX() + 1,tetro1->getTetromino()[1].getY()),
							this->player1.getCharFromBoard(tetro1->getTetromino()[2].getX() + 1,tetro1->getTetromino()[2].getY()),
							this->player1.getCharFromBoard(tetro1->getTetromino()[3].getX() + 1,tetro1->getTetromino()[3].getY()) };

		

		char leftArr1[4] = { this->player1.getCharFromBoard(tetro1->getTetromino()[0].getX() - 1,tetro1->getTetromino()[0].getY()),
							this->player1.getCharFromBoard(tetro1->getTetromino()[1].getX() - 1,tetro1->getTetromino()[1].getY()),
							this->player1.getCharFromBoard(tetro1->getTetromino()[2].getX() - 1,tetro1->getTetromino()[2].getY()),
							this->player1.getCharFromBoard(tetro1->getTetromino()[3].getX() - 1,tetro1->getTetromino()[3].getY()) };

		
		char downArr2[4] = { this->player2.getCharFromBoard(tetro2->getTetromino()[0].getX(),tetro2->getTetromino()[0].getY() + 1),
							this->player2.getCharFromBoard(tetro2->getTetromino()[1].getX(),tetro2->getTetromino()[1].getY() + 1),
							this->player2.getCharFromBoard(tetro2->getTetromino()[2].getX(),tetro2->getTetromino()[2].getY() + 1),
							this->player2.getCharFromBoard(tetro2->getTetromino()[3].getX(),tetro2->getTetromino()[3].getY() + 1) };

		char rightArr2[4] = { this->player2.getCharFromBoard(tetro2->getTetromino()[0].getX() + 1,tetro2->getTetromino()[0].getY()),
							this->player2.getCharFromBoard(tetro2->getTetromino()[1].getX() + 1,tetro2->getTetromino()[1].getY()),
							this->player2.getCharFromBoard(tetro2->getTetromino()[2].getX() + 1,tetro2->getTetromino()[2].getY()),
							this->player2.getCharFromBoard(tetro2->getTetromino()[3].getX() + 1,tetro2->getTetromino()[3].getY()) };

		char leftArr2[4] = { this->player2.getCharFromBoard(tetro2->getTetromino()[0].getX() - 1,tetro2->getTetromino()[0].getY()),
							this->player2.getCharFromBoard(tetro2->getTetromino()[1].getX() - 1,tetro2->getTetromino()[1].getY()),
							this->player2.getCharFromBoard(tetro2->getTetromino()[2].getX() - 1,tetro2->getTetromino()[2].getY()),
							this->player2.getCharFromBoard(tetro2->getTetromino()[3].getX() - 1,tetro2->getTetromino()[3].getY()) };
							*/
		Sleep(300);
		//handleUserInput(player1.getCurrTetro(), player2.getCurrTetro(), player1, player2, leftArr1, rightArr1, downArr1, leftArr2, rightArr2, downArr2);
		handleUserInput();
			
		moveTetriminoDown(player1);
		moveTetriminoDown(player2);
				
	}
	endGame();
	delete(player1.getCurrTetro());
	delete(player2.getCurrTetro());
}


void Controller::moveTetriminoDown(Player& player)
{
	/*
	char downArr[4] = {
	player.getCharFromBoard(tetro->getTetroPoints()[0].getX(), tetro->getTetroPoints()[0].getY() + 1),
	player.getCharFromBoard(tetro->getTetroPoints()[1].getX(), tetro->getTetroPoints()[1].getY() + 1),
	player.getCharFromBoard(tetro->getTetroPoints()[2].getX(), tetro->getTetroPoints()[2].getY() + 1),
	player.getCharFromBoard(tetro->getTetroPoints()[3].getX(), tetro->getTetroPoints()[3].getY() + 1)
	};
	*/

	for (int i = 0; i < 4; i++) {
		player.getCurrTetro()->setNextMoveByIndex(player.getCharFromBoard(player.getCurrTetro()->getTetroPoints()[i].getX(), player.getCurrTetro()->getTetroPoints()[i].getY() + 1), i);
	}

	//tetro->erase(gap);

	if (player.getCurrTetro()->moveDown(player.getCurrTetro()->getNextMove()))
	{
		//tetro->erase(gap);
		player.getCurrTetro()->move(player.getGap());
		
		if (player.getCurrTetro()->isNewBorn())
			player.getCurrTetro()->setNewBorn(false);
	}
	else
	{
		if (player.getCurrTetro()->isTopReached())
		{
			player.getGap() == 22 ? this->winner = 1 : this->winner = 2; // checking who's the winner based on the gap.
			this->gameStatus = false;
			
		}
		int num;
		player.getCurrTetro()->setNewBorn(true);
		player.getCurrTetro()->draw(player.getGap());
		player.getCurrTetro()->finishMoving();
		
			
		player.addToBoard(player.getCurrTetro());
		while ((num = player.whichRowFull()) != -1) {
			player.removeFullLine(num, player.getGap());
			player.increaseScore();
			this->updateScore(player, player.getGap());
			if (player.getScore() == 2) {
				if (player.getGap() == 22)
					this->winner = 2;
				else
					this->winner = 1;

				this->gameStatus = false;
				break;
			}
			
		}

		
	}
}


//ROTETAD!!!!!!!!!!!!!

void Controller::handleUserInput()
{
	Point pointsToRotate[4];
	Point* pointsArrTemp;
	char keyPressed;
	this->player1.getCurrTetro()->erase(player1.getGap());
	this->player2.getCurrTetro()->erase(player2.getGap());
	//while (_kbhit())_getch();
	//while (_kbhit())
	while(_kbhit())
	{
		keyPressed = _getch();
		//if (player.getGap() == 22) // if it's the second player
		//{
			switch (keyPressed)
			{
			case 'l':
			case 'L':
			{
				/*
				this->player2.getCurrTetro()->setNextMove(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[0].getX() + 1, this->player2.getCurrTetro()->getTetroPoints()[0].getY()),
															this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[1].getX() + 1, this->player2.getCurrTetro()->getTetroPoints()[1].getY()),
															this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[2].getX() + 1, this->player2.getCurrTetro()->getTetroPoints()[2].getY()),
															this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[3].getX() + 1, this->player2.getCurrTetro()->getTetroPoints()[3].getY()));
															*/

				for (int i = 0; i < 4; i++) {
					this->player2.getCurrTetro()->setNextMoveByIndex(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX() + 1, 
																	this->player2.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}

				this->player2.getCurrTetro()->moveRight(this->player2.getCurrTetro()->getNextMove());
				break;
			}
			case 'k':
			case 'K':
			{
				pointsArrTemp = this->player2.getCurrTetro()->rotateClockwise();
				for (int i = 0; i < 4; i++) {
					pointsToRotate[i].setX(pointsArrTemp[i].getX());
					pointsToRotate[i].setY(pointsArrTemp[i].getY());
				}

				/*
			char rotateArr[4] = { this->player2.getCharFromBoard(pointsToRotate[0].getX(),pointsToRotate[0].getY()),
								 this->player2.getCharFromBoard(pointsToRotate[1].getX(),pointsToRotate[1].getY()),
								 this->player2.getCharFromBoard(pointsToRotate[2].getX(),pointsToRotate[2].getY()),
								 this->player2.getCharFromBoard(pointsToRotate[3].getX(),pointsToRotate[3].getY()) };
			*/
				for (int i = 0; i < 4; i++)
				{
					this->player2.getCurrTetro()->setNextMoveByIndex(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX(),
																									this->player2.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}
				this->player2.getCurrTetro()->isRotateLegal(pointsToRotate, this->player2.getCurrTetro()->getNextMove());
				break;
			}
			case 'i':
			case 'I':
			{
				pointsArrTemp = this->player2.getCurrTetro()->rotateCounterClockwise();
				for (int i = 0; i < 4; i++) {
					pointsToRotate[i].setX(pointsArrTemp[i].getX());
					pointsToRotate[i].setY(pointsArrTemp[i].getY());
				}

				/*
				char rotateCounterArr[4] = { this->player2.getCharFromBoard(pointsToRotate[0].getX(),pointsToRotate[0].getY()),
											this->player2.getCharFromBoard(pointsToRotate[1].getX(),pointsToRotate[1].getY()),
											this->player2.getCharFromBoard(pointsToRotate[2].getX(),pointsToRotate[2].getY()),
											this->player2.getCharFromBoard(pointsToRotate[3].getX(),pointsToRotate[3].getY()) };
											*/
				for (int i = 0; i < 4; i++)
				{
					this->player2.getCurrTetro()->setNextMoveByIndex(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX(),
																									this->player2.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}
				this->player2.getCurrTetro()->isRotateLegal(pointsToRotate, this->player2.getCurrTetro()->getNextMove());
				break;
			}		
			case 'j':
			case 'J':
			{
				/*
				this->player2.getCurrTetro()->setNextMove(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[0].getX() - 1, this->player2.getCurrTetro()->getTetroPoints()[0].getY()),
														this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[1].getX() - 1, this->player2.getCurrTetro()->getTetroPoints()[1].getY()),
														this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[2].getX() - 1, this->player2.getCurrTetro()->getTetroPoints()[2].getY()),
														this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[3].getX() - 1, this->player2.getCurrTetro()->getTetroPoints()[3].getY()));
														*/

				for (int i = 0; i < 4; i++) {
					this->player2.getCurrTetro()->setNextMoveByIndex(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX() - 1,
																									this->player2.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}

				this->player2.getCurrTetro()->moveLeft(this->player2.getCurrTetro()->getNextMove());
				//this->player2.getCurrTetro()->moveLeft(leftArr2);
				break;
			}
			case 'm':
			case 'M':
			{
				/*
				this->player2.getCurrTetro()->setNextMove(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[0].getX(), this->player2.getCurrTetro()->getTetroPoints()[0].getY()) + 1,
					this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[1].getX(), this->player2.getCurrTetro()->getTetroPoints()[1].getY()) + 1,
					this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[2].getX(), this->player2.getCurrTetro()->getTetroPoints()[2].getY()) + 1,
					this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[3].getX(), this->player2.getCurrTetro()->getTetroPoints()[3].getY()) + 1);
					*/

				for (int i = 0; i < 4; i++) {
					this->player2.getCurrTetro()->setNextMoveByIndex(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX(),
																									this->player2.getCurrTetro()->getTetroPoints()[i].getY() + 1), i);
				}

				while (this->player2.getCurrTetro()->moveDown(this->player2.getCurrTetro()->getNextMove())) {
					this->player2.getCurrTetro()->setNewBorn(false);
					this->player2.getCurrTetro()->draw(this->player2.getGap());
					Sleep(20);
					this->player2.getCurrTetro()->erase(this->player2.getGap());
					for (int i = 0; i < 4; i++) {
						//downArr2[i] = this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX(), this->player2.getCurrTetro()->getTetroPoints()[i].getY() + 1);
						this->player2.getCurrTetro()->setNextMoveByIndex(this->player2.getCharFromBoard(this->player2.getCurrTetro()->getTetroPoints()[i].getX(), this->player2.getCurrTetro()->getTetroPoints()[i].getY() + 1), i);
					}
				}
				break;
			}
			case 27:
				entryScreen();
				keyPressed = 0;
				break;
			default:
				break;
			}
		//}
		//else // Player 1
		//{
			switch (keyPressed)
			{
			case 'a':
			case 'A':
			{
				for (int i = 0; i < 4; i++) {
					this->player1.getCurrTetro()->setNextMoveByIndex(this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX() - 1,
						this->player1.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}

				this->player1.getCurrTetro()->moveLeft(this->player1.getCurrTetro()->getNextMove());
				//this->player1.getCurrTetro()->moveLeft(leftArr1);
				break;
			}

			case 'd':
			case 'D':
			{
				for (int i = 0; i < 4; i++) {
					this->player1.getCurrTetro()->setNextMoveByIndex(this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX() + 1,
						this->player1.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}

				this->player1.getCurrTetro()->moveRight(this->player1.getCurrTetro()->getNextMove());
				//this->player1.getCurrTetro()->moveRight(rightArr1);
				break;
			}
			case 's':
			case 'S':
			{
				pointsArrTemp = this->player1.getCurrTetro()->rotateClockwise();
				for (int i = 0; i < 4; i++) {
					pointsToRotate[i].setX(pointsArrTemp[i].getX());
					pointsToRotate[i].setY(pointsArrTemp[i].getY());
				}


				/*
				char rotateArr[4] = { this->player1.getCharFromBoard(pointsToRotate[0].getX(),pointsToRotate[0].getY()),
									 this->player1.getCharFromBoard(pointsToRotate[1].getX(),pointsToRotate[1].getY()),
									 this->player1.getCharFromBoard(pointsToRotate[2].getX(),pointsToRotate[2].getY()),
									 this->player1.getCharFromBoard(pointsToRotate[3].getX(),pointsToRotate[3].getY()) };
									 */

				for (int i = 0; i < 4; i++)
				{
					this->player1.getCurrTetro()->setNextMoveByIndex(this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX(),
						this->player1.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}
				this->player1.getCurrTetro()->isRotateLegal(pointsToRotate, this->player1.getCurrTetro()->getNextMove());
				break;
			}
			case 'w':
			case 'W':
			{
				pointsArrTemp = this->player1.getCurrTetro()->rotateCounterClockwise();
				for (int i = 0; i < 4; i++) {
					pointsToRotate[i].setX(pointsArrTemp[i].getX());
					pointsToRotate[i].setY(pointsArrTemp[i].getY());
				}
				/*
				char rotateCounterArr[4] = { this->player1.getCharFromBoard(pointsToRotate[0].getX(),pointsToRotate[0].getY()),
											this->player1.getCharFromBoard(pointsToRotate[1].getX(),pointsToRotate[1].getY()),
											this->player1.getCharFromBoard(pointsToRotate[2].getX(),pointsToRotate[2].getY()),
											this->player1.getCharFromBoard(pointsToRotate[3].getX(),pointsToRotate[3].getY()) };
											*/

				for (int i = 0; i < 4; i++)
				{
					this->player1.getCurrTetro()->setNextMoveByIndex(this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX(),
																									this->player1.getCurrTetro()->getTetroPoints()[i].getY()), i);
				}

				this->player1.getCurrTetro()->isRotateLegal(pointsToRotate, this->player1.getCurrTetro()->getNextMove());
				break;
			}
			case 'x':
			case 'X':
			{
				for (int i = 0; i < 4; i++) {
					this->player1.getCurrTetro()->setNextMoveByIndex(this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX(),
						this->player1.getCurrTetro()->getTetroPoints()[i].getY() + 1), i);
				}
				
				while (this->player1.getCurrTetro()->moveDown(this->player1.getCurrTetro()->getNextMove())) {
					this->player1.getCurrTetro()->setNewBorn(false);
					this->player1.getCurrTetro()->draw(this->player1.getGap());
					Sleep(20);
					this->player1.getCurrTetro()->erase(this->player1.getGap());
					for (int i = 0; i < 4; i++) {
						this->player1.getCurrTetro()->setNextMoveByIndex(this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX(),
																										this->player1.getCurrTetro()->getTetroPoints()[i].getY() + 1), i);
						//downArr1[i] = this->player1.getCharFromBoard(this->player1.getCurrTetro()->getTetroPoints()[i].getX(), this->player1.getCurrTetro()->getTetroPoints()[i].getY() + 1);
					}			
				}
				break;
			}
			case 27:
				entryScreen();
				break;
			default:
				break;
			}
		//}
		
	}

}



void Controller::entryScreen()
{
	// Clear the console screen
	system("cls");
	if (this->gameStatus)
	{
		// Display the Tetris headline
		cout << "*********************" << endl;
		cout << "*    Tetris C++    *" << endl;
		cout << "*********************" << endl << endl;

		// Display the menu options
		cout << "(1) Start a new game" << endl;
		cout << "(2) Continue a paused game" << endl;
		cout << "(8) Present instructions and keys" << endl;
		cout << "(9) EXIT" << endl << endl;

		//Message for the user to pick a choice
		cout << "Please enter your choice: ";
	}

	else 
	{
		// Display the Tetris headline
		cout << "*********************" << endl;
		cout << "*    Tetris C++    *" << endl;
		cout << "*********************" << endl << endl;

		// Display the menu options
		cout << "(1) Start a new game" << endl;
		cout << "(8) Present instructions and keys" << endl;
		cout << "(9) EXIT" << endl << endl;

		//Message for the user to pick a choice
		cout << "Please enter your choice: ";
	}


	char choice;
	cin >> choice;

	// Process user choice
	switch (choice) 
	{
		case '1':
			cout << "Starting a new game..." << endl;
			system("cls");
			playGame();
			break;
		case '2':
			system("cls");
			this->player1.drawBoardInGame();
			this->player2.drawBoardInGame(22);
			this->printScoreBoard();
			break;
		case '8':
			showInstructions();
			break;

		case '9':
			// Exit the program
			this->gameStatus = false;
			cout << endl;
			cout << "Exiting the Tetris game. Goodbye!" << endl;
			break;

		default:
			// Invalid choice
			cout << "Invalid choice. Please try again." << endl;
			cin.ignore();
			cin.get();
			break;
	}
} 



void Controller::showInstructions()
{
	system("cls");  // Clear console screen
	cout << "*********************" << endl;
	cout << "*    Instructions   *" << endl;
	cout << "*********************" << endl << endl;
	cout << "Player 1 - Use 'A' to move the Tetromino left and 'D' for right." << endl;
	cout << "Player 1 - Use 'X' to drop the Tetromino" << endl;
	cout << "Player 1 - Use 'S' to rotate the Tetromino clockwise and 'W' for counter clockwise." << endl << endl;

	cout << "Player 2 - Use 'J' to move the Tetromino left and 'L' for right." << endl;
	cout << "Player 2 - Use 'M' to drop the Tetromino" << endl;
	cout << "Player 2 - Use 'K' to rotate the Tetromino clockwise and 'I' for counter clockwise." << endl << endl;
	cout << "Press 'ESC' to pause the game." << endl;
	cout << "Press 'Enter' key to go back to the menu...";
	cin.ignore();
	cin.ignore();
	if (_kbhit)
		entryScreen();
}

void Controller::printScoreBoard() {
	for (int row = 20; row <= 23; row++) {
		gotoxy(0, row);
		cout << '*';
		gotoxy(13, row);
		cout << '*';
	}

	for (int col = 1; col <= 12; col++) {
		gotoxy(col, 20);
		cout << '*';
		gotoxy(col, 23);
		cout << '*';
	}
	gotoxy(3, 21);
	cout << "Player #1";
	gotoxy(3, 22);
	cout << "Score: " << this->player1.getScore();

	for (int row = 20; row <= 23; row++) {
		gotoxy(22, row);
		cout << '*';
		gotoxy(35, row);
		cout << '*';
	}

	for (int col = 23; col <= 35; col++) {
		gotoxy(col, 20);
		cout << '*';
		gotoxy(col, 23);
		cout << '*';
	}
	gotoxy(25, 21);
	cout << "Player #2";
	gotoxy(25, 22);
	cout << "Score: " << this->player2.getScore();
}

void Controller::updateScore(Player& p,int gap) {
	gotoxy(3 + gap, 22);
	cout << "Score: " << p.getScore();
}

void Controller::endGame()
{
	system("cls");
	cout << "\033[1;32m********************************\033[0m" << endl;  // Bold green text
	cout << "\033[1;32m*      The Winner is: " << this->winner << "        *\033[0m" << endl;  // Bold green text
	cout << "\033[1;32m********************************\033[0m" << endl << endl;  // Bold green text
	cout << "Player 1 Score: " << this->player1.getScore() << endl;
	cout << "Player 2 Score: " << this->player2.getScore() << endl;

}