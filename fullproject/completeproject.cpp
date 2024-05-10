#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include <limits>
#include <unordered_map>

const int MAX_ATTEMPTS=5;
using namespace std;

class Node {
public:
    string word;
    Node* next;
};

class LinkedList {
private:
    int current_size = 0;
    int current_ch = 0;

public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    void inserting(string newvalue) {
        if (isEmpty()) {
            Node* newnode = new Node();
            newnode->word = newvalue;
            newnode->next = nullptr;
            head = newnode;
            current_size++;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            Node* newnode = new Node();
            newnode->word = newvalue;
            temp->next = newnode;
            newnode->next = nullptr;
            current_size++;
        }
    }

  void display() {
     Node* temp = head;
     while (temp != nullptr) {
            cout << temp->word << " ";
           temp = temp->next;
        }
    }

     int size() {
         return current_size;
    }

    void charsize(string line) {
         current_ch = line.length();
    }

           int ch() {
        return current_ch;
    }
};
void duplicatenum( int nline,vector<LinkedList*>linkedlistline){
            unordered_map<string, int> wordCount;
            Node* temp =linkedlistline[nline - 1]->head;
            while (temp != nullptr) {
                wordCount[temp->word]++;
                temp = temp->next;
             }
            int duplicateCount = 0;
            

           
            for(auto &pair:wordCount){
        if(pair.second>1){
            duplicateCount++;
    
            }
            }
            
            cout << "\nThe number of duplicate words in this line is: " << duplicateCount << endl;
}
void readfromfile(ifstream &Myfile,vector<LinkedList*>&mylinkedlist){
    string line;
    //int i = 0;
    while (getline(Myfile, line)) {
          istringstream iss(line);
         string word;
         LinkedList* newList = new LinkedList();
        newList->charsize(line);
           while (iss >> word) {
            newList->inserting(word);
        }
            mylinkedlist.push_back(newList);
       // i++;
    }
}
int main(){
    vector<LinkedList*>linkedLists;

    ifstream inputFile("input.txt");
     if (!inputFile) {
         cout << "File not found." << endl;
        return 0;
    }
readfromfile(inputFile,linkedLists);

        cout << "Hello with our projects File in Data structure File" << endl;
    int invalidAttempts = 0;

   while (true) {
     if (invalidAttempts >= MAX_ATTEMPTS) {
            cout << "\n\033[1;31mYou have exceeded the maximum number of invalid attempts. Exiting the program...\033[0m"<< invalidAttempts << endl;
            break;
        }
        cout << "\nSelect your choice from the list:\n";
        cout << "1 - Show the entire file." << endl;
        cout << "2 - Enter the line number to show all attributes." << endl;
        cout << "3 - Exit the program." << endl;
        cout << "=======================================================" << endl;

        int menuChoice;
        cout << "Enter your choice: ";
        cin >> menuChoice;
 if (cin.fail()) { // Check if input is not an integer
            cout << "\n\033[0;34mError: Invalid input. Please enter a number.\033[0m" << invalidAttempts<< endl;
           cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the invalid input
            invalidAttempts++;

            continue;
        }

         if (menuChoice < 1 || menuChoice > 3) {
            cout << "\n\033[1;31mError: Invalid choice. Please enter a number between 1 and 3.\033[0m" << invalidAttempts<< endl;
            invalidAttempts++;
            continue;
        }

 if (menuChoice == 1) {
            cout << "Showing the entire file." << endl;
            for(auto dis:linkedLists){
                dis->display();
            }
            cout<<"\n\n";
            
        }

       // start for the choice number 2

else if(menuChoice==2){
 // Enter the line number to show all attributes

 
            int numberchoicein2;
            cout << "=======================================================" << endl;

            cout << "Enter the line number: ";
            cout<<"\033[0;34mNote:line between 1 - "<<linkedLists.size()<<"\033[0m"<<endl;
            cin >> numberchoicein2;
            if (cin.fail() || numberchoicein2 < 1 || numberchoicein2 > linkedLists.size()) {
                cout << "\n\033[1;31mError: Invalid input. Please enter a valid line number.\033[0m" << invalidAttempts <<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                invalidAttempts++;
                continue;
            }

 while (true)
 {          cout<<endl;
            cout << "1 - display the line ." << endl;
            cout << "2 - Number of characters in this line." << endl;
            cout << "3 - Number of duplicate words in this line." << endl;
            cout << "4 - Number of words in this line." << endl;
            cout << "5 - Exit from this Menu." << endl;

   int attributeChoice;
            cout << "Enter your choice: ";
            cin >> attributeChoice;
             if (cin.fail() || attributeChoice < 1 || attributeChoice > 5) {
            cout << "\n\033[1;31mError: Invalid input. Please enter a valid choice.\033[0m" <<  invalidAttempts<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            invalidAttempts++;
            continue;
        }
             if (attributeChoice == 1) {
    cout<<"the line is : ";
        LinkedList* selectedList = linkedLists[numberchoicein2 - 1];
      selectedList->display();
        cout<<endl;
    
 }

            else if (attributeChoice == 2) {
                 if (numberchoicein2 > 0 && numberchoicein2 <= linkedLists.size()) {
                    LinkedList* selectedList = linkedLists[numberchoicein2 - 1];
                    cout << "\nThe number of charecter in this line is: " << selectedList->ch() << endl;
                }
            }
            else if (attributeChoice == 3) {
            // show the duplicate Number in faild .
           duplicatenum(numberchoicein2 ,linkedLists);
            }
           
         if (attributeChoice == 4) {
                if (numberchoicein2 > 0 && numberchoicein2 <= linkedLists.size()) {
                    LinkedList* selectedList = linkedLists[numberchoicein2 - 1];
                    cout << "\nThe number of words in this line is: " << selectedList->size() << endl;
                }
            }

             else if (attributeChoice == 5) {
   cout<<"Exiting from the program...."<<endl;
    break;
 }

        }

        }
// ending of the choice number 2 



  if (menuChoice == 3) {
            cout << "Exiting the program..." << endl;
            break;
        }



   }//ending of while for the main header

}// ending of the main
