// THIS FUNCTION DELETE THE STUDENT FROM THE FILE IF THE STUDENT IS ALREADY REGISTERD.
int deleteStudent(){
  delay();
  system("cls");
  cout<<"\t\t\tDELETE\n\n";
  if(fName_v.size() == 1){
    cout<<"\nTHERE IS NO STUDENT RECORD YET!"<<endl;
    cout<<"\n\n\n";
  }else{
    string id;
    cout<<"ID: ";
    cin.ignore();getline(cin,id);
    for(int i = 0; i < fName_v.size(); i++){
        if(i == (id_v.size()-1) && id_v[i] != id){ // Checking the last id.
          delay();
          system("cls");
          cout<<"\nERROR : STUDENT  NOT FOUND!\n";
          cout<<"\n\n\n";
          break;
        }else if(id_v[i] == id){
        delay();
        char verify;
        cout<<"\nAre you sure you want to delete "<<fName_v[i]<<" "<<lName_v[i]<<" ? (y/n): ";
        cin>>verify;
        if((verify == 'N') || (verify == 'n')){break;};
        delay();
        cout<<"\n"<<fName_v[i]<<" "<<lName_v[i]<<" DELETED SUCCESSFULLY!"<<endl;
        fName_v.erase(fName_v.begin()+i);
        lName_v.erase(lName_v.begin()+i);
        id_v.erase(id_v.begin()+i);
        gender_v.erase(gender_v.begin()+i);
    // Removing the First line of the list
        fName_v.erase(fName_v.begin()+0);
        lName_v.erase(lName_v.begin()+0);
        id_v.erase(id_v.begin()+0);
        gender_v.erase(gender_v.begin()+0);
    // Writting the first line of the list
        fstream Myfile1,Myfile2,Myfile3,Myfile4;
        Myfile1.open("firstName.txt",ios::out);
        Myfile2.open("lastName.txt",ios::out);
        Myfile3.open("id.txt",ios::out);
        Myfile4.open("gender.txt",ios::out);
        if(Myfile1.is_open() && Myfile2.is_open() && Myfile3.is_open() && Myfile4.is_open()){
          Myfile1<<"FIRST_NAME";Myfile2<<"LAST_NAME";Myfile3<<"ID";Myfile4<<"SEX";
          Myfile1.close();Myfile2.close();Myfile3.close();Myfile4.close();
        }else{
          cout<<"\nERROR: OPENING FILE FAILED!"<<endl;
        }
    // Appending the new List
        Myfile1.open("firstName.txt",ios::app);
        Myfile2.open("lastName.txt",ios::app);
        Myfile3.open("id.txt",ios::app);
        Myfile4.open("gender.txt",ios::app);
        if(Myfile1.is_open() && Myfile2.is_open() && Myfile3.is_open() && Myfile4.is_open()){
          for(int i = 0; i < fName_v.size(); i++){
            Myfile1<<endl<<fName_v[i];
            Myfile2<<endl<<lName_v[i];
            Myfile3<<endl<<id_v[i];
            Myfile4<<endl<<gender_v[i];
          }
          Myfile1.close();Myfile2.close();Myfile3.close();Myfile4.close();
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
  goBack();
 return 0;
}

// CLEAR ALL THE DATA AND MAKE THE SYSTEM EMPTY FOR NEW PROCESS.
void clearData(){
  delay();
  system("cls");
  cout<<endl<<"\t\t\t ------------------  WARNING  -----------------------";
  delay2();
  cout<<endl<<"\t\t\t|                                                    |";
  delay2();
  cout<<endl<<"\t\t\t|THE FOLLOWING DATA WILL BE PERMANENTLT DELETED!     |";
  delay2();
  cout<<endl<<"\t\t\t|                                                    |";
  delay2();
  cout<<endl<<"\t\t\t|1.THE REGISTERED STUDENTS LIST.                     |";
  delay2();
  cout<<endl<<"\t\t\t|                                                    |";
  delay2();
  cout<<endl<<"\t\t\t|2.ALL COURSES SCHEDUAL.                             |";
  delay2();
  cout<<endl<<"\t\t\t|                                                    |";
  delay2();
  cout<<endl<<"\t\t\t|#THIS PROCESS CAN'T BE UNDO!                        |";
  delay2();
  cout<<endl<<"\t\t\t ----------------------------------------------------"<<endl;
  delay2();
  char choice;
  here:
  cout<<"\n\t\tARE YOUR SURE YOU WANT TO CLEAR ALL THE DATA? |y/Y| Or |n/N|: ";
  cin>>choice;
  fstream Myfile1,Myfile2,Myfile3,Myfile4,Myfile5,Myfile6,Myfile7,Myfile8,Myfile9;
  switch(choice){
      case 'Y':
      case 'y': Myfile1.open("firstName.txt",ios::out);Myfile2.open("lastName.txt",ios::out);Myfile3.open("id.txt",ios::out);
                Myfile4.open("gender.txt",ios::out);Myfile5.open("FUNDAMENTALS_OF_PROGRAMING_II.txt",ios::out); Myfile6.open("DATA_COMMUNICATION_AND_COMPUTER_NETWORKS.txt",ios::out);
                Myfile7.open("DATABASE_SYSTEM.txt",ios::out);Myfile8.open("DIGITAL_LOGIC_DESIGN.txt",ios::out);
                Myfile9.open("ECONOMICS.txt",ios::out);
                if(Myfile1.is_open() && Myfile2.is_open() && Myfile3.is_open() && Myfile4.is_open() && Myfile5.is_open() && Myfile6.is_open() && Myfile7.is_open() && Myfile8.is_open() && Myfile9.is_open()){
                  Myfile1<<"FIRST_NAME";Myfile2<<"LAST_NAME";Myfile3<<"ID";Myfile4<<"SEX";
                  Myfile5<<"FUNDAMENTALS_OF_PROGRAMING_II";Myfile6<<"DATA_COMMUNICATION_AND_COMPUTER_NETWORKS";Myfile7<<"DATABASE_SYSTEM";Myfile8<<"DIGITAL_LOGIC_DESIGN";Myfile9<<"ECONOMICS";
                  Myfile1.close();Myfile2.close();Myfile3.close();Myfile4.close(); Myfile5.close();
                  Myfile6.close();Myfile7.close();Myfile8.close();Myfile9.close();
                  delay();
                  cout<<"\nDATA CLEARED SUCCESSFULLY!"<<endl;
                  cout<<"\n\n\n";
                  goBack();exit(0);
                  break;
                }else{
                  cout<<"ERROR: OPENING FILE FAILED!"<<endl;break;
                }
      case 'N':
      case 'n': adminView();break;
      default: cout<<"\nINVALID INPUT!\n";goto here;break;
    }
}