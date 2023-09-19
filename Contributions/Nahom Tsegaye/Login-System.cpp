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