# dotlines-assignment
Assignment for Software Development Team - Deadline: December 5, 2023

# NB>
## Database is exported in the database directory should be imported for the use
## client socket program that sends data is a seperate project from this and will be in different git repo


## Description:
You have a structure type called info defined as follows:

	typedef struct user_info {
		int user_id;
		char first_name[100];
		char last_name[100];
		char email[100];
		char subscription_time[50];
		char last_entry_time[50];
		unsigned long view_time;
	} user_info;

A) Write a C or C++ program that sends multiple instances of the user_info structure to a UDP port 2222.

B) Write a C or C++ program that listens on UDP port 2222 and receives the user_info structures sent in part A. 
   After receiving each structure, store the data in a MySQL database table named UserInfo.
   
   N.B: You will store user information only when the email is valid and the address string contains the substring "test" 
		and you cannot use any built in function to match the substring.
   
   Example: 
		"abctest@gmail.com" -> Valid
		"abc@test.com" -> Valid
		"abc@gmail.com" -> Invalid
		"test.com" -> Invalid
   
The table schema is as follows:

	CREATE TABLE `UserInfo` (
	  `id` int(11) NOT NULL AUTO_INCREMENT,
	  `user_id` int(10) DEFAULT NULL,
	  `first_name` varchar(100) DEFAULT NULL,
	  `last_name` varchar(100) DEFAULT NULL,
	  `email` varchar(100) DEFAULT NULL,
	  `subscription_time` datetime DEFAULT NULL,
	  `last_entry_time` datetime DEFAULT NULL,
	  `view_time` int(20) DEFAULT NULL,
	  PRIMARY KEY (`id`)
	) ENGINE=InnoDB AUTO_INCREMENT=64 DEFAULT CHARSET=latin1;


Sample Data Format:
{
	1,
	"Abc",
	"Xyz",
	"abc@gmail.com",
	"2023-25-12 23:50:55",
	"2023-25-13 11:22:33",
	"111112222"
}


