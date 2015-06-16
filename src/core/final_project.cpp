////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// final_project.cpp                                                          //
// The main functions                                                         //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

#include "core.hpp"

using namespace std;
using namespace dsa;

////////////////////////////////////////////////////////////////////////////////
// Main function                                                              //
////////////////////////////////////////////////////////////////////////////////
int main( int argc, char const *argv[] ) {
  ID id1, id2;
  Plaintext passward1, passward2;
  Money money;

  ios::sync_with_stdio(false);

  // Read commands
  string str;
  while ( cin >> str ) {
    if ( str == "login" ) {
      cin >> id1 >> passward1;
      cout << endl;
    } else if ( str == "create" ) {
      cin >> id1 >> passward1;
      cout << endl;
    } else if ( str == "delete" ) {
      cin >> id1 >> passward1;
      cout << endl;
    } else if ( str == "merge" ) {
      cin >> id1 >> passward1 >> id2 >> passward2;
      cout << endl;
    } else if ( str == "deposit" ) {
      cin >> money;
      cout << endl;
    } else if ( str == "withdraw" ) {
      cin >> money;
      cout << endl;
    } else if ( str == "transfer" ) {
      cin >> id1 >> money;
      cout << endl;
    } else if ( str == "find" ) {
      cin >> id1;
      cout << endl;
    } else if ( str == "search" ) {
      cin >> id1;
      cout << endl;
    }
  }
}
