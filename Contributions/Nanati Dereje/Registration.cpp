// STUDENT(S) REGISTRATION GOES HERE.
void registerStudent(){
  delay();
  system("cls");
  cout<<"\t\t\tREGISTRATION FORM\n\n";
  int n;
  cout<<"HOW MANY STUDENTS TO REGISTER?: ";
  cin>>n;
  fstream Myfile1,Myfile2,Myfile3,Myfile4;
  Myfile1.open("firstName.txt",ios::app);
  Myfile2.open("lastName.txt",ios::app);
  Myfile3.open("id.txt",ios::app);
  Myfile4.open("gender.txt",ios::app);
  if(Myfile1.is_open() && Myfile2.is_open() && Myfile3.is_open() && Myfile4.is_open()){
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
    for(const string &b: id_v){
      if(stud[i].id == b){
        cout<<"\nID ALREADY EXISTS!.\n";goto checkId;
      }
    }
    Myfile1<<endl<<stud[i].firstName;
    Myfile2<<endl<<stud[i].lastName;
    Myfile3<<endl<<stud[i].id;
    Myfile4<<endl<<stud[i].gender;
    }
    Myfile1.close();Myfile2.close();Myfile3.close();Myfile4.close();
    appendStudents();
    cout<<"\n\nREGISTRATION FINISHED SUCCESSFULY!!"<<endl; // REGISTRATION ENDS.
  }else{
    cout<<"\nERROR: OPENING FILE FAILED!"<<endl;
  }
  cout<<"\n\n\n";
  goBack();
  exit(0);
};

// HERE THE ADMIN CAN SEE ALL THE REGISTERD STUDENTS.
void checkListOfRegistredStudent(){
  appendStudents();
  system("cls");
  cout<<"\t\t\tREGISTERED STUDENTS LIST"<<endl<<endl;
  if(fName_v.size() == 1){
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
      for(int i = 0; i < fName_v.size(); ++i){
        for(int j = 0; j < fName_v.size(); ++j){
          if((fName_v[j][0] == letter || fName_v[j][0] == convertToUpperCase || static_cast<char>(toupper(fName_v[j][0])) == letter) && j!=0){
            break;
          }else if(j == (fName_v.size() - 1) && letter != fName_v[j][0]){
            cout<<"\nNO STUDENT FOUND!"<<endl;goBack();exit(0);
          }
        }
        if(i == 0){
          cout<<fName_v[i]<<"\t"<<lName_v[i]<<"\t"<<id_v[i]<<"\t"<<gender_v[i]<<endl;
        }else if((fName_v[i][0] == letter) || (fName_v[i][0] == convertToUpperCase) || (static_cast<char>(toupper(fName_v[i][0])) == letter)){
          cout<<fName_v[i]<<"\t\t"<<lName_v[i]<<"\t\t"<<id_v[i]<<"\t\t"<<gender_v[i]<<endl;
        }
      }
    }else if(choice == 2){
      delay();
      system("cls");
      cout<<"\t\t\tALL REGISTERED STUDENTS LIST"<<endl<<endl;
      for(int i = 0; i < fName_v.size(); ++i){
        if(i == 0){
          cout<<fName_v[i]<<"\t"<<lName_v[i]<<"\t"<<id_v[i]<<"\t"<<gender_v[i]<<endl;
        }else{
          cout<<fName_v[i]<<"\t\t"<<lName_v[i]<<"\t\t"<<id_v[i]<<"\t\t"<<gender_v[i]<<endl;
        }
      }
    }else if(choice == 3){
     adminView();exit(0);
    }else{
      cout<<"\nINVALID INPUT!\n";goto retry;
    }
  }
  cout<<"\n\n\n";
  goBack();
  exit(0);
}

// IF THE ADMIN WANTS TO CHECK WHETHER THE STUDENT IS REGISTERD OR NOT, HE COMES HERE AND TYPES HIM/HER ID.
void checkPresence(){
  delay();
  system("cls");
  string id;
  cout<<"\t\t\tSEARCH FOR STUDENT PROFILE\n\n";
  cout<<"ID: ";
  cin.ignore();getline(cin,id);
  delay();
  system("cls");
  for(int i = 0; i < id_v.size(); ++i){
    if(i == (id_v.size()-1) && (id_v[i] != id)){
      cout<<"\nSTUDENT HAS NOT BEEN REGISTERED YET!";
    }else if(id_v[i] != id){
      continue;
    }else{
      cout<<fName_v[0]<<"\t"<<lName_v[0]<<"\t"<<gender_v[0]<<"\t"<<id_v[0]<<endl;
      cout<<fName_v[i]<<"\t\t"<<lName_v[i]<<"\t\t"<<gender_v[i]<<"\t\t"<<id_v[i]<<endl;
      break;
    }
  }
  cout<<"\n\n\n";
  goBack();
  exit(0);
}
