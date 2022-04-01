# C Assignment: Movie Tickets Purchasing System

|Seat type|Price per unit, RM|
|:---:|:---:|
|Standard|15|
|Preferred|18|
|LUXE|20|
|Child|8|

<br>

1. Movie ticket is charged based on type of seat selected.
2. User select the movie title before deciding how many tickets user planned to buy
3. User can choose only **ONE** movie title in each transaction
4. However, user can buy as many movie tickets and seat types can be different as well
5. User is allowed to re-select the movie but all seat selection donw in prior will be **DELETED**
6. The user can increase/reduce number of tickets that has been selected as long as user has yet to terminate this function
7. System should be able to detect the category of movie selected (UMUM or 18-rating) and **block** child ticket purchase if it belongs to 18-rating
8. Additional 10% discount will be granted (to be deducted from grand total) if user spend more than RM80
9. User should be able to go back to any functions in system upon completing the process of payment

### Yet to be implemented

- [x] 18-rating child blocking
- [ ] Data validation
- [ ] Empty seat selection display warning message
- [ ] Ability to go back to any other functions in the system before completing payment process
- [ ] Beautify. ASCII art and color
