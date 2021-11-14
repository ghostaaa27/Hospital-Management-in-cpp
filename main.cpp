#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;

int intCheck(string s);

class Doctor_Others{
    protected:
        string Doctor;
        int DocId;
        int docNum;
        int docSalary;
        int nurNum;
        int nurSalary;

    public:
        Doctor_Others(int a,int b,int c,int d){
                docNum=a;
                docSalary=b;
                nurNum=c;
                nurSalary=d;
        }
        

};

class Patient{
    protected: 
        string patient;
        int patientID;
        string admissionDate;
};

class People_things:  public Doctor_Others, public Patient{
   
   protected:
        
        float medCost;
        float serviceCharge;
        int total; 
        int staffNum;
        int staffSalary;
        string Date;
        string time;

    public:

        People_things(int a,int b,int c,int d,int e,int f) : Doctor_Others(a,b,c,d){
            staffNum=e;
            staffSalary=f;
        }

        virtual void record(){
            
        }
        void result(){}
        virtual void Clear(){}
        virtual void Appointment(){}
        
        
        
        
        
        
};


class Records :  public People_things{
    
    int i;
          
    public:

        Records(int a,int b,int c,int d,int e,int f): People_things(a,b,c,d,e,f){}
        

        void record(){
            ofstream outf("patientprevious.csv", ios:: app);
            ofstream outff("monthlyRecords.txt" , ios :: app);
            ofstream ooo("p.txt");
            


            ifstream inff("serial.txt");
            inff>>i;
            if(i==0)i++;
            inff.close();


            outff<<"Patient No "<<i<<" : "<<"\n";
            //outf<<"Serial No: "<<i<<"\n";
            
            //cin.ignore();
            cout<<"Enter Patient  ID: ";
            cin>>patientID;
            outff<<"Patient ID: "<<patientID<<endl;
            ooo<<"Patient ID: "<<patientID<<endl;
            outf<<patientID<<",";
            getchar();
            cout<<"Enter Doctor Name: ";
            getline(cin,Doctor);
            outf<<Doctor<<",";
            outff<<"Doctor Name: ";
            outff<<Doctor<<"\n";
            ooo<<"Doctor Name: ";
            ooo<<Doctor<<"\n";
            

            cout<<"Enter Patient Name: ";
            getline(cin,patient); 
            outf<<patient<<",";
            outff<<"Patient Name: ";
            outff<<patient<<"\n";
            ooo<<"Patient Name: ";
            ooo<<patient<<"\n";
            
            cout<<"Enter Doctor ID: ";
            cin>>DocId;
            outf<<DocId<<",";
            outff<<"Doctor ID: "<<DocId<<endl;
            ooo<<"Doctor ID: "<<DocId<<endl;


            cout<<"Enter Medicine Cost: ";
            cin>>medCost;
            outf<<medCost<<",";
            outff<<"Medicine Cost: ";
            outff<<medCost<<"\n";
            ooo<<"Medicine Cost: ";
            ooo<<medCost<<"\n";
            


            cout<<"Enter Service charge: ";
            cin>>serviceCharge;
            outf<<serviceCharge<<",";
            outff<<"Service charge: ";
            outff<<serviceCharge<<"\n";
            ooo<<"Service charge: ";
            ooo<<serviceCharge<<"\n";
            


            int total=serviceCharge+medCost;
            outf<<total<<",";
            outff<<"Total Cost: "<<total<<endl;
            ooo<<"Total Cost: "<<total<<endl;

            cout<<"Enter Admission Date: ";
            cin>>admissionDate;
            outff<<"Admission Date: "<<admissionDate<<"\n\n";
            ooo<<"Admission Date: "<<admissionDate<<"\n\n";
            outf<<admissionDate<<","<<endl;

            outf.close();
            outff.close();
            ooo.close();
            

            cout<<endl;

            int graNDTotal;

            ifstream infff("monthlyIncome.txt");
            string gTotal;
            getline(infff,gTotal);
            graNDTotal = intCheck(gTotal);
            infff.close();

            graNDTotal+=total;

           
            ofstream outfff("monthlyIncome.txt");
            outfff<<"Till now total: "<<graNDTotal;
            outfff.close();


            ofstream offff("serial.txt");
            i++;
            offff<<i;
            offff.close();

            cout<<endl;
            cout<<"Record Succesfully Added"<<endl;


            cin.ignore();
            Doctor.clear();
            patient.clear();
            


        }

        void Appointment(){

            ofstream off("appointment.csv",ios::app);
        
           // getchar();
            
            cout<<"Enter Serial Number: ";
            cin>>patientID;
            off<<patientID<<",";
            getchar();

            cout<<"Enter Patient Name: ";
            getline(cin,patient);
            off<<patient<<",";

            cout<<"Enter Doctor Name:  ";
            getline(cin,Doctor);
            off<<Doctor<<",";
            

            cout<<"Enter Doctor ID: ";
            cin>>DocId;
            off<<DocId<<",";
            getchar();

            cout<<"Enter Date: ";
            cin>>Date;
            off<<Date<<",";

            getchar();

            cout<<"Enter Time: ";
            getline(cin,time);
            off<<time<<","<<endl;

            cout<<"\n"<<endl;
            cout<<"Appointment Succesfully Added"<<endl;

            off.close();

        }
        


        void Clear(){
            ofstream outf("patientprevious.csv");
            ofstream outff("monthlyRecords.txt");
            ofstream outfff("monthlyIncome.txt");
            ofstream offff("serial.txt");
            ofstream outffffff("appointment.csv");

            outf<<"";
            outff<<"";
            outfff<<"Till now total: "<<0;
            offff<<0;
            outffffff<<"";

            outf.close();
            outff.close();
            outfff.close();
            offff.close();



        }

        friend int intCheck(string str);
};


class ProfitorLoss : public People_things {
        /*int docNum
        int staffNum
        int nurNum
        int docSalary;
        int staffSalary;
        int nurSalary;*/
        int m1,m2,m3;

        public:

            /*  ProfitorLoss(){
                docNum=0;
                staffNum=0;
                nurNum=0;
                docSalary=0;
                staffSalary=0;
                nurSalary=0;
           }*/

            ProfitorLoss(int a,int b,int c,int d,int e,int f): People_things(a,b,c,d,e,f){}

            void result(){

                int r;
                int Income;
                string incomeStr;

                ifstream inff("monthlyIncome.txt");
                getline(inff,incomeStr);
                Income= intCheck(incomeStr);

                r=Income-(m1+m2+m3);

                cout<<"Doctors Salary Costs: "<<docNum*docSalary<<endl;
                cout<<"Nurses Salary Costs: "<<nurNum*nurSalary<<endl;
                cout<<"Stuffs Salary Costs: "<<staffNum*staffSalary<<endl;
                cout<<"Total Cost: "<<m1+m2+m3<<endl;
                cout<<"Total Income: "<<Income<<endl;
                
                
                if(r>0){
                    cout<<"Total Profit: "<<r<<endl;
                }
                else
                {
                    cout<<"Total loss: "<<r*-1<<endl;
                }     

            }

            void operator*(){

                m1=docNum*docSalary;
                m2=nurNum*nurSalary;
                m3=staffNum*staffSalary;
            }

            friend int intCheck(string str);





};


int intCheck(string s){

                stringstream ss;

                ss<<s;
                string temp;
                int found;

                while(!ss.eof()){

                    ss>>temp;
                    
                    if(stringstream(temp)>>found)
                    break;

                    else temp.clear();
                }
                return found;
}


void Search(){


    ifstream iff("appointment.csv");
    ifstream iiff("patientprevious.csv");
    vector<string>row;
    string temp;
    string str;
    getchar();
    cout<<"Enter The Name or serial Number of Patient : ";
    getline(cin,str);
    int c=0,cc=0;



     while(getline(iff,temp)){
        row.clear();

        //cout<<temp<<endl;
        string s;
            
        for(int i=0;i<temp.size();i++){
                
                if(temp[i]!=','){
                    s.append(1,temp[i]);
                }
                
                else{
                  row.push_back(s);
                  s.clear();
                }
        }

        

        if(str==row[0] || str==row[1]){
            cout<<endl;
            cout<<"Appointment Found. Details Are given below: "<<endl;
            cout<<"Serial No: "<<row[0]<<endl;
            cout<<"Patient Name: "<<row[1]<<endl;
            cout<<"Doctor Name: "<<row[2]<<endl;
            cout<<"Doctor ID: "<<row[3]<<endl; 
            cout<<"Date: "<<row[4]<<endl;
            cout<<"Time: "<<row[5]<<endl;
            c=1;
            break;

        }
        temp.clear();      
    }
    temp.clear();

    string temp1;

    cout<<endl;



    while(getline(iiff,temp1)){
        row.clear();
        

        string ss;
            
        for(int i=0;i<temp1.size();i++){
                
                if(temp1[i]!=','){
                    ss.append(1,temp1[i]);
                }
                
                else{
                  row.push_back(ss);
                  ss.clear();
                }
        }


        if(str==row[0] || str==row[1]){
            cout<<endl;
            cout<<"Previous Data Found. Details Are given below: "<<endl;
            cout<<"Patient ID: "<<row[0]<<endl;
            cout<<"Doctor Name: "<<row[1]<<endl;
            cout<<"Patient Name: "<<row[2]<<endl;
            cout<<"Doctor ID: "<<row[3]<<endl;
            cout<<"Medicine Cost: "<<row[4]<<endl;
            cout<<"Service Charge: "<<row[5]<<endl;
            cout<<"Total Cost: "<<row[6]<<endl;
            cout<<"Admission Date: "<<row[7]<<endl;
            cc=1;
            break;

        }
        temp1.clear();      
    }

    if(c==0  && cc==0){
        cout<<"No data Found"<<endl;
    }

    iff.close();
    iiff.close();


}





int main()
{
    int check=1;
    Records rrr(0,0,0,0,0,0);
    People_things *pt;
    pt=&rrr;


    while(check!=0){
        char ch;
        
        cout<<endl;

        cout<<"Press R/r to enter patient records."<<endl; 
        cout<<"Enter A/a to make an appointment."<<endl;
        cout<<"Press M/m to view monthly Records of patients."<<endl; 
        cout<<"Press S/s to search for  Patient."<<endl;
        cout<<"Press L/l to print last Patient Details."<<endl;
        cout<<"Press P/p to view  Loss/Profit."<<endl;
        cout<<"Press E/e to exit."<<endl;  
        cout<<"Press C/c to clear all records."<<endl; 
        cout<<"\n"<<endl;

        cout<<"Your Choice: ";
        cin>>ch;

       system("Cls");
        cout<<endl;


        if(ch=='r' || ch=='R'){
            pt->record();
        }
        

        else if(ch=='M' || ch=='m'){
            ifstream iff("monthlyRecords.txt");

            if (iff.is_open())cout << iff.rdbuf();
        }

        else if(ch=='P' || ch=='p'){
            int a,b,c,d,e,f;
            cout<<"Enter Doctor Number: ";
            cin>>a;
            cout<<"Enter Doctor Salary: "; 
            cin>>b;
            cout<<"Enter Nurse Number: ";
            cin>>c;
            cout<<"Enter Nurse Salary: ";
            cin>>d;
            cout<<"Enter Staff Number: ";
            cin>>e;
            cout<<"Enter Staff Salary: ";
            cin>>f;

            ProfitorLoss pp(a,b,c,d,e,f);
            *pp;

            cout<<"\n"<<endl;

            pp.result();
        }

        else if(ch=='E' || ch=='e'){
            check=0;
        }

        else if(ch=='a' || ch=='A'){
            pt->Appointment();
        }
        else if(ch=='l' || ch=='L'){
            ifstream iiif("p.txt");

            if (iiif.is_open())cout << iiif.rdbuf();
        }
        else if (ch=='c' || ch=='C'){
            pt->Clear();
            cout<<"Clean succesful!"<<endl;
        }
        else if(ch=='s'  || ch=='S'){
                Search();
        }
        else{
            cout<<"Wrong Input!"<<endl;
        }

        cout<<"\n\n"<<endl;
        //system("Cls");

    }
    return 0;
}