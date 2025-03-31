#include<iostream>
using namespace std;
void display_menu();
void deposit();
void withdraw();
void new_account();
void loan();

int main(){
	while(true){
	
	display_menu();
	cout<<endl;
	int choice ;
	cout<<"Enter your choice : ";
	cin>>choice;
	switch(choice){
		case 1:
			deposit();
			break;
		case 2:
			withdraw();
			break;
		case 3:
			new_account();
		case 4:
			loan();
		case 5:
		cout<<"Exiting from bank management system ";
		break;
		default:
			cout<<"Invalid choice.Please enter valid choice\!";
			break;
			
	}
}
	
	}

void display_menu(){
	cout<<endl;
	cout<<endl<<"\"Welcome to bank management system\" "<<endl;
	cout<<"Press 1.for cash deposit"<<endl;
	cout<<"Press 2.for cash withdrawal"<<endl;
	cout<<"Press 3. for create new account"<<endl;
	cout<<"Press 4, for borrow loan "<<endl;
	cout<<"Press 5.for Exiting from the bank management system "<<endl;
	
}
void deposit(){
	
	int balance,amount;
	cout<<"Enter your previous balance by seeing your account : ";
	cin>>balance;
	cout<<"Enter your amount of deposit : ";
	cin>>amount;
	if(amount>0){
		balance+=amount;
		cout<<"Deposit succesful\!.Your current Balance is : "<<balance<<endl;
	}

	
}
void withdraw(){
	int balance,amount;
	cout<<"Enter your current balance by seeing your account : ";
	cin>>balance;
	cout<<"Enter your amount of withdrawal : ";
	cin>>amount;
	if(amount>0){
		balance-=amount;
		cout<<"Withdrawal successful .Now your new balance is : "<<balance<<endl;
	}
}
	void new_account(){
		int amount;
		cout<<"In what range do you want to create a account  "<<endl;
		cout<<"Enter your amount :  ";
		cin>>amount;
		if((amount>0)&&(amount<100000))
		cout<<"Your account will be student account"<<endl;
		else if((amount>100000)&&(amount<1000000))
		cout<<"Your account will be Salary account "<<endl;
		else if((amount>1000000)&&(amount<10000000))
		cout<<"Your account will be Business account "<<endl;
		
		int a;
		cout<<endl<<"Do you want debit card and chequebook also "<<endl;
		cout<<"If you want,then press 1.If you don\'t want then press 2 "<<endl;
		cin>>a;
		if(a==1)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
}
void loan(){
	string a;
	cout<<"For what purpose do you want loan :  ";
	cin>>a;
	int amount;
	cout<<"How much do you need for loan : ";
	cin>>amount;
	if((amount>0)&&(amount<500000))
	{
		cout<<"Laon will be in 10 installments"<<endl;
		cout<<"Every installment will be "<<amount/10<<endl;
	}
	else if((amount>500000)&&(amount<5000000))
	{
		cout<<"Loan will be in 20 installments "<<endl;
		cout<<"Every installment will be "<<amount/20<<endl;
	}
	else if((amount>5000000)&&(amount<50000000))
	{
		cout<<"Loan will be in 30 installments "<<endl;
		cout<<"Every installment will be "<<amount/30<<endl;
	}
}
	

