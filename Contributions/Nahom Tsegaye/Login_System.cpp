// ADMIN COULD BE ANY PERSON, CLASS REP OR LECTURE(PROFESSOR) WHO HAVE AUTHORIZED ACCESS TO MANIPULATE THE DATA.
void adminLogIn(){
  system("cls");
  string adminPassWord, systemDeafaultPassWord ="1234";
  fstream file1("password.txt");
  if(!file1.good()){
    file1.open("password.txt",ios :: out);
    file1<<systemDeafaultPassWord;
    file1.close();
  }
  fstream file;
  file.open("password.txt",ios::in);
  if(file.is_open()){
    while(getline(file,adminPassWord));
    file.close();
  }else{
    cout<<"\nERROR: OPENING PASSWORD FILE!\n";exit(0);
  }
  int attemptCount = 0;
  tryAgain:
  string password;
  cout<<"ENTER PASSWORD:";
  cin>>password;
  if(password == adminPassWord){
    adminView();
  }else{
    if(attemptCount == 2){
      delay();
      cout<<"\n\t\t------- || ACCESS DENIED || ----------!\n\n";
      exit(0);
    }else{
      ++attemptCount;
    }
    delay();
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
    cout<<"2 STUDENT PROFILE\n";
    cout<<"3 CHECK STUDENT PROFILE BY ID\n";
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
      case 2: checkListOfRegistredStudent();break;
      case 3: checkPresence();break;
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
  appendStudents();
  system("cls");
  if(fName_v.size() == 1){
    cout<<"\nSTUDENTS ARE NOT REGISTERED YET!\n";
    goBack(2);exit(0);
  }

  string userId;
  cout<<"\nID: ";
  cin.ignore();
  getline(cin,userId);

          // First Check Whether The Student Is Registered Or Not Before Going To Another Process.
  for(int i = 0; i < id_v.size(); ++i){
    if(userId == id_v[i]){
      delay();
      system("cls");
      cout<<"\t\t\t"<<fName_v[i]<<" "<<lName_v[i]<<"\n\n";
      break;
    }else if(i == (id_v.size()-1) && userId != id_v[i]){
      delay();
      cout<<"\nERROR: STUDENT NOT FOUND!\n";goBack(2);exit(0);
    }else{
      continue;
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
            for(int i = 0; i < id_v.size(); ++i){
              if(id_v[i] != userId){
                continue;
              }else{
                cout<<"\t\t\tPROFILE\n\n\n";
                cout<<"\t\t"<<fName_v[0]<<"  :  "<<fName_v[i]<<endl;
                cout<<"\t\t"<<lName_v[0]<<"  :  "<<lName_v[i]<<endl;
                cout<<"\t\t"<<gender_v[0]<<"  :  "<<gender_v[i]<<endl;
                cout<<"\t\t"<<id_v[0]<<"  :  "<<id_v[i]<<endl;
                break;
              }
            }break;
    case 2: delay();
            system("cls");
            registeredCourses();
            pleaseTryAgain:
            int courseChoice;
            cout<<"\n\nEnter Choice: ";
            cin>>courseChoice;
            switch(courseChoice){
              case 1:seeClassSchedual(1);break;
              case 2:seeClassSchedual(2);break;
              case 3:seeClassSchedual(3);break;
              case 4:seeClassSchedual(4);break;
              case 5:seeClassSchedual(5);break;
              case 0:main();break;
              default: goto pleaseTryAgain;break;
            }break;
    default: cout<<"\n\t\tINVALID INPUT\n";goto logInAgain;
  }
  cout<<"\n\n";
  goBack(2);
  exit(0);
}