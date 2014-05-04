#include<iostream>
//#include<conio.h>
//#include<stdio.h>
#include<fstream>
#include <cstdlib>
//class salary_hra_metro;
using namespace std;
//class to store the details of the employee
class emp_detail
{
    //to store the name of the employee
    char name[50];
    //to store the unique id of the employee(employee code)
    char emp_id[5];
    //to store the address of the employee
    char address[100];
    //to store the mobile no of the employee
    char mobile_no[11];
    //to store the educational qualification
    char edu[20];
    //to store date of birth
    char dob[9];
    //to store the pan card no of the employee
    char pan[10];
    public:
    //to store the age of the employee
    int age;
    //to store the sex of the employee
    char sex;
    //function to input the details of the employee
    void get_detail()
    {
        fflush(stdin);
        cout<<"enter the full name\n";
        gets(name);
        fflush(stdin);
        cout<<"enter your address\n";
        gets(address);
        cout<<"enter sex(M/F)\n";
        cin>>sex;
        fflush(stdin);
        cout<<"enter date of birth(MM/DD/YY)\n";
        gets(dob);
        cout<<"enter your age\n";
        cin>>age;
        fflush(stdin);
        cout<<"enter your educational qualification\n";
        gets(edu);
        fflush(stdin);
        cout<<"enter your mobile no\n";
        gets(mobile_no);
        fflush(stdin);
        cout<<"enter your 5 digit employee code\n";
        gets(emp_id);
        fflush(stdin);
        cout<<"enter your pan number\n";
        gets(pan);

    }//end of get_detail
    //function to show the details of the employee
    void show_detail()
    {
        cout<<"\nname\t:\t";
        puts(name);
        cout<<"sex\t:\t"<<sex;
        cout<<"\nage\t:\t"<<age;
        cout<<"\ndate of birth\t:\t";
        puts(dob);
        cout<<"educational qualification\t:\t";
        puts(edu);
        cout<<"address\t:\t";
        puts(address);
        cout<<"phone no\t:\t";
        puts(mobile_no);
        cout<<"employee id(10 characters)\t:\t";
        puts(emp_id);
        cout<<"pan number\t:\t";
        puts(pan);

    }//end of show_detail
    //friend tax_cal(emp_detail,salary_hra_metro);
};//end of the class emp_detail
//class to find the final tax
class final_tax
{
    float tax;
    //float temp;
    public:
    float cal(float net,int age,char sex)
    {
        float temp=net;
        if(age>60&&age<80)
        {
            if(net<=250000)
            {
                tax=0;
            }
            if(net>250000&&net<=500000)
            {
                temp=temp-250000;
                tax=(0.1*temp);
            }
            if(net>500000&&net<1000000)
            {
                temp=temp-500000;
                tax=(0.1*250000)+(0.2*temp);
            }
            if(net>1000000)
            {
                temp=temp-1000000;
                tax=(0.1*250000)+(0.2*500000)+(0.3*temp);
            }
        }
        else if(age>=80)
        {
            if(net<=500000)
            {
                tax=0;
            }
            if(net>500000&&net<=1000000)
            {
                temp=temp-500000;
                tax=(0.2*temp);
            }
            if(net>1000000)
            {
                temp=temp-1000000;
                tax=(0.2*500000)+(0.3*temp);
            }
        }
        else
        {
            if(sex=='m')
            {
               if(net<=200000)
            {
                tax=0;
            }
            if(net>200000&&net<=500000)
            {
                temp=temp-200000;
                tax=(0.1*temp);
            }
            if(net>=500000&&net<10000000)
            {
                temp=temp-500000;
                tax=(0.1*300000)+(0.2*temp);
            }
            if(net>1000000)
            {
                temp=temp-1000000;
                tax=(0.1*300000)+(0.2*500000)+(0.3*temp);
            }
            }
            else if(sex=='f')
           {
               if(net<=250000)
            {
                tax=0;
            }
            if(net>250000&&net<=500000)
            {
                temp=temp-250000;
                tax=(0.1*temp);
            }
            if(net>500000&&net<1000000)
            {
                temp=temp-500000;
                tax=(0.1*250000)+(0.2*temp);
            }
            if(net>1000000)
            {
                temp=temp-1000000;
                tax=(0.1*250000)+(0.2*500000)+(0.3*temp);
            }
           }


        }
        return tax;
    }
};//end of final_tax
//to store the details regarding the tax redemption
class tax
{
    //each for the various tax redemption section
    float sec1;
    float sec2;
    float sec3;
    float sec4;
    float sec5;
    float sec6;
    float sec81,sec82;
    float sec9;
    float sec10;
    float sec11;
    float sec12;
    float sec13;
    float sec14;
    //to store the max redemtion available
    float total;
    public:
    //function to get the tax information
    void get_info()
    {
        cout<<"\nenter the amount u spend on section 80C\n";
        cin>>sec1;
        cout<<"\nenter the amount u spend on section 80CCC\n";
        cin>>sec2;
        cout<<"\nenter the amount u spend on section 80CCD\n";
        cin>>sec3;
        cout<<"\nenter the amount u spend on section 80D\n";
        cin>>sec4;
        cout<<"\nenter the amount u spend on section 80DD\n";
        cin>>sec5;
        cout<<"\nenter the amount u spend on section 80DDB\n";
        cin>>sec6;
        cout<<"\nenter the amount u spend on section 80E\n";
        cin>>sec81>>sec82;
        cout<<"\nenter the amount u spend on section 80GG\n";
        cin>>sec9;
        cout<<"\nenter the amount u spend on section 80U\n";
        cin>>sec10;
        cout<<"\nenter the amount u spend on section 8024(1)(iv)\n";
        cin>>sec11;
        cout<<"\nenter the amount u spend on section 10(5)\n";
        cin>>sec12;
        cout<<"\nenter the amount u spend on section Superannuation\n";
        cin>>sec13;
        cout<<"\nenter the amount u spend on section Medical allowance\n";
        cin>>sec14;
    }
    //function to calculate a total redemption allowed
    float cal_red()
    {
        get_info();
        total=0;
        float temp;
        temp=sec1+sec2+sec3;
        if(temp>100000)
        {
            total=total+100000;
        }
        else
        {
            total=total+temp;
        }
        if(sec4>20000)
        {
            total=total+20000;
        }
        else
        {
            total=total+sec4;
        }
        if(sec5>50000)
        {
            total=total+50000;
        }
        else
        {
            total=total+sec5;
        }
        if(sec6>40000)
        {
            total=total+40000;
        }
        else
        {
            total=total+sec6;
        }
        total=total+sec81+(0.5*sec82);
        total=total+(0.1*sec9);

        if(sec11>150000)
        {
            total=total+(sec11-150000);
        }
        if(sec13>100000)
        {
            total=total+(sec13-100000);
        }
        if(sec14>15000)
        {
            total=total+(sec14-15000);
        }
        return total;


    }

};//end of the tax class
//to specify the professional tax slab
class pt_slab
{
    private:
    int tax;
    public:
    int andhra_pradesh(float);
    int karnatka(float);
    int west_bengal(float);
    int orissa(float);
    int gujarat(float);
    int kerela(float);
    int pondicherry(float);
    int assam(float);
    int madhya_pradesh(float);
    int maharashtra(float);
};//end of pt_slab
//functions in pt_slab
int pt_slab :: andhra_pradesh(float salary)
{
if(salary<5000)
tax=0;
else if(salary>5000 && salary<6000)
tax=60;
else if(salary>6000 && salary<10000)
tax=80;
else if(salary>10000 && salary<15000)
tax=100;
else if(salary>15000 && salary<20000)
tax=150;
else if(salary>=2000)
tax=200;
return tax;

}
int pt_slab::karnatka(float salary)
{
if(salary<9999)
tax=0;
else if(salary>10000 && salary<15000)
tax=150;
else if(salary>=15000)
tax=200;
return tax;
}
int pt_slab::west_bengal(float salary)
{
    if(salary>2000 && salary<3000)
    tax=0;
    else if(salary>3000 && salary<5000)
    tax=30;
    else if(salary>5000 && salary<6000)
    tax=40;
    else if(salary>6000 && salary<7000)
    tax=45;
    else if(salary>7000 && salary<8000)
    tax=50;
    else if(salary>8000 && salary<9000)
    tax=90;
    else if(salary>9000 && salary<15000)
    tax=110;
    else if(salary>15000 && salary<25000)
    tax=130;
    else if(salary>25000 && salary<40000)
    tax=150;
    else if(salary>40000)
    tax=200;
    return tax;
}
int pt_slab::orissa(float salary)
{
    if(salary<5000)
    tax=0;
    else if(salary>5000 && salary<6000)
    tax=30;
    else if(salary>600 && salary<8000)
    tax=50;
    else if(salary>8000 && salary<10000)
    tax=75;
    else if(salary>10000 && salary<15000)
    tax=100;
    else if(salary>15000 && salary<20000)
    tax=150;
    else if(salary>=20000)
    tax=200;
    return tax;
}
int pt_slab::gujarat(float salary)
{
   if (salary<3000)
   tax=0;
   else if(salary>3000 && salary<6000)
   tax=20;
   else if(salary>6000 && salary<9000)
   tax=80;
   else if(salary>9000 && salary<12000)
   tax=150;
   else if(salary>=12000)
   tax=20;
   return tax;
}
int pt_slab::kerela(float salary)
{
    if(salary<2000)
    tax=0;
    else if(salary>2000 && salary<3000)
    tax=20;
    else if(salary>3000 && salary<5000)
    tax=30;
    else if(salary>5000 && salary<7500)
    tax=50;
    else if(salary>7500 && salary<10000)
    tax=75;
    else if(salary>9999 && salary<12500)
    tax=100;
    else if(salary>12499 && salary<16667)
    tax=125;
    else if(salary>16666 && salary<20834)
    tax=167;
    else if(salary>20834)
    tax=208;
    return tax;
}
int pt_slab::pondicherry(float salary)
{
    if(salary>300 && salary<600)
    tax=1;
    else if(salary>601 && salary<1200)
    tax=2;
    else if(salary>1201 && salary<1800)
    tax=4;
    else if(salary>1801 && salary<3000)
    tax=6;
    else if(salary>3001 && salary<4800)
    tax=12;
    else if(salary>4801 && salary<6000)
    tax=25;
    else if(salary>6001 && salary<9000)
    tax=50;
    else if(salary>9001 && salary<12000)
    tax=75;
    else if(salary>12001 && salary<15000)
    tax=100;
    else if(salary>=15000)
    tax=125;
    return tax;
}
int pt_slab::assam(float salary)
{
    if(salary<3500)
    tax=0;
    else if(salary>3500 && salary<5000)
    tax=30;
    else if(salary>5000 && salary<7000)
    tax=75;
    else if(salary>7000 && salary<9000)
    tax=110;
    else if(salary>9000)
    tax=208;
    return tax;
}
int pt_slab::madhya_pradesh(float salary)
{
    if(salary<10000)
    tax=0;
    else if(salary>10001 && salary<12500)
    {
        tax=83;
    }
    else if(salary>12501 && salary<15000)
    tax=125;
    else if(salary>15000)
    {
        tax=208;
    }
    return tax;
}
int pt_slab::maharashtra(float salary)
{
    if(salary<5001)
    tax=0;
    else if(salary>5001 && salary<10000)
    tax=175;
    else if(salary>=10001)
    {
    tax=200;
    }
    return tax;
}
//class to store the salary info of the employee
class salary:public emp_detail
{
    protected:
    int a;
    char b;
    //this will save the gross salary
    float gross;
    //this will store the basic slary
    float basic;
    //this will save con of the salary
    float con;
    //this will store the medical Reimbursement
    float medical;
    //this will store the Special Allow
    float spe_all;
    public:
    //function to get the salary structure
    void get_salary()
    {

        get_detail();
        a=age;
        b=sex;
        cout<<"enter your basic salary";
        cin>>basic;
        cout<<"enter your con(max of 800/month)";
        cin>>con;
        cout<<"enter your medical reimbursement(max of 1250/month)";
        cin>>medical;
        cout<<"enter your Special Allowance";
        cin>>spe_all;
    }
    //function to show the salary structure
    void show_salary()
    {
        show_detail();
        cout<<"\nyour basic is\t:\t"<<basic;
        cout<<"\nyour con is\t:\t"<<con;
        cout<<"\nyour medical reimbursement is\t:\t"<<medical;
        cout<<"\nyour Special Allowance is\t:\t"<<spe_all;
    }
    //
};//end of class salary
//staring of class salary_hra_metro
class salary_hra_metro:public salary,public pt_slab,public tax,public final_tax
{
    //this will store the hra of the salary
    float hra;
    char state[30];
    float net;
    float pt;
    float red;
    float final;
    float tax;
    public:
    //function to calculate hra for a metro city and net gross income
    void cal_hra()
    {
        get_salary();
        hra=0.5*basic;
        gross=basic+hra+con+medical+spe_all;
    }
    void net_salary()
    {
        fflush(stdin);
        cout<<"\nenter the state in which you are working to calculate professional tax\n";
        gets(state);
        if(state=="agra" || state=="chandigarh" || state=="chattisgarh" || state=="delhi" || state=="goa" || state=="haryana" || state=="himachal_pradesh" || state=="jammu_kashmir" || state=="jharkhand" || state=="manipur" || state=="mizzoram" || state=="punjab" || state=="rajasthan" || state=="uttranchal")
     {

        cout<<"NO salary zone";
        pt=0;
     }
    else
    {
        if(state=="maharashtra")
        pt=maharashtra(gross);

        else if(state=="andhra pradesh")
        pt=andhra_pradesh(gross);
        else if(state=="orissa")
        pt=orissa(gross);
        else if(state=="assam")
        pt=assam(gross);
        else if(state=="madhya pradesh")
        pt=madhya_pradesh(gross);
        else if(state=="kerela")
        pt=kerela(gross);
        else if(state=="karnatka")
        pt=karnatka(gross);
        else if(state=="gujarat")
        pt=gujarat(gross);
        else if(state=="pondicherry")
        pt=pondicherry(gross);
        else if(state=="west bengal")
        pt=west_bengal(gross);
        else
        pt=0;
    }
        net=(gross-pt)*12;
        red=cal_red();
        final=net-red;

    }
   // friend tax_cal(emp_detail,salary_hra_metro);
    void tax_cal()
    {
        //cout<<"\tage"<<a<<"\tsex"<<b;
        tax=cal(final,a,b);
    }

    //function to show the salary details
    void show()
    {
        show_salary();
        cout<<"\nyour hra is\t:\t"<<hra;
        cout<<"\nyour gross income is\t:\t"<<gross;
        cout<<"\nnet salary is\t:\t"<<net;
        cout<<"\nthe final amount of salry for tax\t:\t"<<final;
        cout<<"\nthe total amount you have to pay as tax ="<<tax<<"\n\n";

    }



};//end of class salary_hra_metro
//staring of class salary_hra_non_metro
class salary_hra_non_metro:public salary,public pt_slab,public tax,public final_tax
{
    //this will store the hra of the salary
    float hra;
    char state[50];
    int pt;
    float net;
    float red;
    float final;
    float tax;
    public:
    //function to calculate hra for a metro city and net gross income
    void cal_hra()
    {
        get_salary();
        hra=0.4*basic;
        gross=basic+hra+con+medical+spe_all;
    }
    void net_salary()
    {
        fflush(stdin);
        cout<<"\nenter the state in which you are working to calculate professional tax\n";
        gets(state);
        if(state=="agra" || state=="chandigarh" || state=="chattisgarh" || state=="delhi" || state=="goa" || state=="haryana" || state=="himachal_pradesh" || state=="jammu_kashmir" || state=="jharkhand" || state=="manipur" || state=="mizzoram" || state=="punjab" || state=="rajasthan" || state=="uttranchal")
     {

        cout<<"NO salary zone";
        pt=0;
     }
    else
    {
        if(state=="maharashtra")
        pt=maharashtra(gross);

        else if(state=="andhra pradesh")
        pt=andhra_pradesh(gross);
        else if(state=="orissa")
        pt=orissa(gross);
        else if(state=="assam")
        pt=assam(gross);
        else if(state=="madhya pradesh")
        pt=madhya_pradesh(gross);
        else if(state=="kerela")
        pt=kerela(gross);
        else if(state=="karnatka")
        pt=karnatka(gross);
        else if(state=="gujarat")
        pt=gujarat(gross);
        else if(state=="pondicherry")
        pt=pondicherry(gross);
        else if(state=="west bengal")
        pt=west_bengal(gross);
        else
        pt=0;
    }
        net=(gross-pt)*12;
        red=cal_red();
        final=net-red;

    }
    void tax_cal()
    {
        tax=cal(final,a,b);
    }
    //function to show the salary details
    void show()
    {
        show_salary();
        cout<<"\nyour hra is\t:\t"<<hra;
        cout<<"\nyour gross income is\t:\t"<<gross;
        cout<<"\nnet salary is\t:\t"<<net;
        cout<<"\nthe final amount of salry for tax\t:\t"<<final;
        cout<<"\nthe total amount you have to pay as tax ="<<tax<<"\n\n";
    }
};//end of class salary_hra_non_metro

//starting of the main function
int main()
{
    //fstream f;
    // it will store the choice that u will select from the main menu
    int choice;
    char save;
    salary_hra_non_metro a;
    salary_hra_metro b;
    //it will be used to print the menu again if the user wishes to go back again
    char repeat='y';
    while(repeat=='y')
    {
        //this if the front menu on screen
        cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-MENU-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
        cout<<"\n\t\tPRESS THE RESPECTIVE NO TO GO TO THAT OPTION\n\n";
        cout<<"\n\t\t1.To enter the employee details and calculate INCOME TAX";
        cout<<"\n\t\t2.To view the employee details and income tax status";
        cout<<"\n\t\t3.HELP regarding the income tax execemption\n";
        cin>>choice;
        if(choice==1||choice==2|choice==3)
        {
            switch(choice)
            {
                case 1: char metro;
                        cout<<"\nare you working in a metro city or not.Press y or n\n";
                        cin>>metro;
                        if(metro=='y')
                        {
                            b.cal_hra();
                            b.net_salary();
                            b.tax_cal();
                            b.show();
                            cout<<"\ndo u want to save this info.Press y or n";
                            cin>>save;
                            if(save=='y')
                            {

                                ofstream f("student.txt",ios::app);
                                f.write((char*)&b,sizeof(b));
                                f.close();
                            }
                        }
                        else if(metro=='n')
                        {
                            a.cal_hra();
                            a.net_salary();
                            a.tax_cal();
                            a.show();
                            cout<<"\ndo u want to save this info.Press y or n";
                            cin>>save;
                            if(save=='y')
                            {
                                ofstream f1("student1.txt",ios::app);
                                f1.write((char*)&a,sizeof(a));
                                f1.close();
                            }


                        }
                        else
                        {
                            cout<<"\nunauthorised input\n";
                        }
                        break;


                case 2: {system("cls");
                        fstream p("student.txt",ios::in);
                        salary_hra_metro c;
                        salary_hra_non_metro d;
                        int i=1;
                        p.seekg(0);
                        while(p.eof()==0)
                        {

                            cout<<i++<<"\n";
                            p.read((char*)&c,sizeof(c));
                            c.show();
                        }
                        p.close();



                        fstream p1("student1.txt",ios::in);
                        //p.seekg(0);
                        while(p1.eof()==0)
                        {
                            cout<<i++<<"\n";
                            p1.read((char*)&d,sizeof(d));

                            d.show();

                        }

                        p1.close();


                        break;
                        }

                case 3: system("cls");
                        cout<<"\nLet us start with the introduction of various sections available in Income Tax act which provides exemptions from income tax liability under some specific conditions. These sections are described below";
                        cout<<"\n:1. Section 80C :";
                        cout<<"\n\nTax payers can avail an advantage of maximum limit up to Rs 1, 00, 000 by investing in securities which comes under this section along with section 80CCC and 80CCD. If a taxpayer’s taxable income lies in the highest tax bracket, he/she can take advantage of Section 80C to reduce his/her taxable income by Rs.1 lakh. The following is a list of important ways in which a taxpayer can get benefit of section 80C of Indian Income Tax Act : Public Provident FundEmployee Provident FundLife Insurance PremiumUnit Linked Insurance Plans(ULIP)Equity Linked Savings Scheme(ELSS)National Savings Certificate(NSC)5 year Fixed deposits with banks and post officeHome loan principal paymentTuition fee paid for children’s education (maximum of 2 children)";
                        cout<<"\n2. Section 80CCC :\nSection 80CCC allows you to get a deduction in respect of premium paid for annuity plan of LIC or Other Insurer.\n3. Section 80CCD :\nSection 80CCD allows you a deduction in respect of contribution to pension account. Deposit made by a Central government servant in his pension account to the extent of 10% of his salary.\n4. Section 80D :\nSection 80D of Indian Income Tax Act is especially useful if the employer does not cover their employee’s health or medical expenses. One can avail a benefit of Rs. 15,000 for insuring self spouse and children. Medical insurance for parents above 65 years can avail a benefit up to Rs 20, 000.\n5. Section 80DD :\nSection 80DD of Indian Income Tax Act provides provision for tax deduction if taxpayer incurs medical expenditure for the dependents who are disabled. Maximum deduction allowed is Rs. 50,000/- in case of normal disability and Rs. 1 Lakh in case of severe disability.";
                        cout<<"\n6. Section 80DDB :\nCosts incurred for treatment of specified illnesses like Neurological diseases, malignant cancers, Chronic Renal Failure etc, could fetch one a tax benefit under section 80DDB. For individual less than 60 years of age, a deduction limit of Rs. 40,000 is applicable. For a senior citizen, the limit is Rs. 60,000.\n7. Section 80E :\nUnder section 80E of Indian Income Tax Act, any amount of interest paid on educational loan taken for individual higher education or higher education of individual’s husband / wife or children is deductible from taxable income.\n8. Section 80G :\nDonations made to funds are deductible from taxable income according to section 80G of Indian Income Tax Act. The extent of deduction is either 50% or 100% of the contribution, depending on the charitable institution donated to. But one needs to know that donations made to not all charitable institutions qualify for a deduction. Here is a list of approved charitable institutions and funds that qualify for a deduction.";
                        cout<<"\nDonations with 100% deduction without any qualifying limit :\na.Prime Ministers National Relief Fund\nb.National Defence Fund\nc.Prime Ministers Armenia Earthquake Relief Fund\nd.The Africa (Public contribution- India) Fund\ne.The National Foundation for Communal Harmony\nf. Approved university or educational institution of national eminence\ng.The Chief Minister’s Earthquake Relief Fund, Maharashtra\nh.Donations made to Zila Saksharta Samitis\ni.The National Blood Transfusion Council or a State Blood Transfusion Council\nj.The Army Central Welfare Fund or the Indian Naval Benevolent Fund or The Air Force Central Welfare Fund.";
                        cout<<"\nDonations with 50% deduction without any qualifying limit :\na. Jawaharlal Nehru Memorial Fund\nb. Prime Minister’s Drought Relief Fund\nc.National Children’s Fund\nd. Indira Gandhi Memorial Trust\ne.The Rajiv Gandhi Foundation";
                        cout<<"\n9. Section 80GG :\nAny House Rent Allowance given to an employee is tax free up to the minimum value of the conditions like 50% of basic salary, rent paid over 10% of annual income, actual HRA received etc.\n10. Section 80U :\nIt is deduction of amount in the case of a person with disability. An individual who is suffering from a permanent disability or mental retardation as specified in the Persons with Disabilities Act, 1995 or the National Trust for Welfare of Persons with Autism, Cerebral Palsy, Mental Retardation and Multiple Disabilities Act, 1999, shall be allowed a deduction of Rs 50,000. In case of severe disability the deduction is Rs. 1, 00,000.\n11. Section 24(1)(vi) :\nIndividuals can avail a tax benefit of up to Rs. 1, 50, 000 for Housing loan interest according to this section.\n12. Section 10(5) :\nThis section allows you to avail tax benefit on leave travel allowance which will be available twice in span of 4 years.";
                        cout<<"\n13. Superannuation :\nAny contribution made by a company to a superannuation fund up to Rs. 1, 00,000 is tax free in the hands of the employee.\n14. Medical allowance :\nAny Medical Allowance given to an employee is tax free up to Rs. 15,000 /-\n";
            }
        }
        else
        {
            cout<<"\nYou have entered an invalid choice.\nPlease try again";
        }
        cout<<"\nTo go back to the MENU again then press 'y' else press any key to exit\n\n";
        cin>>repeat;
       system("cls");

    }

}
