#include <iostream>
#include <ContactData.h>
#include <cmunmmap.h>

int
main(int argc, char** argv) {
	ContactUMap<ContactData> cv;

	cv.addContact("anand", "anandnilkal@gmail.com", 9988776655, 1234567890);
	cv.addContact("ilkal", "ilkal@gmail.com", 8888776655, 1234567891);
	cv.addContact("anand", "ilkal1@gmail.com", 9988776654, 1234567892);
	cv.displayAll();
	cv.displayContact("ilkal");
	cv.displayContact(1234567892);
	cv.displayContact(9988776655);

	cv.displayContact("anand");
	cv.removeContact("anand");
	cv.displayAll();
}
