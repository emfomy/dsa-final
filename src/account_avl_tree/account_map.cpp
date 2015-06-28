////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.cpp                                                            //
// The of class AccountMap                                                    //
//                                                                            //
// Author: kevin<skypole211221@gmail.com>                                     //
//         emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////


#include "account_map.hpp"
#include "account.hpp"
////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

struct _Account {
  ID key;
  Account* data;

  _Account( const ID& id, const Plaintext& plaintext ) {
    key = id;
    data = new Account(id, plaintext);
  }
};

int string_cmp( const void* pa ,const void* pb ,void* para){
  return reinterpret_cast<const _Account*>(pa)->key.compare(
      reinterpret_cast<const _Account*>(pb)->key);
}

int score(ID a, ID b){
  int s = 0 ; 
  int la = a.length() ;
  int lb = b.length() ;
  int min = la < lb ? la : lb ; 
  int diff = la < lb ? lb - min : la - min ;
  
  for (int i = 0 ; i < diff ; i ++)
    s+= i ;
  for (int i = 0 ; i < min ; i ++)
    s+= a[i]!=b[i] ? min - i : 0 ;
  return s ;
}

////////////////////////////////////////////////////////////////////////////////
// The constructor of AccountMap                                              //
////////////////////////////////////////////////////////////////////////////////
AccountMap::AccountMap(){
  avl_tree = avl_create( string_cmp ,nullptr ,nullptr);
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of AccountMap                                               //
////////////////////////////////////////////////////////////////////////////////
AccountMap::~AccountMap(){
  avl_destroy (avl_tree, nullptr);
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
Account* AccountMap::At( const ID& id ){
  const avl_node *p;
  for (p = avl_tree->avl_root; p != NULL; ){
    ID& id2 = reinterpret_cast<_Account*>(p->avl_data)->key;
    int cmp = id.compare(id2);
    if (cmp < 0){
      p = p->avl_link[0];
    } else if (cmp > 0) {
      p = p->avl_link[1];
    } else  { /* |cmp == 0| */
      return reinterpret_cast<_Account*>(p->avl_data)->data;
    }
  }
  return nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// Access account by its ID                                                   //
//                                                                            //
// Input Parameters:                                                          //
// id: the ID                                                                 //
//                                                                            //
// Output Parameters:                                                         //
// pit: the pointer of iterator                                               //
//                                                                            //
// Return Value:                                                              //
// Target account if exists, null pointer if not exists                       //
////////////////////////////////////////////////////////////////////////////////
Account* AccountMap::At( const ID& id, void** pit ){
  const avl_node *p;
  for (p = avl_tree->avl_root; p != NULL; ){
    ID& id2 = reinterpret_cast<_Account*>(p->avl_data)->key;
    int cmp = id.compare(id2);
    if (cmp < 0){
      p = p->avl_link[0];
    } else if (cmp > 0) {
      p = p->avl_link[1];
    } else  { /* |cmp == 0| */
      *pit = p->avl_data;
      return reinterpret_cast<_Account*>(p->avl_data)->data;
    }
  }
  return nullptr;
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
void AccountMap::Existing( const ID& id ){
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
void AccountMap::Unused( const ID& id ){

}

////////////////////////////////////////////////////////////////////////////////
// Find existing IDs that matches the wildcard ID                             //
//   but is different from target account                                     //
//                                                                            //
// Input Parameters:                                                          //
// id: the wildcard ID                                                        //
//                                                                            //
// Ensure:                                                                    //
// Display all satisfying IDs to standand output,                             //
//   separated by ',' in ascending dictionary order                           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Find( const ID& id, const Account* account ){

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
bool AccountMap::Emplace( const ID& id, const Plaintext& plaintext ){
  const avl_node *p;
  bool r2 = true;
  for (p = avl_tree->avl_root; p != NULL; ){
    ID& id2 = reinterpret_cast<_Account*>(p->avl_data)->key;
    int cmp = id.compare(id2);
    if (cmp < 0) {
      p = p->avl_link[0];
    } else if (cmp > 0) {
      p = p->avl_link[1];
    } else { /* |cmp == 0| */
      r2 = false;
    }
  }
  if( r2 == true)
    avl_probe(avl_tree, new _Account(id, plaintext));
  return r2;
}

////////////////////////////////////////////////////////////////////////////////
// Erase an account of target iterator                                        //
//                                                                            //
// Parameters:                                                                //
// it: the iterator                                                           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Erase( void* it ){
  avl_delete(avl_tree, it) ;
}

}

// DSA_ACCOUNT_MAP_HPP_