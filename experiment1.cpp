#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;

    cout << "1. Numeric Constant\n";
    cout << "2. Operators\n";
    cout << "3. Comment\n";
    cout << "4. Identifier\n";
    cout << "5. Average of Array\n";
    cout << "6. Min and Max of Array\n";
    cout << "7. Full Name\n";
    cout << "Enter Choice: ";
    cin >> choice;
    cin.ignore();

    if(choice == 1)
    {
        string s;
        cout << "Enter Input: ";
        cin >> s;

        bool num = true;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]<'0' || s[i]>'9')
            {
                num = false;
                break;
            }
        }

        if(num)
            cout << "Numeric Constant";
        else
            cout << "Not Numeric";
    }

    else if(choice == 2)
    {
        string s;
        cout << "Enter Expression: ";
        getline(cin, s);

        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' ||
               s[i]=='/' || s[i]=='%' || s[i]=='=')
            {
                cout << "Operator: " << s[i] << endl;
            }
        }
    }

    else if(choice == 3)
    {
        string s;
        cout << "Enter Line: ";
        getline(cin, s);

        if(s[0]=='/' && s[1]=='/')
            cout << "Single Line Comment";
        else if(s[0]=='/' && s[1]=='*' &&
                s[s.length()-2]=='*' && s[s.length()-1]=='/')
            cout << "Multi Line Comment";
        else
            cout << "Not a Comment";
    }

    else if(choice == 4)
    {
        string s;
        cout << "Enter Identifier: ";
        cin >> s;

        bool valid = true;

        if(!((s[0]>='A' && s[0]<='Z') ||
             (s[0]>='a' && s[0]<='z') ||
             s[0]=='_'))
        {
            valid = false;
        }

        for(int i=1; i<s.length() && valid; i++)
        {
            if(!((s[i]>='A' && s[i]<='Z') ||
                 (s[i]>='a' && s[i]<='z') ||
                 (s[i]>='0' && s[i]<='9') ||
                 s[i]=='_'))
            {
                valid = false;
            }
        }

        if(valid)
            cout << "Valid Identifier";
        else
            cout << "Invalid Identifier";
    }

    else if(choice == 5)
    {
        int n, sum=0;
        cout << "Enter Size: ";
        cin >> n;

        int a[100];

        cout << "Enter Elements: ";
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        cout << "Average = " << (float)sum/n;
    }

    else if(choice == 6)
    {
        int n;
        cout << "Enter Size: ";
        cin >> n;

        int a[100];

        cout << "Enter Elements: ";
        for(int i=0; i<n; i++)
            cin >> a[i];

        int min = a[0];
        int max = a[0];

        for(int i=1; i<n; i++)
        {
            if(a[i] < min)
                min = a[i];

            if(a[i] > max)
                max = a[i];
        }

        cout << "Minimum = " << min << endl;
        cout << "Maximum = " << max;
    }

    else if(choice == 7)
    {
        string first, last;

        cout << "First name: ";
        cin >> first;

        cout << "Please enter Last Name: ";
        cin >> last;

        cout << "Full Name = " << first << " " << last;
    }

    else
    {
        cout << "Invalid Choice";
    }

    return 0;
}
