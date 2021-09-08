#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define max 100

int main()
{
    //variables declaration :

    //integer variables :
    //r = rounds to be played
    //mw = no of words in movie
    //md = date of release , old new or medium
    //p = to enter the movie type in switch case
    //b1 = to ask for options of hints or another try
    //hint = to store the number of hints left
    //won = to store the no of wins
    //point1 = points of first team
    //point2 = points of 2nd team 
    //round = shows which round is going on 

    //strings/character variables :
    //T1 = name of team A
    //T2 = name of team B
    //name = name of movie
    //genre = genre of the movie
    //ma = movie age
    //an = actor's name
    //rn = reel name of the actor
    //cn = co actor name
    //loc = movie location
    //sn = song name
    //s = to check and compare the answers
    //guess = to make guess of team B
    //swap = to swap the points
    int r, mw, md, b1, p = 0, hint =1, won =0, round=0, swap;

    int point1 = 0, point2 = 0;
    //team names
    char T1[max], T2[max];
    //basic hints
    char name[max], ma[max], genre[max];
    //main hints
    char an[max], rn[max], cn[max], loc[max], sn[max];
    //guess for team B
    char guess[max];
    
    char old[max] = "OLD";
    char med[max] = "MEDIUM";
    char new[max] = "NEW";
    
    printf("\n\n\t\t\t\t\t\tHELLO !!!!!!\n\t\t\t\t\t\tWELCOME PEEPS!\n");
    printf("\n\nThis game is called as 'DUMB-CHARADES'.\n\nThe rules of the game are very simple as follows : \n");
    printf("1) We would be having two teams , first is TEAM A and second is TEAM B.\n");
    printf("2) TEAM A would be guessing the movie and giving the hints.\n\nHints are also of two type: \n\ti)Basic Hints : These hints involve\n\t\tA)the number of words in movie\n\t\tB)The age of movie whether it is NEW,MEDIUM or OLD\n\t\tC)Movie genre \n\n\n\tii)Scoring Hints: These would be the 5 hints provided by TEAM A to TEAM B to guess the movie:\n\t\tA)ACTOR/ACTRESS Name\n\t\tB)Name of actor in that movie \n\t\tC)Co-Star name \n\t\tD)Location of movie \n\t\tE)Any name of song from that movie\n");
    printf("\n\tGuessing Team would be given 5 chances to guess the correct name.\n\n");
    printf("\tPoints Distribution is as follow:\n\n");
    printf(" If guessed the correct movie without any HINT +200 points are rewarded to TEAM B and -100 points for TEAM A \n");
    printf(" If guessed the correct movie in 1st HINT +175 points are rewarded to TEAM B and -80 points for TEAM A. \n");
    printf(" If guessed the correct movie in 2nd HINT +150 points are rewarded to TEAM B and -60 points for TEAM A. \n");
    printf(" If guessed the correct movie in 3rd HINT +125 points are rewarded to TEAM B and -40 points for TEAM A. \n");
    printf(" If guessed the correct movie in 4th HINT +100 points are rewarded to TEAM B and -20 points for TEAM A. \n");
    printf(" If guessed the correct movie in 5th HINT +50 points are rewarded to TEAM B and -10 points for TEAM A. \n\n");
    printf(" If TEAM B is unable to guess without using any hint then +200 points are rewarded to TEAM A and -10 points for TEAM B\n");
    printf(" If TEAM B is unable to guess after using 1st HINT then +200 points are rewarded to TEAM A and -20 points to TEAM B\n");
    printf(" If TEAM B is unable to guess after using 5th hint then +200 points are rewarded to TEAM A and -100 points to TEAM B\n");
    printf(" If TEAM B is unable to guess after using 2nd HINT then +200 points are rewarded to TEAM A and -40 points to TEAM B\n");
    printf(" If TEAM B is unable to guess after using 3rd hint then +200 points are rewarded to TEAM A and -60 points to TEAM B\n");
    printf(" If TEAM B is unable to guess after using 4th hint then +200 points are rewarded to TEAM A and -80 points to TEAM B\n");
    printf("\n\nNOTE: All the input alphabets must be CAPITAL LETTERS\n\n\n");
    printf("\n\n\t\t\t\tSO LET US BEGIN THE GAME\n");
    
    printf("\nEnter Team A name - ");
    gets(T1);
    printf("\nEnter Team B name - ");
    gets(T2);

    printf("\nEnter the number of rounds to be played: ");
    scanf("%d", &r);  
    
    while(r--)
    {
        round++;
        fgets(name , max , stdin );
        printf("\nEnter the name of movie: ");
        fgets(name, max, stdin);
    
        printf("\nEnter total words in movie name: ");
        scanf("%d", &mw);

        fgets(genre, max , stdin);
        printf("\nEnter the movie Genre: ");
        fgets(genre, max , stdin);
    
        printf("Enter age of movie wheather it is OLD, MEDIUM or NEW.\n\tFor OLD enter 1\n\tFor MEDIUM enter 2\n\tFor NEW enter 3\n");
        scanf("%d", &md);

        do
        {
            switch(md)
            {
                case 1:     p = 1;
                            strcpy(ma , old);
                            break;
                case 2:     p = 1;
                            strcpy(ma , med );
                            break;
                case 3:     p = 1;
                            strcpy(ma , new);
                            break;   
                default:    printf("Enter valid choice :\n");
                            scanf("%d", &md);
            }
        }while(p == 0);

        printf("\nEnter the 5 hints:\n");
        fgets(an, max, stdin);
        printf("1) Main Actor or Actress Name : ");
        fgets(an, max, stdin);

        printf("2) Name of that Actor or Actress in movie : ");
        fgets(rn, max, stdin);

        printf("3) Co-Star name : ");
        fgets(cn, max, stdin);

        printf("4) Location of movie in story : ");
        fgets(loc, max, stdin);

        printf("5) Any song name in the movie : ");
        fgets(sn, max, stdin);

        for (int i = 0; i < 25; i++)
        {
            printf("\n");
        }

        printf("  Here are your basic hints:\n\n");
        printf("  No of Words in the name of movie : %d \n", mw);
        printf("  Movie Genre : %s", genre);
        printf("  Movie type : ");
        for (int p = 0; ma[p] != '\0'; p++)
        {
            printf("%c", ma[p]);
        }

        //loop using i to give 5 chances to team B to guess the movie name
        for (int i = 0; i <5; i++)
        {
            printf("\n\n  Enter your guess TEAM B :");
            printf("i= %d\n", i);
            fgets(guess, max, stdin);
            //s = to check and compare the answers
            int s = strcmp(guess, name);
            if (s == 0)
            {
                printf("\n\nCONGRATULATIONS, TEAM B YOU GUESSED THE MOVIE\n\n");
                won++;
                break;
            }
            else
            {
                printf("  Your guess was incorrect .\n  Please try again or you can use the HINTS. For getting HINTS enter '0' or for again trying enter any other number than 0.\n");
                scanf("%d", &b1);
                if (b1 == 0)
                {
                    if (hint == 1)
                    {
                        printf("  HINT %d \n  Main Actor or Actress Name %s\n", hint, an);
                        hint++;
                    }
                    else if (hint == 2)
                    {
                        printf("  HINT %d \n  Name of that Actor or Actress in movie : %s\n", hint, rn);
                        hint++;
                    }
                    else if (hint == 3)
                    {
                        printf("  HINT %d \n  Co-Star name: %s\n", hint, cn);
                        hint++;
                    }
                    else if (hint == 4)
                    {
                        printf("  HINT %d \n  Location of story in movie: %s\n", hint, loc);
                        hint++;
                    }
                    else if (hint == 5)
                    {
                        printf("  HINT %d \n  Name of any song in the movie: %s\n", hint, sn);
                        hint++;
                    }
                printf("\n\n ");
                }
            }
            fgets(guess, max, stdin);
        }
        hint--;
    
        if (hint == 0 && won == 1)
        {
            point2 = point2 + 200;
            point1 = point1 - 100;
        }
        else if (hint == 1 && won == 1)
        {
            point2 = point2 + 175;
            point1 = point1 - 80;
        }
        else if (hint == 2 && won == 1)
        {
            point2 = point2 + 150;
            point1 = point1 - 60;
        }
        else if (hint == 3 && won == 1)
        {
            point2 = point2 + 125;
            point1 = point1 - 40;
        }
        else if (hint == 4 && won == 1)
        {
            point2 = point2 + 100;
            point1 = point1 - 20;
        }
        else if (hint == 5 && won == 1)
        {
            point2 = point2 + 50;
            point1 = point1 - 10;
        }
        else if(won == 0)
        {
            point1 = point1 + 200;

            if (hint == 0)
            {
                printf(" Oops! TEAM couldn't guess the correct movie.\n Correct movie was : %s \n", name);
                point2 = point2 - 10;
            }
            else if (hint == 1)
            {
                printf(" Oops! TEAM couldn't guess the correct movie.\n Correct movie was : %s \n", name);
                point2 = point2 - 20;
            }
            else if (hint == 2)
            {
                printf(" Oops! TEAM couldn't guess the correct movie.\n Correct movie was : %s \n", name);
                point2 = point2 - 40;
            }
            else if (hint == 3)
            {
                printf(" Oops! TEAM couldn't guess the correct movie.\n Correct movie was : %s \n", name);
                point2 = point2 - 60;
            }
            else if (hint == 4)
            {
                printf(" Oops! TEAM couldn't guess the correct movie.\n Correct movie was : %s \n", name);
                point2 = point2 - 80;
            }
            else
            {
                printf(" Oops! TEAM couldn't guess the correct movie.\n Correct movie was : %s \n", name);
                point2 = point2 - 100;
            }
        }

        printf(" Scores after round %d are as follow:\n\n Points of TEAM %s = %d\n Points of TEAM %s = %d\n", round, T1, point1, T2, point2);
        printf("\n\nPress Enter to Continue with the 2nd team\n(TEAM 1 becomes TEAM 2 and TEAM 2 becomes TEAM 1 now)");
        for (int i = 0; i < 5; i++)
        {
            printf("\n");
        }
        
        swap = point1;
        point1 = point2;
        point2 = swap;
        hint = 1;
        won = 0;    
    }
    return 0;
}