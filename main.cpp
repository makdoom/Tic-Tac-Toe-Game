#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

//#########################################
//Global Variables
int choice,score1 =0,score2=0,again;
char symbol;


//#########################################
//Function Declarations
void home();
int checkWin(char []);
void close();
void human_move();
void board(char []);
void with_multiplayer();
void comp_move();


//##########################################
//Functions Definitions

void with_comp()
{
    comp_move();
}
void with_multiplayer()
{
    human_move();
}

void comp_move()
{
    char a[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int player = 1,choice,i;
    system("cls");
    do
    {
        board( a);
        player = (player % 2)?1:2;
        if(player ==2)
        {
//                cout << "Players  " << player<<endl;
//                cout<<"Press Enter for CPU"<<endl;
                choice = rand() % 9;
                symbol = '0';
                int placed = 0;
                while(placed == 0)
                {
                    if((a[2] == a[3] || a[5] == a[9] || a[4] == a[7]) && (a[1] == '1'))
                        {a[1] = symbol; placed =1;}
                    else if((a[1] == a[3] || a[5] == a[8]) && a[2] == '2')
                        {a[2] = symbol; placed =1;}
                    else if(( a[1] == a[2] || a[5] == a[7] || a[6] == a[9]) && (a[3] == '3'))
                        {a[3] = symbol; placed =1;}
                    else if((a[1] == a[7] || a[5] == a[6]) && a[4] == '4')
                       {a[4] = symbol; placed =1;}
                    else if(( a[2] == a[8] || a[1] == a[9] || a[3] == a[7] || a[4] == a[6]) && (a[5] == '5'))
                        {a[5] = symbol; placed =1;}
                    else if((a[3] == a[9] || a[4] == a[5]) && a[6] == '6')
                        {a[6] = symbol; placed =1;}
                    else if(( a[1] == a[4] || a[3] == a[5] || a[8] == a[9] ) && (a[7] == '7'))
                        {a[7] = symbol; placed =1;}
                    else if((a[7] == a[9] || a[2] == a[5]) && a[8] == '8')
                        {a[8] = symbol; placed =1;}
                    else if((a[3] == a[6] || a[7] == a[8] || a[1] == a[5]) && (a[9] == '9'))
                        {a[9] = symbol; placed =1;}

                    else
                    {
                        if((choice = 1) && (a[1] == '1'))
                            {a[1] = symbol; placed =1;}
                        else if((choice = 2) && (a[2] == '2'))
                             {a[2] = symbol; placed =1;}
                        else if((choice = 3) && (a[3] == '3'))
                             {a[3] = symbol; placed =1;}
                        else if((choice = 4) && (a[4] == '4'))
                             {a[4] = symbol; placed =4;}
                        else if((choice = 5) && (a[5] == '5'))
                             {a[5] = symbol; placed =1;}
                        else if((choice = 6) && (a[6] == '6'))
                             {a[6] = symbol; placed =1;}
                        else if((choice = 7) && (a[7] == '7'))
                             {a[7] = symbol; placed =1;}
                        else if((choice = 8) && (a[8] == '8'))
                             {a[8] = symbol; placed =1;}
                        else if((choice = 9) && (a[9] == '9'))
                             {a[9] = symbol; placed =1;}
                        else
                            choice =rand() % 9;
                    }

                }

                i = checkWin(a);
                player++;
                board(a);
        }

        else if(player == 1)
        {
            cout<<"\n\t\t\t\t\tPlayer  "<<player<<" Enter a Position Number ";
            cin>>choice;
            symbol = 'x';
            if(choice == 1 && a[1] == '1')
                a[1] = symbol;

            else if(choice == 2 && a[2] == '2')
                a[2] = symbol;

            else if(choice == 3 && a[3] == '3')
                a[3] = symbol;

            else if(choice == 4 && a[4] == '4')
                a[4] = symbol;

            else if(choice == 5 && a[5] == '5')
                a[5] = symbol;

            else if(choice == 6 && a[6] == '6')
                a[6] = symbol;

            else if(choice == 7 && a[7] == '7')
                a[7] = symbol;

            else if(choice == 8 && a[8] == '8')
                a[8] = symbol;

            else if(choice == 9 && a[9] == '9')
                a[9] = symbol;
            else
            {
                cout<<"\t\t\t\t\tInvalid Move !!!";
                player--;
                cin.ignore();
                cin.get();
            }
            i = checkWin(a);
            player++;

        }

    }while(i == -1);
    board(a);

    if(i ==1)
       {
           score1 +=i;
           cout<<"\n\t\t\t\t\t\t  ******  YOU WON ! ******"<<endl;
           cout<<"\n\t\t\t\t\t\t\t      SCORE :\n\t\t\t\t\t\tYou : "<<score1<<"\t\t\tComputer : "<<score2<<endl;

       }
    else if(i==2)
    {
            score2 =score2+(i-1);
            cout<<"\n\t\t\t\t\t\t  ******  COMPUTER WON ! ****** "<<endl;
            cout<<"\n\t\t\t\t\t\t\t     SCORE :\n\t\t\t\t\t\tYou : "<<score1<<"\t\t\tComputer : "<<score2<<endl;
    }
    else if(i==0)
    {
            cout<<"\n\t\t\t\t\t\t  ******  GAME DRAW  ******"<<endl;
            cout<<"\n\t\t\t\t\t\t\t     SCORE :\n\t\t\t\t\t\tYou : "<<score1<<"\t\t\tComputer : "<<score2<<endl;
    }
    label:
    cout<<"\n\n\t\t\t\t\t\tEnter 1 to Play again and 0 to Exit ";
    cin>>again;
    switch(again)
    {
    case 1:
        comp_move();
        break;
    case 0:
        close();
        break;
    default:
        cout<<"\n\t\t\t\t\t\t\t  Oops, Invalid Entry !! "<<endl<<"\t\t\t\t\t\t\t";
        system("pause");//delay(100000000);
        goto label;
    }

}

void close()
{
    cout<<"\n\t\t\t\t\tTHIS TIC TAC TOE GAME IS DEVELOPED BY MAKDOOM SHAIKH "<<endl<<endl;
    exit(1);
}

int checkWin(char a[10])
{

    if((a[1] == 'x' && a[2] == 'x' && a[3] == 'x')  ||  (a[1] == 'x' && a[5] == 'x' && a[9] == 'x')  ||  (a[1] == 'x' && a[4] == 'x' && a[7 ] == 'x') )
        return 1;
    else if((a[1] == '0' && a[2] == '0' && a[3] == '0') || (a[1] == '0' && a[5] == '0' && a[9] == '0' ) ||  (a[1] == '0' && a[4] == '0' && a[7] == '0' ))
        return 2;

    else if(a[2] == 'x' && a[5] == 'x' && a[8] == 'x' )
        return 1;
    else if(a[2] == '0' && a[5] == '0' && a[8] == '0' )
        return 2;
    else if((a[3] == 'x' && a[5] == 'x' && a[7] == 'x') || (a[3] == 'x' && a[6] == 'x' && a[9] == 'x' ))
        return 1;
    else if((a[3] == '0' && a[5] == '0' && a[7] == '0') || (a[3] == '0' && a[6] == '0' && a[9] == '0' ))
        return 2;

    else if(a[4] == 'x' && a[5] == 'x' && a[6] == 'x' )
        return 1;
    else if(a[4] == '0' && a[5] == '0' && a[6] == '0' )
        return 2;

    else if(a[7] == 'x' && a[8] == 'x' && a[9] == 'x' )
        return 1;
    else if(a[7] == '0' && a[8] == '0' && a[9] == '0' )
        return 2;
    else if(a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9'  )
        return 0;
    else
        return -1;


/*
    if( (a[1] == a[2]) && (a[2] == a[3]) )
        return 1;
    else if( (a[1] == a[4]) && (a[4] == a[7]) )
        return 1;
    else if( (a[1] == a[5]) && (a[5] == a[9]) )
        return 1;
    else if( (a[2] == a[5]) && (a[5] == a[8]) )
        return 1;
    else if( (a[3] == a[5]) && (a[5] == a[7]) )
        return 1;
    else if( (a[3] == a[6]) && (a[6] == a[9]) )
        return 1;
    else if( (a[4] == a[5]) && (a[5] == a[6]) )
        return 1;
    else if( (a[3] == a[4]) && (a[4] == a[5]) )
        return 1;
    else if( (a[7] == a[8]) && (a[8] == a[9]) )
        return 1;
    else if(a[1] != '1' && a[2] != '2' && a[3] != '3' && a[4] != '4' && a[5] != '5' && a[6] != '6' && a[7] != '7' && a[8] != '8' && a[9] != '9'  )
        return 0;
    else
        return -1;
*/

}
void board(char a[10])
{

    system("cls");
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t    Player 1: < X >  \t    Player 2: < 0 > "<<endl<<endl;
    cout<<"\t\t\t\t\t\t           |           |       "<<endl;
    cout<<"\t\t\t\t\t\t"<<"    "<<a[1]<<"      | "<<"    "<<a[2]<<"     |"<<"    "<<a[3]<<endl;
    cout<<"\t\t\t\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t           |           |       "<<endl;
    cout<<"\t\t\t\t\t\t"<<"    "<<a[4]<<"      | "<<"    "<<a[5]<<"     |"<<"    "<<a[6]<<endl;
    cout<<"\t\t\t\t\t\t----------------------------------"<<endl;
    cout<<"\t\t\t\t\t\t           |           |       "<<endl;
    cout<<"\t\t\t\t\t\t"<<"    "<<a[7]<<"      | "<<"    "<<a[8]<<"     |"<<"    "<<a[9]<<endl;


}
void human_move()
{
    char a[10] = {'0','1','2','3','4','5','6','7','8','9'};
    int player =1,ch,i;

    system("cls");
    do
    {
        board( a);
        player = (player % 2)?1:2;
        cout<<"\n\t\t\t\t\tPlayer  "<<player<<" Enter a Position Number ";
        cin>>ch;
        symbol = (player == 1) ? 'x' : '0';

        if(ch == 1 && a[1] == '1')
            a[1] = symbol;

        else if(ch == 2 && a[2] == '2')
            a[2] = symbol;

        else if(ch == 3 && a[3] == '3')
            a[3] = symbol;

        else if(ch == 4 && a[4] == '4')
            a[4] = symbol;

        else if(ch == 5 && a[5] == '5')
            a[5] = symbol;

        else if(ch == 6 && a[6] == '6')
            a[6] = symbol;

        else if(ch == 7 && a[7] == '7')
            a[7] = symbol;

        else if(ch == 8 && a[8] == '8')
            a[8] = symbol;

        else if(ch == 9 && a[9] == '9')
            a[9] = symbol;
        else
        {
            cout<<"\t\t\t\t\tInvalid Move !!!";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkWin(a);
        player++;

    }while(i == -1);
    board(a);

    if(i ==1)
       {
           score1 +=i;
           cout<<"\n\t\t\t\t\t\t  ******  PLAYER 1 WON ! ******"<<endl;
           cout<<"\n\t\t\t\t\t\t\t       SCORE :\n\t\t\t\t\t\tPlayer 1: "<<score1<<"\t\tPlayer 2: "<<score2<<endl;

       }
    else if(i==2)
    {
            score2 =score2+(i-1);
            cout<<"\n\t\t\t\t\t\t  ******  PLAYER 2 WON ! ****** "<<endl;
            cout<<"\n\t\t\t\t\t\t\t      SCORE :\n\t\t\t\t\t\tPlayer 1: "<<score1<<"\t\tPlayer 2: "<<score2<<endl;
    }
    else if(i==0)
    {
            cout<<"\n\t\t\t\t\t\t  ******  GAME DRAW  ******"<<endl;
            cout<<"\n\t\t\t\t\t\t\t      SCORE :\n\t\t\t\t\t\tPlayer 1: "<<score1<<"\t\tPlayer 2: "<<score2<<endl;
    }
    label:
    cout<<"\n\n\t\t\t\t\t\tEnter 1 to Play again and 0 to Exit ";
    cin>>again;
    switch(again)
    {
    case 1:
        human_move();
        break;
    case 0:
        close();
        break;
    default:
        cout<<"\n\t\t\t\t\t\t\t  Oops, Invalid Entry !! "<<endl<<"\t\t\t\t\t\t\t";
        system("pause");//delay(100000000);
        goto label;
    }

       /*if(i == 1)
        cout<<"\n\t\t\t\t\t\t******  PLAYER  "<<--player<<" WON ******"<<endl;
    else
        cout<<"\n\t\t\t\t\t\t******  GAME DRAW  ****** "<<endl;

    */

}

void home()
{
    system("cls");

    cout<<"\n\n\t\t\t\t\t################################################"<<endl;
    cout<<"\t\t\t\t\t#                                              #"<<endl;
    cout<<"\t\t\t\t\t#               TIC TAC TOE GAME               #"<<endl;
    cout<<"\t\t\t\t\t#                                              #"<<endl;
    cout<<"\t\t\t\t\t################################################"<<endl;
    cout<<"\n\n\n\t\t\t\t\t1. Computer vs. You ";
    cout<<"\t2. Local Multiplayer "<<endl;

    cout<<"\n\t\t\t\t\t\t    Enter Your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
       // board();
        with_comp();
        break;
    case 2:
        //board();
        with_multiplayer();
        break;
    case 3:
        exit(1);
        break;
    }
}

//############################################
//Main Function
main()
{
    home();
    getch();
}
