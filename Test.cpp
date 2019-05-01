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
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"}, c2610{"2610"}, c0406{"0406"}, c98765{"98765"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"} , g2610{"2610"}, g0406{"0406"}, g98765{"98765"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2610","2610"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2610","1234"), "0,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0406","0406"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0406","3657"), "0,1")      // 0 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1111","1112"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1212","1234"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8777","8778"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8777","7778"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345","12345"), "5,0")      	// 5 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12234","12324"), "3,2")      	// 3 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4444","1234"), "1,0")      		// 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0000","1234"), "0,0")      		// 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("433434","123456"), "2,0")     // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("433434","434343"), "2,4")     // 2 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12345678","87655678"), "4,0") // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2610","0406"), "0,2")      		// 0 bull, 2 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		
		.CHECK_EQUAL(play(c2610, g2610, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c2610, g0406, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c0406, g2610, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c0406, g0406, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c98765, g0406, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c2610, g98765, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).   
		.CHECK_EQUAL(play(c9999, g9999, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c9999, g0406, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c9999, g2610, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c0406, g98765, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long). 
		.CHECK_EQUAL(play(c98765, g2610, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).

		.CHECK_EQUAL(play(c9999, g9999, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g2610, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c0406, g9999, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c0406, g1234, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c9999, g1234, 4, 100), 101)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c12345, g98765, 5, 100), 101)  // guesser loses by running out of turns

		.CHECK_EQUAL(play(c9999, g9999, 5, 100), 0)      // chooser loses technically by choosing an illegal number (too short).
		.CHECK_EQUAL(play(c9999, g12345, 5, 100), 0)     // chooser loses technically by choosing an illegal number (too short).
		.CHECK_EQUAL(play(c12345, g9999, 5, 100), 101)     // guesser loses technically by making an illegal guess (too short).
		.CHECK_EQUAL(play(c12345, g98765, 4, 100), 0)    // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c1234, g2610, 4, 90), 91)    	 // guesser loses by running out of turns
		.CHECK_EQUAL(play(c0406, g9999, 4, 10), 11)    	 // guesser loses by running out of turns
		.CHECK_EQUAL(play(c0406, g1234, 4, 6), 7)    		 // guesser loses by running out of turns
		.CHECK_EQUAL(play(c9999, g1234, 4, 300), 301)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c12345, g98765, 5, 56), 57)  	 // guesser loses by running out of turns
		.CHECK_EQUAL(play(c9999, g9999, 4, 2), 1)      	 // guesser wins in one turn.
		;


		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true);  // smarty should always win in at most 100 turns!
		}

		testcase
		.CHECK_EQUAL(play(c1234, smarty, 4, 100) <= 100, true)  
		.CHECK_EQUAL(play(c9999, smarty, 4, 100) <= 100, true)
		.CHECK_EQUAL(play(c2610, smarty, 4, 100) <= 100, true)
		.CHECK_EQUAL(play(c0406, smarty, 4, 100) <= 100, true)

	;



    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}