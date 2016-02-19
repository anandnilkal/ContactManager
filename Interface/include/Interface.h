#ifndef _INTERFACE_H
#define _INTERFACE_H

#include <iostream>

using namespace std;

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
			: _name(""), _email(""), _num_home(""), _num_office("") {
			}
			contact(string name, string email, string num_home, string num_office)
			: _name(name), _email(email), _num_home(num_home), _num_office(num_office){
			}
			~contact() {}
			add(tags_t, string);

		private:
			string _name;
			string _email;
			string _num_home;
			string _num_office;	
	};
}

#endif
