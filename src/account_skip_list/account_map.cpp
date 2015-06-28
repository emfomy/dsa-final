////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.cpp                                                            //
// The class AccountMap                                                       //
//                                                                            //
// Author: davidzan<davidzan830@gmail.com>                                    //
//         emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////
#include "dsa.hpp"
#include "account.hpp"
#include "skip_list_for_account.hpp"
#include "account_map.hpp"
#include <cmath>
#include <iostream>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of AccountMap                                              //
////////////////////////////////////////////////////////////////////////////////
AccountMap::AccountMap() : SkipList() {}

////////////////////////////////////////////////////////////////////////////////
// The destructor of AccountMap                                               //
////////////////////////////////////////////////////////////////////////////////
AccountMap::~AccountMap() { }

////////////////////////////////////////////////////////////////////////////////
// Access account by its ID                                                   //
//                                                                            //
// Parameters:                                                                //
// id: the ID                                                                 //
//                                                                            //
// Return Value:                                                              //
// Target account if exists, null pointer if not exists                       //
////////////////////////////////////////////////////////////////////////////////
class Account* AccountMap::At( const ID& id ) {
  SkipListNode* temp;

  if (Find(id, temp)) {
    return temp->data_account;
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
class Account* AccountMap::At( const ID& id, void** pit ) {
  SkipListNode* temp;
  if (Find(id, temp)) {
    *pit = temp;
    return temp->data_account;
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

// Score function
int calculate_score( ID& a, ID& b ) {
  int len_a = a.size();
  int len_b = b.size();
  int s = 0;
  int L = (len_a < len_b) ? len_a:len_b;
  int dL = abs(len_a - len_b);

  s = dL * (dL + 1) / 2;
  for (int i = L-1; i >= 0; --i) {
    s += ((a[i] == b[i]) ? 0:(L-i));
  }

  return s;
}

// Insert an id into vector
void insert_id_to_vector( 
    vector<ID*>& list_id,
    vector<int>& list_score,
    int state,
    ID& id,
    int score,
    int& size
) {

  if (size < 10) size += 1;

  if (state == 0) {
    int i = size - 2;
    while (i >= 0 && score <= list_score[i]) {
      list_score[i+1] = list_score[i];
      list_id[i+1] = list_id[i];
      --i;
    }
    list_id[i+1] = &id;
    list_score[i+1] = score;
  } else {
    int i = size - 2;
    while (i >= 0 && score < list_score[i]) {
      list_score[i+1] = list_score[i];
      list_id[i+1] = list_id[i];
      --i;
    }
    list_id[i+1] = &id;
    list_score[i+1] = score;
  }
}

void AccountMap::Existing( const ID& id ) {
  vector<ID*> list_id(10);
  vector<int> list_score(10);
  int target_score = 1;
  int num_compare = id.size() - 1;
  int score_temp;
  int size = 0;
  SkipListNode* front;
  SkipListNode* back;

  // Set the iteratro go to front and back
  Find(id, front);
  back = Next(front);

  // Stop when get enough data, or two iterator are at the end
  while ((front->data_id.front() != '!' || back->data_id.front() != '{') && \
         (size != 10 || list_score[10] > target_score)
  ) {

    // First move front iteratro
    while (front->data_id.front() != '!' && \
          (num_compare == 0 || id.compare(0, num_compare, front->data_id, 0, num_compare) == 0)
    ) {
      score_temp = calculate_score(id, front->data_id);
      if (size < 10 || score_temp <= list_score.back()) {
        insert_id_to_vector(list_id, list_score, 0, front->data_id, score_temp, size);
      }
      front = Previous(front);
    }
    
    // If get enough data, stop
    if (size == 10 && list_score[10] <= target_score) break;
    
    // If data is not enough, move back iterator
    while (back->data_id.front() != '{' && \
          (num_compare == 0 || id.compare(0, num_compare, back->data_id, 0, num_compare) == 0)
          ) {
      score_temp = calculate_score(id, back->data_id);
      if (size < 10 || score_temp < list_score.back()) {
        insert_id_to_vector(list_id, list_score, 1, back->data_id, score_temp, size);
      }
      back = Next(back);
    }

    // Add the tolerent to score, adjust the number of string to compare
    target_score += 1;
    if (num_compare > 0) num_compare -= 1;
  }

  // Print the result
  bool comma = false;
  for (int i = 0; i < (int)list_score.size(); ++i) {
    if (comma) {
      cout << ',';
    }
    cout << *(list_id[i]);
    comma = true;
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

// Change text to the next one accrording to dictionary order
// The part that can be changed is between string[min_len] and string[max_len-1]
// Retrun true if succeed, false if the next one doesn't exist
bool next_string( ID& text, int min_len, int max_len ) {
  if (text.size() < max_len) {
    text.append('0');
    return true;
  }

  while (text.back() == 'z') {
    text.pop_back();
    if (text.size() == min_len) {
      return false;
    }
  }

  char c = text.back();
  if (c == '9') {
    text.back() = 'A';
  } else if (c == 'Z') {
    text.back() = 'a';
  } else {
    text.back() += 1;
  }
  return true;
}

void AccountMap::Unused( const ID& id ) {
  int target_score = 1;
  int len = id.size();
  int min_len = len - 1;
  int max_len = (len+1 < 100) ? (len+1):100;
  int output = 0;
  bool comma = false;
  SkipListNode* temp;
  
  string test = id.substr(0, min_len);

  while (output < 10) {
    if (calculate_score(test, id) == target_score && !Find(test, temp)) {
      if (comma) {
        cout << ',';
      }
      cout << test;
      comma = true;
      output += 1;
    } 
    if (!next_string(test, min_len, max_len)) {
      target_score += 1;
      min_len = (min_len == 0) ? 0:(min_len-1);
      if (max_len != 100 &&
          (max_len+1-len+1)*(max_len+1-len)/2 <= target_score)
      {
        max_len += 1;
      }
      test = id.substr(0, min_len);
    }
  }

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

// Return whether two char* is matching, a may have wildcard
bool match_recursion( const char* a, const char* b ) {
  if (*a == '\0' && *b == '\0') {
    return true;
  }

  if (*a == '?' || *a == *b) {
    return match_recursion(a+1, b+1);
  }

  if (*a == '*' && *(a+1) != '\0' && *b == '\0') {
    return false;
  }

  if (*a == '*') {
    return match_recursion(a+1, b) || match_recursion(a, b+1);
  }

  return false;
}

void AccountMap::Find( const ID& id, const class Account* account ) {
  SkipListNode* node = Next(ninf);

  int i = id.find_first_of("?*");

  string id_key;
  bool key_not_used = true;
  if (i == string::npos) {
    id_key = id;
    key_not_used = false;
  } else if (i > 0) {
    id_key = id.substr(0, i);
    key_not_used = false;
  }

  bool comma = false;
  while (node->data_id.front() != '{' && (key_not_used || \
         node->data_id.compare(0, i, id_key) == 0)) {
    if (match_recursion(id.c_str(), node->data_id.c_str()) && \
        account != node->data_account) {
      if (comma) {
        cout << ',';
      }
      cout << node->data_id;
      comma = true;
    }
    node = Next(node);
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
 bool AccountMap::Emplace( const ID& id, const Plaintext& plaintext ) {
  if(Insert(id, plaintext)) {
    return true;
  }
  return false;
}

////////////////////////////////////////////////////////////////////////////////
// Erase an account of target iterator                                        //
//                                                                            //
// Parameters:                                                                //
// it: the iterator                                                           //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Erase( void* it ) {
  Remove((SkipListNode*)it);
}

}
