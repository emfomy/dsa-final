////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.cpp                                                                //
// The class Account                                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "account.hpp"
#include <cstring>
#include "md5.h"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of Account                                                 //
//                                                                            //
// Parameters:                                                                //
// id:        the ID                                                          //
// plaintext: the plain password                                              //
////////////////////////////////////////////////////////////////////////////////
Account::Account( const ID id, const Plaintext plaintext ) {
  MD5 md5(plaintext);
  memcpy(id_, id, kIDLength+1);
  ciphertext_ = *reinterpret_cast<const Ciphertext*>(md5.result());
  history_map_ = new HistoryMap(id);
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Account                                                  //
////////////////////////////////////////////////////////////////////////////////
Account::~Account() {
  delete history_map_;
}

////////////////////////////////////////////////////////////////////////////////
// Get the starting pointer of ID                                             //
////////////////////////////////////////////////////////////////////////////////
IDptr Account::id() {
  return id_;
}

////////////////////////////////////////////////////////////////////////////////
// Check password correction                                                  //
//                                                                            //
// Parameters:                                                                //
// plaintext: the plain password                                              //
//                                                                            //
// Return Value:                                                              //
// true if the password is correct, false if not                              //
////////////////////////////////////////////////////////////////////////////////
bool Account::Login( const Plaintext plaintext ) {
  MD5 md5(plaintext);
  return (ciphertext_ == *reinterpret_cast<const Ciphertext*>(md5.result()));
}

////////////////////////////////////////////////////////////////////////////////
// Merge with target account                                                  //
//                                                                            //
// Parameters:                                                                //
// that: target account                                                       //
////////////////////////////////////////////////////////////////////////////////
void Account::Merge( Account* that ) {
  this->money_ += that->money_;
  this->history_map_->Merge(that->history_map_);
}

////////////////////////////////////////////////////////////////////////////////
// Display all history with target ID                                         //
//                                                                            //
// Parameters:                                                                //
// id: target ID                                                              //
//                                                                            //
// Ensure:                                                                    //
// Display all history with target ID to standand output, line by line        //
////////////////////////////////////////////////////////////////////////////////
void Account::Search( const ID id ) {
  history_map_->Search(id);
}

}
