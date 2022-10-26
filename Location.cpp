#include "Location.h"

Location:: Location()
{
    this->location = "";
}

Location:: Location(string place)
{
    this->location = place;
}

string
Location:: getLocation()
{
    return this->location;
}

void
Location::addPeople
(std::string person){
    people[numpeople] = person;
    numpeople ++;
}

Json::Value
Location::dump2JSON
()
{

    Json::Value result;
    

    if (this->people[0] != "")
        {
            result["people here"] = this->people[0] + " and " +  this->people[1];

        }

    result["Location"] = this->location;
    return result;
}