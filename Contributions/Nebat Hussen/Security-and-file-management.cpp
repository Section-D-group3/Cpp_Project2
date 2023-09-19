
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
