#ifndef _CONTACT_DATA_H
#define _CONTACT_DATA_H
#include <Interface.h>

namespace ContactManager {
	class ContactData : public contact {
		public:

			ContactData()
			: _name(""), _email(""), _num_home(0), _num_office(0) {
			}
			ContactData(string name, string email, uint64_t num_home, uint64_t num_office)
			: _name(name), _email(email), _num_home(num_home), _num_office(num_office){
			}
			~ContactData() {}
			void contact_add(contact::tags_t, void*);
			void dump_contact_details();
            string& getName();
            string& getEmail();
            uint64_t& getHomeNum();
            uint64_t& getOffNum();

        private:
			string _name;
			string _email;
			uint64_t _num_home;
			uint64_t _num_office;	
	};
}
#endif
