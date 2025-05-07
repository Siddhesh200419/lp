#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Converts a string to lowercase
string to_lower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Generates a chatbot response based on user input
string chatbot_response(string user_input)
{
    user_input = to_lower(user_input);

    if (user_input.find("hello") != string::npos || user_input.find("hii") != string::npos)
    {
        return "Hello! Welcome to City Hospital. How can I assist you today?";
    }
    else if (user_input.find("appointment") != string::npos)
    {
        return "To book an appointment, please provide the department and preferred date.";
    }
    else if (user_input.find("doctor") != string::npos)
    {
        return "We have specialists in cardiology, pediatrics, orthopedics, and many other departments.";
    }
    else if (user_input.find("timing") != string::npos)
    {
        return "Our hospital is open 24/7. Outpatient consultations are from 9 AM to 5 PM.";
    }
    else if (user_input.find("emergency") != string::npos)
    {
        return "For emergencies, please call 911 or come directly to our emergency department.";
    }
    else if (user_input.find("insurance") != string::npos)
    {
        return "We accept most major insurance plans. Please contact our billing department for details.";
    }
    else if (user_input.find("location") != string::npos)
    {
        return "We are located at 123 Health Avenue, Medical District.";
    }
    else if (user_input.find("contact") != string::npos)
    {
        return "You can reach us at 1-800-HOSPITAL or email info@cityhospital.com.";
    }
    else
    {
        return "I'm sorry, I didn't understand that. Could you please rephrase?";
    }
}

int main()
{
    cout << "Welcome to the City Hospital ChatBot! Type 'exit' to end the conversation." << endl;

    string user_input;
    while (true)
    {
        cout << "You: ";
        getline(cin, user_input);

        string input_check = to_lower(user_input);
        if (input_check == "exit" || input_check == "bye")
        {
            cout << "Chatbot: Thank you for contacting City Hospital. Take care!" << endl;
            break;
        }

        cout << "Chatbot: " << chatbot_response(user_input) << endl;
    }

    return 0;
}
