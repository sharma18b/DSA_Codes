#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class Account
{
public:
    int account_number;
    bool is_open = false;
    int pin;
    double curr_balance;
};


class Bank{
private:
  int active_accounts_count = 0;
  Account all_accs[100];
  int manager_pin = 1234;

  public:
  int find_new_account()
  {
    for (int i=0;i<100;i++)
    {
      if(!(all_accs[i].is_open))
      {
        return i;
      }
    }
  }
  void open_new_account()
  {
    if (active_accounts_count > 100)
    {
      cout << "Sorry the bank has reached the limit of max no. of accounts that could be opened " << endl;
      return;
    }
    double init;
    int pin;
    cout << "Initial deposit ? : ";
    cin >> init;
    cout << "PIN ? : ";
    cin >> pin;
    active_accounts_count++;
    int new_account_index = find_new_account();
    Account acc;
    acc.account_number = 1001 + new_account_index;
    acc.pin = pin;
    acc.is_open = true;
    acc.curr_balance = init;
    all_accs[new_account_index] = acc;
    cout << "New Account Created " << endl << " Account number : " << all_accs[new_account_index].account_number << endl;
  }

  int find_account()
  {
    cout << "Account number ? : ";
    int account_num;
    cin >> account_num;
    if (account_num >= 1001 && account_num <= 1100)
    {
      if (all_accs[account_num - 1001].is_open) return account_num - 1001;
      else
      {
        cout << " No such Account exists Error ! " << endl;
        return -1;
      }
    }
    else
    {
      return -1;
    }
  }
  bool verify_pin(int account_num)
  {
    int pin_test;
    cout << "Pin ? : " << endl;
    cin >>  pin_test;
    if (pin_test == all_accs[account_num].pin)
    {
      return true;
    }
    else
    {
      cout << "Incorrect Pin Error !!";
      return false;
    }
  }
  void balance_inquiry()
  {
     int acc = find_account();
     if (acc==-1) return;
     if (!verify_pin(acc)) return;
     cout << " Account Details " << endl;
     cout << "Account number : " << all_accs[acc].account_number << endl << "Account Current Balance : " << all_accs[acc].curr_balance << endl;
     return;
  }
  void deposit()
  {
    int acc = find_account();
    if (acc==-1) return;
    double amount;
    cout << "Amount ? : ";
    cin >> amount;
    if (!verify_pin(acc)) return;
    all_accs[acc].curr_balance += amount;
    cout << "Account number : " << all_accs[acc].account_number << endl << "Account New Balance : " << all_accs[acc].curr_balance << endl;
  }

  void withdraw()
  {
    int acc = find_account();
    if (acc==-1) return;
    double amount;
    cout << "Amount ? : ";
    cin >> amount;
    if (!verify_pin(acc)) return;
    if (all_accs[acc].curr_balance > amount)
    {
      all_accs[acc].curr_balance -= amount;
      cout << "Account number : " << all_accs[acc].account_number << endl << "Account New Balance : " << all_accs[acc].curr_balance << endl;
    }
    else
    {
       cout << "No sufficient funds Available" << endl;
    }
  }
  void close_the_account()
  {
    int acc = find_account();
    if (acc==-1) return;
    if (!verify_pin(acc)) return;
    all_accs[acc].is_open = false;
    cout << "Account closed Successfully " << endl;
    return;
  }
  void comp_interest()
  {
    double interest_rate;
    cout << "Interest rate ? : ";
    cin >> interest_rate;
    for (int i=0;i<100;i++)
    {
      if (all_accs[i].is_open)
      {
            all_accs[i].curr_balance += (all_accs[i].curr_balance*interest_rate)/100;
      }
    }
    return;
  }

  void print_all()
  {
    int index = 1;
    cout << "All accounts and there amounts respectively " << endl;
    for (int i=0;i<100;i++)
    {
      if (all_accs[i].is_open)
      {
            cout << index << "  Account number : " << all_accs[i].account_number <<  "      Account New Balance : " << all_accs[i].curr_balance << endl;
            index++;
      }
    }

  }
  void close_all()
  {
    for (int i=0;i<100;i++)
    {
      if (all_accs[i].is_open)
      {
        all_accs[i].is_open = false;
      }
    }
    cout << "All accounts closed and exiting program" << endl;
    return;
  }
  bool verify_manager()
  {
    int manager_pin_test;
     cout << "Enter the Manager pin :";
     cin >> manager_pin_test;
     if (manager_pin_test==manager_pin)
     {
       return true;
     }
     else
     {
       cout << "Invalid Manager Pin Error !" << endl;
       return false;
     }

  }

};





int main()
{
  Bank A;
  // int man = 1234;
  // A.manager_pin = man;
  //
  char a;
  bool x = true;
	   do{
       cin >> a;
       switch(a)
       {
          case 'O': A.open_new_account();break;
          case 'B': A.balance_inquiry();break;
          case 'D': A.deposit();break;
          case 'W': A.withdraw();break;
          case 'C': A.close_the_account();break;
          case 'I': {
            if(A.verify_manager())
            {
              A.comp_interest();
            }
          }break;
          case 'P':{
            if(A.verify_manager())
            {
              A.print_all();
            }
          }break;
          case 'E':{
            if(A.verify_manager())
            {
              A.close_all();
            }
          }break;
       }
       if (a=='E') x = false;
     }
     while(x);
     return 0;
}
