#include<iostream>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice = enGameChoice::Stone;
    enGameChoice ComputerChoice = enGameChoice::Stone;
    enWinner Winner = enWinner::Draw;
    string WinnerName = "";
};

struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner = enWinner::Draw;
    string WinnerName = "";
};
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
string ChoiceName(enGameChoice Choice)
{
    string arrGameChoices[3] = { "Stone","Paper","Scissors" };
    return arrGameChoices[Choice - 1];
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player1","Computer","No Winner" };
    return arrWinnerName[Winner - 1];
}
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == enGameChoice::Paper)
            return enWinner::Computer;
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
            return enWinner::Computer;
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == enGameChoice::Stone)
            return enWinner::Computer;
        break;
    }
    return enWinner::Player1;
}
enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}
void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        cout << "\a";
        break;
    default:
        system("color 6F");
        break;
    }
}

void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "]____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________\n" << endl;
    SetWinnerScreenColor(RoundInfo.Winner);
}
enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if (Player1WinTimes > ComputerWinTimes)
        return enWinner::Player1;
    else if (ComputerWinTimes > Player1WinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}
stGameResults FillGameResults(int GameRounds, short Player1WinTimes,
    short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.Computer2WinTimes = ComputerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}
stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

int main()
{
   srand((unsigned)time(NULL));
    return 0;
}
