
//C++ program that implements a simple user signup application

// Dependencies
#include <iostream>
#include <array>
#include <string>

using namespace std;

// --------------------------------------------- //

// Define values
constexpr int MAX_USERS = 100;


// --------------------------------------------- //
// Types definitions

enum class record_options
{
    ADD = 1,
    FETCH = 2,
    QUIT = 3
};

class user_info
{
    public:
    string username;
    int age;
};

// Functions prototypes
void print_message(string msg);
void print_message(string msg);
void print_message();
record_options read_user_input(void);

// --------------------------------------------- //

class application
{
    private:
    int user_index = 0;

    public:
    // variables
    array<user_info,MAX_USERS> users;

    // functions
    // add user function
    void add_user_record(const string &name,const int &age)
    {
        if (user_index < MAX_USERS)
        {
            users[user_index].username = name;
            users[user_index].age = age;
            user_index++;
            cout << "User record has been added successfully. \n \n";
        }
        else
        {
            cout << "Error - User record has reached its limit. \n \n";
        }

    }

    // get user function
    void get_user_record(const int &id)
    {
        print_message("User Name: ");
        cout << users[id].username;
        print_message("\n");
        print_message("User Age: ");
        cout << users[id].age;
        print_message("\n\n");
    }
    
    // verify if id is greater than number of users added 
    bool is_valid_id(const int &id)
    {
    bool result = true;
    if (id > user_index)
    {
        result = false; 
    }
    return result;

    }


};

// --------------------------------------------- //



// Functions


/**
 * @brief Main function of the User Signup Application.
 * 
 * This function initializes the application, handles user input, and manages
 * the main loop for adding and fetching user records.
 * 
 * @return int Returns 0 upon successful execution.
 */
int main()
{
    bool isRunning = true;
    record_options options;
    application user_information;
    string name;
    int age = 0;
    int id = 0;

    print_message("User Signup Application \n \n");

    while (isRunning == true)
    {
        // Print the menu options to the console
         print_message();
         // Read the user's input for the menu option
         options = read_user_input();
         print_message("\n");

         switch (options)
         {
         case record_options::ADD:
            // Ignore any leftover newline characters in the input stream
            cin.ignore();

            // Prompt the user to enter the user's name and age
            print_message("Add user. Please enter user name and age:\n");
            print_message("Name: ");
            getline (cin,name);
            print_message("Age: ");
            cin >>age;
            print_message("\n");

             // Store the user's record to the application
            user_information.add_user_record(name,age);
            break;

         case record_options::FETCH:
            // Prompt the user to enter the user's ID
            print_message("Please enter user ID: \n");
            print_message("User ID: ");
            cin >>id;

            // Check if the entered ID is valid
            if (user_information.is_valid_id(id) == true)
            {
                 // Fetch and display the user's record
                user_information.get_user_record(id-1);
            }
            else
            {
                // Print an error message if the ID is invalid
                print_message("Invalid User ID \n \n");
            }

            break;

        case record_options::QUIT:
            // Set the isRunning flag to false to exit the main loop
             isRunning = false;
            break;

         default:
              // Print an error message if the user enters an invalid option
              print_message("Invalid input please try again\n\n");
            break;
         }


    }



    return 0;
}

/**
 * @brief Prints a message to the standard output.
 * 
 * This function outputs the provided string message to the console.
 * 
 * @param msg The message to be printed.
 */
void print_message(string msg)
{
    cout <<msg;
}


// Override print message to print the options
/**
 * @brief Displays the available options to the user.
 * 
 * This function prints the menu options for the user to select from,
 * including adding a record, fetching a record, or quitting the application.
 */
void print_message()
{   
    cout <<"Please select an option:\n";
    cout <<"1: Add Record \n";
    cout <<"2: Fetch Record \n";
    cout <<"3: QUIT \n \n";
    cout <<"Enter option: ";
}


// Read user input
record_options read_user_input(void)
{
    int input = 0;
    cin >>input;
    return static_cast<record_options>(input);
}



