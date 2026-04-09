#include<iostream>
#include<string>
using namespace std;
class passwordchecker{
    private:
        string password;
    public:
        string getpassword();
        void setpassword(string pw);
        int checkstrength();
};
void passwordchecker::setpassword(string pw)
{
    password = pw;
}
string passwordchecker::getpassword()
{
    return password;
}
int passwordchecker::checkstrength()
{
    int len = password.length();
    int count = 0;
    if(len <= 6) //checking length
     return count;
    else if(len < 12)
     count++;
    else
     count+=2;
    for(int i=0; i<len; i++) //checking lowecase
     if(islower(password[i]))
     {
        count++;
        break;
     }
    for(int i=0; i<len; i++) //checking uppercase
     if(isupper(password[i]))
     {
        count++;
        break;
     }
    for(int i=0; i<len; i++) //checking digits
     if((password[i]>=0)&&(password[i]<=9))
     {
        count++;
        break;
     }
     for(int i=0; i<len; i++) //checking special characters
     if((!islower(password[i]))&&(!isupper(password[i]))&&(!((password[i]>=0)&&(password[i]<=9))))
     {
        count+=2;
        break;
     }
    return count;
}
void displayresult(int c)
{
    switch(c)
    {
        case 0:
        case 1:
        case 2: cout<<"WEAK.";
                break;
        case 3: 
        case 4: 
        case 5: cout<<"MODERATE.";
                break;
        case 6:
        case 7: cout<<"STRONG.";
                break;
        default: cout<<"strong.";
    }
}
int main()
{
    string password;
    cout<<"Enter your password: ";
    cin>>password;
    passwordchecker p;
    p.setpassword(password);
    int strength = p.checkstrength();
    displayresult(strength);
}