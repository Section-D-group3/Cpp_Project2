
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
