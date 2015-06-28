////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.cpp                                                            //
// The  class AccountMap                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "account_map.hpp"
#include <stdexcept>
#include "account.hpp"
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of AccountMap                                              //
////////////////////////////////////////////////////////////////////////////////
AccountMap::AccountMap() : _AccountMap() {
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of AccountMap                                               //
////////////////////////////////////////////////////////////////////////////////
AccountMap::~AccountMap() {
}

////////////////////////////////////////////////////////////////////////////////
// Access account by its ID                                                   //
//                                                                            //
// Parameters:                                                                //
// id: the ID                                                                 //
//                                                                            //
// Return Value:                                                              //
// Target account if exists, null pointer if not exists                       //
////////////////////////////////////////////////////////////////////////////////
Account* AccountMap::At( const IDptr id ) {
  auto it = find(id);
  return ((it != end()) ? it->second.get() : nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// Access account by its ID                                                   //
//                                                                            //
// Input Parameters:                                                          //
// id: the ID                                                                 //
//                                                                            //
// Output Parameters:                                                         //
// ppit: the double pointer of iterator                                       //
//                                                                            //
// Return Value:                                                              //
// Target account if exists, null pointer if not exists                       //
////////////////////////////////////////////////////////////////////////////////
Account* AccountMap::At( const IDptr id, void** ppit ) {
  auto pit = new AccountMap::iterator(find(id));
  *ppit = reinterpret_cast<void*>(pit);
  return ((*pit != end()) ? (*pit)->second.get() : nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// Construct and insert an account                                            //
//                                                                            //
// Parameters:                                                                //
// id:        the ID                                                          //
// plaintext: the plain password                                              //
//                                                                            //
// Return Value:                                                              //
// true if insert succeeded, false if the ID already exists                   //
////////////////////////////////////////////////////////////////////////////////
bool AccountMap::Emplace( const IDptr id, const Plaintext plaintext ) {
  auto& uniptr = (*this)[id];
  bool success = (!uniptr);
  if ( success ) {
    uniptr.reset(new Account(id, plaintext));
  }
  return success;
}

////////////////////////////////////////////////////////////////////////////////
// Erase an account of target iterator                                        //
//                                                                            //
// Parameters:                                                                //
// pit: the pointer of iterator                                               //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Erase( void* pit ) {
  erase(*reinterpret_cast<AccountMap::iterator*>(pit));
}

////////////////////////////////////////////////////////////////////////////////
// Display existing IDs                                                       //
//                                                                            //
// Input Parameters:                                                          //
// id: the ID                                                                 //
//                                                                            //
// Ensure:                                                                    //
// Display best satisfying IDs to standand output, separated by ','           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Existing( const IDptr id ) {
}

////////////////////////////////////////////////////////////////////////////////
// Display unused IDs                                                         //
//                                                                            //
// Input Parameters:                                                          //
// id: the ID                                                                 //
//                                                                            //
// Ensure:                                                                    //
// Display best satisfying IDs to standand output, separated by ','           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Unused( const IDptr id ) {
}

////////////////////////////////////////////////////////////////////////////////
// Find existing IDs that matches the wildcard ID                             //
//   but is different from target account                                     //
//                                                                            //
// Input Parameters:                                                          //
// id:      the wildcard ID                                                   //
// account: target account                                                    //
//                                                                            //
// Ensure:                                                                    //
// Display all satisfying IDs to standand output,                             //
//   separated by ',' in ascending dictionary order                           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Find( const IDptr id, const Account* account ) {
}

}
