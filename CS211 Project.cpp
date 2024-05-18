#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Structure for date
struct Date{
    int month, year;
};

// Structure for customer information
struct CustomerInfo{
    int id;
    char firstName[20];
    char lastName[20];
    string sex;
    Date birthday;
    string email;
    int phone;
};

// Function prototypes
void MainMenu();
double onlineShopping();
void signUp(CustomerInfo& customer);
float Electronics();
float Cloths();
double Accessories();
char delivery();
string giftMessage();
void writeCustomerToFile(const CustomerInfo& customer);
void readCustomerFromFile();

// Structure for customer address
struct Address {
    string street;
    string city;
    string district;
    string postalCode;
} Address[50]; // global array of struct

// main function
int main() {
    MainMenu();
    return 0;
}

// Function for signing up the customer 
void signUp(CustomerInfo& customer){
    cout << "\nEnter your first name: ";
    cin >> customer.firstName;
    
    cout << "\nEnter your last name: ";
    cin >> customer.lastName;
    
    cout << "\nEnter your sex ('F' for female or 'M' for male): ";
    cin >> customer.sex;
    while(customer.sex != "F" && customer.sex != "f" && customer.sex != "M" && customer.sex != "m"){
    	cout<<"\nInvalid choice. Please enter 'F' for female or 'M' for male: ";
    	cin>>customer.sex;
	}
    
    cout << "\nEnter your birth year: ";
    
    while(!(cin>>customer.birthday.year)){
    	cout<<"\nPLEASE ENTER A NUMBER FOR YOUR BIRTH YEAR: ";
    	cin.clear();
    	cin.ignore();
    	
		while(customer.birthday.year >= 2007){
    	cout<<"\n!!!YOU HAVE TO BE 18 YEARS OLD OR OLDER TO SIGN UP IN OUR STORE !!!";
    	cout<<"\n!!!!!!!!!!!!PLEASE ASK SOMEONE OLDER TO SIGN UP FOR YOU!!!!!!!!!!!!";
    	cout << "\nEnter your birth year: ";
        cin >> customer.birthday.year;
	}
	}
	
    while(customer.birthday.year >= 2007){
    	cout<<"\n!!!YOU HAVE TO BE 18 YEARS OLD OR OLDER TO SIGN UP IN OUR STORE !!!";
    	cout<<"\n!!!!!!!!!!!!PLEASE ASK SOMEONE OLDER TO SIGN UP FOR YOU!!!!!!!!!!!!";
    	cout << "\nEnter your birth year: ";
        
        while(!(cin>>customer.birthday.year)){
        	cout<<"\nPLEASE ENTER A NUMBER FOR YOUR BIRTH YEAR: ";
    	    cin.clear();
    	    cin.ignore();
		}
	}
    
    cout << "\nEnter your birth month from 1 to 12: ";    
    while(!(cin>>customer.birthday.month) || customer.birthday.month < 1 || customer.birthday.month > 12){
    	cout<<"\nInvalid input. Please enter a number from 1 to 12: ";
    	cin.clear();
    	cin.ignore();
	}
    
    cout << "\nEnter your email: ";
    cin >> customer.email;
    
    cout << "\nEnter your phone number: ";
    while(!(cin>>customer.phone)){
    	cout<<"\nInvalid input. Please enter a phone number: ";
    	cin.clear();
    	cin.ignore();
	}
    
    //write the customer information to the file
    writeCustomerToFile(customer);
}


// Function to write customer information to a file
void writeCustomerToFile(const CustomerInfo& customer) {
    ofstream outFile("customer_records.txt", ios::app);
    if (!outFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    outFile << customer.id << " " << customer.firstName << " " << customer.lastName << " " << customer.sex << " "
            << customer.birthday.month << " " << customer.birthday.year << " " << customer.email << " "
            << customer.phone << endl;

    outFile.close();
}

// Function to read customer information from a file
void readCustomersFromFile() {
    ifstream inFile("customer_records.txt");
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int id, month, year, phone;
    char firstName[20], lastName[20], sex[20];
    string email;

    cout << "Customer Records:" << endl;
    while (inFile >> id >> firstName >> lastName >> sex >> month >> year >> email >> phone) {
        cout << "ID: " << id << ", Name: " << firstName << " " << lastName << ", Sex: " << sex
             << ", Birthday: " << month << "/" << year << ", Email: " << email << ", Phone: " << phone << endl;
    }

    inFile.close();
}


// Function for delivery services
char delivery(){
    int province;
    char choice;
    
	cout << "\n********************************************************************************************" << endl;
    cout << "***************************** Welcome to our delivery service! *****************************" << endl;
    cout << "*************************** Please enter your address information **************************" << endl;
    
    cout<<"\n1) Riyadh"<<endl;
    cout<<"2) Qasim"<<endl;
    cout<<"3) Ha'il"<<endl;
    cout<<"4) Jawf"<<endl;
    cout<<"5) Tabuk"<<endl;
    cout<<"6) Northern Borders"<<endl;
    cout<<"7) Madinah"<<endl;
    cout<<"8) Makkah"<<endl;
    cout<<"9) Bahah"<<endl;
    cout<<"10) Asir"<<endl;
    cout<<"11) Jizan"<<endl;
    cout<<"12) Najran"<<endl;
    cout<<"13) Eastern Province"<<endl;
    cout<<"\nWhat is your province? (1-13): ";
	    
    while(!(cin>>province)){
    	cout<<"\nInvalid input. Please enter a number from 1 to 13: ";
    	cin.clear();
    	cin.ignore();
	}
    
    for(int i = 0; i<50; i++){
    	cout<<"\nStreet: ";
    	cin>>Address[i].street;
    	
    	cout<<"\nCity: ";
    	cin>>Address[i].city;
    	
    	cout<<"\nDistrict: ";
    	cin>>Address[i].district;
    	
    	cout<<"\nPostal code: ";
    	cin>>Address[i].postalCode;
    	
    	cout<<"Do you want to add another address? ('Y' for yes or 'N' for no): ";
    	cin>>choice;
    	
    	if(choice == 'y' || choice == 'Y'){
    		
        }else if(choice == 'n' || choice == 'N'){
            break;
        }
        else {
            cout << "Invalid choice. Please enter ('Y' for yes or 'N' for no)" << endl;
        }
    	
	}
    
    if(province == 1 || province == 2 || province == 3){
    	cout<<"\nYour order will be delivered in 2 to 3 days !!!";
	}else if(province == 4 || province == 5 || province == 6){
		cout<<"\nYour order will be delivered in 3 to 4 days !!!";
	}else if(province == 6 || province == 7 || province == 8 || province == 9 || province == 10 || province == 11 || province == 12){
		cout<<"\nYour order will be delivered in 4 to 5 days !!!";
	}else if(province == 13){
		cout<<"\nYour order will be delivered in 5 to 7 days !!!";
	}
	
   
    return choice; 
}

// Function for adding a gift message
string giftMessage(){
    string message;
    
    cout << "\n********************************************************************************************" << endl;
    cout << "*******************************Please enter your gift message*******************************" << endl;
    cin.ignore();
	getline(cin, message);
    
    return message;
}

// function for the store sections
double onlineShopping() {
    char choice;
    
    cout << "\n********************************************************************************************" << endl;
    cout << "\nChoose one of the categories below:" << endl << endl;
    cout << "1. Electronics" << endl;
    cout << "2. Clothes" << endl;
    cout << "3. accessories" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case '1':
            return Electronics();
        case '2':
            return Cloths();
            
        case '3':
            return Accessories();
        
        default:
            cout << "You have entered the wrong index" << endl;
            return 0;
    }
}

// Main menu function
void MainMenu() {
    char startValue;
    char choiceAgain;
    char deliveryChoice;
    char giftChoice;

    cout << "Please press 's' to start shopping" << endl;
    cin >> startValue;
    
    cout << "\n********************************************************************************************" << endl;
    cout << "*********************************** Welcome to our store ***********************************" << endl;
    cout << "*********************************** Please sign up first ***********************************" << endl;
    
    CustomerInfo customer;
    signUp(customer);

    if (startValue == 's' || startValue == 'S') {
        double totalAmount = onlineShopping();
        cout << "Total Bill Amount is: " << totalAmount << endl;
        
        // Ask if the user wants delivery service
        cout << "\nDo you want your order to be delivered? Yes or No ('Y' for yes & 'N' for no): ";
        cin >> deliveryChoice;
        
        if(deliveryChoice == 'y' || deliveryChoice == 'Y'){
            delivery();
        } 
        else if(deliveryChoice == 'n' || deliveryChoice == 'N'){
            cout << "No problem. We'll proceed" << endl;
        }
        else {
            cout << "Invalid choice. Please enter ('Y' for yes or 'N' for no): " << endl;
        }
        
        // Ask if the user wants to add a gift message
        cout << "\nDo you want to add free gift wrapping and a message? Yes or No ('Y' for yes & 'N' for no): ";
        cin >> giftChoice;
        
        if(giftChoice == 'y' || giftChoice == 'Y'){
            giftMessage();
        }
        else if(giftChoice == 'n' || giftChoice == 'N'){
            cout << "No problem. We'll proceed" << endl;
        }
        else {
            cout << "Invalid choice. Please enter. ('Y' for yes or 'N' for no): " << endl;
        }

        // Ask if the user wants to shop again
        cout << "\nDo you want to shop again? Yes or No ('Y' for yes & 'N' for no): " << endl;
        cin >> choiceAgain;

        if (choiceAgain == 'y' || choiceAgain == 'Y') {
            onlineShopping();
        } 
        else if (choiceAgain == 'n' || choiceAgain == 'N') {
            cout << "Thanks for shopping :)" << endl;
        }
        else {
            cout << "You have entered the wrong option, please type again" << endl;
            onlineShopping();
        }
    } 
    else {
        cout << "You have entered the wrong option, please press 's'" << endl;
        MainMenu();
    }
}


// function for the electronics section
float Electronics() {
    char choice;
    char item;
    int quantity;
    float billAmount = 0;

    cout << "*****************" << endl;
    cout << "\nElectronics Section" << endl;
    cout << "*****************" << endl;
    cout << "\nChoose what you want from below:" << endl;
    cout << "(1) Please enter 'm' to order mobile phones" << endl;
    cout << "(2) Please enter 'l' to order laptops" << endl;
    cout << "(3) Please enter 'd' to order desktops" << endl;
    cout << "(4) Please enter 's' to order speakers" << endl;
    cout << "(5) Please enter 'h' to order headphones" << endl;
    cout << "Your choice: ";
    cin >> choice;

    // Handle user's choice
    if (choice == 'm' || choice == 'M') {
        // Code for ordering mobile phones
        cout << "Available mobile phones:" << endl;
        cout << "1. Apple   => Price: 40000" << endl;
        cout << "2. Vivo    => Price: 25000" << endl;
        cout << "3. Oppo    => Price: 20000" << endl;
        cout << "4. Redmi   => Price: 18000" << endl;
        cout << "5. Huawei  => Price: 17000" << endl;
        cout << "6. Samsung => Price: 25000" << endl;
        cout << "Enter your choice: ";
        cin >> item;
        if (item == '1') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 40000;
        } 
        
        else if (item == '2') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 25000;
        } 
        
        else if (item == '3') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 20000;
        } 
        
        else if (item == '4') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 18000;
        } 
        
        else if (item == '5') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 17000;
            
        } 
        
        else if (item == '6') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 25000;
        } 
        
        else {
            cout << "Invalid choice!" << endl;
        }
        
    }
    
    else if (choice == 'l' || choice == 'L') {
        // Code for ordering laptops
        cout << "Available laptops:" << endl;
        cout << "1. Dell     => Price: 6000 SAR" << endl;
        cout << "2. HP       => Price: 5700 SAR" << endl;
        cout << "3. Lenovo    => Price: 5000 SAR" << endl;
        cout << "4. Asus     => Price: 4200 SAR" << endl;
        cout << "5. Acer     => Price: 3500 SAR" << endl;
        cout << "Enter your choice: ";
        cin >> item;
        
        if (item == '1') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 6000;
            
        }
        
        else if (item == '2') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 5700;
        } 
        
        else if (item == '3') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 5000;
            
        } 
        
        else if (item == '4') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 4200;
            
        } 
        
        else if (item == '5') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 3500;
        } 
        
        else {
            cout << "Invalid choice!" << endl;
        }
        
    } 
    
    else if (choice == 'd' || choice == 'D') {
        // Code for ordering desktops
        cout << "Available desktops:" << endl;
        cout << "1) Dell     => Price: 4000 SAR" << endl;
        cout << "2) HP       => Price: 3200 SAR" << endl;
        cout << "3) Lenovo   => Price: 3600 SAR" << endl;
        cout << "4) Asus     => Price: 9800 SAR" << endl;
        cout << "5) Acer     => Price: 8500 SAR" << endl; 
        
        
        cout << "Enter your choice: ";
        cin >> item;
        
        if (item == '1') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 4000;
            
        }
        
        else if (item == '2') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 3200;
            
        } 
        
        else if (item == '3') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 3600;
            
        }
        
        else if (item == '4') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 9800;
            
        }
        
        else if (item == '5') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 8500;
            
        } 
        
        else {
            cout << "Invalid choice!" << endl;
        }
        
    } 
    
    else if (choice == 's' || choice == 'S') {
        // Code for ordering speakers
        cout << "Available speakers:" << endl;
        cout << "1. JBL      => Price: 1000 SAR" << endl;
        cout << "2. Sony     => Price: 1200 SAR" << endl;
        cout << "3. Bose     => Price: 1500 SAR" << endl;
        cout << "4. Philips  => Price: 800 SAR" << endl;
        cout << "5. LG       => Price: 1100 SAR" << endl;
        cout << "Enter your choice: ";
        cin >> item;
        
        if (item == '1') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1000;
            
        }
        
        else if (item == '2') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1200;
            
        } 
        
        else if (item == '3') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1500;
            
        }
        
        else if (item == '4') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 800;
            
        }
        
        else if (item == '5') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1100;
            
        } 
        
        else {
            cout << "Invalid choice!" << endl;
        }
        
    } 
    
    else if (choice == 'h' || choice == 'H') {
        // Code for ordering headphones
        cout << "Available headphones:" << endl;
        cout << "1. Beats    => Price: 1500 SAR" << endl;
        cout << "2. Sony     => Price: 1000 SAR" << endl;
        cout << "3. JBL      => Price: 1200 SAR" << endl;
        cout << "4. Bose     => Price: 1800 SAR" << endl;
        cout << "5. Sennheiser => Price: 2000 SAR" << endl;
        cout << "Enter your choice: ";
        cin >> item;
        
        if (item == '1') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1500;
            
        }
        
        else if (item == '2') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1000;
            
        }
        
        else if (item == '3') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1200;
            
        }
        
        else if (item == '4') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 1800;
            
        } 
        
        else if (item == '5') {
            
            cout << "Enter quantity: ";
            cin >> quantity;
            billAmount += quantity * 2000;
            
        }
        
        else {
            cout << "Invalid choice!" << endl;
        }
        
    } 
    
    else {
        cout << "You have entered the wrong option" << endl;
    }
    return billAmount;
}

   

// function for the clothes section
float Cloths() {
    char choice;
    int quantity;
    float billAmount = 0;

    cout << "*****************" << endl;
    cout << "\nClothes Section" << endl;
    cout << "*****************" << endl;
    cout << "\nChoose what you want from below:" << endl;
    cout << "(1) T-Shirts   => Price: 50 SAR" << endl;
    cout << "(2) Pants      => Price: 55 SAR" << endl;
    cout << "(3) Dresses    => Price: 250 SAR" << endl;
    cout << "(4) Skirts     => Price: 90 SAR" << endl;
    cout << "Your choice: ";
    cin >> choice;

    switch (choice) {
        case '1':
            cout << "Enter the quantity: ";
            cin >> quantity;
            billAmount += quantity * 50;
            break;
        case '2':
            cout << "Enter the quantity: ";
            cin >> quantity;
            billAmount += quantity * 55;
            break;
        case '3':
            cout << "Enter the quantity: ";
            cin >> quantity;
            billAmount += quantity * 250;
            break;
        case '4':
            cout << "Enter the quantity: ";
            cin >> quantity;
            billAmount += quantity * 90;
            break;
        default:
            cout << "You have entered the wrong option" << endl;
            break;
    }
    return billAmount;
}

// function for the accessories section
double Accessories() {
    char choice;
    int quantity;
    double billAmount = 0.0;
    
    cout << "*****************" << endl;
    cout << "\nAccessories Section" << endl;
    cout << "*****************" << endl;
    cout << "\nChoose anyone from below:" << endl;
    cout << "(1) Sunglasses => Price: 300 SAR" << endl;
    cout << "(2) Watches    => Price: 300 SAR" << endl;
    cout << "(3) Jewelry    => Price: 500 SAR" << endl;
    cout << "(4) Scarves    => Price: 150 SAR" << endl;
    cout << "(5) Handbags   => Price: 400 SAR" << endl;
    cout << "Your choice: ";
    cin >> choice;

    if (choice == '1') {
        cout << "Enter the quantity: ";
        cin >> quantity;
        billAmount += quantity * 300.0;
    } else if (choice == '2') {
        cout << "Enter the quantity: ";
        cin >> quantity;
        billAmount += quantity * 300.0;
        
    } else if (choice == '3') {
        cout << "Enter the quantity: ";
        cin >> quantity;
        billAmount += quantity * 500.0;
    } else if (choice == '4') {
        cout << "Enter the quantity: ";
        cin >> quantity;
        billAmount += quantity * 150.0;
    } else if (choice == '5') {
        cout << "Enter the quantity: ";
        cin >> quantity;
        billAmount += quantity * 450.0;
    } else {
        cout << "You have entered the wrong option" << endl;
    }

    return billAmount;
}


