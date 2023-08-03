// HERE,THE |appendStudents()| FUNCTION READS DATA FROM THE FILE IN THE COMPUTER AND PREPARE FOR THE UPCOMING PROCESS.
void appendStudents(){
  delay();
  fName_v = {}; lName_v = {},gender_v = {};id_v = {};
  fstream file1("firstName.txt");
  fstream file2("lastName.txt");
  fstream file3("id.txt");
  fstream file4("gender.txt");
  if((!file1.good()) || (!file2.good()) || (!file3.good()) || (!file4.good())){
    file1.open("firstName.txt",ios::out);
    file2.open("lastName.txt",ios::out);
    file3.open("id.txt",ios::out);
    file4.open("gender.txt",ios::out);

    file1<<"FIRST_NAME";file2<<"LAST_NAME";file3<<"ID";file4<<"SEX";
    file1.close();file2.close();file3.close();file4.close();
  }

  fstream Myfile1,Myfile2,Myfile3,Myfile4;
  Myfile1.open("firstName.txt",ios::in);
  Myfile2.open("lastName.txt",ios::in);
  Myfile3.open("id.txt",ios::in);
  Myfile4.open("gender.txt",ios::in);
  if(Myfile1.is_open() && Myfile2.is_open() && Myfile3.is_open() && Myfile4.is_open()){
    string f_name,l_name,id,gender;
    while(getline(Myfile1,f_name) && getline(Myfile2,l_name) && getline(Myfile3,id) && getline(Myfile4,gender)){
      fName_v.push_back(f_name);
      lName_v.push_back(l_name);
      gender_v.push_back(gender);
      id_v.push_back(id);
    }
    Myfile1.close();Myfile2.close();Myfile3.close();Myfile4.close();
  }else{
    cout<<"\nERROR: OPENING FILE FAILD WHIEL APPENDING STUDENT!\n";
  }
}

// REGISTERED COURSES.
void registeredCourses(){
  fstream file1("FUNDAMENTALS_OF_PROGRAMING_II.txt");
  fstream file2("DATA_COMMUNICATION_AND_COMPUTER_NETWORKS.txt");
  fstream file3("DATABASE_SYSTEM.txt");
  fstream file4("DIGITAL_LOGIC_DESIGN.txt");
  fstream file5("ECONOMICS.txt");
  if((!file1.good()) || (!file2.good()) || (!file3.good()) || (!file4.good()) || (!file5.good())){
    file1.open("FUNDAMENTALS_OF_PROGRAMING_II.txt",ios::out);
    file2.open("DATA_COMMUNICATION_AND_COMPUTER_NETWORKS.txt",ios::out);
    file3.open("DATABASE_SYSTEM.txt",ios::out);
    file4.open("DIGITAL_LOGIC_DESIGN.txt",ios::out);
    file5.open("ECONOMICS.txt",ios::out);

    file1<<"FUNDAMENTALS_OF_PROGRAMING_II";file2<<"DATA_COMMUNICATION_AND_COMPUTER_NETWORKS";file3<<"DATABASE_SYSTEM";file4<<"DIGITAL_LOGIC_DESIGN";file5<<"ECONOMICS";
    file1.close();file2.close();file3.close();file4.close();file5.close();
  }
  cout<<"\nCOURSESE\n";
  cout<<"\n1 FUNDAMENTALS_OF_PROGRAMING_II";
  cout<<"\n2 DATA_COMMUNICATION_AND_COMPUTER_NETWORKS";
  cout<<"\n3 DATABASE_SYSTEM";
  cout<<"\n4 DIGITAL_LOGIC_DESIGN";
  cout<<"\n5 ECONOMICS";
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
  goBack();
  return 0;
}