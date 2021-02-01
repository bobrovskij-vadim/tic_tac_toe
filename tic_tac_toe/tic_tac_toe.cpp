#include <iostream>
#include <string>

using namespace std;

struct player 
{
    string name;
    int score = 0;
    //char character;
    //int sign;
};

struct table
{
    int playing_field[3][3] = { {0, 0, 0},
                                {0, 0, 0},
                                {0, 0, 0} };
};

void print_field(int arr[3][3])        //ВОПРОС: Не получается передать массив через указатель, не могу понять почему, хотя тут это не к чему 
{
    int row = 0;
    cout << "------------------------------------------------------\n" << "Input field number according rectangular coordinate system: " << endl;
    cout << "Y" << endl;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (arr[i][j] == 0)
            {
                cout << "_|";
            }
            else if (arr[i][j] == 1)
            {
                cout << "x|";
            }
            else if (arr[i][j] == 2)
            {
                cout << "o|";
            }
        }

        row++;
        if (row == 3) {
            cout << " X" << endl;
        }
        else {
            cout << endl;
        }
    }
   
}
/* функция хода
int make_move()  // передать указатель на массив
{
    cout << player_1 << " make your move \n";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    field.playing_field[x][y] = 1;

    cout << player_1 << " make your move \n";
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    field.playing_field[x][y] = 1;
}*/

int find_winner(int arr[3][3])
{
     
   /*
      1. Вариант 
      if (arr[0][0] == 1 && arr[0][1] == 1 && arr[0][2] == 1) { return 1; }                       
      else if (arr[1][0] == 1 && arr[1][1] == 1 && arr[1][2] == 1) { return 1; } 
      // Сильно много кода

      2. 

      
      
      for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            int temp = j++;
            if (arr[i][j] == arr[i][temp]) {
                return 1;
            }
        }
    }

   // for (int i = 0; i <= 2; i++) {
   //     for (int j = 0; j <= 2; j++) {

   /* for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            int temp = j++;
            if (arr[i][j] == arr[i][temp]) {
                return 1;
            }
            else {
                return 2;
            }
        }
    }
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (arr[0][0] == 1 && arr[0][1] == 1 && arr[0][2] == 1) { return 1; }
            else if (arr[1][0] == 1 && arr[1][1] == 1 && arr[1][2] == 1) { return 1; }
            else if (arr[2][0] == 1 && arr[2][1] == 1 && arr[2][2] == 1) { return 1; }
        }
    }
    
*/
    return 0;
}

/*
void winner_announcement(int winner, string player)
{
    if (winner != 0)
    {
        cout << "-----" << player << " won the game. Congratulations!-----" << endl;
    }
    else if (winner == 0)
    {
        cout << "------------DEAD HEAT!------------" << endl;
    }
}*/

int main()
{
    cout << "-----Welcome to tic tac toe!-----\n" << endl;

    string player_1 = " ";
    string player_2 = " ";

    //char player_1[] = " ";  //ВОПРОС: Почему так не работает? 
    //char player_2[] = " "; 
    
    cout << "First player input your name: ";
    cin >> player_1;
    cout << "Good luck, " << player_1 << endl;
                                                    
    player john;                                  
    john.name = player_1;
    //john.character = 'x';
    //john.sign = 1;

    cout << "Second player input your name: ";
    cin >> player_2;
    cout << "Good luck, " << player_2 << endl;

    player sam;
    sam.name = player_2;
    //sam.character = 'o';
    //sam.sign = 2;

    bool do_you_want_to_play = true;

    while (do_you_want_to_play)
    {
        table field;                                      //ВОПРОС: После входа в новый цикл лучше создавать новое поле или обнулять старое (при создание нового, старое остается висеть в памяти?)
        print_field(field.playing_field);

        int count = 4;
        int winner = 3;

        int x;
        int y;

        while (count >= 0 || winner != 3)                     // Доделать систему защиты от повторного ввода в одну и туже клетку
        {                                                     // Защиту от ввода всякого хлама  
            cout << player_1 << " make your move \n";         // Вынести из функции main
            cout << "    X: ";                                // Останавливать ввод второго игрока если первый выйграл, 
            cin >> x;
            cout << "    Y: ";
            cin >> y;
            field.playing_field[3 - y][x - 1] = 1;

            print_field(field.playing_field);

            cout << player_2 << " make your move \n";
            cout << "    X: ";
            cin >> x;
            cout << "    Y: ";
            cin >> y;
            field.playing_field[3 - y][x - 1] = 2;

            print_field(field.playing_field);

            count--;

            /* if (count < 2) {
                 winner = find_winner(field.playing_field);
             }*/

        }
        char answer = ' ';
        cout << "Do you vant to play again? Y/N: ";
        cin >> answer;
        if (answer == 'Y' || answer == 'y')
        {
            do_you_want_to_play = true;
        }
        else
        {
            do_you_want_to_play = false;
        }
    }

    cout << "GAME OVER! HOPE YOU ENJOYED IT!" << endl;
    cout << "Your score:" << endl;
    cout << player_1 << " - " << john.score << endl;
    cout << player_2 << " - " << sam.score << endl;
   
    if (john.score > sam.score) 
    {
        cout << "Congratulations, " << player_1 << "!" <<endl;
    }
    else if (john.score < sam.score)
    {
        cout << "Congratulations, " << player_2 << "!" << endl;
    }
    else
    {
        cout << "Dead Heat! " << endl;
    }

 
    return 0;
    }


  