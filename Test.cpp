/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"}, c001("001"), c987654321{"987654321"}, c9876{"9876"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"}, g1{"1"}, g123456789{"123456789"},g9876{"9876"},
		inputEr{"jklj777"}, inputEr1{"-999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0000","9999"), "0,0")
		.CHECK_OUTPUT(calculateBullAndPgia("111","111"), "3,0")
		.CHECK_OUTPUT(calculateBullAndPgia("555","655"), "2,0")
		//.CHECK_OUTPUT(calculateBullAndPgia("001","1"), "0,1") 
		//.CHECK_OUTPUT(calculateBullAndPgia("010","1"), "0,1")     
       //         .CHECK_OUTPUT(calculateBullAndPgia("100","1"), "1,0")
		.CHECK_OUTPUT(calculateBullAndPgia("4","1"), "0,0") 
                .CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")
                .CHECK_OUTPUT(calculateBullAndPgia("01","10"), "0,2")
  		.CHECK_OUTPUT(calculateBullAndPgia("10","10"), "2,0")
                .CHECK_OUTPUT(calculateBullAndPgia("9876543210","9876543210"), "10,0")  
                .CHECK_OUTPUT(calculateBullAndPgia("987654321","123456789"), "1,8") 
	        .CHECK_OUTPUT(calculateBullAndPgia("666","11176"), "0,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("4567","7654"), "0,4") 
		.CHECK_OUTPUT(calculateBullAndPgia("4","7654"), "0,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("7","7654"), "1,0") 
		.CHECK_OUTPUT(calculateBullAndPgia("7","60"), "0,0") 
		//.CHECK_OUTPUT(calculateBullAndPgia("7777","77"), "2,0") 





	 	;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c001, g1, 3, 100), 101)     // guesser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c9999, g123456789, 4, 100),101 )     // guesser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c1234, g123456789, 9, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c9876, g9876, 4, 100), 1)//gusser wins in one turn
		.CHECK_EQUAL(play(c1234, g9999, 4, 57), 58)    // guesser loses by running out of turns
                .CHECK_EQUAL(play(c987654321, g123456789, 9, 12), 13)    // guesser loses by running out of turns 



		;

		testcase.setname("Play with smart guesser");

		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		
		RandomChooser randy1;
		SmartGuesser smarty1;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy1, smarty1, 4, 100)>100, false);  // smarty should always win in at most 100 turns!
		}

		RandomChooser randy5;
		SmartGuesser smarty5;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy5, smarty5, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		
		RandomChooser randy9;
		SmartGuesser smarty9;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy9, smarty9, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}