To compile: g++ -std=c++14 -g -Wall -Wextra classic.cpp comedy.cpp customer.cpp drama.cpp inventory.cpp movie.cpp myhash.cpp store.cpp ass4.cpp -o ass4
To run: ./ass4

Will read data4movies.txt, data4customers.txt, data4commands.txt

Assumptions:
- Above files have correct format, even if input is invalid.
- Above files are named correctly and saved in the proper directory.
- Customers can only borrow one copy of the same movie at a time, but they may
  have multiple copies checked out at the same time.
- There are a maximum of 10,000 customers, each with a unique ID.
- Major actors for Classic movies only have first and last names.
- Release dates for Classic movies only have numbers for month and year.
- Actions are Inventory (denoted as 'I'), History (denoted as 'H'),
  Borrow (denoted as 'B'), and Return (denoted as 'R').
- Movie genres are Comedy (denoted as 'F'), Drama (denoted as 'D'),
  and Classic (denoted as 'C').
- Media type(s) is/are 'D' (DVD).
- Movies are considered the same if they have the same genre
  and unique identifier, and separate movies otherwise (even for Classics).
