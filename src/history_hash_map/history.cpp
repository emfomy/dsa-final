////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history.cpp                                                                //
// The class History                                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history.hpp"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

// Initialize counter
Time History::counter_ = 0;

////////////////////////////////////////////////////////////////////////////////
// The constructor of History                                                 //
//                                                                            //
// Parameters:                                                                //
// money:     the amount of money changes                                     //
// direction: the transfer direction                                          //
////////////////////////////////////////////////////////////////////////////////
History::History( const Money money, bool direction ) {
  time_      = ++counter_;
  money_     = money;
  direction_ = direction;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of History                                                  //
////////////////////////////////////////////////////////////////////////////////
History::~History() {
}

////////////////////////////////////////////////////////////////////////////////
// Display this history                                                       //
//                                                                            //
// Parameters:                                                                //
// id: target ID                                                              //
//                                                                            //
// Ensure:                                                                    //
// Display 'no record' if no record exists                                    //
// Display all history with target ID to standand output, line by line        //
////////////////////////////////////////////////////////////////////////////////
void History::Display( const IDptr id ) {
  cout << (direction_ ? "To " : "From ") << id << ' ' << money_ << endl;
}

}
