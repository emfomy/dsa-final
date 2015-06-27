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
class Account* AccountMap::At( const IDptr id ) {
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
class Account* AccountMap::At( const IDptr id, void** pit ) {
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
int calculate_score( IDptr a, IDptr b ) {
  int len_a = strlen(a);
  int len_b = strlen(b);
  int s = 0;

  int L = (len_a < len_b) ? len_a:len_b;
  int dL = abs(len_a - len_b);

  s = dL * (dL - 1) / 2;
  for (int i = L-1; i >= 0; --i) {
    s += ((a[i] == b[i]) ? 0:(L-i));
  }

  return s;
}

// Insert an id into vector
void insert_id_to_vector( 
    vector<IDptr>& list_id,
    vector<int>& list_score,
    int state,
    IDptr id,
    int score
) {

  int size = list_id.size();

  if (size < 10) {
    list_id.push_back(nullptr);
    list_score.push_back(-1);
  }

  if (state == 0) {
    int i = size - 2;
    while (i >= 0 && score <= list_score[i]) {
      list_score[i+1] = list_score[i];
      list_id[i+1] = list_id[i];
      --i;
    }
    list_id[i+1] = id;
    list_score[i+1] = score;
  } else {
    int i = size - 2;
    while (i >= 0 && score < list_score[i]) {
      list_score[i+1] = list_score[i];
      list_id[i+1] = list_id[i];
      --i;
    }
    list_id[i+1] = id;
    list_score[i+1] = score;
  }
}

void AccountMap::Existing( const IDptr id ) {
  vector<IDptr> list_id;
  vector<int> list_score;
  int target_score = 1;
  int num_compare = strlen(id) - 1;
  int score_temp;
  SkipListNode* front;
  SkipListNode* back;

  // Set the iteratro go to front and back
  Find(id, front);
  back = Next(front);

  // Stop when get enough data, or two iterator are at the end
  while ((*(front->data_id) != '!' || *(back->data_id) != '{') && \
         (list_id.size() != 10 || list_score[10] > target_score)
  ) {

    // First move front iteratro
    while (*(front->data_id) != '!' && \
          (num_compare == 0 || strncmp(id, front->data_id, num_compare) == 0)
    ) {
      score_temp = calculate_score(id, front->data_id);
      if (list_id.size() < 10 || score_temp <= list_score.back()) {
        insert_id_to_vector(list_id, list_score, 0, front->data_id, score_temp);
      }
    }
    
    // If get enough data, stop
    if (list_id.size() == 10 && list_score[10] <= target_score) break;
    
    // If data is not enough, move back iterator
    while (*(back->data_id) != '{' && \
          (num_compare == 0 || strncmp(id, back->data_id, num_compare) == 0)
          ) {
      score_temp = calculate_score(id, back->data_id);
      if (list_id.size() < 10 || score_temp < list_score.back()) {
        insert_id_to_vector(list_id, list_score, 0, back->data_id, score_temp);
      }
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
    cout << list_id[i];
  }
  cout << endl;

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
bool next_string( IDptr text, int min_len, int max_len, int& cur_len ) {
  if (cur_len < max_len) {
    text[cur_len] = '0';
    cur_len += 1;
    text[cur_len] = '\0';
    return true;
  }

  while (text[cur_len-1] == 'z') {
    cur_len -= 1;
    text[cur_len] = '\0';
    if (cur_len == min_len) {
      return false;
    }
  }

  text[cur_len-1] += 1;
  return true;
}

void AccountMap::Unused( const IDptr id ) {
  int target_score = 1;
  int len = strlen(id);
  int min_len = len - 1;
  int max_len = (len+1 < 100) ? (len+1):100;
  int cur_len = min_len;
  int output = 0;
  bool comma = false;
  SkipListNode* temp;
  
  IDptr test = new ID;
  strncpy(test, id, min_len);
  test[min_len] = '\0';

  while (output < 10) {
    if (next_string(test, min_len, max_len, cur_len)) {
      if (calculate_score(test, id) == target_score) {
        if (comma) {
          cout << ',';
        }
        cout << test;
        comma = true;
        output += 1;
      } 
    } else {
      target_score += 1;
      min_len = (min_len == 0) ? 0:(min_len-1);
      test[min_len] = '\0';
      if (max_len != 100 &&
          (max_len+1-len)*(max_len+len)/2 <= target_score &&
          !Find(test, temp))
      {
        max_len += 1;
      }
    }
  }
  cout << endl;

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

void AccountMap::Find( const IDptr id, const class Account* account ) {
  IDptr id_avoid = account->id();
  SkipListNode* node = Next(ninf);

  int i = 0;
  while (id[i] != '*' && id[i] != '?' && id[i] != '\0') {
    ++i;
  }

  IDptr id_key = new ID;
  bool key_not_used = true;
  if (i > 0) {
    strncpy(id_key, id, i);
    id_key[i] = '\0';
    Find(id_key, node);
    node = Next(node);
    key_not_used = false;
  }

  bool comma = false;
  while (*(node->data_id) != '{' && (key_not_used || \
         strncmp(id_key, node->data_id, i) == 0)) {
    if (match_recursion(id, node->data_id) && \
        id_avoid != node->data_id) {
      if (comma) {
        cout << ',';
      }
      cout << node->data_id;
      comma = true;
    }
    node = Next(node);
  }

  cout << endl;

}

////////////////////////////////////////////////////////////////////////////////
// Insert an account                                                          //
//                                                                            //
// Parameters:                                                                //
// account: target account                                                    //
////////////////////////////////////////////////////////////////////////////////
void AccountMap::Insert( class Account* account ) {
  IDptr id = account->id();
  Insert(id, account);
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
