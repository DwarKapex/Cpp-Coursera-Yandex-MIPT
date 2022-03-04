# Desctiption

In this task, you need to develop the SmsNotifier and Email Notifier classes that send notifications in the form of SMS and e-mail, respectively, as well as an abstract base class for them.

You are given the SendSms and Sendmail functions, which simulate sending SMS and e-mail.

```c++
void SendSms(const string& number, const string& message);
void SendEmail(const string& email, const string& message);
```

Develop: 

 1. Abstract base class **Notifier**, which will have one purely virtual method void Notify(const string& message).

 2. The Sms Notifier class, which:

    - is a descendant of the Notifier class;

    - in the constructor, it takes one parameter of the string type - the phone number;

    - overrides the Notify method and calls the SendSms function from it.

3. The Email Notifier class, which:

    - is a descendant of the Notifier class;

    - in the constructor, it takes one parameter of the string type — the email address;

    - overrides the Notify method and calls the SendEmail function from it.

## Example

```c++
#include <iostream>
#include <string>

using namespace std;

void SendSms(const string& number, const string& message) {
  cout << "Send '" << message << "' to number " << number << endl;
}

void SendEmail(const string& email, const string& message) {
  cout << "Send '" << message << "' to e-mail "  << email << endl;
}

/*
 Implement INotifier, SmsNotifier, EmailNotifier here
*/

void Notify(INotifier& notifier, const string& message) {
  notifier.Notify(message);
}


int main() {
  SmsNotifier sms{"+7-495-777-77-77"};
  EmailNotifier email{"na-derevnyu@dedushke.ru"};

  Notify(sms, "I have White belt in C++");
  Notify(email, "And want a Yellow one");
  return 0;
}
```