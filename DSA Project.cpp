#include <iostream>
#include <stack>
#include <queue>
//#include <vector>
#include <string>
#include <cstdlib>  // for random computer move
#include <ctime>    // for random seed

using namespace std;

// Player class to store player information (name and password)
class Player {
public:
    string name;
    string password;

    Player(string playerName, string playerPassword) {
    	name=playerName;
    	password=playerPassword;
	} 
};

// Chessboard class (One-Dimensional Array)
class ChessBoard {
public:
    char board[64]; // 8x8 chessboard in 1D array
    ChessBoard() {
        for (int i = 0; i < 64; ++i) {
            board[i] = ' '; // Initialize empty spaces
        }
        board[0] = 'R'; board[1] = 'N'; board[2] = 'B'; board[3] = 'Q'; board[4] = 'K'; board[5] = 'B'; board[6] = 'N'; board[7] = 'R';
        board[8] = 'P'; board[9] = 'P'; board[10] = 'P'; board[11] = 'P'; board[12] = 'P'; board[13] = 'P'; board[14] = 'P'; board[15] = 'P';
        board[48] = 'p'; board[49] = 'p'; board[50] = 'p'; board[51] = 'p'; board[52] = 'p'; board[53] = 'p'; board[54] = 'p'; board[55] = 'p';
        board[56] = 'r'; board[57] = 'n'; board[58] = 'b'; board[59] = 'q'; board[60] = 'k'; board[61] = 'b'; board[62] = 'n'; board[63] = 'r';
    }

    void displayBoard(bool isComputerOpponent, string player1, string player2) {
        cout << "   A   B   C   D   E   F   G   H" << endl;
        for (int i = 0; i < 8; ++i) {
            cout << 8 - i << " "; // Row labels (reverse order for user side at the bottom)
            for (int j = 0; j < 8; ++j) {
                cout << "[" << board[i * 8 + j] << "] "; // Print board piece with brackets for better clarity
            }
            cout << 8 - i << endl; // Row labels
        }
        cout << "   a   b   c   d   e   f   g   h" << endl;
        cout << player2 << "'s side is at the top." << endl;
        cout << player1 << "'s side is at the bottom." << endl;
    }

    void movePiece(int from, int to) {
        // Basic move logic (to be expanded)
        board[to] = board[from];
        board[from] = ' ';
    }
     int getPositionFromInput(string move) {
        
        int fromCol = tolower(move[0]) - 'a'; // Convert to lowercase for uniformity
        int fromRow = 8 - (move[1] - '0');
        int toCol = tolower(move[2]) - 'a'; // Convert to lowercase for uniformity
        int toRow = 8 - (move[3] - '0');

        return fromRow * 8 + fromCol;
    }
    void computerMove() {
        // Simple random move logic for the computer (to be expanded)
        srand(time(0));
        int from, to;
        do {
            from = rand() % 64;
            to = rand() % 64;
        } while (board[from] == ' ' || islower(board[from]) || (board[to] != ' ' && islower(board[to]))); // Ensure valid move

        movePiece(from, to);
        cout << "Computer move: " << char('A' + (to % 8)) << (8 - (to / 8)) << endl; // Display computer move
    }

};

// Node for single linked list (Move history)
struct MoveNode {
    int from, to;
    MoveNode* next;
    MoveNode(int f, int t) {
    	from=f;
    	to=t;
    	next=NULL;
	} 
};

// Single Linked List for storing moves
class MoveHistory {
public:
    MoveNode* head;
    MoveHistory() {
    	head=NULL;
	}

    void addMove(int from, int to) {
        MoveNode* newMove = new MoveNode(from, to);
        newMove->next = head;
        head = newMove;
    }

    void displayMoves() {
        MoveNode* current = head;
        while (current!=NULL) {
            cout << "Move from " << current->from << " to " << current->to << endl;
            current= current->next;
        }
    }
};

// Node for circular linked list (Turn-based player switching)
struct PlayerNode {
    string playerName;
    PlayerNode* next;
    PlayerNode(string name){
    	playerName=name;
    	next=NULL;
	} 
};

// Circular Linked List for player turns
class PlayerTurnQueue {
public:
    PlayerNode* head;
    PlayerNode* tail;

    PlayerTurnQueue(){
    	head=NULL;
    	tail=NULL;
	} 

    void addPlayer(string playerName) {
        PlayerNode* newPlayer = new PlayerNode(playerName);
        if (!head) {
            head = tail = newPlayer;
            newPlayer->next = head;  // Circular link
        } else {
            tail->next = newPlayer;
            tail = newPlayer;
            tail->next = head;  // Circular link
        }
    }

    void nextTurn() {
        if (head!=NULL) {
            cout << "It's " << head->playerName << "'s turn." << endl;
            head = head->next;
        }
    }
};

// Node for double linked list (Piece history for undo/redo)
struct PieceNode {
    char piece;
    int position;
    PieceNode* prev;
    PieceNode* next;
    PieceNode(char p, int pos) {
    	piece=p;
    	position=pos;
    	prev=NULL;
    	next=NULL;
	}
};

// Double Linked List for piece history
class PieceHistory {
public:
    PieceNode* head;
    PieceNode* tail;

    PieceHistory(){
    	head=NULL;
    	tail=NULL;
	} 

    void addPiece(char piece, int position) {
        PieceNode* newPiece = new PieceNode(piece, position);
        if (head!=NULL) {
            head = tail = newPiece;
        } else {
            tail->next = newPiece;
            newPiece->prev = tail;
            tail = newPiece;
        }
    }

    void undoMove() {
        if (tail!=NULL) {
            cout << "Undo move: " << tail->piece << " from position " << tail->position << endl;
            PieceNode* temp = tail;
            tail = tail->prev;
            if (tail!=NULL)
			{
			  tail->next = nullptr;
		}
            delete temp;
        }
    }

    void redoMove() {
        if (head!=NULL) {
            cout << "Redo move: " << head->piece << " to position " << head->position << endl;
            PieceNode* temp = head;
            head = head->next;
            if (head!=NULL) 
			{
			head->prev = nullptr;
		}
            delete temp;
        }
    }
};


// Queue for managing pending moves
class MoveQueue {
public:
    queue<string> moveQueue;

    void addMove(string move) {
        moveQueue.push(move);
    }

    void executeMove() {
        if (!moveQueue.empty()) {
            cout << "Executing move: " << moveQueue.front() << endl;
            moveQueue.pop();
        }
    }
};

// Global list of registered players
vector<Player> registeredPlayers;
Player* loggedInPlayer = NULL;

void displayMainMenu() {
	cout<<"   ******************************"<<endl;
	cout<<"   **                          **"<<endl;
	cout<<"   **   Welcome to CHESS GAME  ** "<<endl;
	cout<<"   **                          ** "<<endl;
	cout<<"   ******************************"<<endl;
	cout<<" \n------------------------------------ "<<endl;
    cout << "\n1. Register player by name and password" << endl;
    cout << "2. Login Player 1" << endl;
    cout << "3. Play game" << endl;
    cout << "4. Show registered players" << endl;
    cout << "5. Exit game" << endl;
    cout << "Enter your choice: ";
}

// Function to register a player
void registerPlayer() {
    string name, password;
    cout << "Enter player name: ";
    cin >> name;
    cout << "Enter player password: ";
    cin >> password;

    Player newPlayer(name, password);
    registeredPlayers.push_back(newPlayer);
    cout << "Player " << name << " registered successfully!" << endl;
}

// Function to login a player
void loginPlayer() {
    string name, password;
    cout << "Enter player name: ";
    cin >> name;
    cout << "Enter player password: ";
    cin >> password;

    bool found = false;
    for (auto& player : registeredPlayers) {
        if (player.name == name && player.password == password) {
            loggedInPlayer = &player;
            found = true;
            cout << "Login successful!" << endl;
            break;
        }
    }

    if (found==NULL) {
        cout << "Invalid credentials!" << endl;
    }
}


bool isLastRowEmpty( ChessBoard& board, bool isPlayer1) {
    int start = isPlayer1 ? 56 : 0;
    for (int i = start; i < start + 8; ++i) {
        if (board.board[i] != ' ') {
            return false;
        }
    }
    return true;
}

// Function to play the game
void playGame() {
	string playerMove;
	
    ChessBoard board;
    MoveHistory moveHistory;
    PlayerTurnQueue turnQueue;
    PieceHistory pieceHistory;
    MoveQueue moveQueue;

    string playerName1, playerName2;
    cout << "Enter Player 1 name: ";
    cin >> playerName1;
    cout << "Enter Player 2 name (uppercase moves): ";
    cin >> playerName2;

    int gameChoice;
    cout << "1. Play with computer" << endl;
    cout << "2. Play with another player" << endl;
    cout << "Enter your choice: ";
    cin >> gameChoice;

    if (gameChoice == 1) {
        turnQueue.addPlayer(playerName1);
        turnQueue.addPlayer("Computer");

        bool gameOver = false;
bool isPlayer1Turn = true;//maening that player1 do his move first
      while (true) {
        board.displayBoard(false, playerName1,"Computer");
        string move;
        cout << (isPlayer1Turn ? playerName1 : "Computer") << "'s turn. Enter your move (e.g., e2e4) or type exit to exit the game : ";
        cin >> move;

        if (move.length() != 4) {
            cout << "Invalid move format. Please enter a move like e2e4." << endl;
            continue;
        }
		else if(move=="exit"){
        	cout<<"The game is exit. "<<endl;
		}

        int from = board.getPositionFromInput(move.substr(0, 2));
        int to = board.getPositionFromInput(move.substr(2, 2));

        if (from < 0 || from >= 64 || to < 0 || to >= 64 || board.board[from] == ' ') {
            cout << "Player has lost the game. " << endl;
            break;
        }
		else if(move=="exit"){
        	cout<<"The game is exit "<<endl;
		}

        board.movePiece(from, to);
        board.displayBoard(true, playerName1, "Computer");
         

        // Check for winning condition
        if (isLastRowEmpty(board, isPlayer1Turn)) {
            cout << (isPlayer1Turn ? playerName1 : "Computer") << " wins!" << endl;
            break;
        }
        

        board.computerMove(); 
		
		       }
    } 
	else if (gameChoice == 2) {
        if (registeredPlayers.size() < 2) {
            cout << "Not enough players are logged in. Please log in the second player." << endl;
            string playerName2, password2;
            cout << "Enter second player name: ";
            cin >> playerName2;
            cout << "Enter password: ";
            cin >> password2;

            Player secondPlayer(playerName2, password2);
            registeredPlayers.push_back(secondPlayer);
        }

        playerName2 = registeredPlayers[1].name;
        turnQueue.addPlayer(playerName1);
        turnQueue.addPlayer(playerName2);
     bool isPlayer1Turn = true;
      while (true) {
        board.displayBoard(false, playerName1,playerName2);
        string move;
        cout << (isPlayer1Turn ? playerName1 : playerName2) << "'s turn. Enter your move (e.g., e2e4) or type exit to exit the game : ";
        cin >> move;

        if (move.length() != 4) {
            cout << "Invalid move format. Please enter a move like e2e4." << endl;
            continue;
        }
        else if(move=="exit"){
        	cout<<"The game is exit "<<endl;
		}

        int from = board.getPositionFromInput(move.substr(0, 2));
        int to = board.getPositionFromInput(move.substr(2, 2));

        if (from < 0 || from >= 64 || to < 0 || to >= 64 || board.board[from] == ' ') {
            cout << "Player has/have lost the game." << endl;
            break;
        }
		else if(move=="exit"){
        	cout<<"The game is exit. "<<endl;
		}

        board.movePiece(from, to);
        moveHistory.addMove(from, to);

        // Check for winning condition
        if (isLastRowEmpty(board, isPlayer1Turn)) {
            cout << (isPlayer1Turn ? playerName1 : playerName2) << " wins!" << endl;
            break;
        }

        isPlayer1Turn = !isPlayer1Turn; // Switch turns
    }

}
}

int main() {
    
    int choice;

    while (true) {
        displayMainMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            registerPlayer();
            break;
        case 2:
            loginPlayer();
            break;
        case 3:
            playGame();
            break;
        case 4:
            for (auto& player : registeredPlayers) {
                cout << "Players that have login :  " << player.name << endl;
                cout << "Players Password is : " << player.password  << endl;
            }
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
