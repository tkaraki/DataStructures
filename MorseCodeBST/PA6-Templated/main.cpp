/*******************************************************************************                                        *
 * Date:  3/30/2019                                                                     *
 *                                                                             *
 * Description: Morse Code
 ******************************************************************************/

#include "BST.h"


int main()
{
	BST<char,string> morseCode;
	cout << "          Morse Code Tool          " << endl;
	cout << "___________________________________" << endl << endl;

	cout << "PRINT CODE:" << endl;
	morseCode.print();
	cout << endl << endl;

	cout << "CONVERT CODE:" << endl;
	morseCode.convertText();
	cout << endl << endl;
}
