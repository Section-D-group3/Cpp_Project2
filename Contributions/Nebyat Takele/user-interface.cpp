
// THIS FUNCTION MAKES THE USER INTERFACE AND EXPIRIENCE MORE ATTRACTIVE.
void delay(){
  cout<<"LOADING";
  for(int a = 0 ; a<4; ++a){
    cout<<".";
    for(int i = 0; i < 100000;++i){
      for(int j = 0; j < 1000; ++j){

      }
  }
  }
  for(int b = 0 ; b<1; ++b){
    for(int i = 0; i < 100000;++i){
      for(int j = 0; j < 1000; j+=10){
      }
  }
  }
}
// THIS LAST(BUT NOT LEAST) FUNCTION HELPS US TO FLOW THROUGH THE PROGRAM EASLY.
int goBack(int to){
  int backTo = to;
  switch(backTo){
    case 1: cout<<"\nENTER |1| TO GO |BACK| OR ANY KEY TO |EXTI|"<<endl;
            int choice1;
            cin>>choice1;
            switch (choice1){
              case 1: adminView(); break;
              default: break;
              }
              break;
    case 2:cout<<"\nENTER |1| TO GO |BACK| OR ANY KEY TO |EXTI|"<<endl;
            int choice2;
            cin>>choice2;
            switch (choice2){
              case 1:main(); break;
              default: break;
              }
              break;
    default: break;
  }
  return 0;
}

// ADDITIONAL INFORMATIONS.
void developersInfo(){
  delay();
  system("cls");
  cout<<"\n\t\t\t\t\t\tDEVELOPERS INFO\n";
  cout<<"\t  --------------------------------------------------------------------------------------------"<<endl;
  cout<<"\t|   -> C++ PROJECT                                                                            |"<<endl;
  cout<<"\t|   -> ADDIS ABABA SCIENCE AND TECHNOLOGY UNIVERSTY ||DEPARTMENT OF SOFTWARE ENGINEERING||;   |"<<endl;
  cout<<"\t|   -> PROJECT TITLE : STUDENT ATTENDANCE MANAGEMENT SYSTEM;                                  |"<<endl;
  cout<<"\t|   -> SECTION : D;                                                                           |"<<endl;
  cout<<"\t|   -> COURSE INSTRUCTOR : INS.ELENI THESHOME;                                                |"<<endl;
  cout<<"\t|                 ------------------------------------------                                  |"<<endl;
  cout<<"\t|               |        PREPARED BY                         |                                |"<<endl;
  cout<<"\t|               |   NAME                        ID           |                                |"<<endl;
  cout<<"\t|               |   1.NEBIYAT TAKELE            ETS 1282/14  |                                |"<<endl;
  cout<<"\t|               |   2.NAHOM TSEGAYE             ETS 1154/14  |                                |"<<endl;
  cout<<"\t|               |   3.NANATI DEREJE             ETS 1177/14  |                                |"<<endl;
  cout<<"\t|               |   4.NEBAT HUSSEN              ETS 1278/14  |                                |"<<endl;
  cout<<"\t|               |   5.NASIFAY CHALA             ETS 1195/14  |                                |"<<endl;
  cout<<"\t|               |   6.NATAN ADDIS               ETS 1199/14  |            --------------------|"<<endl;
  cout<<"\t|                 ------------------------------------------             |  AUGUST 4,2023 G.C |"<<endl;
  cout<<"\t ---------------------------------------------------------------------------------------------"<<endl;
  cout<<"\n\n\t\t# A GENTLE REMINDER\n\n";
  cout<<"\t1.IF YOU ARE USING THIS SOFTWARE FOR THE VERY FIRST TIME, \n";
  cout<<"\t\t||-> CREATE A NEW FOLDER AND SAVE THIS CPP FILE IN IT.\n";
  cout<<"\t\t||-> THE DEFAULT PASSWORD FOR ADMIL IS '1234'.\n";
  cout<<"\t\t||-> THEN YOU CAN CHANGE IT LATER IF YOU WANT.(GOTO: ADMIN LOGIN >> SETTING >> CHANGE PASSWORD )\n";
  cout<<"\t2.USE LETTERS,NUMBERS AND SPECIAL CHARACTERS FOR STRONG PASSWORD\n";
  cout<<"\t3.UPDATE YOUR PASSWORD FREQUENTLY FOR MORE SECURED SYSTEM\n\n";
  cout<<"\tNEED HELP? CONTACT US: \n";
  cout<<"\t\tnasifayc11@gmail.com"<<endl;
  cout<<"\t\tnataddis21@gmail.com"<<endl;
  cout<<"\t\tnahihaile4253@gmail.com"<<endl;
  cout<<"\t\tnanatidereje@gmail.com"<<endl;
  cout<<"\t\tnebathussen989@gmail.com"<<endl;
  cout<<"\t\tnebiyattakele23@gmail.com"<<endl;
  cout<<"\n\n\t|---------------------------------- ||  THANK YOU, STAY SAFE || -------------------------------------|"<<endl;
  goBack(2);
}
