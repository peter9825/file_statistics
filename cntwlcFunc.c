/*   This program will count the number of lines, words, characters from standard input or from
 *   file(s) listed as arguments on the command line using the function cntwlc. This program's
 *   main purpose is to compute the statistics for both files and stdin.
 *
 *
 *
 */

#include "cntwlcFunc.h"

/*  cntwlc function, calculates number of words,chracters,lines,digits,special and sends it to the main function when called  */

int cntwlc(FILE *fileptr, char *stringptr)
{

#define WORD 1
#define FALSE 0

    int i,
        word = FALSE,
        words = 0;

    int characters = 0;
    int alpha = 0;
    int lines = 0;
    int digits = 0;
    int special = 0;

    // if there is no file entered by the user, initiate computation for stdin.

    if (fileptr == NULL)
    {
        lines = 1;

        /*for loop using the getchar function.
          As long as there is a character from stdin and it is NOT the EOF key increments the characters variable by 1. */

        for (characters = 0; (i = getchar()) != EOF; characters++)
        {

            /*if the character is a new line increments the lines variable by 1. */

            if (i == '\n')
            {
                lines++;
            }

            /*stays inside of a word and sets the value to 1(true) until stdin encounters
             a space, new line, or tab. This way only words are counted and not
             every character. The word must also be alphabetic, using the isalpha function from ctype.h*/

            if (i == ' ' || i == '\n' || i == '\t')
            {
                word = FALSE;
            }
            else
            {
                if (isalpha(i) && word == FALSE)
                {
                    words++;
                    word = WORD;
                }

                // checks if the character is alphabetic using isalpha function from ctype.h, increments alpha variable by 1

                if (isalpha(i))
                {
                    alpha++;
                }

                // checks if the character is a digit using the isdigit function from ctype.h, increments digits variable by 1

                if (isdigit(i))
                {
                    digits++;
                }

                // checks if the character is neither alphabetic nor a digit, increments special variable by 1

                if (!isalpha(i) && !isdigit(i))
                {
                    special++;
                }
            }
        }
        // prints the table and the results for Lines, Words, Characters, Alphabetic, Digits, and Special Characters

        printf("\n\n---   Text Statistics:   ---\n\n");
        printf("Lines%18d\n", lines);
        printf("Words%18d\n", words);
        printf("Characters%13d\n", characters);
        printf("Alphabetic%13d\n", alpha);
        printf("Digits%17d\n", digits);
        printf("Special%16d\n", special);

        printf("\nThank you for using cntwlc1. Bye!\n");
    }
    else
    {

        /* follows the same logic as the code above but reads stats from files using the while loop and file pointer  */

        while ((i = fgetc(fileptr)) != EOF)
        {

            if (i != ' ' || i == ' ' || i == '\n')
            {
                characters++;
            }

            if (i == '\n')
            {
                lines++;
            }

            if (i == ' ' || i == '\n' || i == '\t')
            {
                word = FALSE;
            }

            else
            {

                if (isalpha(i) && word == FALSE)
                {
                    words++;
                    word = WORD;
                }

                if (isalpha(i))
                {
                    alpha++;
                }

                if (isdigit(i))
                {
                    digits++;
                }

                if (!isalpha(i) && !isdigit(i))
                {
                    special++;
                }
            }
        }

        // uses string pointer to print the names of the files in output

        printf("\n\n---   Text Statistics for %s:   ---\n\n", stringptr);
        printf("Lines%18d\n", lines);
        printf("Words%18d\n", words);
        printf("Characters%13d\n", characters);
        printf("Alphabetic%13d\n", alpha);
        printf("Digits%17d\n", digits);
        printf("Special%16d\n", special);
    }
    return 0;
}
