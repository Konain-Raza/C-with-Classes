#include <conio.h>
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct Predefined
{
  string email;
  string password;
  string account_type;
  string pin;
  string credit_card;
  int total_balance;
  string username;
};

Predefined member[100];
Predefined newMember;
int memberCount = 5;
int notes[4] = {20, 20, 20, 20};
int note_values[4] = {100, 500, 1000, 5000};
string email, password, admin_email, admin_password, credit_card, pin, remenu;
int email_check = 0, atm_menu, userindex = -1, admin_option;
bool goBackToMainMenu = true;
string pinInput;
char ch;

bool loggedIn = false;

void signUp()
{
  if (memberCount < 100)
  {
    system("cls");
    Predefined newMember;
    ofstream file("user_credentials.txt", std::ios::app);

    if (file.is_open())
    {
      cout << endl
           << endl
           << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
      cout << "Note: The List of Banks which are registered in this ATM are: "
           << endl
           << endl;
      cout << "1. Bank Name: Mezaanbank      Domain: username@mezaanbank.pk"
           << endl;
      cout << "2. Bank Name: Silkbank        Domain: username@silkbank.pk"
           << endl;
      cout << "3. Bank Name: HBLbank         Domain: username@hblbank.pk"
           << endl;
      cout << "4. Bank Name: UBLbank         Domain: username@ublbank.pk"
           << endl
           << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
      cout << "Enter your email: ";
      cin >> newMember.email;

      for (int i = 0; i < memberCount; i++)
      {
        if (member[i].email == newMember.email)
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Email already exists. Please choose a different email."
               << endl;
          return;
        }
      }
      if (!(newMember.email.find("@mezaanbank.pk") != string::npos ||
            newMember.email.find("@hblbank.pk") != string::npos ||
            newMember.email.find("@ublbank.pk") != string::npos ||
            newMember.email.find("@silkbank.pk") != string::npos))
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\nWrong email. Please use the email domain '@mezaanbank.pk','@ublbank.pk', '@silkbank.pk', '@hblbank.pk'\n";
        return;
      }
      else if (newMember.email.length() > 30)
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\nWrong email. Email cannot be greater than 30!\n";
        return;
      }

      cout << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
      cout << "Note: Password can't be greater than 20 characters." << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
      cout << "Enter your password: ";
      cin >> newMember.password;

      if (newMember.password.length() > 20)
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\nPassword cannot be greater than 20 characters." << endl;
        return;
      }

      int acctype_op = 0;
      cout << endl;
      cout << "  ";
      cout << " \n _____________________";
      cout << "\n|    Account Types    |";
      cout << "\n|---------------------|";
      cout << "\n| 1. Current          |";
      cout << "\n| 2. Saving           |";
      cout << "\n|_____________________|" << endl
           << endl;
      cout << "Enter your Option: ";
      cin >> acctype_op;

      if (acctype_op == 1)
      {
        newMember.account_type = "Current";
      }
      else if (acctype_op == 2)
      {
        newMember.account_type = "Saving";
      }
      else
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\nAccount Type must be Current or Saving" << endl;
        return;
      }

      cout << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
      cout << "Note: PIN can't be greater than 4 digits." << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
      cout << "Enter your PIN (4 digits): ";
      pinInput.clear();
      for (int i = 0; i < 4; i++)
      {
        ch = getch();
        pinInput.push_back(ch);
        cout << "*";
      }

      newMember.pin = pinInput;
      cout << endl;

      if (newMember.pin.length() > 4)
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "\nPIN cannot be greater than 4 digits." << endl;
        return;
      }

      cout << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
      cout << "Note: Credit Card Number can't be greater than 14 digits." << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
      cout << "Enter your credit card number (14-digit without dashes): ";
      cin >> newMember.credit_card;

      if (newMember.credit_card.length() > 14)
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Credit card number can't be longer than 14 digits." << endl;
        return;
      }

      cout << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
      cout << "Note: Username can't be greater than 20 characters." << endl;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
      cout << "Enter your username: ";
      cin >> newMember.username;

      if (newMember.username.length() > 20)
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Username can't be greater than 20 characters." << endl;
        return;
      }

      cout << "\nEnter your initial balance: ";
      cin >> newMember.total_balance;
	  if(newMember.total_balance<=0){
	  	cout<< "Initial Balance should not in negative balance"<<endl;
	  	return;
	  }
	  
      member[memberCount] = newMember;
      memberCount++;
      string signupmsg = "Signup successful!";
      string registered = "Signup successful!";
      for (char ch : signupmsg)
      {
        cout << ch;
        Sleep(30);
      }
      if (registered == "Signup successful!")
      {
        file << "Email: " << newMember.email << endl;
        file << "Password: " << newMember.password << endl;
        file << "Account Type: " << newMember.account_type << endl;
        file << "PIN: " << newMember.pin << endl;
        file << "Credit Card: " << newMember.credit_card << endl;
        file << "Username: " << newMember.username << endl;
        file << "Initial Balance: " << newMember.total_balance << endl;
        file.close();
      }

      userindex = memberCount - 1;
      loggedIn = true;
    }
    else
    {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
      cout << "Maximum number of members reached." << endl;
    }
  }
  else
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Unable to open the file for writing." << endl;
    return;
  }
}

bool verifyCredentials(string email, string password, string credit_card, string pin, int &userindex)
{
  for (int i = 0; i < memberCount; i++)
  {
    if (member[i].email == email)
    {
      userindex = i;
      break;
    }
  }

  if (userindex == -1)
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "User not found." << endl;
    return false;
  }

  if (member[userindex].password != password)
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Incorrect password." << endl;
    return false;
  }

  if (member[userindex].credit_card != credit_card)
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Wrong credit card number." << endl;
    return false;
  }

  if (member[userindex].pin != pin)
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Invalid PIN." << endl;
    return false;
  }

  loggedIn = true;
  return true;
}

void withdraw(int userindex)
{
  int withdraw_menu_option = 0;
  int withdraw_money = 0;
  system("color 02");
  cout << "\n _____________________";
  cout << "\n|   Withdrawal Menu   |";
  cout << "\n|---------------------|";
  cout << "\n| 1. 500              |";
  cout << "\n| 2. 2000             |";
  cout << "\n| 3. 10000            |";
  cout << "\n| 4. 25000            |";
  cout << "\n|_____________________|";
  cout << endl
       << endl;
  cout << "Enter your option: ";
  cin >> withdraw_menu_option;

  switch (withdraw_menu_option)
  {
  case 1:
    withdraw_money = 500;
    break;
  case 2:
    withdraw_money = 2000;
    break;
  case 3:
    withdraw_money = 10000;
    break;
  case 4:
    withdraw_money = 25000;
    break;
  default:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Wrong Option" << endl;
    return;
  }

  int charges = 0;
  if (member[userindex].account_type == "Current")
  {
    charges = 13 * withdraw_money / 100;
  }

  if (withdraw_money <= member[userindex].total_balance - charges)
  {
    int remaining_amount = withdraw_money;
    int dispensed_notes[4] = {0, 0, 0, 0};

    for (int i = 3; i >= 0; i--)
    {
      int note_quantity = min(notes[i], remaining_amount / note_values[i]);
      dispensed_notes[i] = note_quantity;
      remaining_amount -= note_quantity * note_values[i];
    }

    if (remaining_amount == 0)
    {
      system("cls");
      cout << "Dispensing Notes";
      for (int i = 0; i < 4; i++)
      {
        for (int j = 0; j < 4; j++)
        {
          cout << (".");
          Sleep(30);
        }
      }
      for (int i = 3; i >= 0; i--)
      {
        if (dispensed_notes[i] > 0)
        {
          cout << endl;
          cout << "Rs " << note_values[i] << ": " << dispensed_notes[i]
               << " notes" << endl;
          notes[i] -= dispensed_notes[i];
        }
      }
      member[userindex].total_balance -= (withdraw_money + charges);
      cout << endl;
      cout << "Remaining Balance: " << member[userindex].total_balance << endl;

      if (charges > 0)
      {
        cout << "Charges applied: " << charges << endl;
        if (member[userindex].account_type == "Current")
        {
          cout << "Charges canceled due to account type." << endl;
          member[userindex].total_balance += charges;
        }
      }

      cout << "\nWould you like a receipt? [Y / N]: ";
      char receipt_choice;
      cin >> receipt_choice;

      if (receipt_choice == 'Y' || receipt_choice == 'y')
      {
        const int receipt_cost = 5;
        if (member[userindex].total_balance >= receipt_cost)
        {
          member[userindex].total_balance -= receipt_cost;
          cout << endl;
          cout << ("Printing Receipt ");
          for (int i = 0; i < 4; i++)
          {
            for (int j = 0; j < 4; j++)
            {
              cout << (".");
              Sleep(250);
            }
          }
          cout << endl
               << endl;
          cout << "\nUpdated Balance: " << member[userindex].total_balance
               << endl;
          ofstream file("user_credentials.txt");
          if (file.is_open())
          {
            for (int i = 0; i < memberCount; i++)
            {
              // Update the balance of the user
              if (i == userindex)
              {
                file << "Email: " << member[i].email << endl;
                file << "Password: " << member[i].password << endl;
                file << "Account Type: " << member[i].account_type << endl;
                file << "PIN: " << member[i].pin << endl;
                file << "Credit Card: " << member[i].credit_card << endl;
                file << "Username: " << member[i].username << endl;
                file << "Initial Balance: " << member[i].total_balance << endl;
              }
              else
              {
                // Write other users' details as it is
                file << "Email: " << member[i].email << endl;
                file << "Password: " << member[i].password << endl;
                file << "Account Type: " << member[i].account_type << endl;
                file << "PIN: " << member[i].pin << endl;
                file << "Credit Card: " << member[i].credit_card << endl;
                file << "Username: " << member[i].username << endl;
                file << "Initial Balance: " << member[i].total_balance << endl;
              }
              file << endl;
            }
            file.close();
          }
          else
          {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            cout << "Failed to open the file for updating the balance." << endl;
          }
        }

        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "\nInsufficient balance to print the receipt." << endl;
        }
      }
    }
    else
    {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
      cout << "\nUnable to dispense the requested amount." << endl;
    }
  }
  else
  {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "\nInsufficient balance." << endl;
  }
}

int main()
{

  member[0] = {"konainraza@mezaanbank.pk", "Paris2023", "Current", "1732", "98654723015489", 27000, "KonainRaza"};
  member[1] = {"huzaifa@hblbank.pk", "Sydney!2023", "Saving", "4829", "58294367120938", 27000, "MuhammadHuzaifa"};
  member[2] = {"ahmedkhan@ublbank.pk", "Tokyo#2020", "Current", "6924", "76412953872651", 27000, "AhmedKhan"};
  member[3] = {"zahim@silkbank.pk", "Barcelona$2022", "Saving", "5813", "21348597630247", 27000, "ZahimZahid"};
  member[4] = {"khubaib@mezaanbank.pk", "Rome*2025", "Current", "45781236904573", "7546", 27000, "Khubaib"};
  system("color 02");
  COORD pos = {25, 5};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  string welcomemsg = "Welcome to our ATM. Your convenient and secure banking solution awaits.";
  for (char ch : welcomemsg)
  {
    cout << ch;
    Sleep(30);
  }

ReMenu:
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
  cout << endl
       << endl;
  pos = {46, 10};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << " ________________________ ";
  pos = {46, 11};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "|          ATM           |";
  pos = {46, 12};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "|------------------------|";
  pos = {46, 13};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "| 1. Inquire Balance     |";
  pos = {46, 14};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "| 2. Withdraw            |";
  pos = {46, 15};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "| 3. Admin Panel         |";
  pos = {46, 16};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "| 4. Signup              |";
  pos = {46, 17};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "| 5. Exit                |";
  pos = {46, 18};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "|________________________|";
  pos = {46, 19};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << endl
       << endl;
  pos = {46, 21};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
  cout << "Enter your Option: ";
  cin >> atm_menu;
  cout << endl;

  switch (atm_menu)
  {
  case 1:
    system("cls");
    if (loggedIn)
    {
      system("color 02");

      cout << "\n _________________________________________________";
      cout << "\n|                 Account Summary                 |";
      cout << "\n|-------------------------------------------------|";
      cout << "\n|  Account Holder Username: " << member[userindex].username
           << "            |";
      cout << "\n|  Account Type: " << member[userindex].account_type
           << "                          |";
      cout << "\n|-------------------------------------------------|";
      cout << "\n|  Available Balance: " << member[userindex].total_balance
           << "                       |";
      cout << "\n|_________________________________________________|";
    }
    else
    {
      cout << endl
           << endl
           << endl;

      cout << "Enter your Bank Email: ";
      cin >> email;
      for (int i = 0; i <= memberCount; i++)
      {
        if (email == member[i].email)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Wrong Email" << endl
               << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
          goto ReMenu;
        }
      }
      cout << endl;

      cout << "Enter your Password: ";
      cin >> password;
      for (int i = 0; i <= memberCount; i++)
      {
        if (password == member[i].password)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Incorrect Password" << endl
               << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
          goto ReMenu;
        }
      }

      cout << "\nEnter your Credit Card Number (without dashes): ";
      cin >> credit_card;
      cout << endl;
      for (int i = 0; i <= memberCount; i++)
      {
        if (credit_card == member[i].credit_card)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Incorrect Credit Card Number" << endl
               << endl;
          goto ReMenu;
        }
      }

      cout << "Enter your PIN (4 digits): ";
      for (int i = 0; i < 4; i++)
      {
        ch = getch();
        pinInput.push_back(ch);
        cout << "*";
      }

      string pin = pinInput;
      cout << endl;
      for (int i = 0; i <= memberCount; i++)
      {
        if (pin == member[i].pin)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Incorrect PIN" << endl
               << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
          goto ReMenu;
        }
      }

      if (verifyCredentials(email, password, credit_card, pin, userindex))
      {
        cout << "\n _________________________________________________";
        cout << "\n|                 Account Summary                 |";
        cout << "\n|-------------------------------------------------|";
        cout << "\n|  Account Holder Username: " << member[userindex].username << "           |";
        cout << "\n|  Account Type: " << member[userindex].account_type << "                          |";
        cout << "\n|-------------------------------------------------|";
        cout << "\n|  Available Balance: " << member[userindex].total_balance << "                       |";
        cout << "\n|_________________________________________________|";
        loggedIn = true;
      }
    }

    while (goBackToMainMenu)
    {
      cout << "\nIf you want to go back to the Main Menu, enter [Y / N]: ";
      cin >> remenu;

      if (remenu == "Y" || remenu == "y")
      {
        system("cls");
        goto ReMenu;
      }
      else
      {
        goBackToMainMenu = false;
        break;
      }
    }
    break;

  case 2:
    system("cls");
    if (loggedIn)
    {
      cout << "Credentials already entered." << endl;
      withdraw(userindex);
    }
    else
    {
      system("cls");
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
      cout << endl
           << endl
           << endl;
      cout << "Enter your Bank Email: ";
      cin >> email;
      for (int i = 0; i <= memberCount; i++)
      {
        if (email == member[i].email)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Wrong Email" << endl
               << endl;
          goto ReMenu;
        }
      }
      cout << endl;

      cout << "Enter your Password: ";
      cin >> password;
      for (int i = 0; i <= memberCount; i++)
      {
        if (password == member[i].password)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Incorrect Password" << endl
               << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
          goto ReMenu;
        }
      }

      cout << "\nEnter your Credit Card Number (without dashes): ";
      cin >> credit_card;
      cout << endl;
      for (int i = 0; i <= memberCount; i++)
      {
        if (credit_card == member[i].credit_card)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Incorrect Credit Card Number" << endl
               << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
          goto ReMenu;
        }
      }

      cout << "Enter your PIN (4 digits): ";
      for (int i = 0; i < 4; i++)
      {
        ch = getch();
        pinInput.push_back(ch);
        cout << "*";
      }

      string pin = pinInput;
      cout << endl;
      for (int i = 0; i <= memberCount; i++)
      {
        if (pin == member[i].pin)
        {
          break;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied due to Incorrect PIN" << endl
               << endl;
          goto ReMenu;
        }
      }

      if (verifyCredentials(email, password, credit_card, pin, userindex))
      {
        loggedIn = true;
        cout << "\nCredentials verified." << endl;
        withdraw(userindex);
      }
    }

    while (goBackToMainMenu)
    {
      cout << "\nIf you want to go back to the Main Menu, enter [Y / N]: ";
      cin >> remenu;

      if (remenu == "Y" || remenu == "y")
      {
        system("cls");
        goto ReMenu;
      }
      else
      {
        goBackToMainMenu = false;
        break;
      }
    }
    break;

  case 3:
  {
    static bool isAdminLoggedIn = false;

    if (!isAdminLoggedIn)
    {
      system("cls");

      system("color 02");
      cout << endl
           << endl
           << endl;
      cout << "Enter Admin Email: ";
      cin >> admin_email;
      cout << endl;

      if (admin_email == "admin@atm.pk")
      {
        cout << "Enter Admin Password: ";
        string admin_password;
        cin >> admin_password;

        if (admin_password == "Corruption6666")
        {
          cout << "\nWelcome Back Admin" << endl;
          isAdminLoggedIn = true;
        }
        else
        {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
          cout << "Access Denied." << endl;
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
          goto ReMenu;
        }
      }
      else
      {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        cout << "Incorrect Email." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        goto ReMenu;
      }
    }

    while (true)
    {
      system("cls");
      cout << "\n ______________________________________";
      cout << "\n|             Admin Panel              |";
      cout << "\n|--------------------------------------|";
      cout << "\n|1. View Notes and Quantities of ATM   |";
      cout << "\n|2. Add Notes to ATM                   |";
      cout << "\n|______________________________________|";
      cout << endl
           << endl;
      cout << "Select your option: ";
      cin >> admin_option;
      cout << endl
           << endl;

      switch (admin_option)
      {
      case 1:
        system("cls");
        cout << "Notes and Quantities:" << endl;
        for (int i = 0; i < 4; i++)
        {
          cout << "Rs " << note_values[i] << ": " << notes[i] << " notes"
               << endl;
        }
        break;

      case 2:
        system("cls");
        cout << endl;
        cout << "\n ____________________________________________";
        cout << "\n|                Notes Menu:                 |";
        cout << "\n|--------------------------------------------|";
        cout << "\n| 1. Rs 100                                  |";
        cout << "\n| 2. Rs 500                                  |";
        cout << "\n| 3. Rs 1000                                 |";
        cout << "\n| 4. Rs 5000                                 |";
        cout << "\n|____________________________________________|";
        cout << endl
             << endl;
        cout << "Enter your option: ";
        int add_note_option;
        cin >> add_note_option;

        if (add_note_option >= 1 && add_note_option <= 4)
        {
          int quantity;
          cout << "Enter the quantity to add: ";
          cin >> quantity;

          notes[add_note_option - 1] += quantity;

          cout << "Note quantity updated." << endl;
        }
        else
        {
          cout << "Invalid option." << endl;
        }
        break;

      default:
        cout << "Invalid option. Please try again." << endl;
        break;
      }

      cout << endl;
      cout << "\nIf you want to go back to the Main Menu, enter [Y / N]: ";
      cin >> remenu;

      if (remenu == "Y" || remenu == "y")
      {
        system("cls");
        goto ReMenu;
      }
      else
      {
        goBackToMainMenu = false;
        exit(0);
      }
      break;
    }
    break;
  }

  case 4:
    system("cls");
    signUp();
    while (goBackToMainMenu)
    {
      cout << "\nIf you want to go back to the Main Menu, enter [Y / N]: ";
      cin >> remenu;

      if (remenu == "Y" || remenu == "y")
      {
        system("cls");
        goto ReMenu;
      }
      else
      {
        goBackToMainMenu = false;
        break;
      }
    }
    break;

  case 5:
  {
    string thankmsg = "Thank you for using our ATM. Have a nice day!";
    system("cls");
    pos = {40, 2};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    for (char ch : thankmsg)
    {
      cout << ch;
      Sleep(30);
    }
    cout << endl
         << endl
         << endl
         << endl;

    break;
  }
  default:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Wrong Option" << endl;
    break;
  }

  return 0;
}