
// test_GPS.cpp

#include "Person.h"
#include "Thing.h"
#include "Location.h"

int
main(int argc, char *argv[])
{
  // if (argc != 3) return -1;
  Person red_riding_hood{"little red riding hood"};
  Person grandmother{"grandmother"}; 
  Person wolf{"Wolf"};
  Person mother{"mother"};
  Thing red_hood{grandmother, "red hood"};
  Thing cakeandwine{mother, "cake and wine"};
  Location woods{"Woods"};
  Location grandmothersHome{"Grandma's House"};
  Location outsideWoods{"Outside Woods"};
  Thing threeTrees{grandmothersHome};


  
  Location home {"little red riding hoods home"};
  red_riding_hood.setHome(home);
  red_riding_hood.setLocation(home, *getNowJvTime());
  wolf.setHome(woods);
  wolf.setLocation(woods, *getNowJvTime());

  red_hood.give(red_riding_hood);
  std::cout << (red_hood.dump2JSON()).toStyledString() << std::endl;

  cakeandwine.give(red_riding_hood);
  std::cout << (cakeandwine.dump2JSON()).toStyledString() << std::endl;

  grandmother.setHome(grandmothersHome);
  grandmother.setLocation(grandmothersHome, *getNowJvTime());

  
  red_riding_hood.setLocation(outsideWoods, *getNowJvTime());
  wolf.setLocation(outsideWoods, *getNowJvTime());

  outsideWoods.addPeople(wolf.getName());
  outsideWoods.addPeople(red_riding_hood.getName());

  std::cout << (outsideWoods.dump2JSON()).toStyledString() << std::endl;







  
  
  /*
  
  GPS_DD gps_Home_Woodland { 38.672215864622636, -121.72280111121437 };
  GPS_DD gps_TLC_UCDavis   { 38.53874868013882,  -121.7542091083306 };
  GPS_DD gps_IKEA_Sacramento { 38.58681641563053, -121.55296296578501};

  Person Felix { "987654321", "Felix", gps_Home_Woodland };
  Felix.setLocation(gps_IKEA_Sacramento, (*getNowJvTime()));

  IP_Address meatball_IP { 2850883174 };
  IOT_Thing Swedish_Meatball { Felix , meatball_IP };
  Swedish_Meatball.model = "HUVUDROLL";
  Swedish_Meatball.sequence_num = "123456-0000";
  Swedish_Meatball.description = "frozen";
  Swedish_Meatball.location = gps_Home_Woodland;
  Swedish_Meatball.purchased = *getNowJvTime();
  Swedish_Meatball.sold = *getNowJvTime();
  Swedish_Meatball.owner = Felix;

  Felix.setLocation(gps_TLC_UCDavis, (*getNowJvTime()));

  std::cout << (Felix.dump2JSON()).toStyledString() << std::endl;
  std::cout << (Swedish_Meatball.dump2JSON()).toStyledString() << std::endl;
  
  // GPS_DD current { atof(argv[1]), atof(argv[2]) };
  // GPS_DD gps_NYC {40.7, -73.95};
  // GPS_DD gps_Sydney {-33.87, 151.213};
  // double distance_calculated;
  // distance_calculated = gps_TLC_UCDavis.distance(current);
  // std::cout << "the distance to Davis is " << distance_calculated << " miles." << std::endl;
  */
 
  return 0;
}
