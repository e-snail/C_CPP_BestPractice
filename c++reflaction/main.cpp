#include <iostream>
#include <string>
#include <stdlib.h>
#include <list>
#include <map>

using namespace std;
class Base;

typedef Base* (*ObjectCreating) ();
void RegisterFactoryCreate(ObjectCreating func_prt, string className);
map<string, ObjectCreating> funcMap;

#define DECLARE_CLASS_CREATE(class_name) \
static Base* CreateClass##class_name();

#define REG_CLASS_CREATE(class_name) \
RegisterFactoryCreate(class_name::CreateClass##class_name, #class_name);

#define IMPLE_CLASS_CREATE(class_name) \
static Base* CreateClass##class_name () {\
	return new class_name;	\
};

#define IGNORE_FUNC \
void forgetme();

class Base
{
public:
	Base() {};
	void showMySelf() { cout <<"Base::Show Me!" <<endl; };
	~Base() {};

	//following is neccessary for each class needs creating by name string
	//also, "static" is neccessary. non-static function will cause compiling error
	//static Base* CreateClassBase() { return new Base; };

	//or we can use macro

	IMPLE_CLASS_CREATE(Base);
};

int main(int argc, char **argv)
{
	//following are why we need reflaction mechanism
	//Base *b = new "Base";  or
	//Base *b = CreateObject("Base");  /*We can implemnt this with method factory*/ 
	//Base *b = CreateObject(FunctionForCreating, "Base"); /* we r gonna implement this with point function */

	//RegisterFactoryCreate(Base::CreateClassBase, "Base");
	//or
	//REG_CLASS_CREATE(Base);

	REG_CLASS_CREATE(Base);
	Base *b = 0;
	ObjectCreating c = funcMap["Base"];
	b = c(); 
	if (b) {
		b->showMySelf();
	}

	return 0;
}

void RegisterFactoryCreate(ObjectCreating func_prt, string className )
{
	funcMap[className] = func_prt;
}
