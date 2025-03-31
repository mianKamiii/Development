#include<iostream>
using namespace std;
class employee{
	protected:
		int ID;
		string name;
		string department;
		int stock;
	public:
			employee(){
				cout<<"Enter the ID of employee : ";cin>>ID;
				cout<<"Enter the name of employee : ";cin>>name;
				cout<<"Enter the department of enmployee : ";cin>>department;
			}
		
};
class field{
	protected:
		int footbalrequired;
		int paddlerequired;
		int hockeyrequired;
		int batrequired;
		int bladderrequired;
		int sportswearrequired;
	public:
		void footbal(){
			cout<<endl<<" ID of product in fcatory is : 101 "<<endl;
			cout<<"Daily production of footabll is 250"<<endl;
			cout<<"Number of employees working in football departmnet is 50 "<<endl;
			cout<<"Number of press used in footbal in one unit : 5 pressses"<<endl;
		}
		void paddle(){
			cout<<endl<<"Id of product in fcatory is : 301 "<<endl;
			cout<<"Daily production of paddle is : 150"<<endl;
			cout<<"Number of empoyees working in paddle department is : 40 "<<endl;
			cout<<"Number of dyes used in paddle in one unit : 6 dyes "<<endl;
		}
		void hockey(){
			cout<<endl<<"ID of product in fcatory is : 470 "<<endl;
			cout<<"Daily production of hockey is : 120"<<endl;
			cout<<"Number of employees working in hockey department : 40"<<endl;
			cout<<"Number of machines used in this department : 20 "<<endl;
		}void bat(){
			cout<<endl<<"Id of product in factory is : 570 "<<endl;
			cout<<"Daily production of bat is : 100 "<<endl;
			cout<<"Number of employees working in bat department : 40 "<<endl;
			cout<<"Number of machines used in this department : 6 "<<endl;
		}
		void bladder(){
			cout<<endl<<"Id of product in factory is : 620 "<<endl;
			cout<<"Daily production of bladder is : 800 "<<endl;
			cout<<"Number of employees working in  department : 50 "<<endl;
			cout<<"Number of machines used in this department : 12 "<<endl;
		}
		void sports_wear(){
			cout<<endl<<"Id of product in factory is : 940 "<<endl;
			cout<<"Daily production of sports wear items  is : 100 "<<endl;
			cout<<"Number of employees working in  department : 40 "<<endl;
			cout<<"Number of machines used in this department : 20"<<endl;
		}
	};
	class footbalpurchase:public field{
		public:
			footbalpurchase(){
	         int maxstock=100000;
	         int price=1200;
			cout<<endl<<"How many footballs do yo need : ";cin>>footbalrequired;
			if(footbalrequired>=maxstock)
			cout<<"Too much demand.Its takes a long time to make"<<endl;
			else if(footbalrequired<=maxstock)
			{
			maxstock=maxstock-footbalrequired;
			cout<<"Price of one footbal is : "<<price<<endl;
			cout<<"Price of your order : "<<price*footbalrequired<<endl;
			cout<<"You will be provided from the stock .\nRemaining stock is : "<<maxstock<<endl;
		}
	}
	};
	class paddlepurchase:public field{
		public:
			paddlepurchase(){
	         int maxstock=100000;
	         int price=3000;
			cout<<endl<<"How many paddles do yo need : ";cin>>paddlerequired;
			if(paddlerequired>=maxstock)
			cout<<"Too much demand.Its takes a long time to make"<<endl;
			else if(paddlerequired<=maxstock)
			{
			maxstock=maxstock-paddlerequired;
			cout<<"Price of one paddle is "<<price<<endl;
			cout<<"Price of your order : "<<price*paddlerequired<<endl;
			cout<<"You will be provided from the stock .\nRemaining stock is : "<<maxstock<<endl;
		}
	}
	};
	class hockeypurchase:public field{
		public:
			hockeypurchase(){
	         int maxstock=100000;
	         int price=5000;
			cout<<endl<<"How many hockeys do yo need : ";cin>>hockeyrequired;
			if(hockeyrequired>=maxstock)
			cout<<"Too much demand.Its takes a long time to make"<<endl;
			else if(hockeyrequired<=maxstock)
			{
			maxstock=maxstock-hockeyrequired;
			cout<<"Price of one hockey is "<<price<<endl;
			cout<<"Price of your order : "<<price*hockeyrequired<<endl;
			cout<<"You will be provided from the stock .\nRemaining stock is : "<<maxstock<<endl;
		}
	}
	};
	class batpurchase:public field{
		public:
			batpurchase(){
	         int maxstock=100000;
	         int price=8000;
			cout<<endl<<"How many Bats do yo need : ";cin>>batrequired;
			if(batrequired>=maxstock)
			cout<<"Too much demand.Its takes a long time to make"<<endl;
			else if(batrequired<=maxstock)
			{
			maxstock=maxstock-batrequired;
			cout<<"Price of one bat is "<<price<<endl;
			cout<<"Price of your order : "<<price*batrequired<<endl;
			cout<<"You will be provided from the stock .\nRemaining stock is : "<<maxstock<<endl;
		}
	}
	};
	class bladderpurchase:public field{
		public:
			bladderpurchase(){
	         int maxstock=100000;
	         int price=1500;
			cout<<endl<<"How many Bladders do yo need : ";cin>>bladderrequired;
			if(bladderrequired>=maxstock)
			cout<<"Too much demand.Its takes a long time to make"<<endl;
			else if(bladderrequired<=maxstock)
			{
			maxstock=maxstock-bladderrequired;
			cout<<"Price of one bladder is "<<price<<endl;
			cout<<"Price of your order : "<<price*bladderrequired<<endl;
			cout<<"You will be provided from the stock .\nRemaining stock is : "<<maxstock<<endl;
		}
	}
	};
	class sportwearpurchase:public field{
		public:
			sportwearpurchase(){
	         int maxstock=100000;
	         int price=800;
			cout<<endl<<"How many track suits do yo need : ";cin>>sportswearrequired;
			if(sportswearrequired>=maxstock)
			cout<<"Too much demand.Its takes a long time to make"<<endl;
			else if(sportswearrequired<=maxstock)
			{
			maxstock=maxstock-sportswearrequired;
			cout<<"Price of one Tarck Suit  is "<<price<<endl;
			cout<<"Price of your order : "<<price*sportswearrequired<<endl;
			cout<<"You will be provided from the stock .\nRemaining stock is : "<<maxstock<<endl;
		}
	}
	};
class salary:public employee{
	public:
		
		    salary(){
			
			if(department=="footbal")
			cout<<"salary of worker is : 25000"<<endl;
			else if(department=="paddle")
			cout<<"salary of worker is : 23500"<<endl;
			else if(department=="hockey")
			cout<<"Salary of worker is : 28000"<<endl;
			else if(department=="bladder")
			cout<<"Salary of workers is : 27500"<<endl;
			else if(department=="Bat")
			cout<<"Salary of workers is : 29000"<<endl;
			else if(department=="sports wear")
			cout<<"Salary of workers is : 22000"<<endl;
		}
};
class getjob{
		protected:
			int age;
			string name;
			string dept;
			public:
			getjob(){
				cout<<"Enter Your age : ";cin>>age;
				cout<<"Enter your name : ";cin>>name;
				cout<<"Enter your department : ";cin>>dept;
			}
	};
	class conditions:public getjob{
	public:
		conditions(){
			if(age<20)
			cout<<"Your are not eligible for this job "<<endl;
			else if(dept=="bat")
			cout<<"Starting  Salary will be 18000"<<endl;
			else if(dept=="footbal")
			cout<<"Starting Salary will be 20000"<<endl;
			else if(dept=="hockey")
			cout<<"Starting salary will be 19500"<<endl;
			else if(dept=="paddle")
			cout<<"Starting salary will be 17000 "<<endl;
			else if(dept=="bladder")
			cout<<"Starting salary will be 21000"<<endl;
			else if(dept=="sports_wear")
			cout<<"Starting salary will be 18500 "<<endl;
		}
		
	};
class account{
	public:
     account(){
			cout<<"Number of employees in account department is : 15 "<<endl;
			cout<<"Number of employeees maintaining footabll department workers salary : 5 "<<endl;
			cout<<"Number of employeees maintaining paddle department workers salary : 5 "<<endl;
			cout<<"Number of employeees maintaining hockey department workers salary : 5 "<<endl;
		}
	};
	class security{
	protected:
		string name;
		int id;
		string location;
	public:
		security(){
		
		cout<<endl<<"Number of guards in a fcatory : 15 "<<endl;
		cout<<"Enter the name of security guard : ";cin>>name;
		cout<<"Enter the ID of security guard : ";cin>>id;
		cout<<"Enter the location of guard duty in factory : ";cin>>location;
		}
		
};
class salary1:public security{
	public:
		salary1(){
		    if(location=="gate")
			cout<<"Salary of security guard is : 20000"<<endl;
			else if(location=="hall")
			cout<<"Salary of security guard is : 15000"<<endl;
			else if(location=="production_area")
			cout<<"Salary of security guard is : 14500"<<endl;}
};
void display(){
	cout<<endl<<"-------------------------------------------------------------------------"<<endl;
	cout<<endl<<"Enter the choice in which department of fcatory you are interested : "<<endl;
	cout<<endl<<"For Employee department,press 1"<<endl;
	cout<<"For sports production record,press 2"<<endl;
	cout<<"For account department information , press 3 "<<endl;
	cout<<"For security department information , press 4 "<<endl;
	cout<<"For purchsing department , press 5 "<<endl;
	cout<<"For getting job ,press 6 "<<endl;
	cout<<"Press 7 for exit "<<endl;
}
void display_field(){
	cout<<endl<<"Press 1 for footbal department information "<<endl;
	cout<<"Press 2 for paddle department information "<<endl;
	cout<<"Press 3 for hockey department information "<<endl;
	cout<<"Press 4 for bat department information "<<endl;
	cout<<"Press 5 for bladder department information "<<endl;
	cout<<"Press 6 for sports wear department information "<<endl<<endl;
}
class total_employee{
	public:
		total_employee(){
			const int employees=300;
			cout<<"Total number of employees in factory : "<<employees<<endl;
		}
};
class purchase{
	public:
		purchase(){
			cout<<"Press 1 for footbal purchasing "<<endl;
			cout<<"Press 2 for paddle purchsing "<<endl;
			cout<<"Press 3 for hockey purchsing "<<endl;
			cout<<"Press 4 for bat purchasing "<<endl;
			cout<<"Press 5 for bladder purchasing "<<endl;
			cout<<"Press 6 for sports wear items purchasing  "<<endl;
		}
};


int main(){
	cout<<"------AK sports factory-----"<<endl;
	int k;
    
	cout<<endl<<"To get entry into the factory,enter your cnic number :";cin>>k;
	cout<<endl<<"----------Welcome to the branded AK sports Factrory.------------"<<endl;
    cout<<"                                                                      "<<endl;
    total_employee ak;
    
	while(k!=0){
	display();
	field f;
	int a;
	cout<<endl<<"Enter your choice of department : ";cin>>a;
	if(a==1)
	salary s;
	else if(a==2){
		cout<<"Now you are in sports department ."<<endl;
		display_field();
	int n;
	cout<<"Enter your choice of sport field : ";cin>>n;
	if(n==1)
	f.footbal();
	else if(n==2)
	f.paddle();
	else if(n==3)
	f.hockey();
	else if(n==4)
	f.bat();
	else if(n==5)
	f.bladder();
	else if(n==6)
	f.sports_wear();}
	else if(a==3){
	account c;	
	}
	else if(a==4){
		salary1 sc1;
		}
	else if(a==5){
		cout<<endl<<"Now you are in purchasing department "<<endl;
		purchase p;
		int z;
		cout<<endl<<"which product do you want to buy \? ";cin>>z;
		
		if(z==1){
		footbalpurchase fp;
		}
		else if(z==2){
			paddlepurchase pd;
		}
		else if(z==3){
			hockeypurchase hp;
		}
		else if(z==4){
			batpurchase bt;
		}
		else if(z==5){
			bladderpurchase bld;
		}
		else if(z==6){
			sportwearpurchase spt;
		}
	}
	else if(a==6){
		conditions gc;
	}
	else if(a==7)
	cout<<endl<<"\a Thanks for visiting , Sir.\n See you again. "<<endl;
	cout<<"        -----------                "<<endl;
}
}