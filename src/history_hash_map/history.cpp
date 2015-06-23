////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history.cpp                                                                //
// The class History                                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history.hpp"

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

}
