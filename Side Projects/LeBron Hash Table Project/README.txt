As I am an avid NBA fan, I thought it would be cool to create a program that can take any players' statistics over all seasons
and manipulate and store that data using C++!

After some research, I had found an NBA player statistics website that worked perfectly!
link -> https://www.basketball-reference.com/players/j/jamesle01.html.

I chose LeBron James as he was played many seasons in the NBA and it would prove if my design would "scale" to the relative 
NBA player population, which it did!

Before I began my C++ and Excel extractions, manipulation, coding, etc., I had to decide what data structure to use to work with this
data. I chose the Hash Table Data Structure as it allows for easy access of the data and can be adjusted without too much trouble. 
Furthermore, the hash table made the most sense to me as one of my initial goals was to be able to store every season's data into 
a specific category/object, yet have easy access to any statistic over any year.

Then, I pulled the data from the website into an excel file, converted it to a CSV file for extraction to the C++ project, and took a 
few of the statistics out that I did not believe were necessary to show. Then, in my C++ project, I decided to utulize a two-dimensional
array to initially store all the data which would then be dumped into the LeBron object I would create, which would store all this
information in one object. 

After pulling the data into the C++ program, I began creation of the "LeBron" class. NOTE: I simply named this class "LeBron" for ease of 
reference, (and that he is one of my favorite players :) ....) but this class can easily be used for ANY player whose data can be
extracted from a CSV file as long as the "Season" of the player is known.

To "hash" the data, I chose to hash by the "Season" data item as my goal of this project was to store the data by each of LeBron's seasons.

After creating the interface and implementation, I created a console interface to test all the member functions of the class and it 
turned out well!

I think this project is really usable for any sort of data manipulation as it scales well for many applications, can easily be 
adjusted to store any "amounts" of info since it utulizes a 2D array, and can find individual statistics under certain constraints 
in large amounts of data. From this project, I learned that different data structures may work better in some areas than others.
For example, I think that the hash table is great for data which can be stored in n-dimensional arrays or any sort of large data
requirements.

I have included all the cpp files, excel files, etc. to show the project. 
If you have read this far, you are awesome and I hope you enjoy the project!!!!
Thanks, Amir Hajjari :)
