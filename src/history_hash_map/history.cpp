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
// money: the amount of money changes                                         //
////////////////////////////////////////////////////////////////////////////////
History::History( const Money money ) {
  money_ = money;
  time_ = counter_++;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of History                                                  //
////////////////////////////////////////////////////////////////////////////////
History::~History() {
}

}
