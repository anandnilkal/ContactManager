#include <ContactData.h>

using namespace std;

namespace ContactManager {
/**
* Add single property of the ContactData class.
*/
	void ContactData::contact_add(contact::tags_t tag, void* value) {
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
*  display ContactData information
*/
	void ContactData::dump_contact_details() {
		cout << endl;
		cout << "name 		: " << _name << endl;
		cout << "email 		: " << _email << endl;
		cout << "num_home 	: " << _num_home << endl;
		cout << "num_office 	: " << _num_office << endl;
		cout << endl;
	}

    string& ContactData::getName() {
       return _name; 
    }

    string& ContactData::getEmail() {
        return _email;
    }

    uint64_t& ContactData::getHomeNum() {
        return _num_home;
    }

    uint64_t& ContactData::getOffNum() {
        return _num_office;
    }
}
