/*   This program will count the number of lines, words, characters from standard input or from
 *   file(s) listed as arguments on the command line using the function cntwlc.
 *
 *
 *
 */

#include "cntwlcFunc.h"

/*        Main Function takes in argc and *argv[] as parameters for command line arguments     */

int main(int argc, char *argv[])
{

    int i;

    // file pointer and fopen function is initialized to 1
    FILE *file = fopen(argv[1], "r");

    /*       If the user trys to only run the executable the program defaults to reading from stdin  */

    if (file == NULL && argc == 1)
    {
        printf("\n\nWelcome to cntwlc the CIS158 version of word count.\n\n");
        printf("This program will produce statistics about the text entered from standard\nin.\n\n");
        printf("Please enter your text now. When finished enter a control D to end.\n");

        cntwlc(NULL, NULL);
    }

    /*      If the user enters files, initiate for loop.                                */

    if (file != NULL && argc > 1)
    {

        /*     for loop iterates through command line arguments entered by the user.
         *     using the file pointer and the fopen function, the loop counter is set
         *     to open each file entered by the user in reading mode.
         */

        for (i = 1; i < argc; i++)
        {
            FILE *file = fopen(argv[i], "r");

            /*      if statement checks if a file entered by the user does not exist      */

            if (argc > 1 && file == NULL)
            {
                printf("\n       --- ERROR ---     \n");
                printf("The file '%s' cannot be found\n", argv[i]);
            }

            /*      if file(s) exists the function cntwlc is called which counts the number of lines,characters,words,digits,special characters
             *      in the file(s) and displays them for the user*/

            else
            {
                cntwlc(file, argv[i]);
            }
        }
        // fclose function closes files
        fclose(file);
        // prints thank you message
        printf("\nThank you for using cntwlc1. Bye!\n");

        return 0;
    }
}