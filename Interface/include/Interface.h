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

			virtual void contact_add(tags_t, void*) = 0;
			virtual void dump_contact_details() = 0;
            virtual string& getName() = 0;
            virtual string& getEmail() = 0;
            virtual uint64_t& getHomeNum() = 0;
            virtual uint64_t& getOffNum() = 0;
	};
}

#endif
