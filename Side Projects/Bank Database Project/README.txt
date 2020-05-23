Bank Database Project Overview

In this project, I have replicated a Bank Account System that communicates with a database to write, read, and change 
information about users' bank account information. 

The idea is quite simple. I used a ".dat" file (essentially a binary file) to function as my database, with each segment of the 
file corresponding to a user's bank account details. Furthermore, I had created a Bank Account class that allows for multiple
functionalities needed such as deposit, withdraw, choose account type (checking or savings), interest rate, bank number, etc. and used 
objects of the class to interact with the file streams created by the .dat file.

I had chosen to use a binary type file as I knew that this file type is very efficient and relatively easy to use in data retrieval/
writing, unlike text or csv files which have details such as delimeters, potential random text, and formatting. The tricky thing with 
binary/data files is that the text is not easily readable, it stored as hexadecimal data (base-16) rather than the base-10 number base
ingrained within us. Therefore, it is extremely difficult to read directly from this file type, but with the power of C++, it is possible!

Please feel free to go over the project and observe its operation. Within the database, there is already three users' data within it that
can be accessed and viewed in a clear format from the cpp program. Furthermore, a clear interface is established and the user can create
an account, deposit to an account, withdraw from an account, observe all accounts in the system, and even delete accounts with just
the created bank number! This is was a fun project to make and I feel like I learned a good amount about how relational databases operate
at a deeper level and I look forward to learning more about specific database languages like SQL.

Thanks for reading, hope you enjoy!
Amir Hajjari
