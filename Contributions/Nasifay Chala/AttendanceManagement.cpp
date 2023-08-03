//THSI FUNCTION MARK STUDENTS ATTENDANCE.
void markAttendance(){
  delay();
  system("cls");
  cout<<"\t\t\tATTENDANCE"<<endl<<endl;
  if(fName_v.size() == 1){
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
        case 1:prepareAttendance(1); break;
        case 2:prepareAttendance(2);break;
        case 3:prepareAttendance(3);break;
        case 4:prepareAttendance(4);break;
        case 5:prepareAttendance(5);break;
        case 0:adminView();exit(0);break;
        default: goto enterCourseAgain;break;
      }
  }
  cout<<"\n\n\n";
  goBack();
}

void prepareAttendance(int couresCode){
  date_v = {};
  int choosenCourse = couresCode;
  string courseName;
  switch(choosenCourse){
    case 1: courseName = "FUNDAMENTALS_OF_PROGRAMING_II";break;
    case 2: courseName = "DATA_COMMUNICATION_AND_COMPUTER_NETWORKS";break;
    case 3: courseName = "DATABASE_SYSTEM";break;
    case 4: courseName = "DIGITAL_LOGIC_DESIGN";break;
    case 5: courseName = "ECONOMICS";break;
    default:break;
  }
  cout<<"\t\t"<<courseName<<endl;
  fstream file;
  file.open(courseName+".txt",ios::in);
  if(file.is_open()){
    delay();
    system("cls");
    cout<<"\t\t\t"<<courseName<<" CLASS DAYS\t\t||SELECT DAY||\n\n";
    string courseDate;
    while(getline(file,courseDate)){
      date_v.push_back(courseDate);
    }
    file.close();
  }else{
    cout<<"\nERROR: OPENING "<<courseName<<" FILE FAILD!";exit(1);
  }

  if(date_v.size() == 1){
    delay();
    cout<<"\n\t\t\t -------------------------------";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t| PLEASE MAKE A SCHEDUAL FIRST  |";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t -------------------------------"<<endl;
  }else{
    for(int i = 0; i < date_v.size(); ++i){
      if(i != 0){
        cout<<i<<" "<<date_v[i]<<endl;
      }
    }
    enterDateAgain:
    int chooseCourseDate;
    cout<<"ENTER CHOICE: ";
    cin>>chooseCourseDate;
    for(int i = 0; i < date_v.size(); ++i){
      if(chooseCourseDate == i && i!=0){
        attendanceStatus = {'s'};
        delay();
        system("cls");
        cout<<"\n\t\t\tMARK ATTENDACE\n";
        cout<<"\nCOURSE: "<<courseName<<"\t\t\tDATE: "<<date_v[i]<<endl;
        for(int j = 0; j < fName_v.size(); ++j){
          if(j!=0){
            char tick;
            cout<<"\nIS "<<fName_v[j]<<" "<<lName_v[j]<<" PRESENT? (y/n): ";
            cin>>tick;
            attendanceStatus.push_back(tick);
          }
        }
        delay();
        system("cls");
        cout<<"\n\n"<<courseName<<" ATTENDANCE ON :  "<<date_v[i]<<endl;
        for(int k = 0; k < fName_v.size(); ++k){
          if(k!=0){
            cout<<"\n"<<fName_v[k]<<" "<<lName_v[k]<<" Is "<<(attendanceStatus[k] == 'y'? "PRESENT" : "ABSENT")<<".";
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
    registeredCourses();
    enterAgain:
    int courseChoice;
    cout<<"\n\nENTER CHOICE: ";
    cin>>courseChoice;
    switch(courseChoice){
      case 1:seeClassSchedual(1);break;
      case 2:seeClassSchedual(2);break;
      case 3:seeClassSchedual(3);break;
      case 4:seeClassSchedual(4);break;
      case 5:seeClassSchedual(5);break;
      case 0:seeClassSchedual(0);break;
      default: goto enterAgain;break;
    }
  }else if(choice == 2){
    delay();
    system("cls");
    cout<<"\n\t\t\tMAKE SCHEDUAL\n";
    registeredCourses();
    TryAgain:
    int courseChoice2;
    cout<<"\n\nENTER CHOICE: ";
    cin>>courseChoice2;
    switch(courseChoice2){
      case 1:updateSchedual(1);break;
      case 2:updateSchedual(2);break;
      case 3:updateSchedual(3);break;
      case 4:updateSchedual(4);break;
      case 5:updateSchedual(5);break;
      case 0:updateSchedual(0);break;
      default: goto TryAgain;break;
    }
  }else if(choice == 3){
    adminView();
  }
  goBack();
};

// HERE REGISTERD STUDENTS CAN SEE AVAILABLE CLASS DAYS TO ATTEND.
void seeClassSchedual(int courseCode){
  int choosenCourse = courseCode;
  string courseName;
  switch(choosenCourse){
    case 1: courseName = "FUNDAMENTALS_OF_PROGRAMING_II";break;
    case 2: courseName = "DATA_COMMUNICATION_AND_COMPUTER_NETWORKS";break;
    case 3: courseName = "DATABASE_SYSTEM";break;
    case 4: courseName = "DIGITAL_LOGIC_DESIGN";break;
    case 5: courseName = "ECONOMICS";break;
    case 0: announceClassDays();break;
    default:break;
  }
  cout<<"\t\t"<<courseName<<endl;
  fstream file;
  file.open(courseName+".txt",ios::in);
  if(file.is_open()){
    date_v = {};
    string courseDate;
    while(getline(file,courseDate)){
      date_v.push_back(courseDate);
    }
    file.close();
  }else{
    cout<<"\nERROR: OPENING "<<courseName<<" FILE FAILD!";exit(1);
  }
  delay();
  system("cls");
  cout<<"\t\t\tAVAILABLE CLASS DAYS FOR "<<courseName<<endl<<endl;
  if(date_v.size()==1){
    cout<<"\n\t\t\t -------------------------------";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t| NO AVAILABLE CLASS THIS WEEK  |";
    cout<<"\n\t\t\t|                               |";
    cout<<"\n\t\t\t -------------------------------"<<endl;
  }else{
    for(int i = 0; i < date_v.size(); ++i){
      if(i!=0){
        cout<<"# UPCOMING CLASS ON (mm/dd/yy) : "<<date_v[i]<<endl;
      }
    }
  }
};
void updateSchedual(int crs){
  delay();
  system("cls");
  int courseCode = crs;
  string courseName;
  switch(courseCode){
    case 1: courseName = "FUNDAMENTALS_OF_PROGRAMING_II";break;
    case 2: courseName = "DATA_COMMUNICATION_AND_COMPUTER_NETWORKS";break;
    case 3: courseName = "DATABASE_SYSTEM";break;
    case 4: courseName = "DIGITAL_LOGIC_DESIGN";break;
    case 5: courseName = "ECONOMICS";break;
    case 0: announceClassDays();exit(0);break;
    default:break;
  }
  cout<<"\t\t"<<courseName<<endl;
  fstream file;
  file.open(courseName+".txt",ios::out);
  if(file.is_open()){
    file<<courseName;
    file.close();
  }else{
    cout<<"ERROR: OPENING "<<courseName<<"FILE FAILD!"<<endl;exit(1);
  }
  file.open(courseName+".txt",ios::app);
  if(file.is_open()){
    string dateForCourse;
    char wantToContinue = 'y';
    while(wantToContinue == 'y' || wantToContinue == 'Y'){
      cout<<"\nDATE(mm/dd/yyyy): ";
      cin>>dateForCourse;
      file<<endl<<dateForCourse;
      cout<<"\nCONTINUE?(y/n): ";
      cin>>wantToContinue;
    }
    file.close();
    delay();
    cout<<"\n\nCLASS FOR "<<courseName<<" SCHEDUALED SUCCESSFULLY!\n";
  }else{
    cout<<"ERROR: OPENING "<<courseName<<" FILE FAILD!"<<endl;exit(0);
  }
};
