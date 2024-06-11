#include<iostream>
#include<string>
using namespace std;

int main() {
    int row, column, size;

    // Είσοδος αριθμού γραμμών, στηλών και μη μηδενικών στοιχείων
    cout << "Enter the number of rows in the matrix: ";
    cin >> row;
    cout << "Enter the number of columns in the matrix: ";
    cin >> column;
    cout << "Enter the number of non zero elements in the matrix: ";
    cin >> size;

    // Έλεγχος εάν το μέγεθος του αραιού πίνακα είναι έγκυρο
    if (size > (row * column)) {
        cout << "Error: Number of non-zero elements cannot exceed the size of the matrix." << endl;
        return 1; // Επιστρέφουμε 1 για να υποδείξουμε ένα σφάλμα
    }

    // Εισαγωγή του πίνακα σε αραιή μορφή (τριάδα)
    int sparseMatrix[size][3];
    for (int i = 0; i < size; i++) {
        cout << "Enter the row index, column index, and value of element " << i + 1 << endl;
        cin >> sparseMatrix[i][0];
        cin >> sparseMatrix[i][1];
        cin >> sparseMatrix[i][2];
    }

    // Εμφάνιση του αραιού πίνακα
    cout << "Your sparse matrix is:\n";
    for (int i = 0; i < size; i++) {
        cout << sparseMatrix[i][0] << " " << sparseMatrix[i][1] << " " << sparseMatrix[i][2] << endl;
    }

    // Υπολογισμός της μετατροπής
    int transpose[size][3];
    int k = 0;
    for (int i = 0; i < column; i++) {
        for (int j = 0; j < size; j++) {
            if (sparseMatrix[j][1] == i) {
                transpose[k][0] = sparseMatrix[j][1];
                transpose[k][1] = sparseMatrix[j][0];
                transpose[k][2] = sparseMatrix[j][2];
                k++;
            }
        }
    }

    // Εμφάνιση της μετατροπής του αραιού πίνακα
    cout << "\n\nTranspose of sparse matrix is:\n";
    for (int i = 0; i < size; i++) {
        cout << transpose[i][0] << " " << transpose[i][1] << " " << transpose[i][2] << endl;
    }
    
    return 0;
}
