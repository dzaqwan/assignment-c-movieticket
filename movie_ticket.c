#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define clear() system("cls||clear")

void selectMovieTitle(void);
char selectSeat(void);
void summary(void);
char payment(void);
void reset(void);

char _title[50];
char _seats[4][10] = {"Standard", "Preferred", "LUXE", "Child"};
int _seat_type[4];
int _price[4] = {15, 18, 20, 8};
int _child_safe, _amount;

int main()
{
    char flow_control = '0';

    clear();
    printf("\tWelcome to GSC Electronic Self-service Ticket Counter!\n\n");
    
    while(flow_control == '0')
    {
        selectMovieTitle();
        flow_control = selectSeat();
        if(flow_control == '0')
        {
            reset();
            continue;
        }
        summary();
        flow_control = payment();
        if(flow_control == '0')
            reset();
    }

    printf("\n\tThank you and enjoy your movie.");
    return 0;
}

void selectMovieTitle()
{
    char movie_titles[4][50] = {"Jujutsu Kaisen 0", "The Batman", "(18+) The Wolf of Wall Street", "Morbius"};
    int child_safe[4] = {1, 1, 0, 1};

    int user_input;

    printf("\n\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 NOW SHOWING \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    for(int i=0; i<4;i++)
        printf("\n\t\xDB\xDB\xDB\xDB\xB2 %d.\t%s\n", i+1, movie_titles[i]);
    printf("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    printf("\n\tPlease select a movie (Enter the number): ");
    scanf("%d", &user_input);
    printf("\n");

    strcpy(_title, movie_titles[user_input-1]);
    _child_safe = child_safe[user_input -1];
}

char selectSeat()
{   
    int user_input;
    char user_selection;

    while(1)
    {
        clear();
        printf("\n\t\t\t\t\xB2\xB2\xB2\xB2 SEAT SELECTION  \xB2\xB2\xB2\xB2");
        printf("\n\n\t=====================================================================\n");
        printf("\t Seat Type\t\tPrice per Unit (RM)\tNo item purchased\n");
        printf("\t=====================================================================\n");
        for(int i=0;(_child_safe == 1) ? i<4 : i<3; i++)
            printf("\t %d. %s\t\t%10d\t\t%10d\n", i+1, _seats[i], _price[i], _seat_type[i]);

        printf("\n\tEnter number to select seat. Enter 0 to exit the selection: ");
        scanf("%d", &user_input);

        if(user_input == 0)
            break;
        else if(user_input == 1 || user_input == 2 || user_input == 3 || (user_input == 4 && _child_safe == 1))
        {
            printf("\t[%s] selected. Please enter the number of seats desired: ", _seats[user_input-1]);
            scanf("%d", &_seat_type[user_input-1]);
        }
        else if(user_input == 4 && _child_safe == 0)
            printf("\tNo child seat is sold for 18-rating movies");
        else
            printf("\tInvalid input.");
    }

    _amount = 0;
    for(int i=0;i<4;i++)
        _amount += _price[i] * _seat_type[i];
    printf("\n\n\tTotal amount = RM%d", _amount);

    printf("\n\n\t1. Proceed to payment.\n\t2. Edit seat selection.\n\t0. Re-select movie title. (All seat selection done in prior will be DELETED)\n");
    printf("\n\t> ");
    getchar();
    user_selection = getchar();

    if(user_selection == '2')
        selectSeat();
    else
        return user_selection;
}

void summary()
{
    clear();

    int no_of_tickets=0;

    for(int i=0;i<4;i++)
        no_of_tickets += _seat_type[i];

    printf("\n\t\t\t\t\xB2\xB2\xB2\xB2 SUMMARY  \xB2\xB2\xB2\xB2");
    printf("\n\n\tYou have selected movie %s", _title);
    printf("\n\n\tYou have selected %d movie tickets, which consists of:\n", no_of_tickets);
    printf("\n\n\t===============================================================\n");
    printf("\tQuantity\t      Type\t\tAmount, RM");
    printf("\n\t===============================================================\n");

    for(int i=0;i<4;i++)
    {
        if(_seat_type[i] !=0)
            printf("\t%3d\t\t    %s\t\t%3d.00\n", _seat_type[i], _seats[i], _seat_type[i] * _price[i]);
    }
}

char payment()
{
    float amount_left, user_input;
    char user_selection;

    printf("\n\n\n\tThe total amount is RM%d.00", _amount);
    amount_left = _amount * 1.06;
    printf("\n\tPlus 6%% Service Tax, RM%.2f", amount_left);

    if(amount_left > 80)
    {
        printf("\n\tYou have spent more than RM80.00. Discount 10%% -> RM%.2f", amount_left*0.1);
        amount_left *= 0.9;
    }

    printf("\n\n\tPlease pay RM%.2f NETT", amount_left);

    while(amount_left > 0.01)
    {
        printf("\n\t> ");
        scanf("%f", &user_input);

        amount_left -= user_input;

        if(amount_left > 0.01)
            printf("\n\tYou still need to pay another RM%.2f", amount_left);
    }

    if(amount_left < 0)
        printf("\n\tYour outstanding balance is RM%.2f", -amount_left);

    printf("\n\n\tEnter 0 to purchase another movie tickets, or just enter (without 0) to exit.\n\t> ");
    getchar();
    user_selection = getchar();

    return user_selection;
}

void reset()
{
    for(int i=0; i<4; i++)
            _seat_type[i] = 0;
        clear();
}