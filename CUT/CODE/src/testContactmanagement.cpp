#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include <adminMenu.h>
#include <admin.h>
#include <user.h>

using namespace std;
using namespace CppUnit;

string PROJECTDIR;

class TestContactManagement : public CppUnit::TestFixture
{
    	CPPUNIT_TEST_SUITE(TestContactManagement);
	
	CPPUNIT_TEST(testcheckAdminforsunnycases);
    	CPPUNIT_TEST(testcheckAdminforrainycases);
	
	CPPUNIT_TEST(testcheckContactforsunnycases);
    	CPPUNIT_TEST(testcheckContactforrainycases);
	
	CPPUNIT_TEST(testcheckDateforsunnycases);
    	CPPUNIT_TEST(testcheckDateforrainycases);
    	
    	CPPUNIT_TEST_SUITE_END();

	private: 
		User *u;
	public:
    		void setUp(void );
    		void tearDown(void );

	protected:
		void testcheckAdminforsunnycases(void );
		void testcheckAdminforrainycases(void );
		
		void testcheckContactforsunnycases(void );
		void testcheckContactforrainycases(void );
		
		void testcheckDateforsunnycases(void );
		void testcheckDateforrainycases(void );
};

void TestContactManagement::setUp(void) { 
	u = new User;
}
void TestContactManagement::tearDown(void) { 
	delete u;
}

void TestContactManagement::testcheckAdminforsunnycases(void ) {
	CPPUNIT_ASSERT(1 == checkAdmin("Admin"));
}

void TestContactManagement::testcheckAdminforrainycases(void ) {
	CPPUNIT_ASSERT(0 == checkAdmin("admin"));
	CPPUNIT_ASSERT(0 == checkAdmin("capgemini"));
}

void TestContactManagement::testcheckContactforsunnycases(void ) {
    	CPPUNIT_ASSERT(1 == u->checkContact("p:prakash|raj|9834256378|9846572845|9898342567|prakash@gmail.com|surya@gmail.com|Anikkorai, Ooty|8745637854|23/05/2001|yes"));
    	CPPUNIT_ASSERT(1 == u->checkContact("p:rahul|sharma|9834267345|9847582845|9845462567|rahul@gmail.com|rahul2001@gmail.com|Avadi, Chennai|8743457854|12/02/2005|No"));
}

void TestContactManagement::testcheckContactforrainycases(void ) {
    	CPPUNIT_ASSERT(0 == u->checkContact("p:prakash|r|9834256378|9846572845|9898342567|prakash@gmail.com|surya@gmail.com|Anikkorai, Ooty|8745637854|29/02/2001|yes"));
    	CPPUNIT_ASSERT(0 == u->checkContact("p:rajesh|khanna|9829386378|9820932845|9898983567|rajesh@gmail.com|surya@gmail.com||8745643564|23/05/2001|yes"));
}

void TestContactManagement::testcheckDateforsunnycases(void ) {
   	CPPUNIT_ASSERT(1 == u->checkDate("31/05/2001"));
    	CPPUNIT_ASSERT(1 == u->checkDate("31/08/2001"));
	CPPUNIT_ASSERT(1 == u->checkDate("30/09/2005"));
	CPPUNIT_ASSERT(1 == u->checkDate("29/02/2000"));
}

void TestContactManagement::testcheckDateforrainycases(void ) {
    	CPPUNIT_ASSERT(0 == u->checkDate("31/12/1990"));
    	CPPUNIT_ASSERT(0 == u->checkDate("39/08/2001"));
	CPPUNIT_ASSERT(0 == u->checkDate("30/13/2005"));
	CPPUNIT_ASSERT(0 == u->checkDate("29/02/2001"));
}

CPPUNIT_TEST_SUITE_REGISTRATION( TestContactManagement );

int main(int argc, char* argv[])
{
    	CPPUNIT_NS::TestResult testresult;

    	CPPUNIT_NS::TestResultCollector collectedresults;
    	testresult.addListener (&collectedresults);

    	CPPUNIT_NS::BriefTestProgressListener progress;
    	testresult.addListener (&progress);

    	CPPUNIT_NS::TestRunner testrunner;
    	testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    	testrunner.run(testresult);

    	CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    	compileroutputter.write ();

    	ofstream xmlFileOut(PROJECTDIR + "reports/cppDateResults.xml");
		XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    	xmlOut.write();

    	return collectedresults.wasSuccessful() ? 0 : 1;		
}
