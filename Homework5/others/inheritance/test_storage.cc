#include <iostream>
#include "Storage.h"

int main(void) {



  Storage<int> intstorage( 5 );
  Storage<double> doublestorage( 4.6);



  std::cout << "Int storage: " << intstorage.get_val() << std::endl;
  std::cout << "double storage: " << doublestorage.get_val() << std::endl;


  StudentRecordPhysics phys;
  std::cout << "Enter physics student and 2 scores:" << std::endl;
  phys.input( std::cin ); 
  Storage<StudentRecord * >  srstorage( &phys );

  std::cout << "SR storage: " ;
  srstorage.get_val()->print(std::cout);
  
};
