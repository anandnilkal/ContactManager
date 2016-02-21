#include <Interface.h>

using namespace std;

namespace ContactManager {
/**
* Add single property of the contact class.
*/
	void contact::contact_add(tags_t tag, void* value) {
		switch(tag) {
			case NAME:{
				string* name = reinterpret_cast<string*>(value);
				_name.assign(*name);
				}
				break;

			case EMAIL:{
				string* email = reinterpret_cast<string*>(value);
				_email.assign(*email);
				}
				break;

			case H_NUM:{
				uint64_t* hnum = reinterpret_cast<uint64_t*>(value);
				_num_home = (*hnum);
				}
				break;

			case O_NUM:{
				uint64_t* onum = reinterpret_cast<uint64_t*>(value);
				_num_office = (*onum);
				}
				break;
		}
	}

/**
*  display contact information
*/
	void contact::dump_contact_details() {
		cout << endl;
		cout << "name 		: " << _name << endl;
		cout << "email 		: " << _email << endl;
		cout << "num_home 	: " << _num_home << endl;
		cout << "num_office 	: " << _num_office << endl;
		cout << endl;
	}
}
