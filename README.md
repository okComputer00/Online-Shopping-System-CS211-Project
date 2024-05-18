# Online-Shopping-System-CS211-Project

<h2>Introduction</h2>

The C++ Online Shopping System project aims to create a simple and practical platform for online shopping. Useres can browse products, add items to their shopping cart, place orders, manage their accounts, request delivery, add a gift message, read data from a file, save it and allow them to register, providing a hands-on experience in building an e-commerce platform. Me and three of my team mates have worked and contributed equally on this project.

<h2> Functions I Have Worked On Explained </h2>

- SignUp() Function
  This function collects coustomer information for signing up. It uses a 'CustomerInfo' struct to store details like first name, last name, se, birth year, birth month, email, and phone number. The function error handling loops to manage incorrect inputs. For example, when the function prompts the user to input the sex, if the user input a letter is not ('F' for female or 'M' for male), a message will pop up asking the user to input a correct letter. It then asks for the birth year, ensuring it is a number and that the user is eighteen years or older. If the user is under eighteen, they are prompted to ask someone older to sign up. The user is then asked for the birth month, ensuring it is between 1 and 12. Then, the user provides their email and phone nuber with the right input validation.

- delivery() function
  This function manages address informatiom and delivery services for customers. It first display a welcome message for the delivery service and prompts the user to input their province by choosing a number from 1 to 13, each number is a specific province in Saudi Arabia. Following the province selection, the function enters a loop that allows the user to input address details like street, city, district, and pstal code. The user can choose to add multiple addresses by entering ('Y' for yes or 'N' for no). The loop continue until the user decides not to add more addresses. Then, the function calculates the estimated delivery duration, Different provinces have different delivery durations ranging from two to seven days, as specified in the conditional statements.

- giftMessage() function
  This function allows users to input a personalized gift message. The function displays a prompt asking the user to enter their gift message. 'cin.ignore()' is used to clear any unwanted charcters from the input buffer before reading the message. Then, it uses 'getline(cin, message)' to read the entire line of text entered by the user, including spaces, and stores it in the message variable of type 'string'.

<h2> Team members <h2>

- Ghadeer Alalawi

- Sara Alhajri

- Rana Saeed

- Jori Balharith