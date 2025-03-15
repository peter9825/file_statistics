# file_statistics
 
- This program is a command-line utility written in C that counts the number of lines, words, characters, alphabetic characters, digits,
  and special characters from standard input or from files provided as command-line arguments. It is a simplified version of the Unix wc command,
  tailored for educational purposes.




# Features

- Multiple Input Sources:
  Process text from standard input (stdin) when no file is provided,
  or from one or more files specified on the command line.

- Comprehensive Statistics
  Counts and displays:
  - Lines
  - Words
  - Characters
  - Alphabetic Characters
  - Digits
  - Special Characters

 - User-Friendly Output:
   Provides clear output with headers and formatted statistics,
   making the text analysis results easy to understand.




# Installation

   - To compile the project, make sure you have GCC installed and simply run: make
   - To clean up the object files, run: make clean
   - To analyze a file (e.g., sample.txt), run: ./cntwlc1 sample.txt
   - If you run the executable without any arguments, it will default to reading from standard input: ./cntwlc1
     After running the above command, you will be prompted to enter text.
     Type your text and press Ctrl+D (on Unix/Linux/macOS) or Ctrl+Z (on Windows) when finished.
     The program will then display the statistics for the entered text.


 

 
