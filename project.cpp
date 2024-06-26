#include<iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include<cstring>
#include <time.h>
using namespace std;


class Person {
   protected:
      string name;
   public:
      Person(string n) {
         name = n;
      }
};



class Date {
private:
  int day;
  int month;
  int year;

public:
  Date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }

  int getDay() const {
    return day;
  }

  void setDay(int d) {
    day = d;
  }

  int getMonth() const {
    return month;
  }

  void setMonth(int m) {
    month = m;
  }

  int getYear() const {
    return year;
  }

  void setYear(int y) {
    year = y;
  }

  void print() const {
    cout << day << "/" << month << "/" << year << endl;
  }
  

};






class Time {
private:
  int hour;
  int minute;
  int second;

public:
  Time(int h, int m, int s) { // constructor
    hour = h;
    minute = m;
    second = s;
  }

  // getters and setters
  int getHour() const {
    return hour;
  }

  void setHour(int h) {
    hour = h;
  }

  int getMinute() const {
    return minute;
  }

  void setMinute(int m) {
    minute = m;
  }

  int getSecond() const {
    return second;
  }

  void setSecond(int s) {
    second = s;
  }

  void print() const { // print time in format "HH:MM:SS"
    cout << hour << ":" << minute << ":" << second << endl;
  }

  // advance the time by n seconds
  void advance(int n) {
    second += n;
    if (second >= 60) { // adjust minute if necessary
      minute += second / 60;
      second %= 60;
      if (minute >= 60) { // adjust hour if necessary
        hour += minute / 60;
        minute %= 60;
        if (hour >= 24) { // adjust hour if necessary
          hour %= 24;
        }
      }
    }
  }
};







class Mcqs{
	public:
    string statement;
    string option1;
    string option2;
    string option3;
    string option4;
    string answer;
	void getstatement()
	{
	//	cout<<"AB Kia"<<endl;
		cout<<statement<<endl;
		cout<<option1<<endl;
		cout<<option2<<endl;
		cout<<option3<<endl;
		cout<<option4<<endl;
	//	cout<<"answer is :"<<answer<<endl;
	cout<<endl;
	}

};

class truefalse{
public:
    string statement;
    string option1;
    string option2;
    string answer;
	void getstatement()
	{
		cout<<statement<<endl;
		cout<<option1<<endl;
		cout<<option2<<endl;
	//	cout<<"answer is :"<<answer<<endl;
	cout<<endl;
	}

};



class subjective{
public:
	
};



class Teacher : public Person {
	Date* date;
	Time* times;
    string subject;
    char email[50];
    char password[30];
	Mcqs* O;
	truefalse* A;
public:
    // Constructor
    Teacher( string s,string n) : Person(name) {
    	name=n;
        subject = s;
    }

    // Getter functions
    string getName() const {
        return name;
    }
    
void setName(string n) {
    name = n;
}


    string getSubject() {
        return subject;
    }

    // Setter functions
    void setSubject(string s) {
        subject = s;
    }
    
    
	void setPassword(char pass[])
	{
		for(int i=0;i<30;i++)
		password[i]=pass[i];
	}
	
	
    void setEmail() {
        int i = 0;
        while (name[i] != '\0') {
            email[i] = name[i];
            ++i;
        }
        email[i] = '@';
        ++i;
        email[i] = 'n';
        ++i;
        email[i] = 'u';
        ++i;
        email[i] = '.';
        ++i;
        email[i] = 'e';
        ++i;
        email[i] = 'd';
        ++i;
        email[i] = 'u';
        ++i;
        email[i] = '.';
        ++i;
        email[i] = 'p';
        ++i;
        email[i] = 'k';
        ++i;
        email[i] = '\0';
//        for(int i=0;i<50;i++)
//        {
//        	cout<<email[i];
//		}
//		cout<<endl;
    }

    // function to check if a character is uppercase
    bool isUpperCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        return false;
    }

    // function to check if a character is lowercase
bool isLowerCase(char c) {
    if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}


    // function to check if a character is a digit
bool isDigit(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}


    // function to check if a character is a special character

static bool isSpecialChar(char c) {
    // list of special characters allowed
    char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*'};
    int numSpecialChars = sizeof(specialChars) / sizeof(char);

    // check if the character matches any of the allowed special characters
    for (int i = 0; i < numSpecialChars; i++) {
        if (c == specialChars[i]) {
            return true;
        }
    }

    return false;
}












	
	void login ()
	{
		bool cm=false;
		char checkmail[50];
		cout<<"Enter the Email to login"<<endl;

		cin>>checkmail;
		

		for(int i=0;i<50;i++)
		{
			if(email[i]=='\0'||checkmail[i]=='\0')
			break;
			if(checkmail[i]!=email[i])
			{
				cm=false;
				break;
			}
			else
			cm=true;
		}
		if(cm==true)
		{
			cout<<"Email verified"<<endl;
		}
		else
		{
			cout<<"Enter the Email Again"<<endl;
			login();
		}
  // Get password from user and validate
    bool isValid = false;

    while (!isValid)
    {
        char password[30];
        cout << "Enter the Password" << endl;
        cin >> password;

        isValid = isValidPassword(password);

        if (!isValid)
        {
            cout << "Password is invalid. Please try again." << endl;
        }
        else
        {
            // Set the password using a setter method
            setPassword(password);
            isValid = true; // Set isValid to true to exit the loop
        }
    }
}

bool isValidPassword(char* pass)
{
    int length = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;

    for (int i = 0; pass[i] != '\0'; i++)
    {
        length++;
    }

    if (length >= 6)
    {
        for (int i = 0; i < length; i++)
        {
            if (pass[i] >= 'A' && pass[i] <= 'Z')
            {
                ++upper;
            }
            else if (pass[i] >= 'a' && pass[i] <= 'z')
            {
                ++lower;
            }
            else if (pass[i] >= '0' && pass[i] <= '9')
            {
                ++digit;
            }
        }

        if (upper >= 1 && lower >= 1 && digit >= 1)
        {
            cout << "The password is valid" << endl;
            return true;
        }
        else
        {
            if (upper < 1)
                cout << "The password is invalid because it does not have an uppercase letter" << endl;
            if (lower < 1)
                cout << "The password is invalid because it does not have a lowercase letter" << endl;
            if (digit < 1)
                cout << "The password is invalid because it does not have a digit" << endl;

            return false;
        }
    }
    else
    {
        cout << "The password is invalid because it must have at least 6 characters" << endl;
        return false;
    }
}


void makequiz()
{
	int choice;
	cout<<"You want to have a quiz of the students"<<endl;
	cout<<"1 for MCQs\n2 for True/False\n3 for subjective type questions"<<endl;
    cin>>choice;
    int allowedtime;
    cout<<"Enter the time you want to allow for the quiz"<<endl;
	cin>>allowedtime;
	  time_t start_time = time(NULL);  // Get the current time
   string line;
   ifstream myfile ("Questions for TestBank.txt");

   
   if (myfile.is_open())
   {
   	    while ((time(NULL) - start_time) < allowedtime) {
        // Wait for that seconds
    	
    	while ( getline (myfile , line) )
		{
			
     	if(choice==1)
     	{

        	if(line.find("2efcde9") != string::npos)
    		{

        	getline(myfile,O->statement);
    		getline(myfile,O->option1);
   			getline(myfile,O->option2);
   			getline(myfile,O->option3); 
   			getline(myfile,O->option4);
   		

//		   	if(line.find("option dabfac4") != string::npos)
//			{
//				getline(myfile,O->answer);
//			}
		O->getstatement();
	
		}

	}
		
		if(choice==2)
   		{
		if(line.find("b94d27b") != string::npos)
    	{
        getline(myfile,A->statement);
    	getline(myfile,A->option1);
   		getline(myfile,A->option2);
   		if(line.find("option dabfac4:") != string::npos)
		{
				getline(myfile,A->answer);
		}
			A->getstatement();
		}
		
		}
    }
}
     myfile.close ();
		
	}
	else
	{
		cout<<"unable to open file"<<endl;
		
	}


}

	
};









//class truefalse{
//	bool array1[10]={true,false,true,true,true,false,false,true,false,true};
//	bool answers[10];
//	int points;
//public:
//	truefalse(){
//		points=0;
//	}
//	
//	void TFQuiz() {
//		for(int i=0;i<10;i++)
//		{
//			cout<<"Enter the answer for true/false "<<i+1<<endl;
//			cin>>answers[i];
//		}
//		
//		for(int i=0;i<10;i++)
//		{
//			if(answers[i]==array1[i])
//			{
//				points++;
//			}
//		}
//		cout<<"Number of correct answers are : "<<points<<endl;
//	}
//	
//	void anskey()
//		{
//			cout<<"Answer key for the quiz is :"<<endl;
//			for(int i=0;i<10;i++)
//			{
//				cout<<"answer to the quiz is"<<array1[i]<<endl;
//				
//			}
//		}
//};
//
//
//class MCQs{
//	char array1[10]={'a', 'c', 'd', 'b', 'a', 'a', 'b', 'd', 'c', 'c'};
//	char answer[10];
//	int points;
//public:
//	MCQs(){
//		points=0;
//		}
//		void MCQQuiz()
//		{
//			for(int i=0;i<10;i++)
//			{
//			cout<<"Enter the answer for true/false "<<i+1<<endl;
//			cin>>answer[i];
//			}
//			for(int i=0;i<10;i++)
//			{
//			if(answer[i]==array1[i])
//			{
//				points++;
//			}
//		}
//		cout<<"Number of correct answers are : "<<points<<endl;
//		}
//		
//		void anskey()
//		{
//			cout<<"Answer key for the quiz is :"<<endl;
//			for(int i=0;i<10;i++)
//			{
//				cout<<"answer to the quiz is"<<array1[i]<<endl;
//				
//			}
//		}
//		
//	};
//	
//class subjective {
//    char key[100];
//    char answer[100];
//    int point;
//public:
//    // Constructor
//    subjective(char k[], char a[], int p) {
//        int i;
//        for (i = 0; k[i] != '\0'; i++) {
//            key[i] = k[i];
//        }
//        key[i] = '\0';
//        for (i = 0; a[i] != '\0'; i++) {
//            answer[i] = a[i];
//        }
//        answer[i] = '\0';
//        point = p;
//    }
//    // Compare string
//    bool compare(char str[]) {
//        int i;
//        for (i = 0; answer[i] != '\0' && str[i] != '\0'; i++) {
//            if (answer[i] != str[i]) {
//                return false;
//            }
//        }
//        return answer[i] == str[i];
//    }
//};
	
	


class SetEmail {
public:
    // function to check if a character is uppercase
    static bool isUpperCase(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    // function to check if a character is lowercase
    static bool isLowerCase(char c) {
        return (c >= 'a' && c <= 'z');
    }

    // function to check if a character is a digit
    static bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }

    // function to check if a character is a special character
    static bool isSpecialChar(char c) {
        // list of special characters allowed
        char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*'};
        int numSpecialChars = sizeof(specialChars) / sizeof(char);

        // check if the character matches any of the allowed special characters
        for (int i = 0; i < numSpecialChars; i++) {
            if (c == specialChars[i]) {
                return true;
            }
        }

        return false;
    }

    // function to get a password from the user
    static void getPassword(char* password) {
        cout << "Enter password: ";

        // read the password one character at a time
        char c;
        int i = 0;
        while ((c = cin.get()) != '\n') {
            // display asterisks instead of the actual password characters
            cout << "*";

            // store the password character in the password array
            password[i] = c;
            i++;
        }
        password[i] = '\0'; // add null terminator to the end of the password array
    }

    // function to check if a password is valid
    static bool isValidPassword(const char* password) {
        // check if password is at least 6 characters long
        if (strlen(password) < 6) {
            return false;
        }

        bool hasUpperCase = false;
        bool hasLowerCase = false;
        bool hasDigit = false;
        bool hasSpecialChar = false;

        // check each character of the password for the required types
        for (int i = 0; i < strlen(password); i++) {
            if (isUpperCase(password[i])) {
                hasUpperCase = true;
            } else if (isLowerCase(password[i])) {
                hasLowerCase = true;
            } else if (isDigit(password[i])) {
                hasDigit = true;
            } else if (isSpecialChar(password[i])) {
                hasSpecialChar = true;
            }
        }

        // check if password contains all the required types of characters
        if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
            return true;
        } else {
            return false;
        }
    }
};








class student {

    string rollno;
    string name;
    bool CS101;
    bool CS201;
    bool CS102;
    bool CS301;
    bool CS302;
    bool SE301;
    bool CS501;
    bool CS407;
    bool CS307;
    bool CS601;
    bool CS409;
    string email;
    char password[20];

public:


    void setRollno(const string& value) 
	{ 
	rollno = value;
	}
    void setName(const string& value) 
	{
	 name = value;
	}
    void setCS101(bool value) 
	{ 
	CS101 = value; 
	}
    void setCS201(bool value)
	{
	 CS201 = value; 
	}
    void setCS102(bool value) 
	{
	 CS102 = value; 
	}
    void setCS301(bool value) 
	{ 
	CS301 = value; 
	}
    void setCS302(bool value) 
	{ 
	CS302 = value; 
	}
    void setSE301(bool value) 
	{ 
	SE301 = value; 
	}
    void setCS501(bool value) 
	{ 
	CS501 = value; 
	}
    void setCS407(bool value) 
	{
	 CS407 = value; 
	}

    void setCS307(bool value) 
	{ 
	CS307 = value; 
	}
    void setCS601(bool value)
	{
	 CS601 = value; 
	}
    void setCS409(bool value) 
	{
	 CS409 = value; 
	}


    const string& getRollno() const { return rollno; }
    const string& getName() const { return name; }
    bool getCS101() const { return CS101; }
    bool getCS201() const { return CS201; }
    bool getCS102() const { return CS102; }
    bool getCS301() const { return CS301; }
    bool getCS302() const { return CS302; }
    bool getSE301() const { return SE301; }
    bool getCS501() const { return CS501; }
    bool getCS407() const { return CS407; }
    bool getCS307() const { return CS307; }
    bool getCS601() const { return CS601; }
    bool getCS409() const { return CS409; }
    
    void setEmail() {
        email = rollno +"@nu.edu.pk";
    } 
//    void setEmail()
//	{
//    	int i = 0;
//    	while(i<8)
//    	{
//        	email = rollno;
//        	++i;
//    	}
//    	email[i] = '@';
//    	++i;
//    	email[i] = 'n';
//    	++i;
//    	email[i] = 'u';
//    	++i;
//    	email[i] = '.';
//    	++i;
//    	email[i] = 'e';
//    	++i;
//    	email[i] = 'd';
//    	++i;
//    	email[i] = 'u';
//    	++i;
//    	email[i] = '.';
//    	++i;
//    	email[i] = 'p';
//    	++i;
//    	email[i] = 'k';
//    	++i;
//    	email[i] = '\0';
//	}


    
      
    
    
    
    void course_offering()
    {
    	cout<<"\t\t>>>>>Courses offered to the student<<<<<"<<endl;
    	cout<<"Programming Fundamentals"<<endl;
    	cout<<"Object Oriented Programming"<<endl;
    	cout<<"Introduction To Computing"<<endl;
    	cout<<"Data Structures"<<endl;
    	cout<<"Analysis of Algorithms"<<endl;
    	cout<<"Software Requirements Engineering"<<endl;
    	cout<<"Research Methodology"<<endl;
    	cout<<"Big Data Analytics"<<endl;
    	cout<<"Artificial Intelligence"<<endl;
    	cout<<"Deep Learning"<<endl;
    	cout<<"Digital Image Processing"<<endl;
	}
    
    
    void course_registered ()
    {
    cout<<"\t\t>>>>>>>Courses regested<<<<<<"<<endl;
    if(CS101==true)
    cout<<"Programming Fundamentals"<<endl;
    if(CS201==true)
    cout<<"Object Oriented Programming"<<endl;
    if(CS102==true)
    cout<<"Introduction To Computing"<<endl;
    if(CS301==true)
    cout<<"Data Structures"<<endl;
    if(CS302==true)
    cout<<"Analysis of Algorithms"<<endl;
    if(SE301==true)
    cout<<"Software Requirements Engineering"<<endl;
    if(CS501==true)
    cout<<"Research Methodology"<<endl;
    if(CS407==true)
    cout<<"Big Data Analytics"<<endl;
    if(CS307==true)
    cout<<"Artificial Intelligence"<<endl;    
	if(CS601==true)
    cout<<"Deep Learning"<<endl;
    if(CS409==true)
    cout<<"Digital Image Processing"<<endl;	
	}
	
	void setPassword(char setpass[])
	{
		for(int i=0;i<30;i++)
		password[i]=setpass[i];
	}
		
void login()
{
    bool cm = false;
    char checkmail[50];
    cout << "Enter the Email to login" << endl;
    cin >> checkmail;

    for (int i = 0; i < 50; i++)
    {
        if (email[i] == '\0' || checkmail[i] == '\0')
            break;
        if (checkmail[i] != email[i])
        {
            cm = false;
            break;
        }
        else
            cm = true;
    }
    if (cm == true)
    {
        cout << "Email verified" << endl;
    }
    else
    {
        cout << "Enter the Email Again" << endl;
        login();
        return;
    }

    // Get password from user and validate
    bool isValid = false;

    while (!isValid)
    {
        char password[30];
        cout << "Enter the Password" << endl;
        cin >> password;

        isValid = isValidPassword(password);

        if (!isValid)
        {
            cout << "Password is invalid. Please try again." << endl;
        }
        else
        {
            // Set the password using a setter method
            setPassword(password);
            isValid = true; // Set isValid to true to exit the loop
        }
    }
}

bool isValidPassword(char* pass)
{
    int length = 0;
    int upper = 0;
    int lower = 0;
    int digit = 0;

    for (int i = 0; pass[i] != '\0'; i++)
    {
        length++;
    }

    if (length >= 6)
    {
        for (int i = 0; i < length; i++)
        {
            if (pass[i] >= 'A' && pass[i] <= 'Z')
            {
                ++upper;
            }
            else if (pass[i] >= 'a' && pass[i] <= 'z')
            {
                ++lower;
            }
            else if (pass[i] >= '0' && pass[i] <= '9')
            {
                ++digit;
            }
        }

        if (upper >= 1 && lower >= 1 && digit >= 1)
        {
            cout << "The password is valid" << endl;
            return true;
        }
        else
        {
            if (upper < 1)
                cout << "The password is invalid because it does not have an uppercase letter" << endl;
            if (lower < 1)
                cout << "The password is invalid because it does not have a lowercase letter" << endl;
            if (digit < 1)
                cout << "The password is invalid because it does not have a digit" << endl;

            return false;
        }
    }
    else
    {
        cout << "The password is invalid because it must have at least 6 characters" << endl;
        return false;
    }
}
};




int main() {

        string line;
 
	
	int ts;
	cout<<"If Teacher then enter 1 and if student then enter 2"<<endl;
	cin>>ts;
	if(ts==1)
	{
		cout<<"You have to login in the system"<<endl;

    string na;
    string subject;
	
    // get teacher name from user
    cout << "Enter teacher name: "<<endl;
    cin>>na;
        // create teacher object
    Teacher teacher( subject,na);
	teacher.setName(na);
    // get subject from user
    cout << "Enter subject: "<<endl;
    cin >> subject;



    // set teacher email
    teacher.setEmail();
    // login
    teacher.login();
    teacher.makequiz();

    return 0;
}

	if (ts==2)
	{
		cout<<"You have to login in the system"<<endl;
		    const int MAX_STUDENTS = 216;
    student students[MAX_STUDENTS];
    int numStudents = 0;
    ifstream inputFile("Course Registration Data - Sheet1.csv");

    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
        return 1;
    }


    const int MAX_ROWS = 216; // Maximum number of rows to read
    int row = 0;

    while (getline(inputFile, line)) {
        if (row >= MAX_ROWS) {
           // cout << "Maximum number of rows exceeded!" << endl;
            break;
        }

        stringstream lineStream(line);
        string cell;
        int col = 0;
        student newStudent;

        while (getline(lineStream, cell, ',')) {
            switch (col) {
                case 1:
                    newStudent.setRollno(cell);
                    break;
                case 2:
                    newStudent.setName(cell);
                    break;
                case 3:
                    newStudent.setCS101(cell == "TRUE");
                    break;
                case 4:
                    newStudent.setCS201(cell == "TRUE");
                    break;
                case 5:
                    newStudent.setCS102(cell == "TRUE");
                    break;
                case 6:
                    newStudent.setCS301(cell == "TRUE");
                    break;
                case 7:
                    newStudent.setCS302(cell == "TRUE");
                    break;
                case 8:
                    newStudent.setSE301(cell == "TRUE");
                    break;
                case 9:
                    newStudent.setCS501(cell == "TRUE");
                    break;
                case 10:
                    newStudent.setCS407(cell == "TRUE");
                    break;
                case 11:
                    newStudent.setCS307(cell == "TRUE");
                    break;
                case 12:
                    newStudent.setCS601(cell == "TRUE");
                    break;
                case 13:
                    newStudent.setCS409(cell == "TRUE");
                    break;
                default:
                    break;
            }
            col++;
        }

        students[numStudents] = newStudent;
        numStudents++;
        row++;
    }

    inputFile.close();

//    for (int i = 0; i < numStudents; i++) {
//        cout << "Student " << i + 1 << ":" << endl;
//        cout << "  Rollno: " << students[i].getRollno() << endl;
//        cout << "  Name: " << students[i].getName() << endl;
//        cout << "  CS101: " << students[i].getCS101() << endl;
//        cout << "  CS201: " << students[i].getCS201() << endl;
//        cout << "  CS102: " << students[i].getCS102() << endl;
//        cout << "  CS301: " << students[i].getCS301() << endl;
//        cout << "  CS302: " << students[i].getCS302() << endl;
//        cout << "  SE301: " << students[i].getSE301() << endl;
//        cout << "  CS501: " << students[i].getCS501() << endl;
//        cout << "  CS407: " << students[i].getCS407() << endl;
//        cout << "  CS307: " << students[i].getCS307() << endl;
//        cout << "  CS601: " << students[i].getCS601() << endl;
//        cout << "  CS409: " << students[i].getCS409() << endl;
//        cout<<endl;
//    		}




   // bool isValid = getpassword(password);
cout<<students[124].getRollno();
students[124].getName();


students[124].setEmail();
students[124].login();
students[124].course_offering();
//students[124].course_registered();
   
	}
return 0;
}