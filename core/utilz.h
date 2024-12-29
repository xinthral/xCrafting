#ifndef UTILZ_H
#define UTILZ_H

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <random>
#include <stdio.h>
#include <string>
#include <string.h>     // strtok
#include <vector>

namespace Utilz {
  /*!
   * @brief   Generates a random UUID (Universally Unique Identifier) in string format.
   *
   * @details This function uses the standard library's random number generator to create a random UUID.
   *          The generated UUID consists of 32 hexadecimal characters, displayed in the format 
   *          "XXXXXXXX-XXXX-XXXX-XXXX-XXXXXXXXXXXX", where each 'X' represents a random hexadecimal digit.
   *
   * @return  A random UUID in string format.
  */
  std::string CreateUUID();

  /*!
   * @brief   Extracts the file name from a given file path.
   *
   * @details This function takes a file path as input and returns the file name without the extension.
   *
   * @param   file The file path from which to extract the file name.
   * 
   * @return  The file name without the extension.
  */
  std::string FileName(const char *);

  /*!
   * @brief   Extracts a specified number of characters from the file name of a given file path.
   *
   * @details This function takes a file path and a length as input, extracts the file name 
   *          from the path, and then returns the first 'length' characters of the file name.
   *
   * @param   length  The number of characters to extract from the file name.
   * @param   file    The file path from which to extract the file name.
   * 
   * @return  The first 'length' characters of the file name without the extension.
  */
  std::string FileName(int, const char *);

  /*!
   * @brief   Converts file paths between DOS and Unix formats.
   *
   * @details This function takes an integer direction and a string filename as input.
   *          If the direction is 1, it converts the file path from DOS format to Unix format.
   *          If the direction is not 1, it converts the file path from Unix format to DOS format.
   *          The converted file path is stored back in the 'filename' parameter.
   *
   * @param   direction   The conversion direction. 1 for DOS to Unix, any other value for Unix to DOS.
   * @param   filename    The file path to be converted. The converted file path is stored back in this parameter.
   *
   * @return  This function does not return a value. The 'filename' parameter is modified by reference.
  */
  void FilePathConversion(int, std::string&);

  /*!
   * @brief   Extracts the first 'length' characters from a given string.
   *
   * @details This function takes a string and a length as input, and returns the first 'length' characters of the input string.
   *          If the input string is shorter than the specified length, the function will return the entire input string.
   *
   * @param   length  The number of characters to extract from the input string.
   * @param   input   The input string from which to extract characters.
   * 
   * @return  The first 'length' characters of the input string. If the input string is shorter than 'length', the entire input string is returned.
  */
  std::string HeadString(int, std::string);

  /*!
   * @brief   Generates a random string of a specified length.
   *
   * @details This function uses the standard library's random number generator to create a random string of a given length.
   *          The generated string consists of uppercase and lowercase letters.
   *
   * @param   length  The length of the random string to generate.
   * 
   * @return  A random string of the specified length.
  */
  std::string RandomString(int);

  /*!
   * @brief   Converts a string into a vector of strings, splitting the input by spaces and newline characters.
   *
   * @details This function takes a string as input and splits it into a vector of strings using spaces and newline characters as delimiters.
   *          The resulting vector is then stored in the 'output' parameter.
   *
   * @param   input   The input string to be split.
   * @param   output  The vector where the split strings will be stored.
   *
   * @return  This function does not return a value. The 'output' parameter is modified by reference.
  */
  void StringToArray(std::string, std::vector<std::string>&);

  /*!
   * @brief   Strips all spaces from a given string.
   *
   * @details This function takes a string as input and removes all spaces from it.
   *          The modified string is then stored back in the 'input' parameter.
   *
   * @param   input   The input string from which to remove spaces. The modified string is stored back in this parameter.
   *
   * @return  This function does not return a value. The 'input' parameter is modified by reference.
  */
  void Strip(std::string&);

  /*!
   * @brief   Extracts the last 'length' characters from a given string.
   *
   * @details This function takes a string and a length as input, and returns the last 'length' characters of the input string.
   *          If the input string is shorter than the specified length, the function will return the entire input string.
   *
   * @param   length  The number of characters to extract from the end of the input string.
   * @param   input   The input string from which to extract characters.
   * 
   * @return  The last 'length' characters of the input string. If the input string is shorter than 'length', the entire input string is returned.
  */
  std::string TailString(int, std::string);

  /*!
   * @brief   Retrieves the current date and time in a formatted string.
   *
   * @details This function uses the standard library functions to get the current date and time,
   *          formats it according to the provided format string, and returns it as a string.
   *
   * @return  The current date and time in the format "ddd mmm dd hh:mm:ss".
  */
  std::string TimeStamp();

  /*!
   * @brief   Prompts the user for input and returns the entered text.
   *
   * @details This function displays a message to the user, waits for the user to enter input,
   *          and then returns the entered text. The function clears any existing input in the
   *          input buffer before displaying the message.
   *
   * @param   message The message to display to the user before prompting for input.
   *
   * @return  The text entered by the user.
  */
  std::string UserInput(std::string);
}; // namespace Utilz

/*!
 * @brief We don't talk about this...
*/
extern "C" {
  int addIt(int, int);
};

#endif // UTILZ_H //
