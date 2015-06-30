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
#include <iostream>
#include <vector>
using namespace std;
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
  const avl_node *p;
  vector<Exist> record;
  p = avl_tree->avl_root;

  if (p->avl_link[0] != nullptr){
    ExistingInt(id, record, p->avl_link[0]);
  }

  Exist tmp;
  tmp.key = score(id, reinterpret_cast<_Account*>(p->avl_data)->key);
  tmp.id = reinterpret_cast<_Account*>(p->avl_data)->key;
  record.push_back(tmp);
  int r_size = record.size();

  for (int i =0 ; i< r_size-1 ; i++){
    for (int j = 0 ; j < r_size - i - 1 ; j++){
      if (record[j].key > record[j+1].key){
        swap(record[j],record[j+1]);
      }
    }
  }

  if ( r_size >10){
    record.pop_back();
  }

  if (p->avl_link[1] != nullptr){
    ExistingInt(id, record, p->avl_link[1]);
  }
  r_size = record.size();
  for(int i =0 ; i < r_size ; i++){
    cout << record[i].id << ',' ;
  }
}

void AccountMap::ExistingInt( const ID& id, vector<Exist>& r, avl_node* p){ 
  if (p->avl_link[0] != nullptr) { 
    ExistingInt(id, r, p->avl_link[0]); 
  }
  Exist tmp;
  tmp.key = score(id, reinterpret_cast<_Account*>(p->avl_data)->key);
  tmp.id = reinterpret_cast<_Account*>(p->avl_data)->key;
  r.push_back(tmp);
  int r_size = r.size();

  for (int i =0 ; i < r_size-1 ; i++){
    for (int j = 0 ; j < r_size - i - 1 ; j++){
      if (r[j].key > r[j+1].key){
        swap(r[j],r[j+1]);
      }
    }
  }
  if ( r_size >10) { r.pop_back(); }
  if (p->avl_link[1] != nullptr) { 
    ExistingInt(id, r, p->avl_link[1]); 
  }
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
  vector<ID> record;
  const avl_node* p;
  p = avl_tree->avl_root;

  if (p->avl_link[0] != nullptr) { 
    FindInt(id, account, p->avl_link[0], record); 
  }

  ID id2 = reinterpret_cast<_Account*>(p->avl_data)->key;
  int now = 0 ;
  int len = id.length();
  int len2 = id2.length();
  bool d = true;

  for (int i=0; i < len ; i++) { 
    if (id[i] == id2[now]) {
      now++;
    }else if (id[i] == '?') {
      if (now == len2){
        d = false ;
        break ;     
      }
      now++;
    }else if (id[i] == '*' && i != len-1 ) {
      if (now == len2){
        d = false ;
        break ;     
      }
      while (id[i+1] != id2[now] && now != len2) {
        now++;
      }
      if (now == len2){
        d = false ;
        break ;     
      }
    }else if (id[i] == '*' && i == len-1 ) {
      now++;
    }else {
      d = false ;
      break ; 
    }
  }

  if ( d && account != reinterpret_cast<_Account*>(p->avl_data)->data ){
    record.push_back(id2);
  }

  if (p->avl_link[1] != nullptr) { 
    FindInt(id, account, p->avl_link[1], record); 
  }

  int r_size = record.size();

  cout << record[0] <<endl;
  for ( int i = 1 ; i <r_size; i++) {
    cout<< ','<< record[i] ;
  }
  cout<<endl;
}
void AccountMap::FindInt( 
    const ID& id, const Account* account, avl_node* p,vector<ID>& record ){
  if (p->avl_link[0] != nullptr) { 
    FindInt(id, account, p->avl_link[0], record); 
  }

  ID id2 = reinterpret_cast<_Account*>(p->avl_data)->key;
  int now = 0 ;
  int len = id.length();
  int len2 = id2.length();
  bool d = true;

  for (int i=0; i < len ; i++) { 
    if (id[i] == id2[now]) {
      now++;
    }else if (id[i] == '?') {
      if (now == len2){
        d = false ;
        break ;     
      }
      now++;
    }else if (id[i] == '*' && i != len-1 ) {
      if (now == len2){
        d = false ;
        break ;     
      }
      while (id[i+1] != id2[now] && now != len2) {
        now++;
      }
      if (now == len2){
        d = false ;
        break ;     
      }
    }else if (id[i] == '*' && i == len-1 ) {
      now++;
    }else {
      d = false ;
      break ; 
    }
  }

  if ( d && account !=reinterpret_cast<_Account*>(p->avl_data)->data ) {
    record.push_back(id2);
  }

  if (p->avl_link[1] != nullptr) { 
    FindInt(id, account, p->avl_link[1], record); 
  }
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