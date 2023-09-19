
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
