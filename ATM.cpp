#include <iostream>
using namespace std;
class ATM{
    private:
       int balance,pincode,success;
    public:
       ATM(int bal,int pin){
          balance=bal;
          pincode=pin;
       }
    int getbalance(){
        return balance;
    }
    int withdraw(int amount,int pin){
        if(pin!=pincode){
            return false;
        }
        if(amount>balance){
            return false;
        }
            balance-=amount;
            return true;
    }    
    void deposit(int amount){
        balance+=amount;
    }  
    int transfer(int amount,ATM &reciever,int pin){
        if(pin!=pincode){
            return false;
        }
        success=withdraw(amount,pin);
        if(success){
            reciever.deposit(amount);
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    int amount,pin,success,choice;
    char op;
    ATM atm(1000,1890);
    ATM reciever(2000,1234);
    do{
        cout<<"1. Check balance"<<endl;
        cout<<"2. Cash withdraw"<<endl;
        cout<<"3. Cash deposit"<<endl;
        cout<<"4. Cash transfer"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter the choice:";
        cin>>choice;
        switch(choice){
            case 1:
               cout<<"\nYour balance:"<<atm.getbalance()<<endl;
               break;
            case 2:
               cout<<"Your available balance:"<<atm.getbalance()<<endl;
               cout<<"Enter the amount to withdraw:";
               cin>>amount;
               cout<<"\nEnter the pin:";
               cin>>pin;
               success=atm.withdraw(amount,pin);
               if(success){
                 cout<<"\nWithdraw successful..."<<endl;
               }
               else{
                 cout<<"Invalid pin or insufficient balance"<<endl;
               }
               break;
            case 3:
               cout<<"Your available balance:"<<atm.getbalance()<<endl;
               cout<<"Enter the amount to deposit:";
               cin>>amount;
               atm.deposit(amount);
               cout<<"\nDeposit successful..."<<endl;   
               break;
            case 4:
               cout<<"Your available balance:"<<atm.getbalance()<<endl; 
               cout<<"Enter the amount to transfer:";
               cin>>amount;
               cout<<"\nEnter the pin:";
               cin>>pin;  
               success=atm.transfer(amount,reciever,pin);
               if(success){
                 cout<<"\nTransfer successful..."<<endl;
               }
               else{
                cout<<"\nInvalid pin or insufficient balance"<<endl;
               }
               break;
            case 5:
               cout<<"Thanks for using ATM"<<endl;
               exit(1);
               break;
            default:
               cout<<"Invalid choice!"<<endl;      
        }
        cout<<"\nDo you want to make another transaction[y/n]:";
        cin>>op;
    }while(op=='y'||op=='Y');
    return 0;
}