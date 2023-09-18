#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <istream>
#include <fstream>
#include <vector>

using namespace std;
vector<char> attendanceStatus;
vector <string> status_v;
struct students{
  string firstName,lastName,id,gender;
} stud[20];
struct data{
  vector <string> fName_v,lName_v,id_v,gender_v,crs1,crs2,crs3,crs4,crs5;
} readfile;
void appendStudents();
void adminLogIn();
void adminView();
void markAttendance();
int  deleteStudent();
void clearData();
void registerStudent();
void display();
void search();
void studentLogIn();
void announceClassDays();
void seeClassSchedual();
void prepareAttendance(vector <string>);
void updateSchedual();
void registeredCourses();
int goBack(int to = 1);
int setting();
void delay();
void delay2();
void developersInfo();

// Main Function
int main(){
  int choice;
  appendStudents();
  system("cls");
  cout<<"\t\t\tWELCOME TO STUDENT ATTENDANCE MANAGEMENT SYSTEM\n\n";
  cout<<"1 ADMIN LOGIN\n";
  cout<<"2 STUDENT LOGIN\n";
  cout<<"3 DEVELOPERS INFO\n";
  cout<<"0 EXIT\n";
  retry:
  cout<<"\nENTER CHOICE: ";
  cin>>choice;
  switch(choice){
    case 1: adminLogIn();break;
    case 2: studentLogIn();break;
    case 3: developersInfo();break;
    case 0: break;
    default: cout<<"\nInvalid Input!!!";goto retry;break;
  }
  return 0;
}

// HERE,THE |appendStudents()| FUNCTION READS DATA FROM THE FILE IN THE COMPUTER AND PREPARE FOR THE UPCOMING PROCESS.
void appendStudents(){
  readfile.fName_v.clear(); readfile.lName_v.clear(); readfile.gender_v.clear();readfile.id_v.clear();
  readfile.crs1.clear();readfile.crs2.clear();readfile.crs3.clear();readfile.crs4.clear();readfile.crs5.clear();
  fstream file1("documnet.txt");
  fstream file2("Courses.txt");
  if(!file1.good() || !file2.good()){
    file1.open("documnet.txt",ios::out);
    file2.open("Courses.txt",ios ::out);
    file1<<"FIRST_NAME\tLAST_NAME\tID\tSEX";
    file2<<"FOP-II\t\tDCCN\t\tDBS\t\tDLD\t\tECONOMICS";
    file1.close();file2.close();
  }else{
    file1.close();file2.close();
  }
  file1.open("documnet.txt",ios::in); file2.open("Courses.txt",ios::in);
  if(file1.is_open()){
    string f_name,l_name,id,gender;
    while(!file1.eof()){
      file1>>f_name>>l_name>>id>>gender;
      readfile.fName_v.push_back(f_name);
      readfile.lName_v.push_back(l_name);
      readfile.gender_v.push_back(gender);
      readfile.id_v.push_back(id);
    }
    file1.close();
  }else{
    cout<<"\nERROR: OPENING FILE FAILD WHILE APPENDING STUDENT!\n";exit(1);
  }
  if(file2.is_open()){
    string c1,c2,c3,c4,c5;
    while (!file2.eof()){
      file2>>c1>>c2>>c3>>c4>>c5;
      readfile.crs1.push_back(c1);
      readfile.crs2.push_back(c2);
      readfile.crs3.push_back(c3);
      readfile.crs4.push_back(c4);
      readfile.crs5.push_back(c5);
    }
    file2.close();
  }else{
    cout<<"\nERROR: OPENING FILE FAILD WHILE APPENDING STUDENT!\n";exit(1);
  }
}

// ADMIN COULD BE ANY PERSON, CLASS REP OR LECTURE(PROFESSOR) WHO HAVE AUTHORIZED ACCESS TO MANIPULATE THE DATA.
void adminLogIn(){
  system("cls");
  string adminPassWord, systemDeafaultPassWord ="1234";
  fstream file("password.txt");
  if(!file.good()){
    file.open("password.txt",ios :: out);
    file<<systemDeafaultPassWord;
    file.close();
  }else{
    file.close();
  }
  file.open("password.txt",ios::in);
  if(file.is_open()){
    while(getline(file,adminPassWord));
    file.close();
  }else{
    cout<<"\nERROR: OPENING PASSWORD FILE!\n";exit(0);
  }
  int attemptCount = 0,timer = 5;
  tryAgain:
  string password;
  cout<<"ENTER PASSWORD:";
  cin>>password;
  if(password == adminPassWord){
    adminView();
  }else{
    if(attemptCount == 2){
      delay();
      while(true){
        system("cls");
        cout<<"\n+--------------------------  ACCESS DENIED :  Wait "<<timer<<" second --------------------------+";
        for(int a = 0 ; a<4; ++a){
          for(int i = 0; i < 100000;++i){
            for(int j = 0; j < 1000; ++j){

            }
            for(int k = 0; k < 100; ++k){

            }
          }
        }
        --timer;
        if(timer == 0){
          attemptCount = 0;
          timer = 5;
          break;
        }
      }
      system("cls");
      goto tryAgain;
      //exit(0);
    }else{
      ++attemptCount;
    }
    cout<<"\n\tWRONG PASSWORD!\t\tREMAING ATTEMPT:"<<(3-attemptCount)<<endl;goto tryAgain;
  }
}

// HERE ADMIN CAN MAKE REGISTRATION,ATTENDANCE MARKING, DELETING STUDENT AND SO ON.
void adminView(){
  appendStudents();
  system("cls");
    cout<<"--------------------------------------- ||     WELCOME TO ADMIN VIEW     || -------------------------------------------\n\n";
    int choice;
    cout<<"1 REGISTRATION\n";
    cout<<"2 STUDENTS PROFILE\n";
    cout<<"3 SEARCH\n";
    cout<<"4 MARK ATTENDANCE\n";
    cout<<"5 MANAGE CLASS SCHEDUAL\n";
    cout<<"6 DELETE STUDENT\n";
    cout<<"7 CLEAR DATA\n"; // MAKES ALL THE DATA EMPTY AND AVAILABLE FOR NEW PROCESS.
    cout<<"8 SETTING\n";
    cout<<"0 BACK\n";
    retry:
    cout<<"\nENTER CHOICE: ";
    cin>>choice;
    switch(choice){
      case 1: registerStudent();break;
      case 2: display();break;
      case 3: search();break;
      case 4: markAttendance();break;
      case 5: announceClassDays();break;
      case 6: deleteStudent();break;
      case 7: clearData();break;
      case 8: setting();break;
      case 0: main();break;
      default: cout<<"\nInvalid Input!!!";goto retry;break;
    }
}

// ONCE THE STUDENT IS REGISTERD IN THE DATABASE HE/SHE CAN ACCESS THE STUDENT LOG IN FUNCTION.
void studentLogIn(){
  system("cls");
  if(readfile.fName_v.size() == 1){
    cout<<"\nSTUDENTS ARE NOT REGISTERED YET!\n";
    goBack(2);exit(0);
  }

  string userId;
  cout<<"\nID: ";
  cin.ignore();
  getline(cin,userId);

          // First Check Whether The Student Is Registered Or Not Before Going To Another Process.
  for(int i = 0; i < readfile.id_v.size(); ++i){
    if(userId == readfile.id_v[i]){
      delay();
      system("cls");
      cout<<"\t\t\t"<<readfile.fName_v[i]<<" "<<readfile.lName_v[i]<<"\n\n";
      break;
    }else if(i == (readfile.id_v.size()-1) && userId != readfile.id_v[i]){
      delay();
      cout<<"\nERROR: STUDENT NOT FOUND!\n";goBack(2);exit(0);
    }
  }

  // If The Student Is Already Register, Then He Can Accesses |studentLogIn()| Function Here.
  cout<<"\n1 PROFILE";
  cout<<"\n2 SEE CLASS SCHEDUAL";
  cout<<"\n0 Back"<<endl;

  logInAgain:
  int choice;
  cout<<"\nEnter: ";
  cin>>choice;
  switch(choice){
    case 0: main();break;
    case 1: delay();
            system("cls");
            for(int i = 0; i < readfile.id_v.size(); ++i){
              if(readfile.id_v[i] != userId){
                continue;
              }else{
                cout<<"\t\t\tPROFILE\n\n\n";
                cout<<"\t\t"<<readfile.fName_v[0]<<"  :  "<<readfile.fName_v[i]<<endl;
                cout<<"\t\t"<<readfile.lName_v[0]<<"  :  "<<readfile.lName_v[i]<<endl;
                cout<<"\t\t"<<readfile.gender_v[0]<<"  :  "<<readfile.gender_v[i]<<endl;
                cout<<"\t\t"<<readfile.id_v[0]<<"  :  "<<readfile.id_v[i]<<endl;
                break;
              }
            }break;
    case 2: delay();
            system("cls");
            seeClassSchedual();
            break;
    default: cout<<"\n\t\tINVALID INPUT\n";goto logInAgain;
  }
  cout<<"\n\n";
  goBack(2);
  exit(0);
}

// STUDENT(S) REGISTRATION GOES HERE.
void registerStudent(){
  delay();
  system("cls");
  cout<<"\t\t\tREGISTRATION FORM\n\n";
  int n;
  cout<<"HOW MANY STUDENTS TO REGISTER?: ";
  cin>>n;
  fstream Myfile;
  Myfile.open("documnet.txt",ios::app);
  if(Myfile.is_open()){
    for(int i = 0; i < n; ++i){
    cout<<"STUDENT"<<i+1<<" : "<<endl;
    cout<<"FIRST_NAME: ";
    cin>>stud[i].firstName;
    cout<<"LAST_NAME: ";
    cin>>stud[i].lastName;
    cout<<"SEX: ";
    cin>>stud[i].gender;

    checkId:                    // IT CKECKS IF THE ID IS ALREADY IN USE OR NOT WHILE REGISTERING NEW STUDENTS.
    cout<<"ID: ";
    cin>>stud[i].id;
    for(const string &b: readfile.id_v){
      if(stud[i].id == b){
        cout<<"\nID ALREADY EXISTS!.\n";goto checkId;
      }
    }
    Myfile<<endl<<stud[i].firstName<<"\t"<<stud[i].lastName<<"\t"<<stud[i].id<<"\t"<<stud[i].gender;
    }
    Myfile.close();
    appendStudents();
    cout<<"\n\nREGISTRATION FINISHED SUCCESSFULY!!"<<endl; // REGISTRATION ENDS.
  }else{
    cout<<"\nERROR: OPENING FILE FAILED!"<<endl;
  }
  cout<<"\n\n\n";
  goBack(1);
  exit(0);
};

// HERE THE ADMIN CAN SEE ALL THE REGISTERD STUDENTS.
void display(){
  appendStudents();
  system("cls");
  cout<<"\t\t\tREGISTERED STUDENTS LIST"<<endl<<endl;
  if(readfile.fName_v.size() == 1){
      cout<<"\n\t\t\t --------------";
      cout<<"\n\t\t\t|              |";
      cout<<"\n\t\t\t|  EMPTY FILE  |";
      cout<<"\n\t\t\t|              |";
      cout<<"\n\t\t\t --------------"<<endl;
  }else{
    cout<<"1 ALPHABETIZED\n";
    cout<<"2 All LIST\n";
    cout<<"3 BACK\n";
    int choice;
    retry:
    cout<<"\n\nENTER CHOICE: ";
    cin>>choice;
    if(choice==1){
      delay();
      system("cls");
      cout<<"\t\t\tREGISTERED STUDENTS LIST"<<endl<<endl;
      char letter;
      cout<<"\n\nALPHABET: ";
      cin>>letter;
      char convertToUpperCase = static_cast<char>(toupper(letter));
      delay();
      system("cls");
      cout<<"\t\t\tALPHABET: "<<letter<<endl<<endl;
      ifstream file("documnet.txt");
      if(file.is_open()){
        string line;
        for(int i = 0 ;i < readfile.fName_v.size(); ++i){
          for(int j = 0; j < readfile.fName_v.size(); ++j){
            if(j!=0 && (readfile.fName_v[j][0] == letter || readfile.fName_v[j][0] == convertToUpperCase || static_cast<char>(toupper(readfile.fName_v[j][0])) == letter) ){
              break;
            }else if(j == (readfile.fName_v.size() - 1) && letter != readfile.fName_v[j][0]){
              file.close();
              cout<<"\nNO STUDENT FOUND!"<<endl;goBack(1);exit(0);
            }
          }
          if(i == 0){
            cout<<readfile.fName_v[i]<<"\t"<<readfile.lName_v[i]<<"\t"<<readfile.id_v[i]<<"\t"<<readfile.gender_v[i]<<endl;
          }else if((readfile.fName_v[i][0] == letter) || (readfile.fName_v[i][0] == convertToUpperCase) || (static_cast<char>(toupper(readfile.fName_v[i][0])) == letter)){
            cout<<readfile.fName_v[i]<<"\t\t"<<readfile.lName_v[i]<<"\t\t"<<readfile.id_v[i]<<"\t\t"<<readfile.gender_v[i]<<endl;
          }
        }
        file.close();
      }
    }else if(choice == 2){
      delay();
      system("cls");
      cout<<"\t\t\tALL REGISTERED STUDENTS LIST"<<endl<<endl;
      for(int i = 0; i < readfile.fName_v.size(); ++i){
        if(i == 0){
          cout<<readfile.fName_v[i]<<"\t"<<readfile.lName_v[i]<<"\t"<<readfile.id_v[i]<<"\t"<<readfile.gender_v[i]<<endl;
        }else{
          cout<<readfile.fName_v[i]<<"\t\t"<<readfile.lName_v[i]<<"\t\t"<<readfile.id_v[i]<<"\t\t"<<readfile.gender_v[i]<<endl;
        }
      }
    }else if(choice == 3){
     adminView();exit(0);
    }else{
      cout<<"\nINVALID INPUT!\n";goto retry;
    }
  }
  cout<<"\n\n\n";
  goBack(1);
  exit(0);
}

// IF THE ADMIN WANTS TO CHECK WHETHER THE STUDENT IS REGISTERD OR NOT, HE COMES HERE AND TYPES HIM/HER ID.
void search(){
  delay();
  system("cls");
  string id;
  cout<<"\t\t\tSEARCH FOR STUDENT PROFILE\n\n";
  cout<<"ID: ";
  cin.ignore();getline(cin,id);
  delay();
  system("cls");
  for(int i = 0; i < readfile.id_v.size(); ++i){
    if(i == (readfile.id_v.size()-1) && (readfile.id_v[i] != id)){
      cout<<"\nSTUDENT HAS NOT BEEN REGISTERED YET!";
    }else if(readfile.id_v[i] != id){
      continue;
    }else{
      cout<<readfile.fName_v[0]<<"\t"<<readfile.lName_v[0]<<"\t"<<readfile.gender_v[0]<<"\t"<<readfile.id_v[0]<<endl;
      cout<<readfile.fName_v[i]<<"\t\t"<<readfile.lName_v[i]<<"\t\t"<<readfile.gender_v[i]<<"\t\t"<<readfile.id_v[i]<<endl;
      break;
    }
  }
  cout<<"\n\n\n";
  goBack(1);
  exit(0);
}

// THIS FUNCTION DELETE THE STUDENT FROM THE FILE IF THE STUDENT IS ALREADY REGISTERD.
int deleteStudent(){
  delay();
  system("cls");
  cout<<"\t\t\tDELETE\n\n";
  if(readfile.fName_v.size() == 1){
    cout<<"\nTHERE IS NO STUDENT RECORD YET!"<<endl;
    cout<<"\n\n\n";
  }else{
    string id;
    cout<<"ID: ";
    cin.ignore();getline(cin,id);
    for(int i = 0; i < readfile.fName_v.size(); i++){
        if(i == (readfile.id_v.size()-1) && readfile.id_v[i] != id){ // Checking the last id.
          delay();
          system("cls");
          cout<<"\nERROR : STUDENT  NOT FOUND!\n";
          cout<<"\n\n\n";
          break;
        }else if(readfile.id_v[i] == id){
        delay();
        char verify;
        cout<<"\nAre you sure you want to delete "<<readfile.fName_v[i]<<" "<<readfile.lName_v[i]<<" ? (y/n): ";
        cin>>verify;
        if((verify == 'N') || (verify == 'n')){break;};
        delay();
        cout<<"\n"<<readfile.fName_v[i]<<" "<<readfile.lName_v[i]<<" DELETED SUCCESSFULLY!"<<endl;
        readfile.fName_v.erase(readfile.fName_v.begin()+i);
        readfile.lName_v.erase(readfile.lName_v.begin()+i);
        readfile.id_v.erase(readfile.id_v.begin()+i);
        readfile.gender_v.erase(readfile.gender_v.begin()+i);
        
    // Removing the First line of the list
        readfile.fName_v.erase(readfile.fName_v.begin()+0);
        readfile.lName_v.erase(readfile.lName_v.begin()+0);
        readfile.id_v.erase(readfile.id_v.begin()+0);
        readfile.gender_v.erase(readfile.gender_v.begin()+0);
    // Writting the first line of the list
        fstream Myfile("documnet.txt",ios:: out);
        if(Myfile.is_open()){
          Myfile<<"FIRST_NAME\tLAST_NAME\tID\tSEX";
          Myfile.close();
        }else{
          cout<<"\nERROR: OPENING FILE FAILED!"<<endl;
        }
    // Appending the new List
        Myfile.open("documnet.txt",ios::app);
        if(Myfile.is_open()){
          for(int i = 0; i < readfile.fName_v.size(); i++){
            Myfile<<endl<<readfile.fName_v[i]<<"\t"<<readfile.lName_v[i]<<"\t"<<readfile.id_v[i]<<"\t"<<readfile.gender_v[i];
          }
          Myfile.close();
          appendStudents();
          break;
        }else{
          cout<<"\nERROR: OPENING FILE FAILED!"<<endl;
        }
        break;
      }
    }
  }
  cout<<"\n\n\n";
  goBack(1);
 return 0;
}

// CLEAR ALL THE DATA AND MAKE THE SYSTEM EMPTY FOR NEW PROCESS.
void clearData(){
  system("cls");
  cout<<"1. CLEAR STUDENTS FILE\n";
  cout<<"2. CLEAR SCHEDULE\n";
  cout<<"0. BACK\n\n";
  int choice;
  here:
  cout<<"ENTER CHOICE: ";
  cin>>choice;
  if(choice == 1){
    string choice2;
    cout<<"\nPRESS |1| TO CONFIRM: ";
    cin>>choice2;
    if(choice2 == "1"){
      readfile.fName_v.clear(); readfile.lName_v.clear(); readfile.gender_v.clear();readfile.id_v.clear();
      fstream Myfile;
      Myfile.open("documnet.txt",ios::out);
      if(Myfile.is_open()){
          Myfile<<"FIRST_NAME\tLAST_NAME\tID\tSEX";
          Myfile.close();
          delay();
          cout<<"\nDATA CLEARED SUCCESSFULLY!"<<endl;
          cout<<"\n\n\n";
          goBack(1);exit(0);
      }else{
        cout<<"\nERROR: OPENING FILE FAILED!";
      }
    }
  }else if(choice == 2){
    string choice2;
    cout<<"\nPRESS |1| TO CONFIRM: ";
    cin>>choice2;
    if(choice2 == "1"){
      readfile.crs1.clear();readfile.crs2.clear();readfile.crs3.clear();readfile.crs4.clear();readfile.crs5.clear();
      fstream Myfile;
      Myfile.open("Courses.txt",ios::out);
      if(Myfile.is_open()){
          Myfile<<"FOP-II\t\tDCCN\t\tDBS\t\tDLD\t\tECONOMICS";
          Myfile.close();
          delay();
          cout<<"\nDATA CLEARED SUCCESSFULLY!"<<endl;
          cout<<"\n\n\n";
          goBack(1);exit(0);
      }else{
        cout<<"\nERROR: OPENING FILE FAILED!";
      }
    }
  }else if(choice == 0){
    adminView();exit(0);
  }else{
    goto here;
  }
}

//THSI FUNCTION MARK STUDENTS ATTENDANCE.
void markAttendance(){
  delay();
  system("cls");
  cout<<"\t\t\tATTENDANCE"<<endl<<endl;
  if(readfile.fName_v.size() == 1){
    cout<<"\n\t\t\t -------------------------------";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t| REGISTER SOME STUDENTS FIRST  |";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t -------------------------------"<<endl;
  }else{
      registeredCourses();
      enterCourseAgain:
      int courseChoice;
      cout<<"\n\nENTER CHOICE: ";
      cin>>courseChoice;
      switch(courseChoice){
        case 1:prepareAttendance(readfile.crs1); break;
        case 2:prepareAttendance(readfile.crs2); break;
        case 3:prepareAttendance(readfile.crs3); break;
        case 4:prepareAttendance(readfile.crs4); break;
        case 5:prepareAttendance(readfile.crs5); break;
        case 0:adminView();exit(0);break;
        default: goto enterCourseAgain;break;
      }
  }
  cout<<"\n\n\n";
  goBack(1);
}

void prepareAttendance(vector <string> course){
  cout<<"\t\t"<<course[0]<<endl;
  if(course.size() == 1){
    delay();
    cout<<"\n\t\t\t -------------------------------";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t| PLEASE MAKE A SCHEDUAL FIRST  |";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t -------------------------------"<<endl;
  }else{
    for(int i = 0; i < course.size(); ++i){
      if(i != 0){
        cout<<i<<" "<<course[i]<<endl;
      }
    }
    enterDateAgain:
    int chooseCourseDate;
    cout<<"ENTER CHOICE: ";
    cin>>chooseCourseDate;
    for(int i = 0; i < course.size(); ++i){
      if(chooseCourseDate == i && i!=0){
        attendanceStatus = {'s'};
        delay();
        system("cls");
        cout<<"\n\t\t\tMARK ATTENDACE\n";
        cout<<"\nCOURSE: "<<course[0]<<"\t\t\tDATE: "<<course[i]<<endl;
        for(int j = 0; j < readfile.fName_v.size(); ++j){
          if(j!=0){
            char tick;
            cout<<"\nIS "<<readfile.fName_v[j]<<" "<<readfile.lName_v[j]<<" PRESENT? (y/n): ";
            cin>>tick;
            attendanceStatus.push_back(tick);
          }
        }
        delay();
        system("cls");
        cout<<"\n\n"<<course[0]<<" ATTENDANCE ON :  "<<course[i]<<endl;
        for(int k = 0; k < readfile.fName_v.size(); ++k){
          if(k!=0){
            cout<<"\n"<<readfile.fName_v[k]<<" "<<readfile.lName_v[k]<<" Is "<<(attendanceStatus[k] == 'y'? "PRESENT" : "ABSENT")<<".";
          }
        }
        break;
      }
    }
  }
}

// HERE ADMIN ANNOUNCES THE DAY FOR THE COURSES.
void announceClassDays(){
  // delay();
  system("cls");
  cout<<"\t\t\tCLASS DAYS"<<endl<<endl;
  cout<<"1 SEE AVAILABLE CLASS DAYS\n";
  cout<<"2 MAKE CLASS SCHEDUAL\n";
  cout<<"3 BACK\n";
  int choice;
  cout<<"\nENTER CHOICE: ";
  cin>>choice;
  if(choice == 1){
    delay();
    system("cls");
    seeClassSchedual();
  }else if(choice == 2){
    delay();
    system("cls");
    cout<<"\n\t\t\tMAKE SCHEDUAL\n";
    updateSchedual();
  }else if(choice == 3){
    adminView();
  }
  goBack(1);
};

// HERE REGISTERD STUDENTS CAN SEE AVAILABLE CLASS DAYS TO ATTEND.
void seeClassSchedual(){
  delay();
  system("cls");
  cout<<"\t\t\tAVAILABLE CLASS DAYS"<<endl<<endl;
  if(readfile.crs1.size()==1){
    cout<<"\n\t\t\t -----------------------------------------------------------";
    cout<<"\n\t\t\t|                                                            |";
    cout<<"\n\t\t\t|              NO CLASS THIS WEEK                            |";
    cout<<"\n\t\t\t|                                                            |";
    cout<<"\n\t\t\t -----------------------------------------------------------"<<endl;
  }else{
    for(int i=0; i<readfile.crs1.size(); ++i){
      if(i==0){
        cout<<readfile.crs1[i]<<"\t\t"<<readfile.crs2[i]<<"\t\t"<<readfile.crs3[i]<<"\t\t"<<readfile.crs4[i]<<"\t\t"<<readfile.crs5[i]<<endl;
      }else{
        cout<<readfile.crs1[i]<<"\t"<<readfile.crs2[i]<<"\t"<<readfile.crs3[i]<<"\t"<<readfile.crs4[i]<<"\t"<<readfile.crs5[i]<<endl;
      }
    }
  }
};

void updateSchedual(){
  delay();
  system("cls");
  appendStudents();
  string dateForCourse;
  char wantToContinue = 'y';
  while(wantToContinue == 'y' || wantToContinue == 'Y'){
    cout<<"Course: "<<readfile.crs1[0]<<endl;
    cout<<"\nDATE(mm/dd/yyyy): ";
    cin>>dateForCourse;
    readfile.crs1.push_back(dateForCourse);

    cout<<"Course: "<<readfile.crs2[0]<<endl;
    cout<<"\nDATE(mm/dd/yyyy): ";
    cin>>dateForCourse;
    readfile.crs2.push_back(dateForCourse);

    cout<<"Course: "<<readfile.crs3[0]<<endl;
    cout<<"\nDATE(mm/dd/yyyy): ";
    cin>>dateForCourse;
    readfile.crs3.push_back(dateForCourse);

    cout<<"Course: "<<readfile.crs4[0]<<endl;
    cout<<"\nDATE(mm/dd/yyyy): ";
    cin>>dateForCourse;
    readfile.crs4.push_back(dateForCourse);

    cout<<"Course: "<<readfile.crs5[0]<<endl;
    cout<<"\nDATE(mm/dd/yyyy): ";
    cin>>dateForCourse;
    readfile.crs5.push_back(dateForCourse);

    cout<<"\nCONTINUE?(y/n): ";
    cin>>wantToContinue;
  }

  fstream file;
  file.open("Courses.txt",ios :: out);
  if(file.is_open()){
    file<<"FOP-II\t\tDCCN\t\tDBS\t\tDLD\t\tECONOMICS";
    file.close();
  }else{
    cout<<"\nUnable To Open This File! \n";
  }
  file.open("Courses.txt",ios :: app);
  if(file.is_open()){
    for(int i  = 0;i < readfile.crs1.size();++i){
      if(i!=0){
        file<<"\n"<<readfile.crs1[i]<<"\t\t"<<readfile.crs2[i]<<"\t\t"<<readfile.crs3[i]<<"\t\t"<<readfile.crs4[i]<<"\t\t"<<readfile.crs5[i];
      }
    }
    file.close();
    cout<<"\n\nCLASS FOR EACH COURSE SCHEDUALED SUCCESSFULLY!\n";
  }else{
    cout<<"\nError Opening File!\n";exit(0);
  }
};

// REGISTERED COURSES.
void registeredCourses(){
  for(int i=0; i<1;++i){
    cout<<"\n1. "<<readfile.crs1[i]<<"\n2. "<<readfile.crs2[i]<<"\n3. "<<readfile.crs3[i]<<"\n4. "<<readfile.crs4[i]<<"\n5. "<<readfile.crs5[i];
  }
  cout<<"\n0 BACK";
}

//SECURITY MANAGEMNET.
int setting(){
  delay();
  system("cls");
  cout<<"\t\t\tSETTING"<<endl<<endl;
  cout<<"\n1 CHANGE PASSWORD";
  cout<<"\n0 BACK";
  int option;
  cout<<"\n\nENTER CHOICE: ";
  cin>>option;
  switch(option){
    default : return 0;
    case 0: adminView();break;
    case 1: delay();
            system("cls");
            cout<<"\t\t\tSECURITY"<<endl<<endl;
            string oldPassword,newPassword,confirmPassword;
            cout<<"\nOLD PASSWORD: ";
            cin>>oldPassword;
            fstream file;
            file.open("password.txt",ios :: in);
            string realPassword;
            if(file.is_open()){
              while(getline(file,realPassword));
              file.close();
            }else{
              cout<<"\nERRO: OPENING PASSWORD FILE FAILD!\n";break;
            }
            if(oldPassword == realPassword){
              delay();
              system("cls");
              cout<<"\t\t\t------- || PERMISSION GRANTED || ----------"<<endl<<endl;
              cout<<"\nNEW PASSWORD: ";
              cin>>newPassword;
              reEnterPassword:
              cout<<"\nCONFIRM PASSWORD: ";
              cin>>confirmPassword;
              if(newPassword == confirmPassword){
                file.open("password.txt",ios :: out);
                if(file.is_open()){
                  file<<confirmPassword;
                  delay();
                  system("cls");
                  cout<<"\n\n\tPASSWORD CHANGED SUCCESSFULLY!\n";
                  file.close();
                }else{
                  cout<<"\nERROR: OPENING PASSWORD FILE!\n";break;
                }
              }else{
                  cout<<"\nPASSWORD MISMATCHED\n";goto reEnterPassword;
              }
            }else{
              delay();
              system("cls");
              cout<<"\n\n\n\t\t\t------- || PERMISSION DENIED || ----------"<<endl<<endl;
            }
            break;
  }
  cout<<"\n\n\n";
  goBack(1);
  return 0;
}

// THIS FUNCTION MAKES THE USER INTERFACE AND EXPIRIENCE MORE ATTRACTIVE.
void delay(){
  cout<<"LOADING";
  for(int a = 0 ; a<4; ++a){
    cout<<".";
    for(int i = 0; i < 100000;++i){
      for(int j = 0; j < 1000; ++j){

      }
  }
  }
  for(int b = 0 ; b<1; ++b){
    for(int i = 0; i < 100000;++i){
      for(int j = 0; j < 1000; j+=10){
      }
  }
  }
}
// THIS LAST(BUT NOT LEAST) FUNCTION HELPS US TO FLOW THROUGH THE PROGRAM EASLY.
int goBack(int to){
  int backTo = to;
  switch(backTo){
    case 1: cout<<"\nENTER |1| TO GO |BACK| OR ANY KEY TO |EXTI|"<<endl;
            int choice1;
            cin>>choice1;
            switch (choice1){
              case 1: adminView(); break;
              default: break;
              }
              break;
    case 2:cout<<"\nENTER |1| TO GO |BACK| OR ANY KEY TO |EXTI|"<<endl;
            int choice2;
            cin>>choice2;
            switch (choice2){
              case 1:main(); break;
              default: break;
              }
              break;
    default: break;
  }
  return 0;
}

// ADDITIONAL INFORMATIONS.
void developersInfo(){
  delay();
  system("cls");
  cout<<"\n\t\t\t\t\t\tDEVELOPERS INFO\n";
  cout<<"\t  --------------------------------------------------------------------------------------------"<<endl;
  cout<<"\t|   -> C++ PROJECT                                                                            |"<<endl;
  cout<<"\t|   -> ADDIS ABABA SCIENCE AND TECHNOLOGY UNIVERSTY ||DEPARTMENT OF SOFTWARE ENGINEERING||;   |"<<endl;
  cout<<"\t|   -> PROJECT TITLE : STUDENT ATTENDANCE MANAGEMENT SYSTEM;                                  |"<<endl;
  cout<<"\t|   -> SECTION : D;                                                                           |"<<endl;
  cout<<"\t|   -> COURSE INSTRUCTOR : INS.ELENI THESHOME;                                                |"<<endl;
  cout<<"\t|                 ------------------------------------------                                  |"<<endl;
  cout<<"\t|               |        PREPARED BY                         |                                |"<<endl;
  cout<<"\t|               |   NAME                        ID           |                                |"<<endl;
  cout<<"\t|               |   1.NEBIYAT TAKELE            ETS 1282/14  |                                |"<<endl;
  cout<<"\t|               |   2.NAHOM TSEGAYE             ETS 1154/14  |                                |"<<endl;
  cout<<"\t|               |   3.NANATI DEREJE             ETS 1177/14  |                                |"<<endl;
  cout<<"\t|               |   4.NEBAT HUSSEN              ETS 1278/14  |                                |"<<endl;
  cout<<"\t|               |   5.NASIFAY CHALA             ETS 1195/14  |                                |"<<endl;
  cout<<"\t|               |   6.NATAN ADDIS               ETS 1199/14  |            --------------------|"<<endl;
  cout<<"\t|                 ------------------------------------------             |  AUGUST 4,2023 G.C |"<<endl;
  cout<<"\t ---------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n\n\t\t# A GENTLE REMINDER\n\n";
  cout<<"\t1.IF YOU ARE USING THIS SOFTWARE FOR THE VERY FIRST TIME, \n";
  cout<<"\t\t||-> CREATE A NEW FOLDER AND SAVE THIS CPP FILE IN IT.\n";
  cout<<"\t\t||-> THE DEFAULT PASSWORD FOR ADMIL IS '1234'.\n";
  cout<<"\t\t||-> THEN YOU CAN CHANGE IT LATER IF YOU WANT.(GOTO: ADMIN LOGIN >> SETTING >> CHANGE PASSWORD )\n";
  cout<<"\t2.USE LETTERS,NUMBERS AND SPECIAL CHARACTERS FOR STRONG PASSWORD\n";
  cout<<"\t3.UPDATE YOUR PASSWORD FREQUENTLY FOR MORE SECURED SYSTEM\n\n";
  cout<<"\tNEED HELP? CONTACT US: \n";
  cout<<"\t\tnasifayc11@gmail.com"<<endl;
  cout<<"\t\tnataddis21@gmail.com"<<endl;
  cout<<"\t\tnahihaile4253@gmail.com"<<endl;
  cout<<"\t\tnanatidereje@gmail.com"<<endl;
  cout<<"\t\tnebathussen989@gmail.com"<<endl;
  cout<<"\t\tnebiyattakele23@gmail.com"<<endl;
  cout<<"\n\n\t|---------------------------------- ||  THANK YOU, STAY SAFE || -------------------------------------|"<<endl;
  goBack(2);
}
