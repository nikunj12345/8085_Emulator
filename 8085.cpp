#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;








void inst(char st1[10],string reg[],map<char*,string>&mapping)
{
    char str[7]={' '},no[10]={' '},no1[10]={' '};

    int l,i,j,c,m;

    l=strlen(st1);
   // reg[1]=10;
 //cout<<st1;


              // find the length of the coming string

    for(i=0;i<l;i++)               // finding the opcode
    {
        if(st1[i]==' ')
            break;
        str[i]=st1[i];
    }


    if(strcmp(str,"M")==0)
    {


        int k=0;

        j=i+1;
        while(st1[j]!=' ')
        {
          no[k]=st1[j];
          j++;
          k++;
        }
        i=j+1;
        k=0;
         while(st1[i]!=' ')
        {
          no1[k]=st1[i];
          i++;
          k++;
        }

           mapping[no]=no1;

       // cout<<"the value at address is :"<<mapping[no]<<"\n";
    }


    if(strcmp(str,"LDA")==0)
    {

        int k=0;
        for(j=i+1;j<l;j++)
        {
            no[k]=st1[j];
            k++;
        }

        //cout<<mapping[no];
        reg[0]=mapping[no];



        cout<<"the value of register A is :"<<reg[0]<<"\n";
    }


    else if(strcmp(str,"MOV")==0)
    {
        no[0]=st1[i+1];
        no1[0]=st1[i+3];



      if(strcmp(no,"A")==0)
      {

           if(strcmp(no1,"B")==0)
             {
                 reg[0]=reg[1];
             }
           if(strcmp(no1,"C")==0)
             {
                 reg[0]=reg[2];
             }
           if(strcmp(no1,"D")==0)
             {
                 reg[0]=reg[3];
             }
           if(strcmp(no1,"E")==0)
             {
                 reg[0]=reg[4];
             }
           if(strcmp(no1,"H")==0)
             {
                 reg[0]=reg[5];
             }
           if(strcmp(no1,"L")==0)
             {
                 reg[0]=reg[6];
             }
      }



      if(strcmp(no,"B")==0)
      {

           if(strcmp(no1,"A")==0)
             {
                 reg[1]=reg[0];
             }

           if(strcmp(no1,"C")==0)
             {
                 reg[1]=reg[2];
             }
           if(strcmp(no1,"D")==0)
             {
                 reg[1]=reg[3];
             }
           if(strcmp(no1,"E")==0)
             {
                 reg[1]=reg[4];
             }
           if(strcmp(no1,"H")==0)
             {
                 reg[1]=reg[5];
             }
           if(strcmp(no1,"L")==0)
             {
                 reg[1]=reg[6];
             }
      }

      if(strcmp(no,"C")==0)
        {

           if(strcmp(no1,"A")==0)
             {
                 reg[2]=reg[0];
             }
           if(strcmp(no1,"B")==0)
             {
                 reg[2]=reg[1];
             }

           if(strcmp(no1,"D")==0)
             {
                 reg[2]=reg[3];
             }
           if(strcmp(no1,"E")==0)
             {
                 reg[2]=reg[4];
             }
           if(strcmp(no1,"H")==0)
             {
                 reg[2]=reg[5];
             }
           if(strcmp(no1,"L")==0)
             {
                 reg[2]=reg[6];
             }
      }





      if(strcmp(no,"D")==0)
      {

           if(strcmp(no1,"A")==0)
             {
                 reg[3]=reg[0];
             }
           if(strcmp(no1,"B")==0)
             {
                 reg[3]=reg[1];/////
             }
           if(strcmp(no1,"C")==0)
             {
                 reg[3]=reg[2];
             }

           if(strcmp(no1,"E")==0)
             {
                 reg[3]=reg[4];
             }
           if(strcmp(no1,"H")==0)
             {
                 reg[3]=reg[5];
             }
           if(strcmp(no1,"L")==0)
             {
                 reg[3]=reg[6];
             }
      }




      if(strcmp(no,"E")==0)
      {

           if(strcmp(no1,"A")==0)
             {
                 reg[4]=reg[0];
             }
           if(strcmp(no1,"B")==0)
             {
                 reg[4]=reg[1];/////
             }
           if(strcmp(no1,"C")==0)
             {
                 reg[4]=reg[2];
             }
           if(strcmp(no1,"D")==0)
             {
                 reg[4]=reg[3];
             }

           if(strcmp(no1,"H")==0)
             {
                 reg[4]=reg[5];
             }
           if(strcmp(no1,"L")==0)
             {
                 reg[4]=reg[6];
             }
      }






      if(strcmp(no,"H")==0)
      {

           if(strcmp(no1,"A")==0)
             {
                 reg[5]=reg[0];
             }
           if(strcmp(no1,"B")==0)
             {
                 reg[5]=reg[1];/////
             }
           if(strcmp(no1,"C")==0)
             {
                 reg[5]=reg[2];
             }
           if(strcmp(no1,"D")==0)
             {
                 reg[5]=reg[3];
             }
           if(strcmp(no1,"E")==0)
             {
                 reg[5]=reg[4];
             }

           if(strcmp(no1,"L")==0)
             {
                 reg[5]=reg[6];
             }
      }





      if(strcmp(no,"L")==0)
      {

           if(strcmp(no1,"A")==0)
             {
                 reg[6]=reg[0];
             }
           if(strcmp(no1,"B")==0)
             {
                 reg[6]=reg[1];/////
             }
           if(strcmp(no1,"C")==0)
             {
                 reg[6]=reg[2];
             }
           if(strcmp(no1,"D")==0)
             {
                 reg[6]=reg[3];
             }
           if(strcmp(no1,"E")==0)
             {
                 reg[6]=reg[4];
             }
           if(strcmp(no1,"H")==0)
             {
                 reg[6]=reg[5];
             }

      }




    }

  else if(strcmp(str,"MVI")==0)
  {

       no[0]=st1[i+1];
      c=0;
      for(j=i+3;j<l;j++)
      {
        no1[c]=st1[j];
        c++;
      }

      if(strcmp(no,"A")==0)
      {
          reg[0]=no1;
      }


       else if(strcmp(no,"B")==0)
      {
          reg[1]=no1;
      }


       else if(strcmp(no,"C")==0)
      {
          reg[2]=no1;
      }

       else if(strcmp(no,"D")==0)
      {
          reg[3]=no1;
      }


       else if(strcmp(no,"E")==0)
      {
          reg[4]=no1;
      }


       else if(strcmp(no,"H")==0)
      {
          reg[5]=no1;
      }


       else if(strcmp(no,"L")==0)
      {
          reg[6]=no1;
      }


  }

  ///////////////////////////////////Arithmetic Instruction

  else if(strcmp(str,"ADD")==0)
  {
      no[0]=st1[i+1];

        if(strcmp(no,"A")==0)
      {
          /////////////////////////////////////////////////////

	      long int i=0;
	string b1,b2;
	while(no[i])
	{
		switch(no[i])
		{
			case '0' : b1="0000";
				break;
			case '1' : b1="0001";
				break;
			case '2' : b1="0010";
				break;
			case '3' : b1="0011";
				break;
			case '4' : b1="0100";
				break;
			case '5' : b1="0101";
				break;
			case '6' : b1="0110";
				break;
			case '7' : b1="0111";
				break;
			case '8' : b1="1000";
				break;
			case '9' : b1="1001";
				break;
			case 'A' : b1="1010";
				break;
			case 'B' : b1="1011";
				break;
			case 'C' : b1="1100";
				break;
			case 'D' : b1="1101";
				break;
			case 'E' : b1="1110";
				break;
			case 'F' : b1="1111";
				break;

		}
		i++;
	}


	string nx=reg[0];
    i=0;
	while(nx[i])
	{
		switch(nx[i])
		{
			case '0' : b2="0000";
				break;
			case '1' : b2="0001";
				break;
			case '2' : b2="0010";
				break;
			case '3' : b2="0011";
				break;
			case '4' : b2="0100";
				break;
			case '5' : b2="0101";
				break;
			case '6' : b2="0110";
				break;
			case '7' : b2="0111";
				break;
			case '8' : b2="1000";
				break;
			case '9' : b2="1001";
				break;
			case 'A' : b2="1010";
				break;
			case 'B' : b2="1011";
				break;
			case 'C' : b2="1100";
				break;
			case 'D' : b2="1101";
				break;
			case 'E' : b2="1110";
				break;
			case 'F' : b2="1111";
				break;
		}
		i++;
	}
	for(i=0;i<sizeof(b1);i++)
        cout<<b1[i]<<"\n";
	cout<<"\n"<<b2;

  }


          ////////////////////////////////////////////////////





  }

}




















int main()
{
    fstream fout;
    char str[30],st1[10];
    int no;
    char ch,check;
   string reg[7]={" "};
      map<char*,string>*mapping=new map<char*,string>();

    do
    {

    cout<<"\n Press A then m to input or check the value at different address";
    cout<<"\n Press P for writing the program and x to come out of the program";
    cout<<"\n Press E for executing the program";

    cin>>ch;
    switch (ch)
    {
        case 'A':cout<<"\n enter the no of address";
                 cin>>no;
                 cout<<"enter the addresses\n";
                 fout.open("program_file.txt",ios::app|ios::out);
                 while(no>=0)
                 {
                     cin.getline(str,30);
                     fout<<str<<endl;

                  no--;
                 }
                    fout.close();
                     break;
        case 'P':cout<<"\n enter the no of line of the program";
                 cin>>no;
                 cout<<"enter the code\n";
                fout.open("program_file.txt",ios::out|ios::app);
                 while(no>=0)
                 {
                     cin.getline(str,30);
                     fout<<str<<endl;

                  no--;
                 }
                  fout.close();
                 break;
        case 'E':fout.open("program_file.txt",ios::in);


                 while(fout)
                 {
                     fout.getline(st1,10);
                       if(strlen(st1)!=0)
                         {
                          inst(st1,reg,*mapping);
                         }

                 }
                fout.close();
                 break;
    }
    cout<<"\n do you want to continue(y/n)";
    cin>>check;
    }while(toupper(check)=='Y');
     cout<<"A :"<<reg[0]<<"\n";
     cout<<"B :"<<reg[1]<<"\n";
     cout<<"C :"<<reg[2]<<"\n";
     cout<<"D :"<<reg[3]<<"\n";
     cout<<"E :"<<reg[4]<<"\n";
     cout<<"H :"<<reg[5]<<"\n";
     cout<<"L :"<<reg[6]<<"\n";

    return 0;
}











