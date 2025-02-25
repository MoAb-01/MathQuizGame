#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int GetRandom(int from, int to) {
	return from + rand() % (to - from + 1);
}

char GetRandomOpr(int from, int to) {
	char RandomOperation = from + rand() % (to - from + 1);
	while (RandomOperation == 44 || RandomOperation == 45 || RandomOperation == 46)
	{
		RandomOperation = from + rand() % (to - from + 1);
	}
	return RandomOperation;
}
int ReadNumberInRange(string mssg, int from, int to)
{
	int number;
	do
	{
		cout << mssg;
		cin >> number;
	} while (number<from || number>to);
	return number;
}

enum enQuestionlvl { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOf = 5 };

struct strQuizInfo
{
	int QuestionsNumber;
	enQuestionlvl Questionlvl;
	int Number1;
	int Number2;
	int UserQuestionAnswer;
	enOperationType OprType;
	int TrueAns;
	int CorrectAnsCount;
	char OprStore;
	int QuestionDifficultyStore;
};



enQuestionlvl ReadQuestionLevel()
{
	int number = ReadNumberInRange("Enter Question Level: [1] Easy [2] Med [3] Hard [4] Mix ? \n", 1, 4);
	return (enQuestionlvl)number;
}

int SetUpDifficulty(enQuestionlvl Questionlvl,int QuestionDifficultyStore)
{
	if (Questionlvl == enQuestionlvl::Easy)
		return GetRandom(1, 10);
	else if (Questionlvl == enQuestionlvl::Med)
		return GetRandom(10, 20);
	else if (Questionlvl == enQuestionlvl::Hard)
		return GetRandom(20, 100);
	else if (Questionlvl == enQuestionlvl::Mix)
	{
		return SetUpDifficulty (enQuestionlvl(QuestionDifficultyStore),QuestionDifficultyStore);
	}
		

	return 1;
}


int SetRandomNumber(enQuestionlvl Questionlvl, int &QuestionDifficultyStore)
{
	if (QuestionDifficultyStore==0)
		QuestionDifficultyStore = GetRandom(1, 3);
	return SetUpDifficulty(Questionlvl,QuestionDifficultyStore);
}

enOperationType ReadOperation()
{
	int n = ReadNumberInRange("Enter Operation type [1] Add [2] Sub [3] Mul [4] Div [5] Mix  ", 1, 5);
	return (enOperationType)n;
}


void DisplayQuestion(enOperationType OprType, int number1, int number2, char& OprStore)
{
	if (OprType == enOperationType::Add)
	{
		cout << number1 << endl;
		cout << number2 << " +" << endl;
		cout << "________________" << endl;
	}
	else if (OprType == enOperationType::Sub)
	{
		cout << number1 << endl;
		cout << number2 << " -" << endl;
		cout << "________________" << endl;
	}
	else if (OprType == enOperationType::Mul)
	{
		cout << number1 << endl;
		cout << number2 << " x" << endl;
		cout << "________________" << endl;
	}
	else if (OprType == enOperationType::Div)
	{
		cout << number1 << endl;
		cout << number2 << " /" << endl;
		cout << "________________" << endl;
	}
	else if (OprType == enOperationType::MixOf)
	{
		OprStore = GetRandomOpr(42, 47);
		cout << number1 << endl;
		cout << number2 << " " << OprStore << endl;
		cout << "________________" << endl;

	}

}

int QuestionAns(enOperationType OprType, int number1, int number2, char OprStore)
{
	if (OprType == enOperationType::Add)
	{
		return number1 + number2;
	}
	else if (OprType == enOperationType::Sub)
	{
		return number1 - number2;
	}
	else if (OprType == enOperationType::Mul)
	{
		return number1 * number2;
	}
	else if (OprType == enOperationType::Div)
	{
		return number1 / number2;
	}
	else if (OprType == enOperationType::MixOf)
	{
		if (OprStore == '+')
			return number1 + number2;
		else if (OprStore == '-')
			return number1 - number2;
		else if (OprStore == '*')
			return number1 * number2;
		else if (OprStore == '/')
			return number1 / number2;
	}
}

int ReadUserAns()
{
	int number;
	cin >> number;
	return number;
}

void Validate(int UserQuestionAnswer, int TrueAns, int& correctAnswerscount)
{
	if (UserQuestionAnswer == TrueAns)
	{
		cout << "\nCorrect Answer :-)\n " << endl;
		system("color 2f");
		correctAnswerscount++;
	}
	else
	{
		cout << "\nWrong Answer :-(\n " << endl;
		system("color 4f");
		cout << "The Right Answer is " << TrueAns << endl;
	}
}

string QuestionlvlToString(enQuestionlvl Questionlvl)
{
	switch (Questionlvl)
	{
	case 1:
		return "Easy";
	case 2:
		return "Med";
	case 3:
		return "Hard";
	case 4:
		return "Mix";
	}
}

string OpTypeToString(enOperationType optype)
{
	switch (optype)
	{
	case 1:
		return "Add";
	case 2:
		return "Sub";
	case 3:
		return "Mult";
	case 4:
		return "Div";
	case 5:
		return "Mix";
	}
}

string CheckPass(int Questions, int CorrectAns)
{
	string Result = "";
	int HalfQuestions = ceil((float)Questions / 2);
	if (CorrectAns >= HalfQuestions)
		Result = "Pass :-)";
	else if (CorrectAns == 0 || CorrectAns < HalfQuestions)
		Result = "Failed :-(";
	return Result;
}
void GameOver(int Questions, enQuestionlvl Questionlvl, enOperationType OperationType, int CorrectAns)
{
	string Result = CheckPass(Questions, CorrectAns);

	cout << "______________________" << endl;
	cout << "Final Result is " << Result << endl;
	cout << "______________________" << endl;
	cout << "Number Of Questions:  " << Questions << endl;
	cout << "Questions Level\t: " << QuestionlvlToString(Questionlvl) << endl;
	cout << "OpType\t\t: " << OpTypeToString(OperationType) << endl;
	cout << "Number Of Right Answers: " << CorrectAns << endl;
	cout << "Number Of Wrong Answers: " << (Questions - CorrectAns) << endl;
	cout << "______________________" << endl;

}
void QuizGame()
{
	strQuizInfo QuizInfo;
	QuizInfo.CorrectAnsCount = 0;
	int Questions = ReadNumberInRange("How Many Questions Do You Want To Answer ? ", 1, 100);
	QuizInfo.OprType = ReadOperation();
	QuizInfo.Questionlvl = ReadQuestionLevel();
	QuizInfo.OprStore;
	for (int i = 0; i < Questions; ++i)
	{
		QuizInfo.QuestionDifficultyStore;
		QuizInfo.QuestionDifficultyStore = 0;
		QuizInfo.Number1 = SetRandomNumber(QuizInfo.Questionlvl, QuizInfo.QuestionDifficultyStore);
		QuizInfo.Number2 = SetRandomNumber(QuizInfo.Questionlvl, QuizInfo.QuestionDifficultyStore);
		cout << "\nQuestion [" << i + 1 << "/" << Questions << "]" << endl;
		DisplayQuestion(QuizInfo.OprType, QuizInfo.Number1, QuizInfo.Number2, QuizInfo.OprStore);
		QuizInfo.TrueAns = QuestionAns(QuizInfo.OprType, QuizInfo.Number1, QuizInfo.Number2, QuizInfo.OprStore);
		QuizInfo.UserQuestionAnswer = ReadUserAns();
		Validate(QuizInfo.UserQuestionAnswer, QuizInfo.TrueAns, QuizInfo.CorrectAnsCount);
	}
	GameOver(Questions, QuizInfo.Questionlvl, QuizInfo.OprType, QuizInfo.CorrectAnsCount);
}

char WannaPlayAgain()
{
	char Option;
	do
	{
		cout << "Wanna play again? (Y/N): ";
		cin >> Option;
	} while (Option != 'N' && Option != 'n' && Option != 'Y' && Option != 'y');
	return Option;
}

void ResetQuiz()
{
	system("cls");
	system("color 07");
}
void StartQuiz()
{
	while (1)
	{
		QuizGame();
		char choice = WannaPlayAgain();
		if (choice == 'N' || choice == 'n')
			break;
		else
			ResetQuiz();
	}
}

int main()
{
	srand((unsigned)time(NULL));
	StartQuiz();
}
