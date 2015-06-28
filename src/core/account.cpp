////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account.cpp                                                                //
// The class Account                                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "account.hpp"
#include <openssl/md5.h>
#include "history_map.hpp"

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
Account::Account( const ID& id, const Plaintext plaintext ) {
  MD5(
      reinterpret_cast<const unsigned char*>(plaintext.c_str()),
      plaintext.length(),
      reinterpret_cast<unsigned char*>(&ciphertext_)
  );
  history_map_ = new HistoryMap(id);
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of Account                                                  //
////////////////////////////////////////////////////////////////////////////////
Account::~Account() {
  delete history_map_;
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
  Ciphertext tmp = 0;
  MD5(
      reinterpret_cast<const unsigned char*>(plaintext.c_str()),
      plaintext.length(),
      reinterpret_cast<unsigned char*>(&tmp)
  );
  return (ciphertext_ == tmp);
}

////////////////////////////////////////////////////////////////////////////////
// Transfer money to target account                                           //
//                                                                            //
// Parameters:                                                                //
// that:  target account                                                      //
// money: the amount of money to transfer                                     //
////////////////////////////////////////////////////////////////////////////////
void Account::Transfer( Account* that, const Money money ) {
  this->money_ -= money;
  that->money_ += money;
  this->history_map_->Insert(that->history_map_, money);
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
void Account::Search( const ID& id ) {
  history_map_->Search(id);
}

}
