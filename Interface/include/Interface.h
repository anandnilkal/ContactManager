#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <iostream>
#include <stdio.h>
#include <stdint.h>

using namespace std;

/**
* contact class defines the basic data structure for storing contact information.
*   current this data structure supports following 4 information storage.
*	1.	name
*	2.	email
*	3.	home contact number
*	4.	office contact number
*/
namespace ContactManager {
	class contact {
		public:

		enum tags_t {
			NAME = 0,
			EMAIL = 1,
			H_NUM = 2,
			O_NUM = 3
		};

			contact()
			: _name(""), _email(""), _num_home(0), _num_office(0) {
			}
			contact(string name, string email, uint64_t num_home, uint64_t num_office)
			: _name(name), _email(email), _num_home(num_home), _num_office(num_office){
			}
			~contact() {}
			void contact_add(tags_t, void*);
			void dump_contact_details();

			string _name;
			string _email;
			uint64_t _num_home;
			uint64_t _num_office;	
	};
}

#endif
