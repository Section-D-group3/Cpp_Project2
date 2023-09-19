
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
