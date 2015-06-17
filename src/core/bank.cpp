////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// bank.cpp                                                                   //
// The class Bank                                                             //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "bank.hpp"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// Login to a specific account                                                //
//                                                                            //
// Parameters:                                                                //
// id:       the ID of target account                                         //
// password: the plain passward of target account                             //
//                                                                            //
// Ensure:                                                                    //
// Set the logined account as target account if permission allowed            //
////////////////////////////////////////////////////////////////////////////////
void Bank::Login( const ID id, const Plaintext password ) {
  cout << "Login " << id << ' ' << password << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Create a specific account with password                                    //
//                                                                            //
// Parameters:                                                                //
// id:       the ID of target account                                         //
// password: the plain passward of target account                             //
//                                                                            //
// Ensure:                                                                    //
// Create target account if the ID is unused                                  //
////////////////////////////////////////////////////////////////////////////////
void Bank::Create( const ID id, const Plaintext password ) {
  cout << "Create " << id << ' ' << password << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Delete a specific account with password                                    //
//                                                                            //
// Parameters:                                                                //
// id:       the ID of target account                                         //
// password: the plain passward of target account                             //
//                                                                            //
// Ensure:                                                                    //
// Delete target account if permission allowed                                //
////////////////////////////////////////////////////////////////////////////////
void Bank::Delete( const ID id, const Plaintext password ) {
  cout << "Delete " << id << ' ' << password << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Merge the second account into the first one                                //
//                                                                            //
// Parameters:                                                                //
// id1:       the ID of the first account                                     //
// password1: the plain passward of the first account                         //
// id2:       the ID of the second account                                    //
// password2: the plain passward of the second account                        //
//                                                                            //
// Ensure:                                                                    //
// Merge the second account into the first one and delete the second account  //
////////////////////////////////////////////////////////////////////////////////
void Bank::Merge( const ID id1, const Plaintext password1,
                  const ID id2, const Plaintext password2 ) {
  cout << "Merge " << id1 << ' ' << password1 << ' '
                   << id2 << ' ' << password2 << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Deposit money into the logined account                                     //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to deposit                                      //
//                                                                            //
// Ensure:                                                                    //
// Deposit the amount of money into the logined account                       //
////////////////////////////////////////////////////////////////////////////////
void Bank::Deposit( const Money money ) {
  cout << "Deposit " << money << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Withdraw money from the logined account                                    //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to withdraw                                     //
//                                                                            //
// Ensure:                                                                    //
// Withdraw the amount of money from the logined account                      //
//   if there is enough money                                                 //
////////////////////////////////////////////////////////////////////////////////
void Bank::Withdraw( const Money money ) {
  cout << "Withdraw " << money << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Transfer money from the logined account to a specific account              //
//                                                                            //
// Parameters:                                                                //
// id:    the ID of target account                                            //
// money: the amount of money to transfer                                     //
//                                                                            //
// Ensure:                                                                    //
// Transfer the amount of money from the logined account to target account    //
//   if there is enough money                                                 //
////////////////////////////////////////////////////////////////////////////////
void Bank::Transfer( const ID id, const Money money ) {
  cout << "Transfer " << id << ' ' << money << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Find all existing account IDs that matches the wildcard ID                 //
//   but is different from the logined account                                //
//                                                                            //
// Parameters:                                                                //
// id: the wildcard ID                                                        //
//                                                                            //
// Ensure:                                                                    //
// List all satisfying IDs separated by ',' in ascending dictionary order     //
////////////////////////////////////////////////////////////////////////////////
void Bank::Find( const ID id ) {
  cout << "Find " << id << endl;
}

////////////////////////////////////////////////////////////////////////////////
// Search all transfer history of the logined account                         //
//   from/to a specific account                                               //
//                                                                            //
// Parameters:                                                                //
// id: the target ID                                                          //
//                                                                            //
// Ensure:                                                                    //
// List all transfer history in ascending time order                          //
////////////////////////////////////////////////////////////////////////////////
void Bank::Search( const ID id ) {
  cout << "Search " << id << endl;
}

}
