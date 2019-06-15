#include <iostream>
#include <vector>

using namespace std;

class Person{
    protected:
        string firstName;
        string lastName;
        int id;
    public:
        Person(string firstName, string lastName, int identification){
            this->firstName = firstName;
            this->lastName = lastName;
            this->id = identification;
        }
        void printPerson(){
            cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
        }
    
};

class Student :  public Person{
    private:
        vector<int> testScores;  
    public:
        /*  
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
          Student(string firstName, string lastName, int identification, vector<int> score): 
          Person(firstName, lastName, identification), testScores(score) {}
       
        /*  
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        char calculate();
};

char Student::calculate()
{
    char grade;
    int sum=0;
    float average;
    int n;
    n = testScores.size();
    for(int i=0; i<n; i++)
    {
        sum = sum + testScores[i];
    }
    average = sum/n;

    if (average>=90)
    grade = 'O';
    else if (average>=80)
    grade = 'E';
    else if (average>=70)
    grade = 'A';
    else if (average>=55)
    grade = 'P';
    else if (average>=40)
    grade = 'D';
    else if (average<40)
    grade = 'T';

    return grade;
}

int main() {
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++){
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}
