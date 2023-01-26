#pragma once
#include <iostream>
#include <string>
using namespace std;
class Movie
{
public:
    int id;
    string title;
    string ranking;
    int release_date;
    int number_of_tickets;
    int price_of_ticket;
    string comment;
    int get_id(){
        return id;
    }
    string get_title(){
        return title;
    }
    string get_ranking(){
        return ranking;
    }
    int get_release_date(){
        return release_date;
    }
    int get_number_of_tickets(){
        return number_of_tickets;
    }
    int get_price_of_ticket(){
        return price_of_ticket;
    }
    string get_comment(){
        return comment;
    };
    Movie() {};
    enum FilmType
    {
        ACTION,
        ADVENTURE,
        COMEDY,
        CRIME,
        CRIMINAL,
        DETECTIVE,
        DRAMA,
        FAMILY,
        FANTASY,
        HORRORS,
        MELODRAMA,
        ROMANCE,
        THRILLER
    };
    Movie(int id, string title, string ranking, int release_date, int  number_of_tickets, int price_of_ticket, string comment)
    {
        this->id = id;
        this->title = title;
        this->ranking = ranking;
        this->release_date = release_date;
        this->number_of_tickets = number_of_tickets;
        this->price_of_ticket = price_of_ticket;
        this->comment = comment;
    }
    void Print()
    {
        cout << "Id:\t\t" << id << endl;
        cout << "Title:\t\t" << title << endl;
        cout << "Ranking:\t" << ranking << endl;
        cout << "Release date:\t" << release_date << endl;
        cout << "Number of tickets:\t" << number_of_tickets << endl;
        cout << "Ticket price (UAN):\t" << price_of_ticket << endl;
        cout << "Comment:\t" << comment << endl;
    }
    void CalculateProfit()
    {
        int number = number_of_tickets;
        int price = price_of_ticket;
        int calculationofprofit = number * price;
        cout << "Calculation of profit for a certain day (UAN) : " << calculationofprofit << endl;
    };
    ~Movie()
    {

    }
};
class Cinema
{
public:
    string location;
    string get_location()
    {
        return location;
    }
    Cinema() {};
    Cinema(string location)
    {
        this->location = location;
    }
    void Print2()
    {
        cout << "Location:\t" << location << endl;
    }
    ~Cinema()
    {
    }
    Movie arr[99];
    Movie arr_sorted[1];
    int numberelements = 0;
    void MovieAdd(Movie movie)
    {
        arr[numberelements] = movie;
        numberelements++;
    }
    void SortByYear()
    {
        for (int i = 0; i < numberelements; i++)
        {
            for (int j = 0; j < numberelements; j++)
                if (arr[j].release_date < arr[j + 1].release_date)
                {
                    arr_sorted[0] = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = arr_sorted[0];
                }
        }
        for (int n = 0; n < numberelements; n++)
        {
            arr[n].Print();
        }
    }
    void TheHighestRanking()
    {
        for (int i = 0; i < numberelements; i++)
        {
            for (int j = 0; j < numberelements; j++)
            {
                if (arr[j].ranking < arr[j + 1].ranking)
                {
                    arr_sorted[0] = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = arr_sorted[0];
                }
            }
        }
        arr[0].Print();
    }
};
