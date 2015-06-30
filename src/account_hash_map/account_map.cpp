////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.cpp                                                            //
// The  class AccountMap                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "account_map.hpp"
#include <iostream>
#include "account.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The array of characters                                                    //
////////////////////////////////////////////////////////////////////////////////
const char kNextChar[] = {
     0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
     0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
     0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
    '1','2','3','4','5','6','7','8','9','A', 0 , 0 , 0 , 0 , 0 , 0 ,
     0 ,'B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z','a', 0 , 0 , 0 , 0 , 0 ,
     0 ,'b','c','d','e','f','g','h','i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x','y','z', 0 , 0 , 0 , 0 , 0 , 0
};
const char static NextChar( const char c ) {
  return kNextChar[static_cast<size_t>(c)];
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of AccountMap                                              //
////////////////////////////////////////////////////////////////////////////////
AccountMap::AccountMap() :
    _AccountMap(),
    existing_queue_(IDExistingCompare(idptr_)),
    wildcard_queue_(IDWildcardCompare()) {
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
Account* AccountMap::At( const ID& id ) {
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
Account* AccountMap::At( const ID& id, void** ppit ) {
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
bool AccountMap::Emplace( const ID& id, const Plaintext plaintext ) {
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
// Parameters:                                                                //
// id: the ID                                                                 //
//                                                                            //
// Ensure:                                                                    //
// Display best satisfying IDs to standand output, separated by ','           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Existing( const ID& id ) {
  // Change id
  idptr_ = &id;

  // Find best satisfying IDs
  for ( auto& pair : *this ) {
    existing_queue_.push(&pair.first);
    if ( existing_queue_.size() > kNumRecommend ) {
      existing_queue_.pop();
    }
  }

  // Display IDs
  if ( !existing_queue_.empty() ) {
    cout << *existing_queue_.top();
    existing_queue_.pop();
  }
  while ( !existing_queue_.empty() ) {
    cout << ',' << *existing_queue_.top();
    existing_queue_.pop();
  }
}

////////////////////////////////////////////////////////////////////////////////
// Display unused IDs                                                         //
//                                                                            //
// Parameters:                                                                //
// id: the ID                                                                 //
//                                                                            //
// Ensure:                                                                    //
// Display best satisfying IDs to standand output, separated by ','           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Unused( const ID& id ) {
  // Change id
  idptr_ = &id;

  // Find best satisfying IDs
  int num = 0;
  int len = id.size();
  ID tmp;

  // Score 1
  char cend = id[len-1];
  tmp = id;
  if ( len > 0 ) {
    tmp[len-1] = '\0';
    if ( Display(tmp, num) ) {
      return;
    }
  }
  tmp[len-1] = '0';
  for ( auto& ctmp = tmp[len-1]; ctmp < cend; ctmp = NextChar(ctmp) ) {
    if ( Display(tmp, num) ) {
      return;
    }
  }
  if ( len < kIDLength ) {
    tmp.push_back('0');
    for ( auto& ctmp = tmp[len]; ctmp != 0; ctmp = NextChar(ctmp) ) {
      if ( Display(tmp, num) ) {
        return;
      }
    }
    tmp.pop_back();
  }
  tmp[len-1] = NextChar(cend);
  for ( auto& ctmp = tmp[len-1]; ctmp < cend; ctmp = NextChar(ctmp) ) {
    if ( Display(tmp, num) ) {
      return;
    }
  }

  // while ( len <= kNumRecommend ) {
  //   break;
  // }
}

////////////////////////////////////////////////////////////////////////////////
// Find existing IDs that matches the wildcard ID                             //
//   but is different from target account                                     //
//                                                                            //
// Parameters:                                                                //
// id:      the wildcard ID                                                   //
// account: target account                                                    //
//                                                                            //
// Ensure:                                                                    //
// Display all satisfying IDs to standand output,                             //
//   separated by ',' in ascending dictionary order                           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Find( const ID& id, const Account* account ) {
  // Find satisfying IDs
  for ( auto& pair : *this ) {
    if ( pair.second.get() != account && Match(pair.first, id) ) {
      wildcard_queue_.push(&pair.first);
    }
  }

  // Display IDs
  if ( !wildcard_queue_.empty() ) {
    cout << *wildcard_queue_.top();
    wildcard_queue_.pop();
  }
  while ( !wildcard_queue_.empty() ) {
    cout << ',' << *wildcard_queue_.top();
    wildcard_queue_.pop();
  }
}

////////////////////////////////////////////////////////////////////////////////
// Display an ID                                                              //
//                                                                            //
// Input Parameters:                                                          //
// id:  the ID                                                                //
// num: the number of printted IDs                                            //
//                                                                            //
// Output Parameters:                                                         //
// num: the number of printted IDs                                            //
//                                                                            //
// Return Value:                                                              //
// whether the number of printted IDs reaches the limit or not                //
////////////////////////////////////////////////////////////////////////////////
bool AccountMap::Display( const ID& id, int& num ) {
  if ( !count(id) ) {
    if ( num ) {
      cout << ',' << id;
    } else {
      cout << id;
    }
    ++num;
  }
  return (num == kNumRecommend);
}

////////////////////////////////////////////////////////////////////////////////
// Check wildcard matching                                                    //
//                                                                            //
// Parameters:                                                                //
// id:       target ID                                                        //
// wildcard: the wildcard ID                                                  //
//                                                                            //
// Return Value:                                                              //
// whether the ID matches the wildcard ID or not                              //
////////////////////////////////////////////////////////////////////////////////
bool AccountMap::Match( const ID& id, const ID& wildcard ) {
  return Match(id.c_str(), wildcard.c_str());
}

////////////////////////////////////////////////////////////////////////////////
// Check wildcard matching                                                    //
//                                                                            //
// Parameters:                                                                //
// a:  target ID                                                              //
// w:  the wildcard ID                                                        //
// pa: the searching position in target ID                                    //
// pw: the searching position in the wildcard ID                              //
//                                                                            //
// Return Value:                                                              //
// whether the ID matches the wildcard ID or not                              //
////////////////////////////////////////////////////////////////////////////////
bool AccountMap::Match( const char* id, const char* wildcard ) {
  if ( *id == '\0' && *wildcard == '\0' ) {
    return true;
  }

  if ( *wildcard == '?' || *id == *wildcard ) {
    return Match(id+1, wildcard+1);
  }

  if ( *wildcard == '*' ) {
    if ( *id == '\0' && *(wildcard+1) != '\0' ) {
      return false;
    } else {
      return (Match(id+1, wildcard) || Match(id, wildcard+1));
    }
  }
  return false;
}

}
