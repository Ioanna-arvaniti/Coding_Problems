#include <iostream>
#include <vector>
#include <unordered_map> // Προσθέσαμε την απαραίτητη βιβλιοθήκη για το std::unordered_map

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // Χρησιμοποιούμε std::unordered_map για να αποθηκεύσουμε τα νούμερα και τα αντίστοιχα δείκτες τους
    vector<int> result;

    // Προσπελαύνουμε το vector nums
    for (int i = 0; i < nums.size(); i++) {
        // Ελέγχουμε αν υπάρχει ήδη το target - nums[i] στον χάρτη
        // Αν ναι, βρήκαμε το ζευγάρι που μας ενδιαφέρει
        // Αλλιώς, προσθέτουμε τον αριθμό και τον δείκτη του στον χάρτη για περαιτέρω αναφορά
        if (mp.find(target - nums[i]) != mp.end()) {
            result.push_back(mp[target - nums[i]]); // Προσθέτουμε τον δείκτη που βρήκαμε στο result
            result.push_back(i); // Προσθέτουμε τον τρέχοντα δείκτη i στο result
            break; // Βγαίνουμε από την επανάληψη, αφού βρήκαμε το ζευγάρι
        } else {
            mp[nums[i]] = i; // Προσθέτουμε τον αριθμό και τον δείκτη του στον χάρτη
        }
    }
        
    return result;
}

int main() {
    vector<int> arr = {1, 4, 6, 3, 8}; // Μπορούμε να αρχικοποιήσουμε το vector με αυτό τον τρόπο

    vector<int> res = twoSum(arr, 10);
    
    // Ελέγχουμε αν υπάρχουν στοιχεία στο result
    if (res.size() == 2) {
        cout << arr[res[0]] << " " << arr[res[1]] << endl; // Εκτυπώνουμε τα στοιχεία που αντιστοιχούν στους δείκτες που βρήκαμε
    } else {
        cout << "No two sum solution found." << endl; // Αν το result δεν έχει μέγεθος 2, τότε δεν βρέθηκε λύση
    }

    return 0;
}
