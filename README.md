
Assignment for Software Development Team - Deadline: December 5, 2023

## How To Run:
	> Make sure you have '2222' port free for server. 
### 1. quick run server:
	> i. run '.exe' file built in the directory "./bin/debug/" namely "dotlines_assignment.exe" (just the make sure the "libmysql.dll" is on the same directory as the .exe). it will open a console and you will see server is lisenting.. the program will wait 2 minutes for client requests and terminate if there is no incoming data from clients(idle shutdown time set to 120 sec for the program)
   	> ii. for database related operation make sure you have a mysql database running in port 3306 (for this project xampp localhost, mysql module with default config was used. if you have xampp installed you can just start the apache and mysql modules togather).
    		worth noting it is also expected that the database has below characteristics (default for xampp)-
      			database_name = "user_information_database";
			host = "localhost";
			user = "root";
			password = "";
			port = 3306;
   	> iii. You can create a database named "user_information_database" and import the table structures and everything from "user_information_database.sql" source file located on "./database/" directory.
### 2. quick run client:
  	> it has no dependency you can run the executable "client.exe" from the directory "./bin/debug".
   	> it will open a console where you can create a data stuct and send it to server socket.
    > send data sturct while the server is running.
<br />

## To re-build the sever project:
### 1. import the project
	> open an empty project in codeblocks
	> right click project-name under management and select add file recursively and add the main project directory(dotlines_assignement)
### 2. add mysql library and header files(included in 'files for cpp sqll' directory) with compiler. 
    	-put the 'libmysql.a' file from "files for cpp sql/libmysql.a/" directory in the compiler's 'lib' directory for example "..\..\..\..\..\Program Files (x86)\DevCpp\MinGW64\lib\libmysql.a".
       	-put the sql header files from "files for cpp sql/mysqlheaders/" directory in the compiler's 'include' directory for example "..\..\..\..\..\Program Files (x86)\Dev-Cpp\MinGW64\include"
### 3. Linker and search directory settings
     	> this project uses windows socket library winsock2.h, link it with the linker-
       		- open 'project build options' select 'linker settings' and add "ws2_32".
		> sql linker
    		- add the path pf 'libmysql.a' file in the linker "..\..\..\..\..\Program Files (x86)\Dev-Cpp\MinGW64\lib\libmysql.a"
       	> add the search directory for the sql headers under 'Search Directories' the path will be like "..\..\..\..\..\Program Files (x86)\Dev-Cpp\MinGW64\include"
### 4. follow step (ii) and (iii) of quick run server to ensure database set up for the server. 
<br />

## To re-build the client project:
	just import the project like server
<br />  			
<br />

## Description of the assignment:
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


### NB:
Database is exported in the database directory should be imported for the use. This is the server socket. 
client socket program that sends data is a seperate project from this and will be in different git repo
