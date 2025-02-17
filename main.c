#include "myHeader.h"

void game();
void wl_menu();
void winning(int pl, int rand);
void lose(int rand);
void Display();
void Guide_Book();
void Start_menu(int value);
void PL_clear();
void PL_Display(int lp);
void Condi(int ans);
void Histo_clr(void);
void MHisto(int flag, int value, int pl);
void GuessCenter();

int GuessR1 = -1, GuessR2 = -1, GuessR3 = -1,
	GuessR4 = -1, GuessR5 = -1, GuessR6 = -1,
	GuessR7 = -1, GuessR8 = -1, GuessR9 = -1,
	GuessR10 = -1;
int HistoR1 = -1, HistoR2 = -1, HistoR3 = -1,
	HistoR4 = -1, HistoR5 = -1, HistoR6 = -1,
	HistoR7 = -1, HistoR8 = -1, HistoR9 = -1,
	HistoR10 = -1;
char message1[] = "You're in the clouds!";
char message2[] = "You're digging too deep!";
char message3[] = "You're close but your answer is High";
char message4[] = "You're close but your answer is Low";

// *******************************************************************************************************************************************************************

void game()
{
	GuessR1 = -1, GuessR2 = -1, GuessR3 = -1,
	GuessR4 = -1, GuessR5 = -1, GuessR6 = -1,
	GuessR7 = -1, GuessR8 = -1, GuessR9 = -1,
	GuessR10 = -1, HistoR1 = -1, HistoR2 = -1, HistoR3 = -1,
	HistoR4 = -1, HistoR5 = -1, HistoR6 = -1,
	HistoR7 = -1, HistoR8 = -1, HistoR9 = -1,
	HistoR10 = -1;
	int loop = 1, answer = 0, Life_Points = 10;
	clrscr();
	srand(time(NULL));
	int random = (rand() % (100)) + 1;
	int clue = (rand() % (5)) + 1;
	gotoxy(2, 1);
	set_color(2, 0);
	printf("  ____ _   _   _ ");
	set_color(3, 0);
	gotoxy(2, 2);
	printf(" / ___| |_| \\ | |");
	set_color(2, 0);
	gotoxy(2, 3);
	printf("| |  _| __|  \\| |");
	set_color(3, 0);
	gotoxy(2, 4);
	printf("| |_| | |_| |\\  |");
	set_color(2, 0);
	gotoxy(2, 5);
	printf(" \\____|\\__|_| \\_|");

	set_color(7, 0);
	gotoxy(55, 2);
	printf(" Guess the Number ");
	gotoxy(55, 3);
	printf(" Points : ");
	gotoxy(55, 4);
	printf(" Attempt : ");
	set_color(4, 0);
	gotoxy(21, 1);
	printf(" _____ \n");
	gotoxy(21, 2);
	printf("|.---.|\n");
	gotoxy(21, 3);
	printf("||___||\n");
	gotoxy(21, 4);
	printf("|+  .'|\n");
	gotoxy(21, 5);
	printf("|_____/\n\n");
	set_color(8, 8);
	for (int i = 0; i <= 35; i++)
	{
		gotoxy(5 + i, 11);
		printf("\xDB");
		gotoxy(75 - i, 11);
		printf("\xDB");
		gotoxy(5 + i, 20);
		printf("\xDB");
		gotoxy(75 - i, 20);
		printf("\xDB");
		delay(50);
	}
	set_color(7, 0);
	gotoxy(7, 10);
	printf("History");
	set_color(8, 8);
	for (int i = 1; i <= 10; i++)
	{
		gotoxy(5, 10 + i);
		printf("\xDB");
		gotoxy(75, 21 - i);
		printf("\xDB");
		delay(50);
	}
	set_color(7, 0);

	while (loop)
	{

		int flag = (10 - Life_Points) / 3, value = 1;
		set_color(0, 0);
		delay(500);
		for (int x = 0; x <= 80; x++)
		{
			for (int y = 7; y <= 8; y++)
			{
				gotoxy(x, y);
				printf("\xDB");
			}
		}
		PL_Display(Life_Points);
		MHisto(flag, value, Life_Points);
		set_color(7, 0);
		gotoxy(10, 7);
		printf("Guess : ");
		scanf("%d", &answer);

		if (answer >= 1 && answer <= 100)
		{
			if (GuessR1 == -1)
			{
				GuessR1 = answer;
			}
			else
			{
				if (GuessR2 == -1)
				{
					GuessR2 = answer;
				}
				else
				{
					if (GuessR3 == -1)
					{
						GuessR3 = answer;
					}
					else
					{
						if (GuessR4 == -1)
						{
							GuessR4 = answer;
						}
						else
						{
							if (GuessR5 == -1)
							{
								GuessR5 = answer;
							}
							else
							{
								if (GuessR6 == -1)
								{
									GuessR6 = answer;
								}
								else
								{
									if (GuessR7 == -1)
									{
										GuessR7 = answer;
									}
									else
									{
										if (GuessR8 == -1)
										{
											GuessR8 = answer;
										}
										else
										{
											if (GuessR9 == -1)
											{
												GuessR9 = answer;
											}
											else
											{
												if (GuessR10 == -1)
												{
													GuessR10 = answer;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}

			if (answer == random)
			{
				loop = 0;
				clrscr();
				winning(Life_Points, random);
			}
			else if (answer <= random + clue && answer > random)
			{
				Life_Points--;
				set_color(7, 2);
				gotoxy(18, 8);
				printf(" %s ", message3);
				set_color(7, 0);
				Condi(3);
			}
			else if (answer >= random - clue && answer < random)
			{
				Life_Points--;
				set_color(7, 3);
				gotoxy(18, 8);
				printf(" %s ", message4);
				set_color(7, 0);
				Condi(4);
			}
			else if (answer > random)
			{
				Life_Points--;
				set_color(7, 2);
				gotoxy(18, 8);
				printf(" %s ", message1);
				set_color(7, 0);
				Condi(1);
			}
			else if (answer < random)
			{
				Life_Points--;
				set_color(7, 3);
				gotoxy(18, 8);
				printf(" %s ", message2);
				set_color(7, 0);
				Condi(2);
			}
			if (Life_Points == 0)
			{
				loop = 0;
				clrscr();
				lose(random);
			}
		}
		else if (answer == 1111 && Life_Points <= 6)
		{
			int keypress, values = 0;
			if ((10 - Life_Points) - 3 * flag >= 1)
			{
				flag += 1;
			}
			set_color(0, 0);
			for (int x = 1; x <= 80; x++)
			{
				for (int y = 7; y <= 8; y++)
				{
					gotoxy(x, y);
					printf("\xDB");
				}
			}
			set_color(7, 0);
			gotoxy(10, 7);
			printf("Guess : ");
			gotoxy(9, 19);
			printf(" back");
			int back = 1;
			while (back)
			{

				gotoxy(74, 19);
				keypress = getch();

				if (keypress == 224)
				{
					keypress = getch();

					if (keypress == 72)
					{
						value--;
						if (value == 0)
						{
							value = flag;
						}
						MHisto(flag, value, Life_Points);
					}
					else if (keypress == 80)
					{
						value++;
						if (value == flag + 1)
						{
							value = 1;
						}
						MHisto(flag, value, Life_Points);
					}
					else if (keypress == 75)
					{
						values--;
						if (values == -1)
						{
							values = 1;
						}
					}
					else if (keypress == 77)
					{
						values++;
						if (values == 2)
						{
							values = 0;
						}
					}
				}
				else if (keypress == 13)
				{
					int loop;
					switch (values)
					{

					case 1:
						back = 0;
						break;
					default:
						exit(0);
					}
				}
				set_color(7, 0);
				if (values == 1)
				{
					gotoxy(9, 19);
					printf("> back <");
				}
				else
				{
					gotoxy(9, 19);
					printf(" back   ");
				}
			}
		}
		else
		{
			set_color(7, 4);
			printf(" Invalid input! The number must be between 0 and 100. \n");
			set_color(7, 0);
		}
	};
}

// *******************************************************************************************************************************************************************

void wl_menu()
{
	int value = 0, loop = 1;
	int keypress;
	while (loop)
	{
		switch (value)
		{
		case 0:
			set_color(7, 0);
			gotoxy(8, 15);
			printf("  Quit    ");
			set_color(0, 3);
			gotoxy(62, 15);
			printf(" > Try Again < ");
			break;
		case 1:
			set_color(0, 3);
			gotoxy(8, 15);
			printf(" > Quit < ");
			set_color(7, 0);
			gotoxy(62, 15);
			printf("    Try Again  ");
			break;
		default:
			break;
		}

		keypress = getch();

		if (keypress == 224)
		{
			keypress = getch();

			if (keypress == 75)
			{
				value--;
				if (value == -1)
				{
					value = 1;
				}
			}
			else if (keypress == 77)
			{
				value++;
				if (value == 2)
				{
					value = 0;
				}
			}
		}
		else if (keypress == 13)
		{
			switch (value)
			{
			case 0:
				set_color(0, 0);
				game();
				break;
			case 1:
				clrscr();
				loop = 0;
				GuessCenter();
				break;
			default:
				exit(0);
			}
		}
	}
}

// *******************************************************************************************************************************************************************

void winning(int pl, int rand)
{
	gotoxy(3, 1);
	set_color(1, 0);
	printf("   _____                            _         _       _   _             ");
	delay(100);
	gotoxy(3, 2);
	set_color(4, 0);
	printf("  / ____|                          | |       | |     | | (_)");
	delay(100);
	gotoxy(3, 3);
	set_color(2, 0);
	printf(" | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __");
	delay(100);
	gotoxy(3, 4);
	set_color(3, 0);
	printf(" | |    / _ \\| '_ \\ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \\| '_ \\");
	delay(100);
	gotoxy(3, 5);
	set_color(1, 0);
	printf(" | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | |");
	delay(100);
	gotoxy(3, 6);
	set_color(4, 0);
	printf("  \\_____\\___/|_| |_|\\__, |_|  \\__,_|\\__|\\__,_|_|\\__,_|\\__|_|\\___/|_| |_|");
	delay(100);
	gotoxy(3, 7);
	set_color(2, 0);
	printf("                     __/ |");
	delay(100);
	gotoxy(3, 8);
	set_color(3, 0);
	printf("                    |___/");
	set_color(7, 0);
	gotoxy(22, 10);
	printf("You guessed the correct number: ");
	set_color(2, 0);
	gotoxy(54, 10);
	printf("%d", rand);
	set_color(7, 0);
	gotoxy(30, 11);
	printf("Your points are ");
	set_color(1, 0);
	gotoxy(47, 11);
	printf("%d", pl * 10);
	wl_menu();
}

// *******************************************************************************************************************************************************************

void lose(int rand)
{
	gotoxy(12, 1);
	set_color(1, 0);
	printf(" ____       _   _              _               _      _ ");
	delay(100);
	gotoxy(12, 2);
	set_color(4, 0);
	printf("| __ )  ___| |_| |_ ___ _ __  | |   _   _  ___| | __ | |");
	delay(100);
	gotoxy(12, 3);
	set_color(2, 0);
	printf("|  _ \\ / _ \\ __| __/ _ \\ '__| | |  | | | |/ __| |/ / | |");
	delay(100);
	gotoxy(12, 4);
	set_color(3, 0);
	printf("| |_) |  __/ |_| ||  __/ |    | |__| |_| | (__|   <  |_|");
	delay(100);
	gotoxy(12, 5);
	set_color(1, 0);
	printf("|____/ \\___|\\__|\\__\\___|_|    |_____\\__,_|\\___|_|\\_\\ (_)");
	set_color(7, 0);
	gotoxy(22, 10);
	printf("You guessed the correct number: ");
	set_color(4, 0);
	gotoxy(54, 10);
	printf("50");
	set_color(7, 0);
	gotoxy(30, 11);
	printf("Your points are ");
	set_color(4, 0);
	gotoxy(47, 11);
	printf("0");
	wl_menu();
}

// *******************************************************************************************************************************************************************

void Display()
{
	set_color(1, 0);
	gotoxy(1, 1);
	printf("__        __   _                            _          _   _          ");
	delay(100);
	set_color(4, 0);
	gotoxy(1, 2);
	printf("\\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_| |__   ___ ");
	delay(100);
	set_color(2, 0);
	gotoxy(1, 3);
	printf(" \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | __| '_ \\ / _ \\");
	delay(100);
	set_color(3, 0);
	gotoxy(1, 4);
	printf("  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |_| | | |  __/");
	delay(100);
	set_color(1, 0);
	gotoxy(1, 5);
	printf("  _\\_/\\_/ \\___|_|\\___\\___/|_|_|_|_|_|\\___|  \\__\\___/   \\__|_| |_|\\___|");
	delay(100);
	set_color(4, 0);
	gotoxy(1, 6);
	printf(" / ___|_   _  ___  ___ ___  | |_| |__   ___                           ");
	delay(100);
	set_color(2, 0);
	gotoxy(1, 7);
	printf("| |  _| | | |/ _ \\/ __/ __| | __| '_ \\ / _ \\                          ");
	delay(100);
	set_color(3, 0);
	gotoxy(1, 8);
	printf("| |_| | |_| |  __/\\__ \\__ \\ | |_| | | |  __/                          ");
	delay(100);
	set_color(1, 0);
	gotoxy(1, 9);
	printf(" \\____|\\__,_|\\___||___/___/  \\__|_| |_|\\___|                          ");
	delay(100);
	set_color(4, 0);
	gotoxy(1, 10);
	printf("| \\ | |_   _ _ __ ___ | |__   ___ _ __                                ");
	delay(100);
	set_color(2, 0);
	gotoxy(1, 11);
	printf("|  \\| | | | | '_ ` _ \\| '_ \\ / _ \\ '__|                               ");
	delay(100);
	set_color(3, 0);
	gotoxy(1, 12);
	printf("| |\\  | |_| | | | | | | |_) |  __/ |                                  ");
	delay(100);
	set_color(1, 0);
	gotoxy(1, 13);
	printf("|_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|                                  ");
	delay(100);
	set_color(7, 4);
	gotoxy(1, 15);
	printf(" This program was created by \x4A\x65\x72\x73\x6F\x6E \x46\x2E \x44\x6F\x72\x6F\x6E\x69\x6C\x61. Thank you for using it! ");
}

// *******************************************************************************************************************************************************************

void Guide_Book()
{
	clrscr();
	set_color(1, 0);
	gotoxy((80 - 54) / 2, 1);
	printf("  ____       _     _        ____              _    ");
	delay(100);

	set_color(4, 0);
	gotoxy((80 - 54) / 2, 2);
	printf(" / ___|_   _(_) __| | ___  | __ )  ___   ___ | | __");
	delay(100);

	set_color(2, 0);
	gotoxy((80 - 54) / 2, 3);
	printf("| |  _| | | | |/ _` |/ _ \\ |  _ \\ / _ \\ / _ \\| |/ /");
	delay(100);

	set_color(3, 0);
	gotoxy((80 - 54) / 2, 4);
	printf("| |_| | |_| | | (_| |  __/ | |_) | (_) | (_) |   < ");
	delay(100);

	set_color(1, 0);
	gotoxy((80 - 54) / 2, 5);
	printf(" \\____|\\__,_|_|\\__,_|\\___| |____/ \\___/ \\___/|_|\\_\\");
	delay(100);
	set_color(7, 4);
	gotoxy((80 - 65) / 2, 7);
	printf(" > Guess the Number Challenge: Can you find the secret number? < ");
	delay(500);
	set_color(7, 0);
	gotoxy(3, 9);
	printf("Welcome to the Guess the Number Challenge! You start with 100 points.");
	gotoxy(3, 10);
	printf("Your goal is to guess the secret number between 1 and 100.");
	gotoxy(3, 11);
	printf("Each incorrect guess will deduct points, so be careful! ");
	gotoxy(3, 12);
	printf("Watch out for clues to help you narrow down your guesses.");
	set_color(7, 2);
	gotoxy(3, 15);
	printf(" # TYPES OF CLUES # ");
	set_color(7, 3);
	for (int i = 17; i <= 23; i++)
	{
		if (i % 2 != 0)
		{
			gotoxy(4, i);
			printf(" * ");
		}
	}
	set_color(7, 0);
	gotoxy(8, 17);
	printf("You're in the clouds!");
	gotoxy(8, 19);
	printf("You're digging too deep!");
	gotoxy(8, 21);
	printf("You're close but your answer is High");
	gotoxy(8, 23);
	printf("You're close but your answer is Low");
	set_color(7, 6);
	gotoxy(3, 25);
	printf("   To acess the history scroll input the code : 1111   ");
	set_color(7, 0);
	gotoxy(3, 27);
	printf("Remember, you have **10 tries** to guess the secret number.");
	gotoxy(3, 28);
	printf("Each wrong guess will deduct **10 points** from your starting score of 100.");
	gotoxy(3, 29);
	printf("Use your guesses wisely!");

	set_color(7, 4);
	gotoxy((80 - 15) / 2, 31);
	printf(" > Good Luck < ");
	set_color(7, 0);
	gotoxy(3, 33);
	printf("Press any key to return to the starting menu... ");
	getch();
	clrscr();
}

// *******************************************************************************************************************************************************************

void Start_menu(int value)
{
	set_color(0, 0);
	for (int j = 17; j <= 19; j++)
	{
		for (int i = 0; i <= 18; i++)
		{
			gotoxy(i, j);
			printf("\xDB");
		}
	}
	if (value == 0)
	{
		set_color(0, 7);
		gotoxy(1, 17);
		printf(">> START ");
		set_color(7, 0);
		gotoxy(1, 18);
		printf("Guide Book");
		gotoxy(1, 19);
		printf("EXIT");
	}
	else if (value == 1)
	{
		set_color(0, 7);
		gotoxy(1, 18);
		printf(">> Guide Book ");
		set_color(7, 0);
		gotoxy(1, 17);
		printf("START");
		gotoxy(1, 19);
		printf("EXIT");
	}
	else if (value == 2)
	{
		set_color(0, 7);
		gotoxy(1, 19);
		printf(">> EXIT ");
		set_color(7, 0);
		gotoxy(1, 17);
		printf("START");
		gotoxy(1, 18);
		printf("Guide Book");
	}
}

// *******************************************************************************************************************************************************************

// *******************************************************************************************************************************************************************
// *******************************************************************************************************************************************************************
// *******************************************************************************************************************************************************************
// *******************************************************************************************************************************************************************
// *******************************************************************************************************************************************************************
void PL_clear()
{
	for (int i = 0; i < 3; i++)
	{
		set_color(0, 0);
		gotoxy(65 + i, 3);
		printf("\xDB");
		gotoxy(66 + i, 4);
		printf("\xDB");
	}
}
void PL_Display(int lp)
{
	PL_clear();
	if (lp < 4)
	{
		set_color(4, 0);
	}
	else if (lp < 6)
	{
		set_color(6, 0);
	}
	else
	{
		set_color(2, 0);
	}
	gotoxy(65, 3);
	printf("%d", lp * 10);
	if (lp < 3)
	{
		set_color(4, 0);
	}
	else if (lp < 5)
	{
		set_color(6, 0);
	}
	else
	{
		set_color(2, 0);
	}
	gotoxy(66, 4);
	printf("%d", lp);
}
void Condi(int ans)
{
	if (HistoR1 == -1)
	{
		HistoR1 = ans;
	}
	else
	{
		if (HistoR2 == -1)
		{
			HistoR2 = ans;
		}
		else
		{
			if (HistoR3 == -1)
			{
				HistoR3 = ans;
			}
			else
			{
				if (HistoR4 == -1)
				{
					HistoR4 = ans;
				}
				else
				{
					if (HistoR5 == -1)
					{
						HistoR5 = ans;
					}
					else
					{
						if (HistoR6 == -1)
						{
							HistoR6 = ans;
						}
						else
						{
							if (HistoR7 == -1)
							{
								HistoR7 = ans;
							}
							else
							{
								if (HistoR8 == -1)
								{
									HistoR8 = ans;
								}
								else
								{
									if (HistoR9 == -1)
									{
										HistoR9 = ans;
									}
									else
									{
										if (HistoR10 == -1)
										{
											HistoR10 = ans;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
void Histo_clr(void)
{
	set_color(0, 0);
	for (int x = 6; x <= 74; x++)
	{
		for (int y = 12; y <= 19; y++)
		{
			gotoxy(x, y);
			printf("\xDB");
		}
	}
}

void MHisto(int flag, int value, int pl)
{
	Histo_clr();
	if (pl == 10)
	{
		set_color(7, 0);
		gotoxy(34, 15);
		printf("No history ...");
	}
	else if (pl == 9)
	{
		set_color(7, 0);
		gotoxy(8, 12);
		printf("Player Guess : ");
		gotoxy(23, 12);
		if (HistoR1 == 1 || HistoR1 == 3)
		{
			set_color(2, 0);
		}
		else
		{
			set_color(3, 0);
		}
		printf("%d", GuessR1);
		set_color(6, 0);
		gotoxy(59, 12);
		printf(" Attempt : 1 ");
		gotoxy(23, 13);
		if (HistoR1 == 1 || HistoR1 == 3)
		{
			set_color(7, 2);
		}
		else
		{
			set_color(7, 3);
		}
		if (HistoR1 == 1)
		{
			printf(" %s ", message1);
		}
		else if (HistoR1 == 2)
		{
			printf(" %s ", message2);
		}
		else if (HistoR1 == 3)
		{
			printf(" %s ", message3);
		}
		else
		{
			printf(" %s ", message4);
		}
	}
	else if (pl == 8)
	{
		set_color(7, 0);
		gotoxy(8, 12);
		printf("Player Guess : ");
		gotoxy(23, 12);
		if (HistoR2 == 1 || HistoR2 == 3)
		{
			set_color(2, 0);
		}
		else
		{
			set_color(3, 0);
		}
		printf("%d", GuessR2);
		set_color(6, 0);
		gotoxy(59, 12);
		printf(" Attempt : 2 ");
		gotoxy(23, 13);
		if (HistoR2 == 1 || HistoR2 == 3)
		{
			set_color(7, 2);
		}
		else
		{
			set_color(7, 3);
		}
		if (HistoR2 == 1)
		{
			printf(" %s ", message1);
		}
		else if (HistoR2 == 2)
		{
			printf(" %s ", message2);
		}
		else if (HistoR2 == 3)
		{
			printf(" %s ", message3);
		}
		else
		{
			printf(" %s ", message4);
		}
		set_color(7, 0);
		gotoxy(8, 14);
		printf("Player Guess : ");
		gotoxy(23, 14);
		if (HistoR1 == 1 || HistoR1 == 3)
		{
			set_color(2, 0);
		}
		else
		{
			set_color(3, 0);
		}
		printf("%d", GuessR1);
		set_color(6, 0);
		gotoxy(59, 14);
		printf(" Attempt : 1 ");
		gotoxy(23, 15);
		if (HistoR1 == 1 || HistoR1 == 3)
		{
			set_color(7, 2);
		}
		else
		{
			set_color(7, 3);
		}
		if (HistoR1 == 1)
		{
			printf(" %s ", message1);
		}
		else if (HistoR1 == 2)
		{
			printf(" %s ", message2);
		}
		else if (HistoR1 == 3)
		{
			printf(" %s ", message3);
		}
		else
		{
			printf(" %s ", message4);
		}
	}
	else if (pl == 7)
	{
		set_color(7, 0);
		gotoxy(8, 12);
		printf("Player Guess : ");
		gotoxy(23, 12);
		if (HistoR3 == 1 || HistoR3 == 3)
		{
			set_color(2, 0);
		}
		else
		{
			set_color(3, 0);
		}
		printf("%d", GuessR3);
		set_color(6, 0);
		gotoxy(59, 12);
		printf(" Attempt : 3 ");
		gotoxy(23, 13);
		if (HistoR3 == 1 || HistoR3 == 3)
		{
			set_color(7, 2);
		}
		else
		{
			set_color(7, 3);
		}
		if (HistoR3 == 1)
		{
			printf(" %s ", message1);
		}
		else if (HistoR3 == 2)
		{
			printf(" %s ", message2);
		}
		else if (HistoR3 == 3)
		{
			printf(" %s ", message3);
		}
		else
		{
			printf(" %s ", message4);
		}

		set_color(7, 0);
		gotoxy(8, 14);
		printf("Player Guess : ");
		gotoxy(23, 14);
		if (HistoR2 == 1 || HistoR2 == 3)
		{
			set_color(2, 0);
		}
		else
		{
			set_color(3, 0);
		}
		printf("%d", GuessR2);
		set_color(6, 0);
		gotoxy(59, 14);
		printf(" Attempt : 2 ");
		gotoxy(23, 15);
		if (HistoR2 == 1 || HistoR2 == 3)
		{
			set_color(7, 2);
		}
		else
		{
			set_color(7, 3);
		}
		if (HistoR2 == 1)
		{
			printf(" %s ", message1);
		}
		else if (HistoR2 == 2)
		{
			printf(" %s ", message2);
		}
		else if (HistoR2 == 3)
		{
			printf(" %s ", message3);
		}
		else
		{
			printf(" %s ", message4);
		}

		set_color(7, 0);
		gotoxy(8, 16);
		printf("Player Guess : ");
		gotoxy(23, 16);
		if (HistoR1 == 1 || HistoR1 == 3)
		{
			set_color(2, 0);
		}
		else
		{
			set_color(3, 0);
		}
		printf("%d", GuessR1);
		set_color(6, 0);
		gotoxy(59, 16);
		printf(" Attempt : 1 ");
		gotoxy(23, 17);
		if (HistoR1 == 1 || HistoR1 == 3)
		{
			set_color(7, 2);
		}
		else
		{
			set_color(7, 3);
		}
		if (HistoR1 == 1)
		{
			printf(" %s ", message1);
		}
		else if (HistoR1 == 2)
		{
			printf(" %s ", message2);
		}
		else if (HistoR1 == 3)
		{
			printf(" %s ", message3);
		}
		else
		{
			printf(" %s ", message4);
		}
	}
	else if (value <= 6 && value > 0)
	{
		if (value == 1)
		{
			if (pl == 6)
			{
				set_color(7, 0);
				gotoxy(8, 12);
				printf("Player Guess : ");
				gotoxy(23, 12);
				if (HistoR4 == 1 || HistoR4 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR4);
				set_color(6, 0);
				gotoxy(59, 12);
				printf(" Attempt : 4 ");
				gotoxy(23, 13);
				if (HistoR4 == 1 || HistoR4 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR4 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR4 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR4 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 14);
				printf("Player Guess : ");
				gotoxy(23, 14);
				if (HistoR3 == 1 || HistoR3 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR3);
				set_color(6, 0);
				gotoxy(59, 14);
				printf(" Attempt : 3 ");
				gotoxy(23, 15);
				if (HistoR3 == 1 || HistoR3 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR3 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR3 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR3 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 16);
				printf("Player Guess : ");
				gotoxy(23, 16);
				if (HistoR2 == 1 || HistoR2 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR2);
				set_color(6, 0);
				gotoxy(59, 16);
				printf(" Attempt : 2 ");
				gotoxy(23, 17);
				if (HistoR2 == 1 || HistoR2 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR2 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR2 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR2 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}
			}
			else if (pl == 5)
			{

				set_color(7, 0);
				gotoxy(8, 12);
				printf("Player Guess : ");
				gotoxy(23, 12);
				if (HistoR5 == 1 || HistoR5 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR5);
				set_color(6, 0);
				gotoxy(59, 12);
				printf(" Attempt : 5 ");
				gotoxy(23, 13);
				if (HistoR5 == 1 || HistoR5 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR5 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR5 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR5 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 14);
				printf("Player Guess : ");
				gotoxy(23, 14);
				if (HistoR4 == 1 || HistoR4 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR4);
				set_color(6, 0);
				gotoxy(59, 14);
				printf(" Attempt : 4 ");
				gotoxy(23, 15);
				if (HistoR4 == 1 || HistoR4 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR4 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR4 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR4 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 16);
				printf("Player Guess : ");
				gotoxy(23, 16);
				if (HistoR3 == 1 || HistoR3 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR3);
				set_color(6, 0);
				gotoxy(59, 16);
				printf(" Attempt : 3 ");
				gotoxy(23, 17);
				if (HistoR3 == 1 || HistoR3 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR3 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR3 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR3 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}
			}
			else if (pl == 4)
			{

				set_color(7, 0);
				gotoxy(8, 12);
				printf("Player Guess : ");
				gotoxy(23, 12);
				if (HistoR6 == 1 || HistoR6 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR6);
				set_color(6, 0);
				gotoxy(59, 12);
				printf(" Attempt : 6 ");
				gotoxy(23, 13);
				if (HistoR6 == 1 || HistoR6 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR6 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR6 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR6 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 14);
				printf("Player Guess : ");
				gotoxy(23, 14);
				if (HistoR5 == 1 || HistoR5 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR5);
				set_color(6, 0);
				gotoxy(59, 14);
				printf(" Attempt : 5 ");
				gotoxy(23, 15);
				if (HistoR5 == 1 || HistoR5 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR5 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR5 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR5 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 16);
				printf("Player Guess : ");
				gotoxy(23, 16);
				if (HistoR4 == 1 || HistoR4 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR4);
				set_color(6, 0);
				gotoxy(59, 16);
				printf(" Attempt : 4 ");
				gotoxy(23, 17);
				if (HistoR4 == 1 || HistoR4 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR4 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR4 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR4 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}
			}
			else if (pl == 3)
			{

				set_color(7, 0);
				gotoxy(8, 12);
				printf("Player Guess : ");
				gotoxy(23, 12);
				if (HistoR7 == 1 || HistoR7 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR7);
				set_color(6, 0);
				gotoxy(59, 12);
				printf(" Attempt : 7 ");
				gotoxy(23, 13);
				if (HistoR7 == 1 || HistoR7 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR7 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR7 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR7 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 14);
				printf("Player Guess : ");
				gotoxy(23, 14);
				if (HistoR6 == 1 || HistoR6 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR6);
				set_color(6, 0);
				gotoxy(59, 14);
				printf(" Attempt : 6 ");
				gotoxy(23, 15);
				if (HistoR6 == 1 || HistoR6 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR6 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR6 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR6 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 16);
				printf("Player Guess : ");
				gotoxy(23, 16);
				if (HistoR5 == 1 || HistoR5 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR5);
				set_color(6, 0);
				gotoxy(59, 16);
				printf(" Attempt : 5 ");
				gotoxy(23, 17);
				if (HistoR5 == 1 || HistoR5 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR5 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR5 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR5 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}
			}
			else if (pl == 2)
			{

				set_color(7, 0);
				gotoxy(8, 12);
				printf("Player Guess : ");
				gotoxy(23, 12);
				if (HistoR8 == 1 || HistoR8 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR8);
				set_color(6, 0);
				gotoxy(59, 12);
				printf(" Attempt : 8 ");
				gotoxy(23, 13);
				if (HistoR8 == 1 || HistoR8 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR8 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR8 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR8 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 14);
				printf("Player Guess : ");
				gotoxy(23, 14);
				if (HistoR7 == 1 || HistoR7 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR7);
				set_color(6, 0);
				gotoxy(59, 14);
				printf(" Attempt : 7 ");
				gotoxy(23, 15);
				if (HistoR7 == 1 || HistoR7 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR7 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR7 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR7 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 16);
				printf("Player Guess : ");
				gotoxy(23, 16);
				if (HistoR6 == 1 || HistoR6 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR6);
				set_color(6, 0);
				gotoxy(59, 16);
				printf(" Attempt : 6 ");
				gotoxy(23, 17);
				if (HistoR6 == 1 || HistoR6 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR6 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR6 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR6 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}
			}
			else if (pl == 1)
			{

				set_color(7, 0);
				gotoxy(8, 12);
				printf("Player Guess : ");
				gotoxy(23, 12);
				if (HistoR9 == 1 || HistoR9 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR9);
				set_color(6, 0);
				gotoxy(59, 12);
				printf(" Attempt : 9 ");
				gotoxy(23, 13);
				if (HistoR9 == 1 || HistoR9 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR9 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR9 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR9 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 14);
				printf("Player Guess : ");
				gotoxy(23, 14);
				if (HistoR8 == 1 || HistoR8 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR8);
				set_color(6, 0);
				gotoxy(59, 14);
				printf(" Attempt : 8 ");
				gotoxy(23, 15);
				if (HistoR8 == 1 || HistoR8 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR8 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR8 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR8 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}

				set_color(7, 0);
				gotoxy(8, 16);
				printf("Player Guess : ");
				gotoxy(23, 16);
				if (HistoR7 == 1 || HistoR7 == 3)
				{
					set_color(2, 0);
				}
				else
				{
					set_color(3, 0);
				}
				printf("%d", GuessR7);
				set_color(6, 0);
				gotoxy(59, 16);
				printf(" Attempt : 7 ");
				gotoxy(23, 17);
				if (HistoR7 == 1 || HistoR7 == 3)
				{
					set_color(7, 2);
				}
				else
				{
					set_color(7, 3);
				}
				if (HistoR7 == 1)
				{
					printf(" %s ", message1);
				}
				else if (HistoR7 == 2)
				{
					printf(" %s ", message2);
				}
				else if (HistoR7 == 3)
				{
					printf(" %s ", message3);
				}
				else
				{
					printf(" %s ", message4);
				}
			}
		}
		else
		{
			set_color(7, 0);
			gotoxy(8, 12);
			printf("Player Guess : ");
			gotoxy(23, 12);
			if (HistoR3 == 1 || HistoR3 == 3)
			{
				set_color(2, 0);
			}
			else
			{
				set_color(3, 0);
			}
			printf("%d", GuessR3);
			set_color(6, 0);
			gotoxy(59, 12);
			printf(" Attempt : 3 ");
			gotoxy(23, 13);
			if (HistoR3 == 1 || HistoR3 == 3)
			{
				set_color(7, 2);
			}
			else
			{
				set_color(7, 3);
			}
			if (HistoR3 == 1)
			{
				printf(" %s ", message1);
			}
			else if (HistoR3 == 2)
			{
				printf(" %s ", message2);
			}
			else if (HistoR3 == 3)
			{
				printf(" %s ", message3);
			}
			else
			{
				printf(" %s ", message4);
			}

			set_color(7, 0);
			gotoxy(8, 14);
			printf("Player Guess : ");
			gotoxy(23, 14);
			if (HistoR2 == 1 || HistoR2 == 3)
			{
				set_color(2, 0);
			}
			else
			{
				set_color(3, 0);
			}
			printf("%d", GuessR2);
			set_color(6, 0);
			gotoxy(59, 14);
			printf(" Attempt : 2 ");
			gotoxy(23, 15);
			if (HistoR2 == 1 || HistoR2 == 3)
			{
				set_color(7, 2);
			}
			else
			{
				set_color(7, 3);
			}
			if (HistoR2 == 1)
			{
				printf(" %s ", message1);
			}
			else if (HistoR2 == 2)
			{
				printf(" %s ", message2);
			}
			else if (HistoR2 == 3)
			{
				printf(" %s ", message3);
			}
			else
			{
				printf(" %s ", message4);
			}

			set_color(7, 0);
			gotoxy(8, 16);
			printf("Player Guess : ");
			gotoxy(23, 16);
			if (HistoR1 == 1 || HistoR1 == 3)
			{
				set_color(2, 0);
			}
			else
			{
				set_color(3, 0);
			}
			printf("%d", GuessR1);
			set_color(6, 0);
			gotoxy(59, 16);
			printf(" Attempt : 1 ");
			gotoxy(23, 17);
			if (HistoR1 == 1 || HistoR1 == 3)
			{
				set_color(7, 2);
			}
			else
			{
				set_color(7, 3);
			}
			if (HistoR1 == 1)
			{
				printf(" %s ", message1);
			}
			else if (HistoR1 == 2)
			{
				printf(" %s ", message2);
			}
			else if (HistoR1 == 3)
			{
				printf(" %s ", message3);
			}
			else
			{
				printf(" %s ", message4);
			}
		}
	}
	if (pl <= 3 && pl >= 1)
	{
		if (value == 2)
		{
			set_color(7, 0);
			gotoxy(8, 12);
			printf("Player Guess : ");
			gotoxy(23, 12);
			if (HistoR6 == 1 || HistoR6 == 3)
			{
				set_color(2, 0);
			}
			else
			{
				set_color(3, 0);
			}
			printf("%d", GuessR6);
			set_color(6, 0);
			gotoxy(59, 12);
			printf(" Attempt : 6 ");
			gotoxy(23, 13);
			if (HistoR6 == 1 || HistoR6 == 3)
			{
				set_color(7, 2);
			}
			else
			{
				set_color(7, 3);
			}
			if (HistoR6 == 1)
			{
				printf(" %s ", message1);
			}
			else if (HistoR6 == 2)
			{
				printf(" %s ", message2);
			}
			else if (HistoR6 == 3)
			{
				printf(" %s ", message3);
			}
			else
			{
				printf(" %s ", message4);
			}

			set_color(7, 0);
			gotoxy(8, 14);
			printf("Player Guess : ");
			gotoxy(23, 14);
			if (HistoR5 == 1 || HistoR5 == 3)
			{
				set_color(2, 0);
			}
			else
			{
				set_color(3, 0);
			}
			printf("%d", GuessR5);
			set_color(6, 0);
			gotoxy(59, 14);
			printf(" Attempt : 5 ");
			gotoxy(23, 15);
			if (HistoR5 == 1 || HistoR5 == 3)
			{
				set_color(7, 2);
			}
			else
			{
				set_color(7, 3);
			}
			if (HistoR5 == 1)
			{
				printf(" %s ", message1);
			}
			else if (HistoR5 == 2)
			{
				printf(" %s ", message2);
			}
			else if (HistoR5 == 3)
			{
				printf(" %s ", message3);
			}
			else
			{
				printf(" %s ", message4);
			}

			set_color(7, 0);
			gotoxy(8, 16);
			printf("Player Guess : ");
			gotoxy(23, 16);
			if (HistoR4 == 1 || HistoR4 == 3)
			{
				set_color(2, 0);
			}
			else
			{
				set_color(3, 0);
			}
			printf("%d", GuessR4);
			set_color(6, 0);
			gotoxy(59, 16);
			printf(" Attempt : 4 ");
			gotoxy(23, 17);
			if (HistoR4 == 1 || HistoR4 == 3)
			{
				set_color(7, 2);
			}
			else
			{
				set_color(7, 3);
			}
			if (HistoR4 == 1)
			{
				printf(" %s ", message1);
			}
			else if (HistoR4 == 2)
			{
				printf(" %s ", message2);
			}
			else if (HistoR4 == 3)
			{
				printf(" %s ", message3);
			}
			else
			{
				printf(" %s ", message4);
			}
		}
	}
}
void GuessCenter()
{
	int value = 0, loop = 1;
	int keypress;
	clrscr();
	Display();
	while (loop)
	{
		Start_menu(value);
		gotoxy(1, 20);
		keypress = getch();

		if (keypress == 224)
		{
			keypress = getch();

			if (keypress == 72)
			{
				value--;
				if (value == -1)
				{
					value = 2;
				}
			}
			else if (keypress == 80)
			{
				value++;
				if (value == 3)
				{
					value = 0;
				}
			}
		}
		else if (keypress == 13)
		{
			switch (value)
			{
			case 0:
				game();
				break;
			case 1:
				Guide_Book();
				Display();
				break;
			case 2:
				loop = 0;
				clrscr();
				break;
			}
		}
	}
}

int main(){
	GuessCenter();
	return 0;
}
